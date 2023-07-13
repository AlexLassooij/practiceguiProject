#include "studentdatamanager.h"
#include <QtGuiPractice.h>

const QString StudentDataManager::DEFAULT_DB_PATH = QString("C:/Users/alexl/Documents/WorkLearn/Codebase/Training/Database/practice.db");

StudentDataManager::StudentDataManager(QtGuiPractice *ui, QCustomPlot *studentPlot)
{
	this->studentPlot = studentPlot;	
	this->ui = ui;
}

void StudentDataManager::setBackground()
{
	QLinearGradient gradient(0, 0, 0, 200);
	gradient.setColorAt(0, QColor(30, 90, 90));
	gradient.setColorAt(0.38, QColor(60, 180, 180));
	gradient.setColorAt(1, QColor(35, 105, 105));
	studentPlot->setBackground(QBrush(gradient));
}

void StudentDataManager::setDatabasePath(QString databasePath)
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

void StudentDataManager::initStudentDb(QString databasePath)
{
	StudentDb = QSqlDatabase::addDatabase("QSQLITE");

	QStringList dbStringList = QSqlDatabase::connectionNames();


	StudentDb.setDatabaseName(databasePath);

	if (!StudentDb.open()) {
		QMessageBox::warning(nullptr, QObject::tr("WARNING"), QString("Can not open !"));
	}

}

void StudentDataManager::populateStudentData()
{
	QSqlQuery query;
	// only need to navigate forwards
	query.setForwardOnly(true);

	//// retrieve table size
	//executeQuery(&query, "SELECT COUNT(*) FROM studentinfo");

	//query.next(); 

	//this->tableSize = query.value(0).toInt();

	//// initialize with size since table may be large (avoid allocating more memory later)
	//this->allStudentData = QVector<StudentDataStruct>(this->tableSize);

	executeQuery(&query, "SELECT StudentID AS sid, [First Name] AS fname, [Last Name] AS lname, Email as email, District AS dist, Grade AS grd, Year AS yr,"
						 " [Score 1] AS score1, [Score 2] AS score2, [Score 3] AS score3, [Score Final] AS scorefinal "
						 "FROM studentinfo");

	allStudentData = processQuery(&query);

	// get all distinct districts
	executeQuery(&query, "SELECT DISTINCT District AS dist FROM studentinfo");

	while (query.next())
	{
		districtList.append(query.value("dist").toString());
	}

	// get all distinct grades
	executeQuery(&query, "SELECT DISTINCT Grade AS grd FROM studentinfo");

	while (query.next())
	{
		gradeList.append(query.value("grd").toString());
	}

	// get all distinct grades
	executeQuery(&query, "SELECT DISTINCT Year AS yr FROM studentinfo");

	while (query.next())
	{
		yearList.append(query.value("yr").toString());
	}

	sortingOptions = QVector<QString>{ "name", "dist", "grd", "yr", "score1", "score2", "score3", "scorefinal" };

	setComboBoxes();
	setQueryComboBoxes();
}

