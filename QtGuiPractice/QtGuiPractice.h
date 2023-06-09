#pragma once

// provide main window widget
#include <QtWidgets/QMainWindow>
#include "ui_QtGuiPractice.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QtSql>
#include <QSqlDatabase>

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
	QString currentFile = "";
	QSqlDatabase HSSDb;
	QTextEdit *projectNameText;
	QTextEdit *studentNameText;
	QTextEdit *versionText;
	QTextEdit *emailText;
	QTextEdit *modelTypeText;
	QTextEdit *descriptionText;
	


private slots:
	void configSlots();
	void handleSave();
	void initDb();

};
