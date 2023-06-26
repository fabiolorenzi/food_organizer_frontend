#include <QtWidgets/QMessageBox>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include "MainWindow.h"
#include "InitialWidget.h"
#include "LoginWidget.h"

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
    } else {
        (*loginButton).setEnabled(true);
        (*logoutButton).setEnabled(false);
        (*settingsButton).setEnabled(false);
        (*dashboardButton).setEnabled(false);
        (*weeklyPlannerButton).setEnabled(false);
        (*storageButton).setEnabled(false);
        (*financesButton).setEnabled(false);
        InitialWidget* initialWidget = new InitialWidget;
        this->setCentralWidget(initialWidget);
    };
}

void MainWindow::LoginMenuClicked() {
    this->takeCentralWidget();
    LoginWidget* loginWidget = new LoginWidget();
    this->setCentralWidget(loginWidget);
}

void MainWindow::LogoutMenuClicked() {
    QMessageBox msg;
    msg.setText("You have logged out successfully");
    msg.exec();
    remove("build/auth.txt");
    UpdateMainWindow();
}

void MainWindow::ExitMenuClicked() {
    QApplication::exit(0);
}

void MainWindow::SettingsMenuClicked() {
    QMessageBox msg;
    msg.setText("Settings menu");
    msg.exec();
}

void MainWindow::DashboardMenuClicked() {
    QMessageBox msg;
    msg.setText("Dashboard menu");
    msg.exec();
}

void MainWindow::WeeklyPlannerMenuClicked() {
    QMessageBox msg;
    msg.setText("Weekly planner menu");
    msg.exec();
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