void StudentDataManager::getFilteredStudentData()
{
	QSqlQuery query;
	filteredStudentData.clear();
	editsOutstanding.clear();
	deletesOutstanding.clear();

	QStringList conditions;

	QString nameCondition = ui->queryNameText->toPlainText();
	if (!nameCondition.isEmpty())
		conditions.append(QString("LOWER(fname) || \" \" ||  LOWER(lname) LIKE LOWER('%%1%')").arg(nameCondition));

	QString scoreConditionSign = ui->queryScoreGreater->isChecked() ? ">" : "<";
	QString scoreConditionNum = ui->queryScoreText->toPlainText();
	if (!scoreConditionNum.isEmpty())
		conditions.append(QString("scorefinal %1 %2").arg(scoreConditionSign).arg(scoreConditionNum));

	QString districtCondition = ui->queryDistrictComboBox->currentText();
	if ((QString::compare(districtCondition, ITEM_ANY) != 0))
		conditions.append(QString("dist LIKE '%%1%'").arg(districtCondition));

	QString gradeCondition = ui->queryGradeComboBox->currentText();
	if ((QString::compare(gradeCondition, ITEM_ANY) != 0))
		conditions.append(QString("grd LIKE '%%1%'").arg(gradeCondition));

	QString yearCondition = ui->queryYearComboBox->currentText();
	if ((QString::compare(yearCondition, ITEM_ANY) != 0))
		conditions.append(QString("yr LIKE '%%1%'").arg(yearCondition));

	QString sortingCondition = (QString::compare(ui->querySortByComboBox->currentText(), ITEM_ANY) != 0) ? 
		QString("ORDER BY %1").arg(ui->querySortByComboBox->currentText()) 
		: "";

	queryConditions = conditions.join(" AND ");
	if (!queryConditions.isEmpty())
		queryConditions.prepend("WHERE ");
	queryConditions.append(sortingCondition);
	// test for corner case : no conditions, joinedConditions should be an empty string 

	executeQuery(&query, QString("SELECT StudentID AS sid, [First Name] AS fname, [Last Name] AS lname, Email as email, District AS dist, Grade AS grd, Year AS yr,"
		" [Score 1] AS score1, [Score 2] AS score2, [Score 3] AS score3, [Score Final] AS scorefinal "
		"FROM studentinfo "
		"%1"
		).arg(queryConditions)
	);

	filteredStudentData = processQuery(&query);
	setQueryResultArea(&filteredStudentData);
}

void StudentDataManager::resetSearch()
{
	getFilteredStudentData();
}

void StudentDataManager::processEdits()
{
	QSqlQuery query;
	for (int i = 0; i < editsOutstanding.size(); i++)
	{
		int rowToEdit = editsOutstanding.at(i);
		QString studentID = ui->queryResultsTable->item(rowToEdit, 0)->text();
		QString name = ui->queryResultsTable->item(rowToEdit, 1)->text();
		QString email = ui->queryResultsTable->item(rowToEdit, 2)->text();
		QString district = ui->queryResultsTable->item(rowToEdit, 3)->text();
		QString grade = ui->queryResultsTable->item(rowToEdit, 4)->text();
		QString year = ui->queryResultsTable->item(rowToEdit, 5)->text();
		QString score1 = ui->queryResultsTable->item(rowToEdit, 6)->text();
		QString score2 = ui->queryResultsTable->item(rowToEdit, 7)->text();
		QString score3 = ui->queryResultsTable->item(rowToEdit, 8)->text();
		QString scorefinal = ui->queryResultsTable->item(rowToEdit, 9)->text();

		QString firstName = name.split(" ").at(0);
		QString lastName = name.split(" ").at(1);

		QString updateQuery = QString(
			"UPDATE studentinfo "
			"SET [First Name] = '%1', [Last Name] = '%2', Email = '%3', "
			"District = '%4', Grade = '%5', Year = '%6', "
			"[Score 1] = '%7', [Score 2] = '%8', [Score 3] = '%9', [Score Final] = '%10' "
			"WHERE StudentID = %11"
		)
			.arg(firstName)
			.arg(lastName)
			.arg(email)
			.arg(district)
			.arg(grade)
			.arg(year)
			.arg(score1)
			.arg(score2)
			.arg(score3)
			.arg(scorefinal)
			.arg(studentID)
			;

		qDebug() << updateQuery << endl;

		// executeQuery(&query, updateQuery);
		
	}

	editsOutstanding.clear();
}


void StudentDataManager::processDeletes()
{

}




void StudentDataManager::handleItemClicked(QTableWidgetItem *item)
{
	int itemRow = item->row();
	int itemColumn = item->column();
	QString studentID = ui->queryResultsTable->item(itemRow, 0)->text();

	// TODO : handle corner case where item is selected for delete and edit 
	if (itemColumn == 0)
	{
		item->setBackground(QColor(255, 0, 0, 127));
		if (!deletesOutstanding.contains(itemRow))
		{
			deletesOutstanding.append(itemRow);
		}
	}
		
	else
	{
		item->setBackground(QColor(0, 0, 200, 127));
		if (!editsOutstanding.contains(itemRow))
		{
			editsOutstanding.append(itemRow);
		}
	}
		
}


