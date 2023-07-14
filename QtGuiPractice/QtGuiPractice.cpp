#include "QtGuiPractice.h"


// will contain functionality of app 
QtGuiPractice::QtGuiPractice(QWidget *parent) : QMainWindow(parent)
{
	// ui = new QtGuiPracticeUiConfigurer();
	setUpUi();
	setWindowTitle(QString("Qt GUI Practice 20230622"));
	setUpStudentDataManager();

}


// configure how actions are handled
void QtGuiPractice::setActionHandling()
{
	// file actions
	QObject::connect(actionSave, SIGNAL(triggered()), this, SLOT(actionSave_triggered()));
	QObject::connect(actionOpen, SIGNAL(triggered()), this, SLOT(actionOpen_triggered()));
	QObject::connect(actionExport, SIGNAL(triggered()), this, SLOT(actionExport_triggered()));
	QObject::connect(actionQuit, SIGNAL(triggered()), this, SLOT(actionQuit_triggered()));

	// edit actions
	QObject::connect(actionCopy, SIGNAL(triggered()), this, SLOT(actionCopy_triggered()));
	QObject::connect(actionPaste, SIGNAL(triggered()), this, SLOT(actionPaste_triggered()));
	QObject::connect(actionCut, SIGNAL(triggered()), this, SLOT(actionCut_triggered()));
}

void QtGuiPractice::setActions() {
	QIcon saveIcon;
	QIcon exportIcon;
	QIcon openIcon;
	QIcon quitIcon;

	saveIcon.addFile(QStringLiteral(":/Resources/Resources/icons8-save-30.png"), QSize(), QIcon::Normal, QIcon::Off);
	exportIcon.addFile(QStringLiteral(":/Resources/Resources/icons8-export-30.png"), QSize(), QIcon::Normal, QIcon::Off);
	openIcon.addFile(QStringLiteral(":/Resources/Resources/icons8-open-file-30.png"), QSize(), QIcon::Normal, QIcon::Off);
	quitIcon.addFile(QStringLiteral(":/Resources/Resources/icons8-quit-50.png"), QSize(), QIcon::Normal, QIcon::Off);

	actionSave = new QAction(this);
	actionSave->setIcon(saveIcon);
	actionSave->setMenuRole(QAction::TextHeuristicRole);
	actionSave->setText("Save");

	actionExport = new QAction(this);
	actionExport->setIcon(exportIcon);
	actionExport->setText("Export");

	actionOpen = new QAction(this);
	actionOpen->setIcon(openIcon);
	actionOpen->setText("Open");

	actionQuit = new QAction(this);
	actionQuit->setIcon(quitIcon);
	actionQuit->setMenuRole(QAction::QuitRole);
	actionQuit->setText("Quit");

	actionCopy = new QAction(this);
	actionCopy->setText("Copy");

	actionPaste = new QAction(this);
	actionPaste->setText("Paste");

	actionCut = new QAction(this);
	actionCut->setText("Cut");

	actionHelp = new QAction(this);
	actionHelp->setText("Help");
}

