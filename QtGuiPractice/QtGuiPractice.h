#pragma once

// provide main window widget
#include <QtWidgets/QMainWindow>
#include "ui_QtGuiPractice.h"
#include "studentplotcontroller.h"
#include <iostream>




#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileDialog>
#include <QMessageBox>

class QtGuiPractice : public QMainWindow
{
	// special Qt Mac
    Q_OBJECT

// widget initialized with no parents
public:
    QtGuiPractice(QWidget *parent = Q_NULLPTR);
	// ui form, included in .pro file 
private:
    Ui::QtGuiPracticeClass ui;
	QSqlDatabase HSSDb;
	/*QTextEdit *projectNameText;
	QTextEdit *studentNameText;
	QTextEdit *versionText;
	QTextEdit *emailText;
	QTextEdit *modelTypeText;
	QTextEdit *descriptionText;*/

	StudentPlotController spController;

	void configSlots();
	void createActions();
	void handleSave();
	void setUpPlotController();
	void initDb();
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
