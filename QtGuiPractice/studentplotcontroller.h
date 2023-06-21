#pragma once
#include <qcustomplot.h>
#include "ui_QtGuiPractice.h"
#include <iostream>
#include <string>
#include <algorithm>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileDialog>
#include <QMessageBox>


class StudentPlotController
{

	// widget initialized with no parents
public:
	StudentPlotController(Ui::QtGuiPracticeClass *ui = Q_NULLPTR, QCustomPlot *studentPlot = Q_NULLPTR);
private:
	Ui::QtGuiPracticeClass *ui;
	QCustomPlot *studentPlot;
	QString databasePath;
	QSqlDatabase StudentDb;

	int tableSize;
	int numDist;
	int numGrd;

	struct StudentDataStruct {
		QString district, grade;
		double pct1, pct2, pct3, pct4, pctave;
	};

	QVector<StudentDataStruct> allStudentData;
	QVector<QString> districtList;
	QVector<QString> gradeList;

	StudentDataStruct currentData;

	char* ITEM_ANY = "Any";
	double YAXIS_BUFFER = 10.0;

	void initStudentDb(QString);
	void populateStudentData();
	void executeQuery(QSqlQuery*, QString);
	void setComboBoxes();
	void showData();



public:
	void setBackground();
	void setDatabasePath(QString);
	void setBarGraph();
};