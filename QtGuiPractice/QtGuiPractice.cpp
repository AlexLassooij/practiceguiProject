#include "QtGuiPractice.h"


// will contain functionality of app 
QtGuiPractice::QtGuiPractice(QWidget *parent) : QMainWindow(parent)
{
	// ui = new QtGuiPracticeUiConfigurer();
	setUpUi();

	initDb();

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

	QObject::connect(savePushButton, &QPushButton::clicked, [=]() {
		saveStudentData();
	});

	QObject::connect(queryPushButton, &QPushButton::clicked, [=]() {
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

	actionExport = new QAction(this);
	actionExport->setIcon(exportIcon);

	actionOpen = new QAction(this);
	actionOpen->setIcon(openIcon);

	actionQuit = new QAction(this);
	actionQuit->setIcon(quitIcon);
	actionSave->setMenuRole(QAction::QuitRole);


	actionCopy = new QAction(this);

	actionPaste = new QAction(this);

	actionCut = new QAction(this);

	actionHelp = new QAction(this);
	//actionSave->setMenuRole(QAction::AboutRole);
}

void QtGuiPractice::setUpStudentFormLayout()
{
	studentFormVerticalLayoutWidget = new QWidget(studentFormTab);
	studentFormVerticalLayoutWidget->setGeometry(QRect(0, 0, MAIN_WINDOW_HEIGHT, MAIN_WINDOW_WIDTH));

	studentFormVerticalLayout = new QVBoxLayout(studentFormVerticalLayoutWidget);
	studentFormVerticalLayout->setSpacing(5);
	studentFormVerticalLayout->setContentsMargins(10, 5, 10, 10);

	projectNameLabel = new QLabel(studentFormVerticalLayoutWidget);
	projectNameLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 2, 20));


	projectNameText = new QPlainTextEdit(studentFormVerticalLayoutWidget);
	projectNameText->setMaximumSize(QSize(400, 35));
	projectNameText->setInputMethodHints(Qt::ImhMultiLine);


	studentNameLabel = new QLabel(studentFormVerticalLayoutWidget);
	studentNameLabel->setMaximumSize(QSize(16777220, 20));

	studentNameText = new QTextEdit(studentFormVerticalLayoutWidget);
	studentNameText->setMaximumSize(QSize(400, 35));


	emailLabel = new QLabel(studentFormVerticalLayoutWidget);
	emailLabel->setMaximumSize(QSize(16777220, 20));

	emailText = new QTextEdit(studentFormVerticalLayoutWidget);
	emailText->setPlaceholderText("Enter as <CWL@student.ubc.ca");
	emailText->setMaximumSize(QSize(400, 35));
	emailText->setInputMethodHints(Qt::ImhEmailCharactersOnly);


	versionLabel = new QLabel(studentFormVerticalLayoutWidget);
	versionLabel->setMaximumSize(QSize(16777220, 20));

	versionText = new QTextEdit(studentFormVerticalLayoutWidget);
	versionText->setMaximumSize(QSize(400, 35));

	descriptionLabel = new QLabel(studentFormVerticalLayoutWidget);
	descriptionLabel->setMaximumSize(QSize(16777220, 20));

	descriptionText = new QTextEdit(studentFormVerticalLayoutWidget);
	descriptionText->setPlaceholderText("Optional");
	descriptionText->setMaximumSize(QSize(MAIN_WINDOW_HEIGHT, 140));

	studentFormVerticalLayout->addWidget(projectNameLabel);
	studentFormVerticalLayout->addWidget(projectNameText);

	studentFormVerticalLayout->addWidget(studentNameLabel);
	studentFormVerticalLayout->addWidget(studentNameText);

	studentFormVerticalLayout->addWidget(emailLabel);
	studentFormVerticalLayout->addWidget(emailText);

	studentFormVerticalLayout->addWidget(versionLabel);
	studentFormVerticalLayout->addWidget(versionText);

	studentFormVerticalLayout->addWidget(descriptionLabel);
	studentFormVerticalLayout->addWidget(descriptionText);


	studentFormHorizontalLayout = new QHBoxLayout();
	studentFormHorizontalLayout->setSpacing(5);
	studentFormHorizontalLayout->setContentsMargins(-1, 5, -1, 5);

	savePushButton = new QPushButton(studentFormVerticalLayoutWidget);
	savePushButton->setMinimumSize(QSize(0, 35));
	savePushButton->setMaximumSize(QSize(350, 40));
	savePushButton->setFont(*bodyFont);

	studentFormHorizontalLayout->addWidget(savePushButton);
	studentFormHorizontalLayout->setStretch(0, 1);

	studentFormVerticalLayout->addLayout(studentFormHorizontalLayout);
}

