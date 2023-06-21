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

QT_BEGIN_NAMESPACE

class Ui_QtGuiPracticeClass
{
public:
    QAction *actionSave;
    QAction *actionExport;
    QAction *actionOpen;
    QAction *actionQuit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
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
    QHBoxLayout *horizontalLayout;
    QPushButton *savePushButton;
    QPushButton *closePushButton;
    QWidget *tab_5;
    QCustomPlot *studentplot;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *districtComboBox;
    QComboBox *gradeComboBox;
    QPushButton *loadDataButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuInsert;
    QMenu *menuTools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiPracticeClass)
    {
        if (QtGuiPracticeClass->objectName().isEmpty())
            QtGuiPracticeClass->setObjectName(QStringLiteral("QtGuiPracticeClass"));
        QtGuiPracticeClass->resize(752, 800);
        QtGuiPracticeClass->setCursor(QCursor(Qt::OpenHandCursor));
        actionSave = new QAction(QtGuiPracticeClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/Resources/icons8-save-30.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI Semibold"));
        font.setBold(true);
        font.setWeight(75);
        actionSave->setFont(font);
        actionSave->setMenuRole(QAction::TextHeuristicRole);
        actionExport = new QAction(QtGuiPracticeClass);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/Resources/icons8-export-30.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport->setIcon(icon1);
        actionOpen = new QAction(QtGuiPracticeClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/Resources/icons8-open-file-30.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionQuit = new QAction(QtGuiPracticeClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Resources/Resources/icons8-quit-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon3);
        actionCopy = new QAction(QtGuiPracticeClass);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionPaste = new QAction(QtGuiPracticeClass);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionCut = new QAction(QtGuiPracticeClass);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        centralWidget = new QWidget(QtGuiPracticeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 800, 800));
        tabWidget->setMinimumSize(QSize(800, 0));
        tabWidget->setMaximumSize(QSize(800, 16777215));
        tabWidget->setFont(font);
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        verticalLayoutWidget = new QWidget(tab_1);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 791, 553));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        projectNameLabel = new QLabel(verticalLayoutWidget);
        projectNameLabel->setObjectName(QStringLiteral("projectNameLabel"));
        projectNameLabel->setMaximumSize(QSize(16777215, 15));
        projectNameLabel->setFont(font);

        verticalLayout->addWidget(projectNameLabel);

        projectNameText = new QPlainTextEdit(verticalLayoutWidget);
        projectNameText->setObjectName(QStringLiteral("projectNameText"));
        projectNameText->setEnabled(true);
        projectNameText->setMaximumSize(QSize(400, 35));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI Semibold"));
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(true);
        projectNameText->setFont(font1);
        projectNameText->setAcceptDrops(true);
        projectNameText->setInputMethodHints(Qt::ImhMultiLine);

        verticalLayout->addWidget(projectNameText);

        studentNameLabel = new QLabel(verticalLayoutWidget);
        studentNameLabel->setObjectName(QStringLiteral("studentNameLabel"));
        studentNameLabel->setMaximumSize(QSize(16777215, 15));
        studentNameLabel->setFont(font);

        verticalLayout->addWidget(studentNameLabel);

        studentNameText = new QTextEdit(verticalLayoutWidget);
        studentNameText->setObjectName(QStringLiteral("studentNameText"));
        studentNameText->setMaximumSize(QSize(400, 35));
        studentNameText->setFont(font);

        verticalLayout->addWidget(studentNameText);

        emailLabel = new QLabel(verticalLayoutWidget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));
        emailLabel->setMaximumSize(QSize(16777215, 15));
        emailLabel->setFont(font);

        verticalLayout->addWidget(emailLabel);

        emailText = new QTextEdit(verticalLayoutWidget);
        emailText->setObjectName(QStringLiteral("emailText"));
        emailText->setMaximumSize(QSize(400, 35));
        emailText->setFont(font);
        emailText->setInputMethodHints(Qt::ImhEmailCharactersOnly|Qt::ImhMultiLine);

        verticalLayout->addWidget(emailText);

        versionLabel = new QLabel(verticalLayoutWidget);
        versionLabel->setObjectName(QStringLiteral("versionLabel"));
        versionLabel->setMaximumSize(QSize(16777215, 15));
        versionLabel->setFont(font);

        verticalLayout->addWidget(versionLabel);

        versionText = new QTextEdit(verticalLayoutWidget);
        versionText->setObjectName(QStringLiteral("versionText"));
        versionText->setMaximumSize(QSize(400, 35));
        versionText->setFont(font);

        verticalLayout->addWidget(versionText);

        descriptionLabel = new QLabel(verticalLayoutWidget);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));
        descriptionLabel->setMaximumSize(QSize(16777215, 15));
        descriptionLabel->setFont(font);

        verticalLayout->addWidget(descriptionLabel);

        descriptionText = new QTextEdit(verticalLayoutWidget);
        descriptionText->setObjectName(QStringLiteral("descriptionText"));
        descriptionText->setMaximumSize(QSize(800, 140));
        descriptionText->setFont(font);

        verticalLayout->addWidget(descriptionText);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, 5);
        savePushButton = new QPushButton(verticalLayoutWidget);
        savePushButton->setObjectName(QStringLiteral("savePushButton"));
        savePushButton->setMinimumSize(QSize(0, 30));
        savePushButton->setMaximumSize(QSize(350, 16777215));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        savePushButton->setFont(font2);

        horizontalLayout->addWidget(savePushButton);

        closePushButton = new QPushButton(verticalLayoutWidget);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        closePushButton->setMinimumSize(QSize(20, 30));
        closePushButton->setMaximumSize(QSize(350, 16777215));
        closePushButton->setFont(font2);

        horizontalLayout->addWidget(closePushButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        tabWidget->addTab(tab_1, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        studentplot = new QCustomPlot(tab_5);
        studentplot->setObjectName(QStringLiteral("studentplot"));
        studentplot->setGeometry(QRect(0, 120, 791, 571));
        verticalLayoutWidget_3 = new QWidget(tab_5);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 751, 117));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(75, 0, 185, 0);
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_7->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_7->addWidget(label);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(75, 0, 75, 30);
        districtComboBox = new QComboBox(verticalLayoutWidget_3);
        districtComboBox->setObjectName(QStringLiteral("districtComboBox"));

        horizontalLayout_3->addWidget(districtComboBox);

        gradeComboBox = new QComboBox(verticalLayoutWidget_3);
        gradeComboBox->setObjectName(QStringLiteral("gradeComboBox"));

        horizontalLayout_3->addWidget(gradeComboBox);

        loadDataButton = new QPushButton(verticalLayoutWidget_3);
        loadDataButton->setObjectName(QStringLiteral("loadDataButton"));
        loadDataButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_3->addWidget(loadDataButton);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        tabWidget->addTab(tab_5, QString());
        QtGuiPracticeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiPracticeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 752, 31));
        menuBar->setFont(font);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        QFont font3;
        font3.setFamily(QStringLiteral("Segoe UI Semibold"));
        font3.setBold(false);
        font3.setWeight(50);
        menuFile->setFont(font3);
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuEdit->setFont(font);
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
        statusBar = new QStatusBar(QtGuiPracticeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiPracticeClass->setStatusBar(statusBar);
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

        retranslateUi(QtGuiPracticeClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(QtGuiPracticeClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiPracticeClass)
    {
        QtGuiPracticeClass->setWindowTitle(QApplication::translate("QtGuiPracticeClass", "QtGuiPractice", Q_NULLPTR));
        actionSave->setText(QApplication::translate("QtGuiPracticeClass", "Save", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("QtGuiPracticeClass", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionExport->setText(QApplication::translate("QtGuiPracticeClass", "Export", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionExport->setShortcut(QApplication::translate("QtGuiPracticeClass", "Ctrl+Shift+E", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("QtGuiPracticeClass", "Open", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("QtGuiPracticeClass", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionQuit->setText(QApplication::translate("QtGuiPracticeClass", "Quit", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("QtGuiPracticeClass", "Copy", Q_NULLPTR));
        actionPaste->setText(QApplication::translate("QtGuiPracticeClass", "Paste", Q_NULLPTR));
        actionCut->setText(QApplication::translate("QtGuiPracticeClass", "Cut", Q_NULLPTR));
        projectNameLabel->setText(QApplication::translate("QtGuiPracticeClass", "Project Name", Q_NULLPTR));
        studentNameLabel->setText(QApplication::translate("QtGuiPracticeClass", "Student Name", Q_NULLPTR));
        emailLabel->setText(QApplication::translate("QtGuiPracticeClass", "Email", Q_NULLPTR));
        versionLabel->setText(QApplication::translate("QtGuiPracticeClass", "Version", Q_NULLPTR));
        descriptionLabel->setText(QApplication::translate("QtGuiPracticeClass", "Description", Q_NULLPTR));
        savePushButton->setText(QApplication::translate("QtGuiPracticeClass", "Save Data", Q_NULLPTR));
        closePushButton->setText(QApplication::translate("QtGuiPracticeClass", "Close", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("QtGuiPracticeClass", "Tab 1", Q_NULLPTR));
        label_2->setText(QApplication::translate("QtGuiPracticeClass", "Select District", Q_NULLPTR));
        label->setText(QApplication::translate("QtGuiPracticeClass", "Select Grade", Q_NULLPTR));
        loadDataButton->setText(QApplication::translate("QtGuiPracticeClass", "Load Data", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("QtGuiPracticeClass", "Tab 2", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("QtGuiPracticeClass", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("QtGuiPracticeClass", "Edit", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("QtGuiPracticeClass", "Help", Q_NULLPTR));
        menuInsert->setTitle(QApplication::translate("QtGuiPracticeClass", "Insert", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("QtGuiPracticeClass", "Tools", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGuiPracticeClass: public Ui_QtGuiPracticeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIPRACTICE_H
