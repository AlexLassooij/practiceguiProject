#include "QtGuiPractice.h"
#include <iostream>
#include <QMessageBox>

// will contain functionality of app 
QtGuiPractice::QtGuiPractice(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	configSlots();
	initDb();

	setWindowTitle(QString("Qt GUI Practice"));
}

// config UI elements
void QtGuiPractice::configSlots() 
{
	ui.emailText->setPlaceholderText("Enter as <CWL@student.ubc.ca");
	ui.descriptionText->setPlaceholderText("Optional");
	connect(ui.savePushButton, &QPushButton::released, this, &QtGuiPractice::handleSave);
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

// QtGuiPractice::QtGuiPractice()
// {
//	delete ui;
//}