void QtGuiPractice::setUpPlotLayout()
{
	plotSettingVerticalLayoutWidget = new QWidget(plotTab);
	plotSettingVerticalLayoutWidget->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, 120));

	plotSettingVerticalLayout = new QVBoxLayout(plotSettingVerticalLayoutWidget);
	plotSettingVerticalLayout->setSpacing(0);
	plotSettingVerticalLayout->setContentsMargins(0, 0, 0, 0);

	settingLabelHorizontalLayout = new QHBoxLayout();
	settingLabelHorizontalLayout->setSpacing(6);
	settingLabelHorizontalLayout->setContentsMargins(75, 0, 185, 0);

	selectDistrictLabel = new QLabel(plotSettingVerticalLayoutWidget);

	selectGradeLabel = new QLabel(plotSettingVerticalLayoutWidget);

	settingLabelHorizontalLayout->addWidget(selectDistrictLabel);
	settingLabelHorizontalLayout->addWidget(selectGradeLabel);


	comboBoxHorizontalLayout = new QHBoxLayout();
	comboBoxHorizontalLayout->setSpacing(15);
	comboBoxHorizontalLayout->setContentsMargins(75, 0, 75, 30);

	districtComboBox = new QComboBox(plotSettingVerticalLayoutWidget);

	gradeComboBox = new QComboBox(plotSettingVerticalLayoutWidget);

	loadDataButton = new QPushButton(plotSettingVerticalLayoutWidget);
	loadDataButton->setMaximumSize(QSize(100, 30));

	comboBoxHorizontalLayout->addWidget(districtComboBox);
	comboBoxHorizontalLayout->addWidget(gradeComboBox);
	comboBoxHorizontalLayout->addWidget(loadDataButton);

	comboBoxHorizontalLayout->setStretch(0, 2);
	comboBoxHorizontalLayout->setStretch(1, 2);
	comboBoxHorizontalLayout->setStretch(2, 1);

	plotSettingVerticalLayout->addLayout(settingLabelHorizontalLayout);
	plotSettingVerticalLayout->addLayout(comboBoxHorizontalLayout);

	studentplot = new QCustomPlot(plotTab);
	studentplot->setGeometry(QRect(0, 120, MAIN_WINDOW_WIDTH, 500));
}