void QtGuiPractice::setUpStudentFormLayout()
{

	addStudentGridLayoutWidget = new QWidget(addStudentTab);
	addStudentGridLayoutWidget->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT*0.7));

	addStudentGridLayout = new QGridLayout(addStudentGridLayoutWidget);
	addStudentGridLayout->setSpacing(10);
	addStudentGridLayout->setContentsMargins(50, 10, 50, 10);


	addStudentTitleLabel = new QLabel(addStudentGridLayoutWidget);
	addStudentTitleLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 40));
	addStudentTitleLabel->setText("Add New Student");
	addStudentTitleLabel->setFont(*headerFont);
	addStudentTitleLabel->setEnabled(false);


	addStudentFirstNameLabel = new QLabel(addStudentGridLayoutWidget);
	addStudentFirstNameLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	addStudentFirstNameLabel->setText("First Name");

	addStudentFirstNameText = new QTextEdit(addStudentGridLayoutWidget);
	addStudentFirstNameText->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 35));


	addStudentLastNameLabel = new QLabel(addStudentGridLayoutWidget);
	addStudentLastNameLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	addStudentLastNameLabel->setText("Last Name");

	addStudentLastNameText = new QTextEdit(addStudentGridLayoutWidget);
	addStudentLastNameText->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 35));


	addStudentEmailLabel = new QLabel(addStudentGridLayoutWidget);
	addStudentEmailLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	addStudentEmailLabel->setText("Email");

	addStudentEmailText = new QTextEdit(addStudentGridLayoutWidget);
	addStudentEmailText->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 35));
	addStudentEmailText->setPlaceholderText("<CWL>@student.ubc.ca");


	addStudentDistrictLabel = new QLabel(addStudentGridLayoutWidget);
	addStudentDistrictLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	addStudentDistrictLabel->setText("District");

	addStudentDistrictComboBox = new QComboBox(searchSelectionGridLayoutWidget);
	addStudentDistrictComboBox->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 35));


	addStudentGradeLabel = new QLabel(addStudentGridLayoutWidget);
	addStudentGradeLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	addStudentGradeLabel->setText("Grade");

	addStudentGradeComboBox = new QComboBox(searchSelectionGridLayoutWidget);
	addStudentGradeComboBox->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 35));


	addStudentYearLabel = new QLabel(addStudentGridLayoutWidget);
	addStudentYearLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	addStudentYearLabel->setText("Year");

	addStudentYearComboBox = new QComboBox(searchSelectionGridLayoutWidget);
	addStudentYearComboBox->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 35));


	addStudentScore1Label = new QLabel(addStudentGridLayoutWidget);
	addStudentScore1Label->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	addStudentScore1Label->setText("Score Quiz 1");

	addStudentScore1Text = new QTextEdit(addStudentGridLayoutWidget);
	addStudentScore1Text->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 35));


	addStudentScore2Label = new QLabel(addStudentGridLayoutWidget);
	addStudentScore2Label->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	addStudentScore2Label->setText("Score Quiz 2");

	addStudentScore2Text = new QTextEdit(addStudentGridLayoutWidget);
	addStudentScore2Text->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 35));


	addStudentScore3Label = new QLabel(addStudentGridLayoutWidget);
	addStudentScore3Label->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	addStudentScore3Label->setText("Score Quiz 3");

	addStudentScore3Text = new QTextEdit(addStudentGridLayoutWidget);
	addStudentScore3Text->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 35));


	addStudentScoreFLabel = new QLabel(addStudentGridLayoutWidget);
	addStudentScoreFLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	addStudentScoreFLabel->setText("Score Quiz Final");

	addStudentScoreFText = new QTextEdit(addStudentGridLayoutWidget);
	addStudentScoreFText->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 35));

	saveStudentPushButton = new QPushButton("Save New Student", addStudentGridLayoutWidget);

	addStudentGridLayout->addWidget(addStudentTitleLabel, 0, 0, 1, 3);
	addStudentGridLayout->addWidget(addStudentFirstNameLabel, 1, 0, 1, 1);
	addStudentGridLayout->addWidget(addStudentFirstNameText, 2, 0, 1, 1);

	addStudentGridLayout->addWidget(addStudentLastNameLabel, 1, 1, 1, 1);
	addStudentGridLayout->addWidget(addStudentLastNameText, 2, 1, 1, 1);

	addStudentGridLayout->addWidget(addStudentEmailLabel, 1, 2, 1, 1);
	addStudentGridLayout->addWidget(addStudentEmailText, 2, 2, 1, 1);

	addStudentGridLayout->addWidget(addStudentDistrictLabel, 3, 0, 1, 1);
	addStudentGridLayout->addWidget(addStudentDistrictComboBox, 4, 0, 1, 1);

	addStudentGridLayout->addWidget(addStudentGradeLabel, 3, 1, 1, 1);
	addStudentGridLayout->addWidget(addStudentGradeComboBox, 4, 1, 1, 1);

	addStudentGridLayout->addWidget(addStudentYearLabel, 3, 2, 1, 1);
	addStudentGridLayout->addWidget(addStudentYearComboBox, 4, 2, 1, 1);

	addStudentGridLayout->addWidget(addStudentScore1Label, 5, 0, 1, 1);
	addStudentGridLayout->addWidget(addStudentScore1Text, 6, 0, 1, 1);

	addStudentGridLayout->addWidget(addStudentScore2Label, 5, 1, 1, 1);
	addStudentGridLayout->addWidget(addStudentScore2Text, 6, 1, 1, 1);

	addStudentGridLayout->addWidget(addStudentScore3Label, 5, 2, 1, 1);
	addStudentGridLayout->addWidget(addStudentScore3Text, 6, 2, 1, 1);

	addStudentGridLayout->addWidget(addStudentScoreFLabel, 5, 3, 1, 1);
	addStudentGridLayout->addWidget(addStudentScoreFText, 6, 3, 1, 1);

	addStudentGridLayout->addWidget(saveStudentPushButton, 7, 0, 1, 1);
}

