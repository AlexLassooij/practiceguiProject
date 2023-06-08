#include "QtGuiPractice.h"
#include <iostream>

#include <QMessageBox>

// will contain functionality of app 
QtGuiPractice::QtGuiPractice(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	
	connect(ui.nameBox, SIGNAL(textChanged()),
			ui.emailBox, SLOT(clear()));

	ui.nameBox->setPlaceholderText("Enter your username");

	// buttons
	connect(ui.savePushButton, &QPushButton::released, this, &QtGuiPractice::handleSave);
	/*QPushButton *saveButton = new QPushButton("Save Data", this);

	saveButton->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));*/
	// this->setCentralWidget(ui.sampleTextBox);

	setWindowTitle(QString("Qt GUI Practice"));


	QSqlDatabase default_DB = QSqlDatabase::addDatabase("QSQLITE");

	QStringList dbStringList = QSqlDatabase::connectionNames();

	static const QString DEFAULT_HSS_DB_PathName = "./config_HSS.hss";

	default_DB.setDatabaseName(DEFAULT_HSS_DB_PathName);

	if (!default_DB.open()) {
		QMessageBox::warning(nullptr, tr("WARNING"), QString("Can not open !"));
	}

	QSqlQuery	query;
	QString		sql1 = "PRAGMA foreign_keys = ON;";
	// QString		sql1 = "PRAGMA foreign_keys = OFF;";
	if (!query.exec(sql1))
		QMessageBox::critical(0, QObject::tr("Error: PRAGMA foreign_keys = ON;"), query.lastError().text());

	// 1. projectInfo Table
	QString sql = "CREATE TABLE ProjectInfo ("
		"ProjectName	VARCHAR (50) PRIMARY KEY,"
		"RecorderPath	VARCHAR (100),"
		"Unit			VARCHAR (50),"
		"Version		VARCHAR (20),"
		"User			VARCHAR (50),"
		"CreatedTime	TEXT,"
		"Description	VARCHAR (100), "
		"ModelType		VARCHAR (50) "
		")";




	if (!query.exec(sql))
		QMessageBox::critical(0, QObject::tr("Error: create ProjectInfo table."), query.lastError().text());

	sql = QString("insert into ProjectInfo (ProjectName, RecorderPath, Unit, Version, User, CreatedTime, Description, ModelType) VALUES('HSS project', '', 'Metric', '%1', '', '%2', 'HSS new project', '%3')")
		.arg("1.0").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm")).arg("2D");

	if (!query.exec(sql))
		qDebug() << query.lastError().text() << endl;


	qDebug() << "test.. " << endl;



}

void QtGuiPractice::handleSave()
{
	ui.savePushButton->setText("Saved Data Successfully");
	studentDB = QSqlDatabase::addDatabase("QMYSQL");
	configStudentDB(&studentDB);
	



}


void QtGuiPractice::configStudentDB(QSqlDatabase *studentDB)
{
	studentDB->setHostName("localhost");
	studentDB->setUserName("root");
	studentDB->setPassword("");
	studentDB->setDatabaseName("studentInfo");
	std::cout << "Student DB initialized" << endl;
}

// QtGuiPractice::QtGuiPractice()
// {
//	delete ui;
//}
