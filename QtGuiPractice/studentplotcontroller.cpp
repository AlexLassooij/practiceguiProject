#include <studentplotcontroller.h>
#include <QtGuiPractice.h>

StudentPlotController::StudentPlotController(QtGuiPractice *ui, QCustomPlot *studentPlot)
{
	this->studentPlot = studentPlot;	

	this->ui = ui;
}

void StudentPlotController::setBackground()
{
	QLinearGradient gradient(0, 0, 0, 200);
	gradient.setColorAt(0, QColor(30, 90, 90));
	gradient.setColorAt(0.38, QColor(60, 180, 180));
	gradient.setColorAt(1, QColor(35, 105, 105));
	studentPlot->setBackground(QBrush(gradient));
}

void StudentPlotController::setDatabasePath(QString databasePath)
{
	if (databasePath.isEmpty())
	{

		return;
	}

	if (QFile::exists(databasePath))
	{
		this->databasePath = databasePath;
		initStudentDb(databasePath);
	}
	else
	{
		QMessageBox::critical(0, QObject::tr("Error: Could not locate database."), "Make sure you select a valid database (.db) file");
	}
}

void StudentPlotController::initStudentDb(QString databasePath)
{
	StudentDb = QSqlDatabase::addDatabase("QSQLITE");

	QStringList dbStringList = QSqlDatabase::connectionNames();


	StudentDb.setDatabaseName(databasePath);
	/*StudentDb.setHostName("localhost");
	StudentDb.setUserName("root");
	StudentDb.setPassword("");*/

	if (!StudentDb.open()) {
		QMessageBox::warning(nullptr, QObject::tr("WARNING"), QString("Can not open !"));
	}

	populateStudentData();
}

void StudentPlotController::populateStudentData()
{
	QSqlQuery query;
	// only need to navigate forwards
	query.setForwardOnly(true);

	// retrieve table size
	executeQuery(&query, "SELECT COUNT(*) FROM studentgrade");

	query.next(); 

	this->tableSize = query.value(0).toInt();

	// initialize with size since table may be large (avoid allocating more memory later)
	this->allStudentData = QVector<StudentDataStruct>(this->tableSize);

	executeQuery(&query, "SELECT District AS dist, Grade AS grd, [Pct Level 1] AS pct1, [Pct Level 2] AS pct2, [Pct Level 3] AS pct3, [Pct Level 4] AS pct4,"
		"([Pct Level 1] + [Pct Level 2] + [Pct Level 3] + [Pct Level 4]) / 4.0 AS pctave "
		"FROM studentgrade");

	int i = 0;
	while (query.next())
	{
		struct StudentDataStruct newData =
		{
			query.value("dist").toString(),
			// represent as string due to "AllGrades" non-numeric value
			query.value("grd").toString(),
			query.value("pct1").toFloat(),
			query.value("pct2").toFloat(),
			query.value("pct3").toFloat(),
			query.value("pct4").toFloat(),
			query.value("pctave").toFloat(),
		};
		
		allStudentData[i] = newData;
		i++;
	}

	// get all distinct districts
	executeQuery(&query, "SELECT DISTINCT District AS dist FROM studentgrade");

	while (query.next())
	{
		districtList.append(query.value("dist").toString());
	}

	// get all distinct grades
	executeQuery(&query, "SELECT DISTINCT Grade AS grd FROM studentgrade");

	while (query.next())
	{
		gradeList.append(query.value("grd").toString());
	}
	
	setComboBoxes();
}

void StudentPlotController::executeQuery(QSqlQuery *query, QString sqlQuery)
{
	if (!query->exec(sqlQuery))
		QMessageBox::critical(0, QObject::tr("Error: Could not query data from studentgrade table."), query->lastError().text());
}

void StudentPlotController::setComboBoxes()
{
	ui->districtComboBox->addItem(ITEM_ANY);
	ui->gradeComboBox->addItem(ITEM_ANY);
	ui->districtComboBox->addItems(districtList.toList());
	ui->gradeComboBox->addItems(gradeList.toList());
}

