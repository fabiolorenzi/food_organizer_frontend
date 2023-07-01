#include <QtWidgets/QMessageBox>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include "MainWindow.h"
#include "InitialWidget.h"
#include "LoginWidget.h"
#include "DashboardWidget.h"
#include "SettingsWidget.h"
#include "WeeklyPlannerWidget.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    ui.setupUi(this);
    UpdateMainWindow();
}

MainWindow::~MainWindow() {
    delete this;
}

void MainWindow::UpdateMainWindow() {
    QAction* loginButton = this->ui.actionLogin;
    QAction* logoutButton = this->ui.actionLogout;
    QAction* settingsButton = this->ui.actionSettings;
    QAction* dashboardButton = this->ui.actionDashboard;
    QAction* weeklyPlannerButton = this->ui.actionWeekly_Planner;
    QAction* storageButton = this->ui.actionStorage;
    QAction* financesButton = this->ui.actionFinances;

    std::ifstream authFile;
    authFile.open("build/auth.txt");

    if (authFile.is_open()) {
        (*loginButton).setEnabled(false);
        (*logoutButton).setEnabled(true);
        (*settingsButton).setEnabled(true);
        (*dashboardButton).setEnabled(true);
        (*weeklyPlannerButton).setEnabled(true);
        (*storageButton).setEnabled(true);
        (*financesButton).setEnabled(true);
        DashboardWidget* dashboardWidget = new DashboardWidget();
        this->setCentralWidget(dashboardWidget);
    } else {
        (*loginButton).setEnabled(true);
        (*logoutButton).setEnabled(false);
        (*settingsButton).setEnabled(false);
        (*dashboardButton).setEnabled(false);
        (*weeklyPlannerButton).setEnabled(false);
        (*storageButton).setEnabled(false);
        (*financesButton).setEnabled(false);
        InitialWidget* initialWidget = new InitialWidget();
        this->setCentralWidget(initialWidget);
    };
}

void MainWindow::LoginMenuClicked() {
    LoginWidget* loginWidget = new LoginWidget();
    ChangeWidget(loginWidget);
}

void MainWindow::LogoutMenuClicked() {
    remove("build/auth.txt");
    InitialWidget* initialWidget = new InitialWidget();
    
    QMessageBox msg;
    msg.setText("You have logged out successfully");
    msg.exec();
    ChangeWidget(initialWidget);
}

void MainWindow::ExitMenuClicked() {
    QApplication::quit();
}

void MainWindow::SettingsMenuClicked() {
    SettingsWidget* settingsWidget = new SettingsWidget();
    ChangeWidget(settingsWidget);
}

void MainWindow::DashboardMenuClicked() {
    DashboardWidget* dashboardWidget = new DashboardWidget();
    ChangeWidget(dashboardWidget);
}

void MainWindow::WeeklyPlannerMenuClicked() {
    WeeklyPlannerWidget* weeklyPlannerWidget = new WeeklyPlannerWidget();
    ChangeWidget(weeklyPlannerWidget);
}

void MainWindow::StorageMenuClicked() {
    QMessageBox msg;
    msg.setText("Storage menu");
    msg.exec();
}

void MainWindow::FinancesMenuClicked() {
    QMessageBox msg;
    msg.setText("Finances menu");
    msg.exec();
}

void MainWindow::AboutMenuClicked() {
    QMessageBox msg;
    msg.setText("About menu");
    msg.exec();
}

void MainWindow::ChangeWidget(QWidget* widget) {
    this->takeCentralWidget();
    this->setCentralWidget(widget);

    std::ifstream authFile;
    authFile.open("build/auth.txt");

    QAction* loginButton = this->ui.actionLogin;
    QAction* logoutButton = this->ui.actionLogout;
    QAction* settingsButton = this->ui.actionSettings;
    QAction* dashboardButton = this->ui.actionDashboard;
    QAction* weeklyPlannerButton = this->ui.actionWeekly_Planner;
    QAction* storageButton = this->ui.actionStorage;
    QAction* financesButton = this->ui.actionFinances;

    if (authFile.is_open()) {
        (*loginButton).setEnabled(false);
        (*logoutButton).setEnabled(true);
        (*settingsButton).setEnabled(true);
        (*dashboardButton).setEnabled(true);
        (*weeklyPlannerButton).setEnabled(true);
        (*storageButton).setEnabled(true);
        (*financesButton).setEnabled(true);
    } else {
        (*loginButton).setEnabled(true);
        (*logoutButton).setEnabled(false);
        (*settingsButton).setEnabled(false);
        (*dashboardButton).setEnabled(false);
        (*weeklyPlannerButton).setEnabled(false);
        (*storageButton).setEnabled(false);
        (*financesButton).setEnabled(false);
    };
}