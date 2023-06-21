#include "QtGuiPractice.h"


// will contain functionality of app 
QtGuiPractice::QtGuiPractice(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	configSlots();
	createActions();
	initDb();

	setWindowTitle(QString("Qt GUI Practice"));
	setUpPlotController();
}

// config UI elements
void QtGuiPractice::configSlots() 
{
	ui.emailText->setPlaceholderText("Enter as <CWL@student.ubc.ca");
	ui.descriptionText->setPlaceholderText("Optional");

}


// create actions

void QtGuiPractice::createActions()
{
	// file actions
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(actionSave_triggered()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(actionOpen_triggered()));
	connect(ui.actionExport, SIGNAL(triggered()), this, SLOT(actionExport_triggered()));
	connect(ui.actionQuit, SIGNAL(triggered()), this, SLOT(actionQuit_triggered()));

	// edit actions
	connect(ui.actionCopy, SIGNAL(triggered()), this, SLOT(actionCopy_triggered()));
	connect(ui.actionPaste, SIGNAL(triggered()), this, SLOT(actionPaste_triggered()));
	connect(ui.actionCut, SIGNAL(triggered()), this, SLOT(actionCut_triggered()));

	connect(ui.savePushButton, &QPushButton::released, this, &QtGuiPractice::handleSave);
}

void QtGuiPractice::setUpPlotController()
{
	spController = StudentPlotController(&ui, ui.studentplot);
	spController.setBackground();
	/*connect(ui.districtComboBox, currentIndexChanged(-1), this, &StudentPlotController::setBarGraph);
	connect(ui.gradeComboBox, SIGNAL(currentIndexChanged(-1)), this, SLOT(spController.setBarGraph()));*/
	//connect(ui.loadDataButton, &QPushButton::released, this, &QtGuiPractice::setBarGraph);
	connect(ui.loadDataButton, &QPushButton::released, this, &QtGuiPractice::setBarGraph);

}

void QtGuiPractice::initDb() {
	HSSDb = QSqlDatabase::addDatabase("QSQLITE");

	QStringList dbStringList = QSqlDatabase::connectionNames();

	static const QString DEFAULT_HSS_DB_PathName = "./project_records.hss";

	HSSDb.setDatabaseName(DEFAULT_HSS_DB_PathName);

	if (!HSSDb.open()) {
		QMessageBox::warning(nullptr, tr("WARNING"), QString("Can not open !"));
	}

	QSqlQuery	query;
	QString		sql1 = "PRAGMA foreign_keys = ON;";
	// QString		sql1 = "PRAGMA foreign_keys = OFF;";
	if (!query.exec(sql1))
		QMessageBox::critical(0, QObject::tr("Error: PRAGMA foreign_keys = ON;"), query.lastError().text());

	// 1. projectInfo Table, create if it does not already exist
	QString sql = "CREATE TABLE IF NOT EXISTS ProjectInfo ("
		"ProjectName	VARCHAR (50)    NOT NULL PRIMARY KEY UNIQUE,"
		"StudentName	VARCHAR (100)	NOT NULL,"
		"Email			VARCHAR (50)	NOT NULL,"
		"Version		VARCHAR (20)	NOT NULL,"
		"CreatedTime	TEXT			NOT NULL,"
		"Description	VARCHAR (100), "
		"ModelType		VARCHAR (50) "
		")";

	if (!query.exec(sql))
		QMessageBox::critical(0, QObject::tr("Error: Could not create ProjectInfo table."), query.lastError().text());

}


void QtGuiPractice::handleSave()
{
	QString projectName = ui.projectNameText->toPlainText();
	QString studentName = ui.studentNameText->toPlainText();
	QString email		= ui.emailText->toPlainText();
	QString version		= ui.versionText->toPlainText();
	QString description	= ui.descriptionText->toPlainText();

	QSqlQuery	query;

	QString sql = QString("insert into ProjectInfo (ProjectName, StudentName, Email, Version, CreatedTime, Description, ModelType)"
		"VALUES('%1', '%2', '%3', '%4', '%5', '%6', '%7')")
		.arg(projectName)
		.arg(studentName)
		.arg(email)
		.arg(version)
		.arg(QDateTime::currentDateTime()
			.toString("yyyy-MM-dd hh:mm"))
		.arg(description)
		.arg("2D");

	if (!query.exec(sql)) 
	{
		qDebug() << query.lastError().text() << endl;
	}
	else 
	{
		ui.savePushButton->setText("Saved Data Successfully");
		qDebug() << "Project info has been stored successfully" << endl;
	}
}

void QtGuiPractice::actionSave_triggered()
{
	qDebug() << "saved" << endl;

}

void QtGuiPractice::actionOpen_triggered()
{
	// create a file dialog 
	// QString fileName = QFileDialog::getOpenFileName(this, "Import Student Data", "C://", "Database file (*.db)");
	QString fileName = "C:/Users/alexl/Documents/WorkLearn/Codebase/Training/Database/practice.db";
	spController.setDatabasePath(fileName);
}

void QtGuiPractice::actionExport_triggered()
{

}

void QtGuiPractice::actionQuit_triggered()
{

}

void QtGuiPractice::actionCopy_triggered()
{
	// ui->
}

void QtGuiPractice::actionPaste_triggered()
{
	// ui->
}

void QtGuiPractice::actionCut_triggered()
{
	// ui->
}

void QtGuiPractice::setBarGraph()
{
	qDebug() << "test" << endl;
	spController.setBarGraph();
}

// QtGuiPractice::QtGuiPractice()
// {
//	delete ui;
//}
