#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
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
#include "qcustomplot.h"

#define MAIN_WINDOW_WIDTH 750
#define MAIN_WINDOW_HEIGHT 800

class Ui_QtGuiPracticeUiConfigurer
{
public:
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
	QPushButton *closePushButton;

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
	void setUpUi(QMainWindow *);

private:
	void setActions(QMainWindow *);
	void setUpStudentFormLayout();
	void setUpPlotLayout();
	void setUpMenu(QMainWindow *);
	void setUiDisplayNames(QMainWindow *);

	void setActions(QMainWindow *QtGuiPracticeClass) {
	QIcon saveIcon;
	QIcon exportIcon;
	QIcon openIcon;
	QIcon quitIcon;

	saveIcon.addFile(QStringLiteral(":/Resources/Resources/icons8-save-30.png"), QSize(), QIcon::Normal, QIcon::Off);
	exportIcon.addFile(QStringLiteral(":/Resources/Resources/icons8-export-30.png"), QSize(), QIcon::Normal, QIcon::Off);
	openIcon.addFile(QStringLiteral(":/Resources/Resources/icons8-open-file-30.png"), QSize(), QIcon::Normal, QIcon::Off);
	quitIcon.addFile(QStringLiteral(":/Resources/Resources/icons8-quit-50.png"), QSize(), QIcon::Normal, QIcon::Off);

	actionSave = new QAction(QtGuiPracticeClass);
	actionSave->setObjectName(QStringLiteral("actionSave"));
	actionSave->setIcon(saveIcon);
	actionSave->setMenuRole(QAction::TextHeuristicRole);
	actionSave->setFont(mainFont);

	actionExport = new QAction(QtGuiPracticeClass);
	actionExport->setObjectName(QStringLiteral("actionExport"));
	actionExport->setIcon(exportIcon);

	actionOpen = new QAction(QtGuiPracticeClass);
	actionOpen->setObjectName(QStringLiteral("actionOpen"));
	actionOpen->setIcon(openIcon);

	actionQuit = new QAction(QtGuiPracticeClass);
	actionQuit->setObjectName(QStringLiteral("actionQuit"));
	actionQuit->setIcon(quitIcon);
	actionSave->setMenuRole(QAction::QuitRole);


	actionCopy = new QAction(QtGuiPracticeClass);
	actionCopy->setObjectName(QStringLiteral("actionCopy"));

	actionPaste = new QAction(QtGuiPracticeClass);
	actionPaste->setObjectName(QStringLiteral("actionPaste"));

	actionCut = new QAction(QtGuiPracticeClass);
	actionCut->setObjectName(QStringLiteral("actionCut"));

	actionHelp = new QAction(QtGuiPracticeClass);
	actionCut->setObjectName(QStringLiteral("actionHelp"));
	//actionSave->setMenuRole(QAction::AboutRole);
}

