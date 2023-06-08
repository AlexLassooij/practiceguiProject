/********************************************************************************
** Form generated from reading UI file 'QtGuiPractice.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIPRACTICE_H
#define UI_QTGUIPRACTICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiPracticeClass
{
public:
    QAction *actionSave;
    QAction *actionExport;
    QAction *actionOpen;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *studentIDBox;
    QLabel *label_2;
    QTextEdit *nameBox;
    QLabel *label_3;
    QTextEdit *emailBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *savePushButton;
    QPushButton *closePushButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuInsert;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiPracticeClass)
    {
        if (QtGuiPracticeClass->objectName().isEmpty())
            QtGuiPracticeClass->setObjectName(QStringLiteral("QtGuiPracticeClass"));
        QtGuiPracticeClass->resize(800, 600);
        QtGuiPracticeClass->setCursor(QCursor(Qt::OpenHandCursor));
        actionSave = new QAction(QtGuiPracticeClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExport = new QAction(QtGuiPracticeClass);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionOpen = new QAction(QtGuiPracticeClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralWidget = new QWidget(QtGuiPracticeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 791, 521));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label);

        studentIDBox = new QTextEdit(verticalLayoutWidget);
        studentIDBox->setObjectName(QStringLiteral("studentIDBox"));
        studentIDBox->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(studentIDBox);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_2);

        nameBox = new QTextEdit(verticalLayoutWidget);
        nameBox->setObjectName(QStringLiteral("nameBox"));
        nameBox->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(nameBox);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(label_3);

        emailBox = new QTextEdit(verticalLayoutWidget);
        emailBox->setObjectName(QStringLiteral("emailBox"));
        emailBox->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(emailBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, 5);
        savePushButton = new QPushButton(verticalLayoutWidget);
        savePushButton->setObjectName(QStringLiteral("savePushButton"));
        savePushButton->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        savePushButton->setFont(font);

        horizontalLayout->addWidget(savePushButton);

        closePushButton = new QPushButton(verticalLayoutWidget);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        closePushButton->setMinimumSize(QSize(20, 30));
        closePushButton->setFont(font);

        horizontalLayout->addWidget(closePushButton);


        verticalLayout->addLayout(horizontalLayout);

        QtGuiPracticeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiPracticeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 31));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuInsert = new QMenu(menuBar);
        menuInsert->setObjectName(QStringLiteral("menuInsert"));
        QtGuiPracticeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiPracticeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiPracticeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiPracticeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiPracticeClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuInsert->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExport);
        menuFile->addAction(actionOpen);

        retranslateUi(QtGuiPracticeClass);

        QMetaObject::connectSlotsByName(QtGuiPracticeClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiPracticeClass)
    {
        QtGuiPracticeClass->setWindowTitle(QApplication::translate("QtGuiPracticeClass", "QtGuiPractice", Q_NULLPTR));
        actionSave->setText(QApplication::translate("QtGuiPracticeClass", "Save", Q_NULLPTR));
        actionExport->setText(QApplication::translate("QtGuiPracticeClass", "Export", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("QtGuiPracticeClass", "Open", Q_NULLPTR));
        label->setText(QApplication::translate("QtGuiPracticeClass", "Student ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("QtGuiPracticeClass", "Name", Q_NULLPTR));
        label_3->setText(QApplication::translate("QtGuiPracticeClass", "Email", Q_NULLPTR));
        savePushButton->setText(QApplication::translate("QtGuiPracticeClass", "Save Data", Q_NULLPTR));
        closePushButton->setText(QApplication::translate("QtGuiPracticeClass", "Close", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("QtGuiPracticeClass", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("QtGuiPracticeClass", "Edit", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("QtGuiPracticeClass", "Help", Q_NULLPTR));
        menuInsert->setTitle(QApplication::translate("QtGuiPracticeClass", "Insert", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGuiPracticeClass: public Ui_QtGuiPracticeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIPRACTICE_H
