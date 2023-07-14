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
#include <iostream>
#include <map>
#include<string>

// sql
#include <QtSql>
#include <QSqlDatabase>

// qcustomplot
#include "qcustomplot.h"

#include "studentdatamanager.h"
#include <iostream>


#define MAIN_WINDOW_WIDTH 1150
#define MAIN_WINDOW_HEIGHT 900
#define TAB_WIDGET_HEIGHT 650




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
	QFont *headerFont;
	QFont *bodyFont;
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
	QWidget *addStudentTab;

	// layout widgets for student tab
	QWidget *addStudentGridLayoutWidget;
	QGridLayout *addStudentGridLayout;


	// student form widgets
	QLabel *addStudentTitleLabel;

	QLabel *addStudentFirstNameLabel;
	QTextEdit *addStudentFirstNameText;

	QLabel *addStudentLastNameLabel;
	QTextEdit *addStudentLastNameText;

	QLabel *addStudentEmailLabel;
	QTextEdit *addStudentEmailText;

	QLabel *addStudentDistrictLabel;
	QComboBox *addStudentDistrictComboBox;

	QLabel *addStudentGradeLabel;
	QComboBox *addStudentGradeComboBox;

	QLabel *addStudentYearLabel;
	QComboBox *addStudentYearComboBox;

	QLabel *addStudentScore1Label;
	QTextEdit *addStudentScore1Text;

	QLabel *addStudentScore2Label;
	QTextEdit *addStudentScore2Text;

	QLabel *addStudentScore3Label;
	QTextEdit *addStudentScore3Text;

	QLabel *addStudentScoreFLabel;
	QTextEdit *addStudentScoreFText;

	QPushButton *saveStudentPushButton;
	


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

	QWidget *searchTab;

	QTableWidget *searchResultsTable;
	QStringList *tableFields;

	QWidget *queryVerticalLayoutWidget;
	QVBoxLayout *queryVerticalLayout;

	QWidget *searchSelectionGridLayoutWidget;
	QGridLayout *searchSelectionGridLayout;

	QLabel *searchTitleLabel;
	QLabel *searchNameLabel;
	QTextEdit *searchNameText;

	QLabel *searchScoreLabel;
	QTextEdit *searchScoreText;

	QGroupBox *searchScoreGroupBox;
	QHBoxLayout *searchScoreHBox;
	QRadioButton *searchScoreGreater;
	QRadioButton *searchScoreLess;

	QLabel *searchDistrictLabel;
	QComboBox *searchDistrictComboBox;

	QLabel *searchGradeLabel;
	QComboBox *searchGradeComboBox;

	QLabel *searchYearLabel;
	QComboBox *searchYearComboBox;

	QLabel *searchSortByLabel;
	QComboBox *searchSortByComboBox;

	QGroupBox *searchSortMethodGroupBox;
	QHBoxLayout *searchSortMethodHBox;
	QRadioButton *searchSortMethodAsc;
	QRadioButton *searchSortMethodDesc;

	QPushButton *searchPushButton;

	QPushButton *applyDeleteButton;
	QPushButton *applyEditButton;
	QPushButton *resetSearchButton;


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
	void setUpSearchLayout();
	void setUpMenu();
	void setActionHandling();

	// ui controlling methods
	void setUpStudentDataManager();
	void setBarGraph();

	// non-ui elements
	QSqlDatabase HSSDb;
	StudentDataManager studentDataManager;
	

private slots:
	void actionOpen_triggered();
	void actionExport_triggered();
	void actionSave_triggered();
	void actionQuit_triggered();
	void actionCopy_triggered();
	void actionPaste_triggered();
	void actionCut_triggered();
};