void StudentPlotController::setBarGraph()
{
	QString districtSelection = ui->districtComboBox->currentText();
	QString gradeSelection = ui->gradeComboBox->currentText();

	int itemCount = 0;

	struct StudentDataStruct aggragateData =
	{
		districtSelection,
		gradeSelection,
		0.0,
		0.0,
		0.0,
		0.0,
		0.0,
	};

	// aggragate all data to compute the average scores for a given district and / or grade
	for (int i = 0; i < allStudentData.size(); i++) {
		StudentDataStruct current = allStudentData.at(i);
		if ((QString::compare(districtSelection, ITEM_ANY) == 0) || (QString::compare(districtSelection, current.district) == 0)) {
			if ((QString::compare(gradeSelection, ITEM_ANY) == 0) || (QString::compare(gradeSelection, current.grade) == 0)) {
				aggragateData.pct1 += current.pct1;
				aggragateData.pct2 += current.pct2;
				aggragateData.pct3 += current.pct3;
				aggragateData.pct4 += current.pct4;
				aggragateData.pctave += current.pctave;

				itemCount++;
			}
		}
	}

	aggragateData.pct1 /= itemCount;
	aggragateData.pct2 /= itemCount;
	aggragateData.pct3 /= itemCount;
	aggragateData.pct4 /= itemCount;
	aggragateData.pctave /= itemCount;

	currentData = aggragateData;
	showData();
}

void StudentPlotController::showData()
{
	studentPlot->addGraph();
	QCPBars *scores = new QCPBars(studentPlot->xAxis, studentPlot->yAxis);
	scores->setAntialiased(false);
	scores->setName("Scores");
	scores->setPen(QPen(QColor(250, 170, 20).lighter(150)));
	scores->setBrush(QColor(250, 170, 20));

	QVector<double> xTicks;
	QVector<QString> xLabels;
	xTicks << 1 << 2 << 3 << 4 << 5;
	xLabels << "pct1" << "pct2" << "pct3" << "pct4" << "pctave";

	QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
	textTicker->addTicks(xTicks, xLabels);
	studentPlot->xAxis->setTicker(textTicker);
	// 0 inside, 4 outside plot
	studentPlot->xAxis->setTickLength(0, 4);
	studentPlot->xAxis->setRange(0, 6);
	studentPlot->xAxis->setBasePen(QPen(Qt::white));
	studentPlot->xAxis->setTickPen(QPen(Qt::white));
	studentPlot->xAxis->grid()->setVisible(true);
	studentPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
	studentPlot->xAxis->setTickLabelColor(Qt::white);
	studentPlot->xAxis->setLabelColor(Qt::white);




	// prepare y axis:
	double rangeMax = std::max({ currentData.pct1, currentData.pct2, currentData.pct3, currentData.pct4, currentData.pctave }) + YAXIS_BUFFER;
	studentPlot->yAxis->setRange(0, rangeMax);
	studentPlot->yAxis->setPadding(5); // a bit more space to the left border
	studentPlot->yAxis->setLabel(QString("Student Scores for District: '%1', Grade: '%2'")
								.arg(currentData.district)
								.arg(currentData.grade));
	studentPlot->yAxis->setBasePen(QPen(Qt::white));
	studentPlot->yAxis->setTickPen(QPen(Qt::white));
	studentPlot->yAxis->setSubTickPen(QPen(Qt::white));
	studentPlot->yAxis->grid()->setSubGridVisible(true);
	studentPlot->yAxis->setTickLabelColor(Qt::white);
	studentPlot->yAxis->setLabelColor(Qt::white);
	studentPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
	studentPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

	// Add data
	QVector<double> scoresData;
	scoresData << currentData.pct1 << currentData.pct2 << currentData.pct3 << currentData.pct4 << currentData.pctave;
	scores->setData(xTicks, scoresData);

	studentPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignHCenter);

	studentPlot->replot();
}