void QtGuiPractice::setUpPlotLayout()
{
	plotSettingVerticalLayoutWidget = new QWidget(plotTab);
	plotSettingVerticalLayoutWidget->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, 120));

	plotSettingVerticalLayout = new QVBoxLayout(plotSettingVerticalLayoutWidget);
	plotSettingVerticalLayout->setSpacing(0);

	settingLabelHorizontalLayout = new QHBoxLayout();
	settingLabelHorizontalLayout->setSpacing(6);
	settingLabelHorizontalLayout->setContentsMargins(75, 0, 185, 0);

	selectDistrictLabel = new QLabel(plotSettingVerticalLayoutWidget);
	selectDistrictLabel->setText("District");

	selectGradeLabel = new QLabel(plotSettingVerticalLayoutWidget);
	selectGradeLabel->setText("Grade");

	settingLabelHorizontalLayout->addWidget(selectDistrictLabel);
	settingLabelHorizontalLayout->addWidget(selectGradeLabel);


	comboBoxHorizontalLayout = new QHBoxLayout();
	comboBoxHorizontalLayout->setSpacing(15);
	comboBoxHorizontalLayout->setContentsMargins(75, 0, 75, 30);

	districtComboBox = new QComboBox(plotSettingVerticalLayoutWidget);

	gradeComboBox = new QComboBox(plotSettingVerticalLayoutWidget);

	loadDataButton = new QPushButton(plotSettingVerticalLayoutWidget);
	loadDataButton->setMaximumSize(QSize(100, 30));
	loadDataButton->setText("Load Data");

	comboBoxHorizontalLayout->addWidget(districtComboBox);
	comboBoxHorizontalLayout->addWidget(gradeComboBox);
	comboBoxHorizontalLayout->addWidget(loadDataButton);

	comboBoxHorizontalLayout->setStretch(0, 2);
	comboBoxHorizontalLayout->setStretch(1, 2);
	comboBoxHorizontalLayout->setStretch(2, 1);

	plotSettingVerticalLayout->addLayout(settingLabelHorizontalLayout);
	plotSettingVerticalLayout->addLayout(comboBoxHorizontalLayout);

	studentplot = new QCustomPlot(plotTab);
	studentplot->setGeometry(QRect(MAIN_WINDOW_WIDTH*0.1, 120, MAIN_WINDOW_WIDTH*0.8, 500));
}