// helper and setter functions 

QVector<StudentDataManager::StudentDataStruct> StudentDataManager::processQuery(QSqlQuery *query)
{
	QVector<StudentDataStruct> dataList;
	while (query->next())
	{
		struct StudentDataStruct newData =
		{
			query->value("sid").toInt(),
			query->value("fname").toString(),
			query->value("lname").toString(),
			query->value("email").toString(),
			query->value("dist").toString(),
			// represent as string due to "AllGrades" non-numeric value
			query->value("grd").toString(),
			query->value("yr").toString(),
			query->value("score1").toFloat(),
			query->value("score2").toFloat(),
			query->value("score3").toFloat(),
			query->value("scorefinal").toFloat(),
		};

		dataList.append(newData);
	}
	return dataList;
}


void StudentDataManager::executeQuery(QSqlQuery *query, QString sqlQuery)
{
	if (!query->exec(sqlQuery))
		QMessageBox::critical(0, QObject::tr("Error: Could not query data from studentinfo table."), query->lastError().text());
}

void StudentDataManager::setComboBoxes()
{
	ui->districtComboBox->addItem(ITEM_ANY);
	ui->gradeComboBox->addItem(ITEM_ANY);
	ui->districtComboBox->addItems(districtList.toList());
	ui->gradeComboBox->addItems(gradeList.toList());
}

void StudentDataManager::setQueryComboBoxes()
{
	ui->queryDistrictComboBox->addItem(ITEM_ANY);
	ui->queryGradeComboBox->addItem(ITEM_ANY);
	ui->queryYearComboBox->addItem(ITEM_ANY);
	ui->querySortByComboBox->addItem(ITEM_ANY);

	ui->queryDistrictComboBox->addItems(districtList.toList());
	ui->queryGradeComboBox->addItems(gradeList.toList());
	ui->queryYearComboBox->addItems(yearList.toList());
	ui->querySortByComboBox->addItems(sortingOptions.toList());

}

void StudentDataManager::setQueryResultArea(QVector<StudentDataStruct> *results)
{
	ui->queryResultsTable->clearContents();
	ui->queryResultsTable->setRowCount(results->size());
	for (int row = 0; row < results->size(); row++)
	{
		StudentDataStruct current = results->at(row);
		QTableWidgetItem *studentID = new QTableWidgetItem(QString::number(current.studentID));
		QTableWidgetItem *name = new QTableWidgetItem(
								 QString("%1 %2")
								.arg(current.firstName)
								.arg(current.lastName));
		QTableWidgetItem *email = new QTableWidgetItem(QString(current.email));
		QTableWidgetItem *district = new QTableWidgetItem(QString(current.district));
		QTableWidgetItem *grade = new QTableWidgetItem(QString(current.grade));
		QTableWidgetItem *year = new QTableWidgetItem(QString(current.year));
		QTableWidgetItem *score1 = new QTableWidgetItem(QString::number(current.score1));
		QTableWidgetItem *score2 = new QTableWidgetItem(QString::number(current.score2));
		QTableWidgetItem *score3 = new QTableWidgetItem(QString::number(current.score3));
		QTableWidgetItem *scorefinal = new QTableWidgetItem(QString::number(current.scorefinal));


		ui->queryResultsTable->setItem(row, 0, studentID);
		ui->queryResultsTable->setItem(row, 1, name);
		ui->queryResultsTable->setItem(row, 2, email);
		ui->queryResultsTable->setItem(row, 3, district);
		ui->queryResultsTable->setItem(row, 4, grade);
		ui->queryResultsTable->setItem(row, 5, year);
		ui->queryResultsTable->setItem(row, 6, score1);
		ui->queryResultsTable->setItem(row, 7, score2);
		ui->queryResultsTable->setItem(row, 8, score3);
		ui->queryResultsTable->setItem(row, 9, scorefinal);
	}

	/*for (int i = 0; i < results.size(); i++) {
		StudentDataStruct current = results.at(i);
		QGridLayout *resultRow = new QGridLayout(ui->queryResultScrollAreaContents);
		QLabel *name = new QLabel(ui->queryResultScrollAreaContents);
		name->setText(QString("'%1' '%2'").arg(current.firstName).arg(current.lastName));

		QLabel *email = new QLabel(ui->queryResultScrollAreaContents);
		email->setText(QString(current.email));

		QLabel *year = new QLabel(ui->queryResultScrollAreaContents);
		email->setText(QString(current.year));

		QLabel *grade = new QLabel(ui->queryResultScrollAreaContents);
		grade->setText(QString(current.email));

		QLabel *district = new QLabel(ui->queryResultScrollAreaContents);
		district->setText(QString(current.email));

		QLabel *pctave = new QLabel(ui->queryResultScrollAreaContents);
		pctave->setText(QString(current.email));

		resultRow->addWidget(name, 0, 0, 1, 2);
		resultRow->addWidget(email, 0, 2, 1, 2);
		resultRow->addWidget(year, 0, 4, 1, 1);
		resultRow->addWidget(grade, 0, 5, 1, 1);
		resultRow->addWidget(district, 0, 6, 1, 1);
		resultRow->addWidget(pctave, 0, 7, 1, 1);

		ui->queryResultScrollAreaVerticalLayout->addLayout(resultRow);*/


}

