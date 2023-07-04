#pragma once

// provide main window widget
#include <QtWidgets/QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

// sql
#include <QtSql>
#include <QSqlDatabase>

// qcustomplot
#include "qcustomplot.h"

#include "studentplotcontroller.h"
#include <iostream>


#define MAIN_WINDOW_WIDTH 750
#define MAIN_WINDOW_HEIGHT 800

class QtGuiPractice : public QMainWindow
{
	// special Qt Mac
    Q_OBJECT

// widget initialized with no parents
public:
    QtGuiPractice(QWidget *parent = Q_NULLPTR);

	// ui elements 

	// high level objects
	QWidget *centralWidget;
	QFont mainFont;
	QTabWidget *tabWidget;

	// menu bar widgets 
	QMenuBar *menuBar;

	// submenus and their corresponding actions 
	QMenu *menuFile;
	QAction *actionSave;
	QAction *actionExport;
	QAction *actionOpen;
	QAction *actionQuit;

	QMenu *menuEdit;
	QAction *actionCopy;
	QAction *actionPaste;
	QAction *actionCut;

	QMenu *menuHelp;
	QAction *actionHelp;
	QMenu *menuInsert;
	QMenu *menuTools;

	// toolbar contains the menubar 
	QToolBar *mainToolBar;

	// all widgets under student tab 
	QWidget *studentFormTab;

	// layout widgets for student tab
	QWidget *studentFormVerticalLayoutWidget;
	QVBoxLayout *studentFormVerticalLayout;
	QHBoxLayout *studentFormHorizontalLayout;


	// student form widgets
	QLabel *projectNameLabel;
	QPlainTextEdit *projectNameText;
	QLabel *studentNameLabel;
	QTextEdit *studentNameText;
	QLabel *emailLabel;
	QTextEdit *emailText;
	QLabel *versionLabel;
	QTextEdit *versionText;
	QLabel *descriptionLabel;
	QTextEdit *descriptionText;


	// student form buttons
	QPushButton *savePushButton;

	// all widgets under plot tab
	QWidget *plotTab;

	// plot widgets 
	QCustomPlot *studentplot;
	QLabel *selectDistrictLabel;
	QLabel *selectGradeLabel;
	QComboBox *districtComboBox;
	QComboBox *gradeComboBox;
	QPushButton *loadDataButton;

	// layout widgets for plot tab

	QWidget *plotSettingVerticalLayoutWidget;
	QVBoxLayout *plotSettingVerticalLayout;
	QHBoxLayout *comboBoxHorizontalLayout;

	QHBoxLayout *settingLabelHorizontalLayout;

	// can probably remove this
	QStatusBar *statusBar;

	// ui configuration functions 

	// main ui set up function
	void setUpUi();

private:

	// ui set up methods 
	void setActions();
	void setUpStudentFormLayout();
	void setUpPlotLayout();
	void setUpMenu();
	void setUiDisplayNames();
	void setActionHandling();

	// ui controlling methods
	void setUpPlotController();
	void initDb();
	void saveStudentData();
	void setBarGraph();

	// non-ui elements
	QSqlDatabase HSSDb;
	StudentPlotController plotController;

	

private slots:
	void actionOpen_triggered();
	void actionExport_triggered();
	void actionSave_triggered();
	void actionQuit_triggered();
	void actionCopy_triggered();
	void actionPaste_triggered();
	void actionCut_triggered();
};