void QtGuiPractice::setUpSearchLayout() 
{
	searchSelectionGridLayoutWidget = new QWidget(searchTab);
	searchSelectionGridLayoutWidget->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT*0.85));

	searchSelectionGridLayout = new QGridLayout(searchSelectionGridLayoutWidget);
	searchSelectionGridLayout->setSpacing(10);
	searchSelectionGridLayout->setContentsMargins(50, 10, 50, 10);


	searchTitleLabel = new QLabel(searchSelectionGridLayoutWidget);
	searchTitleLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 40));
	searchTitleLabel->setText("Search and Edit Students");
	searchTitleLabel->setFont(*headerFont);
	searchTitleLabel->setEnabled(false);


	searchNameLabel = new QLabel(searchSelectionGridLayoutWidget);
	searchNameLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	searchNameLabel->setText("Student Name");

	searchNameText = new QTextEdit(searchSelectionGridLayoutWidget);
	searchNameText->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 35));


	searchScoreLabel = new QLabel(searchSelectionGridLayoutWidget);
	searchScoreLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	searchScoreLabel->setText("Student Score");


	searchScoreText = new QTextEdit(searchSelectionGridLayoutWidget);
	searchScoreText->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 5, 35));
	searchScoreText->setPlaceholderText(QString("0.0 - 100.0"));

	searchScoreGroupBox = new QGroupBox();
	searchScoreGreater = new QRadioButton("Greater");
	searchScoreLess = new QRadioButton("Less");
	searchScoreGreater->setChecked(true);

	searchScoreHBox = new QHBoxLayout();
	searchScoreHBox->addWidget(searchScoreGreater);
	searchScoreHBox->addWidget(searchScoreLess);
	searchScoreGroupBox->setLayout(searchScoreHBox);

	searchGradeLabel = new QLabel(searchSelectionGridLayoutWidget);
	searchGradeLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	searchGradeLabel->setText("Grade");

	searchGradeComboBox = new QComboBox(searchSelectionGridLayoutWidget);

	searchDistrictLabel = new QLabel(searchSelectionGridLayoutWidget);
	searchDistrictLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	searchDistrictLabel->setText("District");

	searchDistrictComboBox = new QComboBox(searchSelectionGridLayoutWidget);

	searchYearLabel = new QLabel(searchSelectionGridLayoutWidget);
	searchYearLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	searchYearLabel->setText("Year");

	searchYearComboBox = new QComboBox(searchSelectionGridLayoutWidget);

	searchSortByLabel = new QLabel(searchSelectionGridLayoutWidget);
	searchSortByLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	searchSortByLabel->setText("Sort By");

	searchSortMethodGroupBox = new QGroupBox();
	searchSortMethodAsc = new QRadioButton("ASC");
	searchSortMethodDesc = new QRadioButton("DESC");
	searchSortMethodAsc->setChecked(true);

	searchSortMethodHBox = new QHBoxLayout();
	searchSortMethodHBox->addWidget(searchSortMethodAsc);
	searchSortMethodHBox->addWidget(searchSortMethodDesc);
	searchSortMethodGroupBox->setLayout(searchSortMethodHBox);


	searchSortByComboBox = new QComboBox(searchSelectionGridLayoutWidget);

	searchPushButton = new QPushButton("Search", searchSelectionGridLayoutWidget);

	searchResultsTable = new QTableWidget(searchSelectionGridLayoutWidget);
	searchResultsTable->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
	tableFields = new QStringList({ "ID", "Name", "Email", "District", "Grade", "Year", "S1", "S2", "S3", "SF", "Edit", "Delete" });
	searchResultsTable->setColumnCount(tableFields->size());
	searchResultsTable->setHorizontalHeaderLabels(*tableFields);
	searchResultsTable->horizontalHeader()->setVisible(true);
	searchResultsTable->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
	searchResultsTable->setSelectionMode(QAbstractItemView::SingleSelection);
	searchResultsTable->horizontalHeader()->setSelectionMode(QAbstractItemView::NoSelection);

	searchResultsTable->setColumnWidth(0, 60);
	searchResultsTable->setColumnWidth(1, 150);
	searchResultsTable->setColumnWidth(2, 200);
	searchResultsTable->setColumnWidth(3, 80);
	searchResultsTable->setColumnWidth(4, 70);
	searchResultsTable->setColumnWidth(5, 70);
	searchResultsTable->setColumnWidth(6, 50);
	searchResultsTable->setColumnWidth(7, 50);
	searchResultsTable->setColumnWidth(8, 50);
	searchResultsTable->setColumnWidth(9, 50);
	searchResultsTable->setColumnWidth(10, 60);
	searchResultsTable->setColumnWidth(11, 60);

	applyEditButton = new QPushButton("Apply Edits", searchSelectionGridLayoutWidget);
	applyDeleteButton = new QPushButton("Apply Deletes", searchSelectionGridLayoutWidget);
	resetSearchButton = new QPushButton("Reset", searchSelectionGridLayoutWidget);

	searchSelectionGridLayout->addWidget(searchTitleLabel, 0, 0, 1, 3);
	searchSelectionGridLayout->addWidget(searchNameLabel, 1, 0, 1, 2);
	searchSelectionGridLayout->addWidget(searchNameText, 2, 0, 1, 2);

	searchSelectionGridLayout->addWidget(searchScoreLabel, 1, 2, 1, 1);
	searchSelectionGridLayout->addWidget(searchScoreText, 2, 2, 1, 1);
	searchSelectionGridLayout->addWidget(searchScoreGroupBox, 2, 3, 1, 1);

	
	searchSelectionGridLayout->addWidget(searchDistrictLabel, 3, 0, 1, 1);
	searchSelectionGridLayout->addWidget(searchDistrictComboBox, 4, 0, 1, 1);

	searchSelectionGridLayout->addWidget(searchGradeLabel, 3, 1, 1, 1);
	searchSelectionGridLayout->addWidget(searchGradeComboBox, 4, 1, 1, 1);

	searchSelectionGridLayout->addWidget(searchYearLabel, 3, 2, 1, 1);
	searchSelectionGridLayout->addWidget(searchYearComboBox, 4, 2, 1, 1);

	searchSelectionGridLayout->addWidget(searchSortByLabel, 3, 3, 1, 1);
	searchSelectionGridLayout->addWidget(searchSortByComboBox, 4, 3, 1, 1);
	searchSelectionGridLayout->addWidget(searchSortMethodGroupBox, 4, 4, 1, 1);

	searchSelectionGridLayout->addWidget(searchPushButton, 5, 0, 1, 1);

	searchSelectionGridLayout->addWidget(searchResultsTable, 6, 0, 4, 5);

	searchSelectionGridLayout->addWidget(applyEditButton, 10, 0, 1, 1);
	searchSelectionGridLayout->addWidget(applyDeleteButton, 10, 1, 1, 1);
	searchSelectionGridLayout->addWidget(resetSearchButton, 10, 2, 1, 1);
}