void QtGuiPractice::setUpQueryLayout() 
{
	//queryVerticalLayoutWidget = new QWidget(queryTab);
	//queryVerticalLayoutWidget->setObjectName(QStringLiteral("studentFormVerticalLayoutWidget"));
	//queryVerticalLayoutWidget->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));

	//queryVerticalLayout = new QVBoxLayout(queryVerticalLayoutWidget);
	//queryVerticalLayout->setSpacing(0);
	//queryVerticalLayout->setObjectName(QStringLiteral("querySelectionVerticalLayout"));
	//// queryVerticalLayout->setContentsMargins(50, 20, 50, 20);
	//queryVerticalLayout->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, 400));


	querySelectionGridLayoutWidget = new QWidget(queryTab);
	querySelectionGridLayoutWidget->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT*0.85));

	querySelectionGridLayout = new QGridLayout(querySelectionGridLayoutWidget);
	querySelectionGridLayout->setSpacing(10);
	querySelectionGridLayout->setContentsMargins(50, 10, 50, 10);


	queryTitleLabel = new QLabel(querySelectionGridLayoutWidget);
	queryTitleLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 40));
	queryTitleLabel->setText("Search and Edit Students");
	queryTitleLabel->setFont(*headerFont);
	queryTitleLabel->setEnabled(false);

	queryNameLabel = new QLabel(querySelectionGridLayoutWidget);
	queryNameLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	queryNameLabel->setText("Student Name");


	queryNameText = new QTextEdit(querySelectionGridLayoutWidget);
	queryNameText->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 35));


	queryScoreLabel = new QLabel(querySelectionGridLayoutWidget);
	queryScoreLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	queryScoreLabel->setText("Student Score");


	queryScoreText = new QTextEdit(querySelectionGridLayoutWidget);
	queryScoreText->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 5, 35));
	queryScoreText->setPlaceholderText(QString("0.0 - 100.0"));


	queryGradeLabel = new QLabel(querySelectionGridLayoutWidget);
	queryGradeLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	queryGradeLabel->setText("Grade");

	queryScoreGroupBox = new QGroupBox();
	queryScoreGreater = new QRadioButton("Greater");
	queryScoreLess = new QRadioButton("Less");
	queryScoreGreater->setChecked(true);

	queryScoreHBox = new QHBoxLayout();
	queryScoreHBox->addWidget(queryScoreGreater);
	queryScoreHBox->addWidget(queryScoreLess);
	queryScoreGroupBox->setLayout(queryScoreHBox);


	queryGradeComboBox = new QComboBox(querySelectionGridLayoutWidget);
	queryGradeComboBox->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 35));


	queryDistrictLabel = new QLabel(querySelectionGridLayoutWidget);
	queryDistrictLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	queryDistrictLabel->setText("District");

	queryDistrictComboBox = new QComboBox(querySelectionGridLayoutWidget);

	queryYearLabel = new QLabel(querySelectionGridLayoutWidget);
	queryYearLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	queryYearLabel->setText("Year");

	queryYearComboBox = new QComboBox(querySelectionGridLayoutWidget);

	querySortByLabel = new QLabel(querySelectionGridLayoutWidget);
	querySortByLabel->setMaximumSize(QSize(MAIN_WINDOW_WIDTH / 3, 20));
	querySortByLabel->setText("Sort By");


	querySortByComboBox = new QComboBox(querySelectionGridLayoutWidget);

	queryPushButton = new QPushButton("Search", querySelectionGridLayoutWidget);

	queryResultsTable = new QTableWidget(querySelectionGridLayoutWidget);
	queryResultsTable->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
	tableFields = new QStringList({ "ID", "Name", "Email", "District", "Grade", "Year", "S1", "S2", "S3", "SF" });
	queryResultsTable->setColumnCount(tableFields->size());
	queryResultsTable->setHorizontalHeaderLabels(*tableFields);
	queryResultsTable->horizontalHeader()->setVisible(true);
	queryResultsTable->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
	queryResultsTable->setSelectionMode(QAbstractItemView::SingleSelection);
	queryResultsTable->horizontalHeader()->setSelectionMode(QAbstractItemView::NoSelection);

	queryResultsTable->setColumnWidth(0, 60);
	queryResultsTable->setColumnWidth(1, 150);
	queryResultsTable->setColumnWidth(2, 200);
	queryResultsTable->setColumnWidth(3, 90);
	queryResultsTable->setColumnWidth(4, 80);
	queryResultsTable->setColumnWidth(5, 70);
	queryResultsTable->setColumnWidth(6, 40);
	queryResultsTable->setColumnWidth(7, 40);
	queryResultsTable->setColumnWidth(8, 40);
	queryResultsTable->setColumnWidth(9, 40);
	// queryResultsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	applyEditButton = new QPushButton("Apply Edits", querySelectionGridLayoutWidget);
	applyDeleteButton = new QPushButton("Apply Deletes", querySelectionGridLayoutWidget);
	resetSearchButton = new QPushButton("Reset", querySelectionGridLayoutWidget);




	querySelectionGridLayout->addWidget(queryTitleLabel, 0, 0, 1, 3);
	querySelectionGridLayout->addWidget(queryNameLabel, 1, 0, 1, 2);
	querySelectionGridLayout->addWidget(queryNameText, 2, 0, 1, 2);

	querySelectionGridLayout->addWidget(queryScoreLabel, 1, 2, 1, 1);
	querySelectionGridLayout->addWidget(queryScoreText, 2, 2, 1, 1);
	querySelectionGridLayout->addWidget(queryScoreGroupBox, 2, 3, 1, 1);

	
	querySelectionGridLayout->addWidget(queryDistrictLabel, 3, 0, 1, 1);
	querySelectionGridLayout->addWidget(queryDistrictComboBox, 4, 0, 1, 1);

	querySelectionGridLayout->addWidget(queryGradeLabel, 3, 1, 1, 1);
	querySelectionGridLayout->addWidget(queryGradeComboBox, 4, 1, 1, 1);

	querySelectionGridLayout->addWidget(queryYearLabel, 3, 2, 1, 1);
	querySelectionGridLayout->addWidget(queryYearComboBox, 4, 2, 1, 1);

	querySelectionGridLayout->addWidget(querySortByLabel, 3, 3, 1, 1);
	querySelectionGridLayout->addWidget(querySortByComboBox, 4, 3, 1, 1);

	querySelectionGridLayout->addWidget(queryPushButton, 5, 0, 1, 1);

	querySelectionGridLayout->addWidget(queryResultsTable, 6, 0, 4, 5);

	querySelectionGridLayout->addWidget(applyEditButton, 10, 0, 1, 1);
	querySelectionGridLayout->addWidget(applyDeleteButton, 10, 1, 1, 1);
	querySelectionGridLayout->addWidget(resetSearchButton, 10, 2, 1, 1);


	//queryResultScrollArea = new QScrollArea(querySelectionGridLayoutWidget);
	////queryResultScrollArea->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT * 0.5));

	//queryResultScrollArea = new QScrollArea(querySelectionGridLayoutWidget);
	//queryResultScrollArea->setObjectName(QStringLiteral("queryResultScrollArea"));
	//queryResultScrollArea->setMaximumSize(QSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT * 0.5));
	//queryResultScrollArea->setWidgetResizable(true);
	//queryResultScrollAreaContents = new QWidget();
	//queryResultScrollAreaContents->setObjectName(QStringLiteral("queryResultScrollAreaContents"));
	//// scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 323, 705));
	//queryResultScrollAreaVerticalLayout = new QVBoxLayout(queryResultScrollAreaContents);
	////queryResultScrollAreaVerticalLayout->setSpacing(4);
	////queryResultScrollAreaVerticalLayout->setContentsMargins(5, 5, 5, 5);
	//queryResultScrollAreaVerticalLayout->setObjectName(QStringLiteral("queryResultScrollAreaVerticalLayout"));
	//queryResultScrollArea->setWidget(queryResultScrollAreaContents);



	//queryVerticalLayout->addWidget(queryTitleLabel);
	//queryVerticalLayout->addWidget(querySelectionGridLayoutWidget);
	//queryVerticalLayout->addWidget(studentplot);

}

