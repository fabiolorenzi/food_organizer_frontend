#include <QtWidgets/QMessageBox>
#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    ui.setupUi(this);

    // The code below is to access an item from the GUI
    // and then to disable it
    QAction* loginButton = this->ui.actionLogin;
    (*loginButton).setEnabled(false);
}

MainWindow::~MainWindow() {
    delete this;
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