void QtGuiPractice::setUpMenu()
{
	menuBar = new QMenuBar(this);
	menuBar->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, 30));
	menuBar->setFont(*bodyFont);

	menuFile = new QMenu(menuBar);
	menuFile->setTitle("File");

	menuEdit = new QMenu(menuBar);
	menuEdit->setTitle("Edit");

	menuHelp = new QMenu(menuBar);
	menuHelp->setTitle("Help");

	menuInsert = new QMenu(menuBar);
	menuInsert->setTitle("Insert");

	menuTools = new QMenu(menuBar);
	menuTools->setTitle("Tools");


	this->setMenuBar(menuBar);
	mainToolBar = new QToolBar(this);
	this->addToolBar(Qt::TopToolBarArea, mainToolBar);

	// remove ? 
	statusBar = new QStatusBar(this);
	this->setStatusBar(statusBar);

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

void QtGuiPractice::setUpUi()
{
	if (this->objectName().isEmpty())
	// set size of the main window 
	this->resize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
	// this->setCursor(QCursor(Qt::OpenHandCursor));

	// define fonts
	headerFont = new QFont("Segoe UI Semibold", 12);
	bodyFont = new QFont("Segoe UI Semibold", 8, QFont::Bold);

	// configure central widget
	centralWidget = new QWidget(this);
	

	// configure tab widget that will contain student and plot tab 
	tabWidget = new QTabWidget(centralWidget);
	tabWidget->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
	tabWidget->setFont(*bodyFont);

	// configure query tab
	searchTab = new QWidget();
	setUpSearchLayout();
	tabWidget->addTab(searchTab, QString());

	// configure student form tab
	addStudentTab = new QWidget();
	setUpStudentFormLayout();
	tabWidget->addTab(addStudentTab, QString());

	// configure plot tab
	plotTab = new QWidget();
	
	setUpPlotLayout();
	tabWidget->addTab(plotTab, QString());

	this->setCentralWidget(centralWidget);
	setActions();
	setActionHandling();
	setUpMenu();

	// start on student form tab
	tabWidget->setCurrentIndex(0);

	tabWidget->setTabText(tabWidget->indexOf(addStudentTab), "Add New Student");
	tabWidget->setTabText(tabWidget->indexOf(searchTab), "Search");
	tabWidget->setTabText(tabWidget->indexOf(plotTab), "Plot");

	QMetaObject::connectSlotsByName(this);
} // setupUi


void QtGuiPractice::setUpStudentDataManager()
{
	studentDataManager = StudentDataManager(this, studentplot);
	studentDataManager.setBackground();
	studentDataManager.initStudentDb();
	studentDataManager.acquireStudentData();
		

	QObject::connect(loadDataButton, &QPushButton::clicked, [=]() {
		studentDataManager.setBarGraph();
	});

	QObject::connect(searchResultsTable, &QTableWidget::itemClicked, [=](QTableWidgetItem* item) {
		studentDataManager.handleItemClicked(item);
	});

	QObject::connect(searchPushButton, &QPushButton::clicked, [=]() {
		studentDataManager.getFilteredStudentData();
	});

	QObject::connect(applyEditButton, &QPushButton::clicked, [=]() {
		studentDataManager.processEdits();
	});

	QObject::connect(applyDeleteButton, &QPushButton::clicked, [=]() {
		studentDataManager.processDeletes();
	});

	QObject::connect(resetSearchButton, &QPushButton::clicked, [=]() {
		studentDataManager.resetSearch();
	});

	QObject::connect(saveStudentPushButton, &QPushButton::clicked, [=]() {
		studentDataManager.processSave();
	});
}

void QtGuiPractice::actionSave_triggered()
{
	qDebug() << "saved" << endl;

}

void QtGuiPractice::actionOpen_triggered()
{
	// create a file dialog 
	QString fileName = QFileDialog::getOpenFileName(this, "Import Student Data", "C://", "Database file (*.db)");
	// QString fileName = "C:/Users/alexl/Documents/WorkLearn/Codebase/Training/Database/practice.db";
	studentDataManager.setDatabasePath(fileName);
}

void QtGuiPractice::actionExport_triggered()
{

}

void QtGuiPractice::actionQuit_triggered()
{

}

void QtGuiPractice::actionCopy_triggered()
{
	// 
}

void QtGuiPractice::actionPaste_triggered()
{
	// 
}

void QtGuiPractice::actionCut_triggered()
{
	// 
}

void QtGuiPractice::setBarGraph()
{
	// qDebug() << "test" << endl;
	studentDataManager.setBarGraph();
}

// QtGuiPractice::QtGuiPractice()
// {
//	delete ui;
//}
