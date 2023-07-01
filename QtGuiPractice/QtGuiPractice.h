#pragma once

// provide main window widget
#include <QtWidgets/QMainWindow>
#include "QtGuiPracticeUiConfigurer.h"
#include "studentplotcontroller.h"
#include <iostream>




#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileDialog>
#include <QMessageBox>

#define MAIN_WINDOW_WIDTH 750
#define MAIN_WINDOW_HEIGHT 800


class QtGuiPractice : public QMainWindow
{
	// special Qt Mac
    Q_OBJECT

// widget initialized with no parents
public:
    QtGuiPractice(QWidget *parent = Q_NULLPTR);
	// ui form, included in .pro file 
private:
	Ui_QtGuiPracticeUiConfigurer ui;
	QSqlDatabase HSSDb;
	StudentPlotController spController;

	void setActionHandling();
	void setUpPlotController();
	void initDb();
	void saveStudentData();
	void setBarGraph();

private slots:
	void actionOpen_triggered();
	void actionExport_triggered();
	void actionSave_triggered();
	void actionQuit_triggered();
	void actionCopy_triggered();
	void actionPaste_triggered();
	void actionCut_triggered();
};