//void StudentDataManager::clearQueryResultArea()
//{
//	if (ui->queryResultScrollAreaVerticalLayout->layout() != NULL)
//	{
//		QLayoutItem* item;
//		while ((item = ui->queryResultScrollAreaVerticalLayout->layout()->takeAt(0)) != NULL)
//		{
//			delete item->widget();
//			delete item;
//		}
//		// delete ui->queryResultScrollAreaVerticalLayout->layout();
//	}
//}

void StudentDataManager::setBarGraph()
{
	QString districtSelection = ui->districtComboBox->currentText();
	QString gradeSelection = ui->gradeComboBox->currentText();

	int itemCount = 0;

	struct StudentDataStruct aggregateData =
	{
		0,
		"",
		"",
		"",
		districtSelection,
		gradeSelection,
		"",
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
				aggregateData.score1 += current.score1;
				aggregateData.score2 += current.score2;
				aggregateData.score3 += current.score3;
				aggregateData.scorefinal += current.scorefinal;

				itemCount++;
			}
		}
	}

	aggregateData.score1 /= itemCount;
	aggregateData.score2 /= itemCount;
	aggregateData.score3 /= itemCount;
	aggregateData.scorefinal /= itemCount;

	currentDataPlotted = aggregateData;
	showData();
}

void StudentDataManager::showData()
{
	studentPlot->addGraph();
	QCPBars *scores = new QCPBars(studentPlot->xAxis, studentPlot->yAxis);
	scores->setAntialiased(false);
	scores->setName("Scores");
	scores->setPen(QPen(QColor(250, 170, 20).lighter(150)));
	scores->setBrush(QColor(250, 170, 20));

	QVector<double> xTicks;
	QVector<QString> xLabels;
	xTicks << 1 << 2 << 3 << 4;
	xLabels << "score1" << "score2" << "score3" << "scorefinal";

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
	double rangeMax = std::max({ currentDataPlotted.score1, currentDataPlotted.score2, currentDataPlotted.score3, currentDataPlotted.scorefinal }) + YAXIS_BUFFER;
	studentPlot->yAxis->setRange(0, rangeMax);
	studentPlot->yAxis->setPadding(5); // a bit more space to the left border
	studentPlot->yAxis->setLabel(QString("Student Scores for District: '%1', Grade: '%2'")
								.arg(currentDataPlotted.district)
								.arg(currentDataPlotted.grade));
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
	scoresData << currentDataPlotted.score1 << currentDataPlotted.score2 << currentDataPlotted.score3 << currentDataPlotted.scorefinal;
	scores->setData(xTicks, scoresData);

	studentPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignHCenter);

	studentPlot->replot();
}


