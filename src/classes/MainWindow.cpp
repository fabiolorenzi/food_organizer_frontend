#include <QtWidgets/QMessageBox>
#include <fstream>
#include <iostream>
#include "MainWindow.h"

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
    QAction* weeklyPlannerButton = this->ui.actionWeekly_Planner;
    QAction* storageButton = this->ui.actionStorage;
    QAction* financesButton = this->ui.actionFinances;

    std::ifstream authFile;
    authFile.open("build/auth.txt");

    if (authFile.is_open()) {
        (*loginButton).setEnabled(false);
        (*logoutButton).setEnabled(true);
        (*settingsButton).setEnabled(true);
        (*weeklyPlannerButton).setEnabled(true);
        (*storageButton).setEnabled(true);
        (*financesButton).setEnabled(true);
    } else {
        (*loginButton).setEnabled(true);
        (*logoutButton).setEnabled(false);
        (*settingsButton).setEnabled(false);
        (*weeklyPlannerButton).setEnabled(false);
        (*storageButton).setEnabled(false);
        (*financesButton).setEnabled(false);
    };
}

void MainWindow::LoginMenuClicked() {
    QMessageBox msg;
    msg.setText("Login menu");
    msg.exec();
}

void MainWindow::LogoutMenuClicked() {
    QMessageBox msg;
    msg.setText("Logout menu");
    msg.exec();
}

void MainWindow::ExitMenuClicked() {
    QApplication::quit();
}

void MainWindow::SettingsMenuClicked() {
    QMessageBox msg;
    msg.setText("Settings menu");
    msg.exec();
}

void MainWindow::MainPageMenuClicked() {
    QMessageBox msg;
    msg.setText("Main page menu");
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