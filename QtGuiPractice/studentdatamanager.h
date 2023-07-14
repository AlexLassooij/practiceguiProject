#pragma once
#include <qcustomplot.h>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileDialog>
#include <QMessageBox>
#include <QMap>

#define EDIT_COL_NUM 10
#define DEL_COL_NUM 11

class QtGuiPractice;

class StudentDataManager
{
	// widget initialized with no parents
public:
	StudentDataManager(QtGuiPractice *ui = Q_NULLPTR, QCustomPlot *studentPlot = Q_NULLPTR);
private:
	QtGuiPractice* ui;
	QCustomPlot *studentPlot;
	QString databasePath;
	QSqlDatabase StudentDb;

	int tableSize;
	int numDist;
	int numGrd;

	struct StudentDataStruct {
		int studentID;
		QString firstName, lastName, email, district, grade, year;
		double score1, score2, score3, scorefinal;
	};

	QVector<StudentDataStruct> allStudentData;
	QVector<StudentDataStruct> filteredStudentData;
	QString queryConditions;

	QVector<QString> districtList;
	QVector<QString> gradeList;
	QVector<QString> yearList;
	QVector<int> editsOutstanding;
	QVector<int> deletesOutstanding;


	StudentDataStruct currentDataPlotted;

	char* ITEM_ANY = "Any";
	double YAXIS_BUFFER = 10.0;

	void executeQuery(QSqlQuery*, QString);
	void setComboBoxes();
	void showData();

	
	QVector<StudentDataStruct> processQuery(QSqlQuery*);
	static const QVector<QString> sortingOptions;
	static const QMap<QString, QString> sortingMap;

public:
	static const QString DEFAULT_DB_PATH;
	void setBackground();
	void setDatabasePath(QString);
	void setBarGraph();
	void acquireStudentData();
	void getFilteredStudentData();
	void setQueryResultArea(QVector<StudentDataStruct>*);
	void initStudentDb(QString = DEFAULT_DB_PATH);
	void handleItemClicked(QTableWidgetItem*);
	void processEdits();
	void processDeletes();
	void processSave();
	void resetSearch();
};