void QtGuiPractice::setUpMenu()
{
	menuBar = new QMenuBar(this);
	menuBar->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, 30));
	menuBar->setFont(*bodyFont);

	menuFile = new QMenu(menuBar);
	menuFile->setFont(*bodyFont);

	menuEdit = new QMenu(menuBar);
	menuEdit->setFont(*bodyFont);

	menuHelp = new QMenu(menuBar);

	menuInsert = new QMenu(menuBar);

	menuTools = new QMenu(menuBar);

	this->setMenuBar(menuBar);
	mainToolBar = new QToolBar(this);
	this->addToolBar(Qt::TopToolBarArea, mainToolBar);

	// remove ? 
	statusBar = new QStatusBar(this);
	this->setStatusBar(statusBar);

	// set order of focus change when pressing "Tab" button
	QWidget::setTabOrder(projectNameText, studentNameText);
	QWidget::setTabOrder(studentNameText, emailText);
	QWidget::setTabOrder(emailText, descriptionText);
	QWidget::setTabOrder(descriptionText, savePushButton);

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

void QtGuiPractice::setUiDisplayNames()
{
	this->setWindowTitle(QApplication::translate("this", "QtGuiPractice", Q_NULLPTR));
	actionSave->setText(QApplication::translate("this", "Save", Q_NULLPTR));
	actionExport->setText(QApplication::translate("this", "Export", Q_NULLPTR));
	actionOpen->setText(QApplication::translate("this", "Open", Q_NULLPTR));
	actionQuit->setText(QApplication::translate("this", "Quit", Q_NULLPTR));
	actionCopy->setText(QApplication::translate("this", "Copy", Q_NULLPTR));
	actionPaste->setText(QApplication::translate("this", "Paste", Q_NULLPTR));
	actionCut->setText(QApplication::translate("this", "Cut", Q_NULLPTR));


	actionSave->setShortcut(QApplication::translate("this", "Ctrl+S", Q_NULLPTR));
	actionExport->setShortcut(QApplication::translate("this", "Ctrl+Shift+E", Q_NULLPTR));
	actionOpen->setShortcut(QApplication::translate("this", "Ctrl+O", Q_NULLPTR));

	// form labels 
	projectNameLabel->setText(QApplication::translate("this", "Project Name", Q_NULLPTR));
	studentNameLabel->setText(QApplication::translate("this", "Student Name", Q_NULLPTR));
	emailLabel->setText(QApplication::translate("this", "Email", Q_NULLPTR));
	versionLabel->setText(QApplication::translate("this", "Version", Q_NULLPTR));
	descriptionLabel->setText(QApplication::translate("this", "Description", Q_NULLPTR));

	savePushButton->setText(QApplication::translate("this", "Save Data", Q_NULLPTR));
	selectDistrictLabel->setText(QApplication::translate("this", "Select District", Q_NULLPTR));
	selectGradeLabel->setText(QApplication::translate("this", "Select Grade", Q_NULLPTR));
	loadDataButton->setText(QApplication::translate("this", "Load Data", Q_NULLPTR));
	tabWidget->setTabText(tabWidget->indexOf(studentFormTab), QApplication::translate("this", "Student Project Form", Q_NULLPTR));
	tabWidget->setTabText(tabWidget->indexOf(queryTab), QApplication::translate("this", "Query", Q_NULLPTR));
	tabWidget->setTabText(tabWidget->indexOf(plotTab), QApplication::translate("this", "Plot", Q_NULLPTR));
	menuFile->setTitle(QApplication::translate("this", "File", Q_NULLPTR));
	menuEdit->setTitle(QApplication::translate("this", "Edit", Q_NULLPTR));
	menuHelp->setTitle(QApplication::translate("this", "Help", Q_NULLPTR));
	menuInsert->setTitle(QApplication::translate("this", "Insert", Q_NULLPTR));
	menuTools->setTitle(QApplication::translate("this", "Tools", Q_NULLPTR));
} // retranslateUi

