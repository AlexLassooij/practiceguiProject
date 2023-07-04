#include "QtGuiPractice.h"


// will contain functionality of app 
QtGuiPractice::QtGuiPractice(QWidget *parent) : QMainWindow(parent)
{
	// ui = new QtGuiPracticeUiConfigurer();
	setUpUi();

	initDb();

	setWindowTitle(QString("Qt GUI Practice 20230622"));
	setUpPlotController();

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

	//QObject::connect(savePushButton, &QPushButton::released, this, &QtGuiPractice::saveStudentData);
	QObject::connect(savePushButton, &QPushButton::clicked, [=]() {
		saveStudentData();
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
	actionSave->setObjectName(QStringLiteral("actionSave"));
	actionSave->setIcon(saveIcon);
	actionSave->setMenuRole(QAction::TextHeuristicRole);
	actionSave->setFont(mainFont);

	actionExport = new QAction(this);
	actionExport->setObjectName(QStringLiteral("actionExport"));
	actionExport->setIcon(exportIcon);

	actionOpen = new QAction(this);
	actionOpen->setObjectName(QStringLiteral("actionOpen"));
	actionOpen->setIcon(openIcon);

	actionQuit = new QAction(this);
	actionQuit->setObjectName(QStringLiteral("actionQuit"));
	actionQuit->setIcon(quitIcon);
	actionSave->setMenuRole(QAction::QuitRole);


	actionCopy = new QAction(this);
	actionCopy->setObjectName(QStringLiteral("actionCopy"));

	actionPaste = new QAction(this);
	actionPaste->setObjectName(QStringLiteral("actionPaste"));

	actionCut = new QAction(this);
	actionCut->setObjectName(QStringLiteral("actionCut"));

	actionHelp = new QAction(this);
	actionCut->setObjectName(QStringLiteral("actionHelp"));
	//actionSave->setMenuRole(QAction::AboutRole);
}

void QtGuiPractice::setUpStudentFormLayout()
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
	studentFormVerticalLayout->addWidget(emailText);

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

void QtGuiPractice::setUpPlotLayout()
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

void QtGuiPractice::setUpMenu()
{
	menuBar = new QMenuBar(this);
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

	this->setMenuBar(menuBar);
	mainToolBar = new QToolBar(this);
	mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
	this->addToolBar(Qt::TopToolBarArea, mainToolBar);

	// remove ? 
	statusBar = new QStatusBar(this);
	statusBar->setObjectName(QStringLiteral("statusBar"));
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
	tabWidget->setTabText(tabWidget->indexOf(studentFormTab), QApplication::translate("this", "Student Project Form", Q_NULLPTR));
	selectDistrictLabel->setText(QApplication::translate("this", "Select District", Q_NULLPTR));
	selectGradeLabel->setText(QApplication::translate("this", "Select Grade", Q_NULLPTR));
	loadDataButton->setText(QApplication::translate("this", "Load Data", Q_NULLPTR));

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
		this->setObjectName(QStringLiteral("this"));
	// set size of the main window 
	this->resize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
	// this->setCursor(QCursor(Qt::OpenHandCursor));

	// define main font 
	mainFont.setFamily(QStringLiteral("Segoe UI Semibold"));
	mainFont.setBold(true);
	mainFont.setWeight(75);

	// configure central widget
	centralWidget = new QWidget(this);
	centralWidget->setObjectName(QStringLiteral("centralWidget"));

	

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
	this->setCentralWidget(centralWidget);
	setActions();
	setActionHandling();
	setUpMenu();
	setUiDisplayNames();

	// start on student form tab
	tabWidget->setCurrentIndex(1);


	QMetaObject::connectSlotsByName(this);
} // setupUi


void QtGuiPractice::setUpPlotController()
{
	plotController = StudentPlotController(this, studentplot);
	plotController.setBackground();
	/*connect(ui.districtComboBox, currentIndexChanged(-1), this, &StudentPlotController::setBarGraph);
	connect(ui.gradeComboBox, SIGNAL(currentIndexChanged(-1)), this, SLOT(spController.setBarGraph()));*/
	//connect(ui.loadDataButton, &QPushButton::released, this, &QtGuiPractice::setBarGraph);
	//connect(loadDataButton, &QPushButton::released, this, &QtGuiPractice::setBarGraph);

	QObject::connect(loadDataButton, &QPushButton::clicked, [=]() {
		setBarGraph();
	});
	//connect(loadDataButton, &QPushButton::released, this, plotController.setBarGraph);


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
	plotController.setDatabasePath(fileName);
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
	plotController.setBarGraph();
}

// QtGuiPractice::QtGuiPractice()
// {
//	delete ui;
//}
