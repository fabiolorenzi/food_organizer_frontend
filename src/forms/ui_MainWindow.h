#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogin;
    QAction *actionLogout;
    QAction *actionExit;
    QAction *actionSettings;
    QAction *actionMain_Page;
    QAction *actionWeekly_Planner;
    QAction *actionStorage;
    QAction *actionFinances;
    QAction *actionAbout;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionLogout = new QAction(MainWindow);
        actionLogout->setObjectName(QString::fromUtf8("actionLogout"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionMain_Page = new QAction(MainWindow);
        actionMain_Page->setObjectName(QString::fromUtf8("actionMain_Page"));
        actionWeekly_Planner = new QAction(MainWindow);
        actionWeekly_Planner->setObjectName(QString::fromUtf8("actionWeekly_Planner"));
        actionStorage = new QAction(MainWindow);
        actionStorage->setObjectName(QString::fromUtf8("actionStorage"));
        actionFinances = new QAction(MainWindow);
        actionFinances->setObjectName(QString::fromUtf8("actionFinances"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLogin);
        menuFile->addAction(actionLogout);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionSettings);
        menuView->addAction(actionMain_Page);
        menuView->addAction(actionWeekly_Planner);
        menuView->addAction(actionStorage);
        menuView->addAction(actionFinances);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(actionLogin, SIGNAL(triggered()), MainWindow, SLOT(LoginMenuClicked()));
        QObject::connect(actionLogout, SIGNAL(triggered()), MainWindow, SLOT(LogoutMenuClicked()));
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(ExitMenuClicked()));
        QObject::connect(actionSettings, SIGNAL(triggered()), MainWindow, SLOT(SettingsMenuClicked()));
        QObject::connect(actionMain_Page, SIGNAL(triggered()), MainWindow, SLOT(MainPageMenuClicked()));
        QObject::connect(actionWeekly_Planner, SIGNAL(triggered()), MainWindow, SLOT(WeeklyPlannerMenuClicked()));
        QObject::connect(actionStorage, SIGNAL(triggered()), MainWindow, SLOT(StorageMenuClicked()));
        QObject::connect(actionFinances, SIGNAL(triggered()), MainWindow, SLOT(FinancesMenuClicked()));
        QObject::connect(actionAbout, SIGNAL(triggered()), MainWindow, SLOT(AboutMenuClicked()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        actionLogout->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        actionMain_Page->setText(QCoreApplication::translate("MainWindow", "Main Page", nullptr));
        actionWeekly_Planner->setText(QCoreApplication::translate("MainWindow", "Weekly Planner", nullptr));
        actionStorage->setText(QCoreApplication::translate("MainWindow", "Storage", nullptr));
        actionFinances->setText(QCoreApplication::translate("MainWindow", "Finances", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_H