void QtGuiPractice::setUpUi()
{
	if (this->objectName().isEmpty())
	// set size of the main window 
	this->resize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
	// this->setCursor(QCursor(Qt::OpenHandCursor));

	// define main font 
	/**bodyFont.setFamily(QStringLiteral("Segoe UI Semibold"));
	*bodyFont.setBold(true);
	*bodyFont.setWeight(75);*/
	headerFont = new QFont("Segoe UI Semibold", 12);
	bodyFont = new QFont("Segoe UI Semibold", 8, QFont::Bold);
	


	// configure central widget
	centralWidget = new QWidget(this);

	

	// configure tab widget that will contain student and plot tab 
	tabWidget = new QTabWidget(centralWidget);
	tabWidget->setGeometry(QRect(0, 0, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
	tabWidget->setMinimumSize(QSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
	tabWidget->setMaximumSize(QSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT));
	tabWidget->setFont(*bodyFont);

	// configure student form tab
	studentFormTab = new QWidget();
	setUpStudentFormLayout();
	tabWidget->addTab(studentFormTab, QString());

	// configure plot tab
	plotTab = new QWidget();
	
	setUpPlotLayout();
	tabWidget->addTab(plotTab, QString());

	// configure query tab
	queryTab = new QWidget();
	
	setUpQueryLayout();
	tabWidget->addTab(queryTab, QString());

	// remove ? 
	this->setCentralWidget(centralWidget);
	setActions();
	setActionHandling();
	setUpMenu();
	setUiDisplayNames();

	// start on student form tab
	tabWidget->setCurrentIndex(2);


	QMetaObject::connectSlotsByName(this);
} // setupUi


void QtGuiPractice::setUpStudentDataManager()
{
	studentDataManager = StudentDataManager(this, studentplot);
	studentDataManager.setBackground();
	studentDataManager.initStudentDb();
	studentDataManager.populateStudentData();
		

	QObject::connect(loadDataButton, &QPushButton::clicked, [=]() {
		studentDataManager.setBarGraph();
	});

	QObject::connect(queryResultsTable, &QTableWidget::itemDoubleClicked, [=](QTableWidgetItem* item) {
		studentDataManager.handleItemClicked(item);
	});

	// connect(queryResultsTable, SIGNAL(itemChanged(QTableWidgetItem*)), studentDataManager, SLOT(StudentDataManager::addToEdit(QTableWidgetItem*)));
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


void QtGuiPractice::saveStudentData()
{
	QString projectName = projectNameText->toPlainText();
	QString studentName = studentNameText->toPlainText();
	QString email		= emailText->toPlainText();
	QString version		= versionText->toPlainText();
	QString description	= descriptionText->toPlainText();

	QSqlQuery	query;

	QString sql = QString("INSERT INTO ProjectInfo (ProjectName, StudentName, Email, Version, CreatedTime, Description, ModelType)"
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
		savePushButton->setText("Saved Data Successfully");
		qDebug() << "Project info has been stored successfully" << endl;
	}
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