	void setUpStudentFormLayout()
{
	studentFormVerticalLayoutWidget = new QWidget(studentFormTab);
	studentFormVerticalLayoutWidget->setObjectName(QStringLiteral("studentFormVerticalLayoutWidget"));
	studentFormVerticalLayoutWidget->setGeometry(QRect(0, 0, MAIN_WINDOW_HEIGHT, MAIN_WINDOW_WIDTH));

	studentFormVerticalLayout = new QVBoxLayout(studentFormVerticalLayoutWidget);
	studentFormVerticalLayout->setSpacing(5);
	studentFormVerticalLayout->setObjectName(QStringLiteral("studentFormVerticalLayout"));
	studentFormVerticalLayout->setContentsMargins(10, 10, 10, 10);


	projectNameLabel = new QLabel(studentFormVerticalLayoutWidget);
	projectNameLabel->setObjectName(QStringLiteral("projectNameLabel"));
	projectNameLabel->setMaximumSize(QSize(16777215, 15));
	projectNameLabel->setFont(mainFont);


	projectNameText = new QPlainTextEdit(studentFormVerticalLayoutWidget);
	projectNameText->setObjectName(QStringLiteral("projectNameText"));
	projectNameText->setEnabled(true);
	projectNameText->setMaximumSize(QSize(400, 35));
	projectNameText->setFont(mainFont);
	projectNameText->setInputMethodHints(Qt::ImhMultiLine);


	studentNameLabel = new QLabel(studentFormVerticalLayoutWidget);
	studentNameLabel->setObjectName(QStringLiteral("studentNameLabel"));
	studentNameLabel->setMaximumSize(QSize(16777215, 15));
	studentNameLabel->setFont(mainFont);

	studentNameText = new QTextEdit(studentFormVerticalLayoutWidget);
	studentNameText->setObjectName(QStringLiteral("studentNameText"));
	studentNameText->setMaximumSize(QSize(400, 35));
	studentNameText->setFont(mainFont);


	emailLabel = new QLabel(studentFormVerticalLayoutWidget);
	emailLabel->setObjectName(QStringLiteral("emailLabel"));
	emailLabel->setMaximumSize(QSize(16777215, 15));
	emailLabel->setFont(mainFont);

	emailText = new QTextEdit(studentFormVerticalLayoutWidget);
	emailText->setObjectName(QStringLiteral("emailText"));
	emailText->setPlaceholderText("Enter as <CWL@student.ubc.ca");
	emailText->setMaximumSize(QSize(400, 35));
	emailText->setFont(mainFont);
	emailText->setInputMethodHints(Qt::ImhEmailCharactersOnly | Qt::ImhMultiLine);


	versionLabel = new QLabel(studentFormVerticalLayoutWidget);
	versionLabel->setObjectName(QStringLiteral("versionLabel"));
	versionLabel->setMaximumSize(QSize(16777215, 15));
	versionLabel->setFont(mainFont);

	versionText = new QTextEdit(studentFormVerticalLayoutWidget);
	versionText->setObjectName(QStringLiteral("versionText"));
	versionText->setMaximumSize(QSize(400, 35));
	versionText->setFont(mainFont);


	descriptionLabel = new QLabel(studentFormVerticalLayoutWidget);
	descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));
	descriptionLabel->setMaximumSize(QSize(16777215, 15));
	descriptionLabel->setFont(mainFont);

	descriptionText = new QTextEdit(studentFormVerticalLayoutWidget);
	descriptionText->setObjectName(QStringLiteral("descriptionText"));
	descriptionText->setPlaceholderText("Optional");
	descriptionText->setMaximumSize(QSize(MAIN_WINDOW_HEIGHT, 140));
	descriptionText->setFont(mainFont);


	studentFormVerticalLayout->addWidget(projectNameLabel);
	studentFormVerticalLayout->addWidget(projectNameText);

	studentFormVerticalLayout->addWidget(studentNameLabel);
	studentFormVerticalLayout->addWidget(studentNameText);

	studentFormVerticalLayout->addWidget(emailLabel);
	studentFormVerticalLayout->addWidget(emailLabel);

	studentFormVerticalLayout->addWidget(versionLabel);
	studentFormVerticalLayout->addWidget(versionText);

	studentFormVerticalLayout->addWidget(descriptionLabel);
	studentFormVerticalLayout->addWidget(descriptionText);


	studentFormHorizontalLayout = new QHBoxLayout();
	studentFormHorizontalLayout->setSpacing(5);
	studentFormHorizontalLayout->setObjectName(QStringLiteral("studentFormHorizontalLayout"));
	studentFormHorizontalLayout->setContentsMargins(-1, 5, -1, 5);

	savePushButton = new QPushButton(studentFormVerticalLayoutWidget);
	savePushButton->setObjectName(QStringLiteral("savePushButton"));
	savePushButton->setMinimumSize(QSize(0, 30));
	savePushButton->setMaximumSize(QSize(350, 40));
	savePushButton->setFont(mainFont);

	studentFormHorizontalLayout->addWidget(savePushButton);
	studentFormHorizontalLayout->setStretch(0, 1);

	studentFormVerticalLayout->addLayout(studentFormHorizontalLayout);
}

	void setUpPlotLayout()
{
	plotSettingVerticalLayoutWidget = new QWidget(plotTab);
	plotSettingVerticalLayoutWidget->setObjectName(QStringLiteral("plotSettingVerticalLayoutWidget"));
	plotSettingVerticalLayoutWidget->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, 120));

	plotSettingVerticalLayout = new QVBoxLayout(plotSettingVerticalLayoutWidget);
	plotSettingVerticalLayout->setSpacing(0);
	plotSettingVerticalLayout->setObjectName(QStringLiteral("plotSettingVerticalLayout"));
	plotSettingVerticalLayout->setContentsMargins(0, 0, 0, 0);

	settingLabelHorizontalLayout = new QHBoxLayout();
	settingLabelHorizontalLayout->setSpacing(6);
	settingLabelHorizontalLayout->setObjectName(QStringLiteral("horizontalLayout_7"));
	settingLabelHorizontalLayout->setContentsMargins(75, 0, 185, 0);

	selectDistrictLabel = new QLabel(plotSettingVerticalLayoutWidget);
	selectDistrictLabel->setObjectName(QStringLiteral("selectDistrictLabel"));

	selectGradeLabel = new QLabel(plotSettingVerticalLayoutWidget);
	selectGradeLabel->setObjectName(QStringLiteral("selectGradeLabel"));

	settingLabelHorizontalLayout->addWidget(selectDistrictLabel);
	settingLabelHorizontalLayout->addWidget(selectGradeLabel);


	comboBoxHorizontalLayout = new QHBoxLayout();
	comboBoxHorizontalLayout->setSpacing(15);
	comboBoxHorizontalLayout->setObjectName(QStringLiteral("comboBoxHorizontalLayout"));
	comboBoxHorizontalLayout->setContentsMargins(75, 0, 75, 30);

	districtComboBox = new QComboBox(plotSettingVerticalLayoutWidget);
	districtComboBox->setObjectName(QStringLiteral("districtComboBox"));

	gradeComboBox = new QComboBox(plotSettingVerticalLayoutWidget);
	gradeComboBox->setObjectName(QStringLiteral("gradeComboBox"));

	loadDataButton = new QPushButton(plotSettingVerticalLayoutWidget);
	loadDataButton->setObjectName(QStringLiteral("loadDataButton"));
	loadDataButton->setMaximumSize(QSize(100, 30));

	comboBoxHorizontalLayout->addWidget(districtComboBox);
	comboBoxHorizontalLayout->addWidget(gradeComboBox);
	comboBoxHorizontalLayout->addWidget(loadDataButton);

	comboBoxHorizontalLayout->setStretch(0, 2);
	comboBoxHorizontalLayout->setStretch(1, 2);
	comboBoxHorizontalLayout->setStretch(2, 1);

	plotSettingVerticalLayout->addLayout(settingLabelHorizontalLayout);
	plotSettingVerticalLayout->addLayout(comboBoxHorizontalLayout);
}

	void setUpMenu(QMainWindow *QtGuiPracticeClass)
{
	menuBar = new QMenuBar(QtGuiPracticeClass);
	menuBar->setObjectName(QStringLiteral("menuBar"));
	menuBar->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, 30));
	menuBar->setFont(mainFont);

	menuFile = new QMenu(menuBar);
	menuFile->setObjectName(QStringLiteral("menuFile"));
	menuFile->setFont(mainFont);

	menuEdit = new QMenu(menuBar);
	menuEdit->setObjectName(QStringLiteral("menuEdit"));
	menuEdit->setFont(mainFont);

	menuHelp = new QMenu(menuBar);
	menuHelp->setObjectName(QStringLiteral("menuHelp"));

	menuInsert = new QMenu(menuBar);
	menuInsert->setObjectName(QStringLiteral("menuInsert"));

	menuTools = new QMenu(menuBar);
	menuTools->setObjectName(QStringLiteral("menuTools"));

	QtGuiPracticeClass->setMenuBar(menuBar);
	mainToolBar = new QToolBar(QtGuiPracticeClass);
	mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
	QtGuiPracticeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

	// remove ? 
	statusBar = new QStatusBar(QtGuiPracticeClass);
	statusBar->setObjectName(QStringLiteral("statusBar"));
	QtGuiPracticeClass->setStatusBar(statusBar);

	// set order of focus change when pressing "Tab" button
	QWidget::setTabOrder(projectNameText, studentNameText);
	QWidget::setTabOrder(studentNameText, emailText);
	QWidget::setTabOrder(emailText, descriptionText);
	QWidget::setTabOrder(descriptionText, savePushButton);
	QWidget::setTabOrder(savePushButton, closePushButton);

	menuBar->addAction(menuFile->menuAction());
	menuBar->addAction(menuEdit->menuAction());
	menuBar->addAction(menuInsert->menuAction());
	menuBar->addAction(menuTools->menuAction());
	menuBar->addAction(menuHelp->menuAction());
	menuFile->addAction(actionSave);
	menuFile->addAction(actionOpen);
	menuFile->addAction(actionExport);
	menuFile->addAction(actionQuit);
	menuEdit->addAction(actionCopy);
	menuEdit->addAction(actionPaste);
	menuEdit->addAction(actionCut);
	menuHelp->addAction(actionHelp);
}

	void setUiDisplayNames(QMainWindow *QtGuiPracticeClass)
{
	QtGuiPracticeClass->setWindowTitle(QApplication::translate("QtGuiPracticeClass", "QtGuiPractice", Q_NULLPTR));
	actionSave->setText(QApplication::translate("QtGuiPracticeClass", "Save", Q_NULLPTR));
	actionExport->setText(QApplication::translate("QtGuiPracticeClass", "Export", Q_NULLPTR));
	actionOpen->setText(QApplication::translate("QtGuiPracticeClass", "Open", Q_NULLPTR));
	actionQuit->setText(QApplication::translate("QtGuiPracticeClass", "Quit", Q_NULLPTR));
	actionCopy->setText(QApplication::translate("QtGuiPracticeClass", "Copy", Q_NULLPTR));
	actionPaste->setText(QApplication::translate("QtGuiPracticeClass", "Paste", Q_NULLPTR));
	actionCut->setText(QApplication::translate("QtGuiPracticeClass", "Cut", Q_NULLPTR));


	actionSave->setShortcut(QApplication::translate("QtGuiPracticeClass", "Ctrl+S", Q_NULLPTR));
	actionExport->setShortcut(QApplication::translate("QtGuiPracticeClass", "Ctrl+Shift+E", Q_NULLPTR));
	actionOpen->setShortcut(QApplication::translate("QtGuiPracticeClass", "Ctrl+O", Q_NULLPTR));

	// form labels 
	projectNameLabel->setText(QApplication::translate("QtGuiPracticeClass", "Project Name", Q_NULLPTR));
	studentNameLabel->setText(QApplication::translate("QtGuiPracticeClass", "Student Name", Q_NULLPTR));
	emailLabel->setText(QApplication::translate("QtGuiPracticeClass", "Email", Q_NULLPTR));
	versionLabel->setText(QApplication::translate("QtGuiPracticeClass", "Version", Q_NULLPTR));
	descriptionLabel->setText(QApplication::translate("QtGuiPracticeClass", "Description", Q_NULLPTR));

	savePushButton->setText(QApplication::translate("QtGuiPracticeClass", "Save Data", Q_NULLPTR));
	closePushButton->setText(QApplication::translate("QtGuiPracticeClass", "Close", Q_NULLPTR));
	tabWidget->setTabText(tabWidget->indexOf(studentFormTab), QApplication::translate("QtGuiPracticeClass", "Student Project Form", Q_NULLPTR));
	selectDistrictLabel->setText(QApplication::translate("QtGuiPracticeClass", "Select District", Q_NULLPTR));
	selectGradeLabel->setText(QApplication::translate("QtGuiPracticeClass", "Select Grade", Q_NULLPTR));
	loadDataButton->setText(QApplication::translate("QtGuiPracticeClass", "Load Data", Q_NULLPTR));

	tabWidget->setTabText(tabWidget->indexOf(plotTab), QApplication::translate("QtGuiPracticeClass", "Plot", Q_NULLPTR));
	menuFile->setTitle(QApplication::translate("QtGuiPracticeClass", "File", Q_NULLPTR));
	menuEdit->setTitle(QApplication::translate("QtGuiPracticeClass", "Edit", Q_NULLPTR));
	menuHelp->setTitle(QApplication::translate("QtGuiPracticeClass", "Help", Q_NULLPTR));
	menuInsert->setTitle(QApplication::translate("QtGuiPracticeClass", "Insert", Q_NULLPTR));
	menuTools->setTitle(QApplication::translate("QtGuiPracticeClass", "Tools", Q_NULLPTR));
} // retranslateUi

	void setUpUi(QMainWindow *QtGuiPracticeClass)
{
	if (QtGuiPracticeClass->objectName().isEmpty())
		QtGuiPracticeClass->setObjectName(QStringLiteral("QtGuiPracticeClass"));
	// set size of the main window 
	QtGuiPracticeClass->resize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
	QtGuiPracticeClass->setCursor(QCursor(Qt::OpenHandCursor));

	// define main font 
	mainFont.setFamily(QStringLiteral("Segoe UI Semibold"));
	mainFont.setBold(true);
	mainFont.setWeight(75);

	// configure central widget
	centralWidget = new QWidget(QtGuiPracticeClass);
	centralWidget->setObjectName(QStringLiteral("centralWidget"));

	setActions(QtGuiPracticeClass);

	// configure tab widget that will contain student and plot tab 
	tabWidget = new QTabWidget(centralWidget);
	tabWidget->setObjectName(QStringLiteral("tabWidget"));
	tabWidget->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
	tabWidget->setMinimumSize(QSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
	tabWidget->setMaximumSize(QSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
	tabWidget->setFont(mainFont);

	// configure student form tab
	studentFormTab = new QWidget();
	studentFormTab->setObjectName(QStringLiteral("studentFormTab"));
	setUpStudentFormLayout();
	tabWidget->addTab(studentFormTab, QString());

	// configure plot tab
	plotTab = new QWidget();
	plotTab->setObjectName(QStringLiteral("plotTab"));
	studentplot = new QCustomPlot(plotTab);
	studentplot->setObjectName(QStringLiteral("studentplot"));
	studentplot->setGeometry(QRect(0, 120, MAIN_WINDOW_WIDTH, 575));
	setUpPlotLayout();

	tabWidget->addTab(plotTab, QString());

	// remove ? 
	QtGuiPracticeClass->setCentralWidget(centralWidget);

	setUpMenu(QtGuiPracticeClass);
	setUiDisplayNames(QtGuiPracticeClass);

	// start on student form tab
	tabWidget->setCurrentIndex(1);


	QMetaObject::connectSlotsByName(QtGuiPracticeClass);
} // setupUi

};

//namespace UiConfig {
//	class QtGuiPracticeUiConfigurer: public Ui_QtGuiPracticeUiConfigurer {};
//}


