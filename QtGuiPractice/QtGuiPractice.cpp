#include "QtGuiPractice.h"
#include <iostream>

// will contain functionality of app 
QtGuiPractice::QtGuiPractice(QWidget *parent)
	: QMainWindow(parent)

{
	ui.setupUi(this);
	
	connect(ui.nameBox, SIGNAL(textChanged()),
			ui.emailBox, SLOT(clear()));

	ui.nameBox->setPlaceholderText("Enter your username");

	// buttons
	connect(ui.savePushButton, &QPushButton::released, this, &QtGuiPractice::handleSave);
	/*QPushButton *saveButton = new QPushButton("Save Data", this);

	saveButton->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));*/
	// this->setCentralWidget(ui.sampleTextBox);

	setWindowTitle(QString("Qt GUI Practice"));


}

void QtGuiPractice::handleSave()
{
	ui.savePushButton->setText("Saved Data Successfully");
	studentDB = QSqlDatabase::addDatabase("QMYSQL");
	configStudentDB(&studentDB);
	



}


void QtGuiPractice::configStudentDB(QSqlDatabase *studentDB)
{
	studentDB->setHostName("localhost");
	studentDB->setUserName("root");
	studentDB->setPassword("");
	studentDB->setDatabaseName("studentInfo");
	std::cout << "Student DB initialized" << endl;
}

// QtGuiPractice::QtGuiPractice()
// {
//	delete ui;
//}
