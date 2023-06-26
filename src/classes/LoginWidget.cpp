#include <QtWidgets/QMessageBox>
#include "LoginWidget.h"

LoginWidget::LoginWidget(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);
}

LoginWidget::~LoginWidget() {
    delete this;
}

void LoginWidget::SigninButtonClicked() {
    QMessageBox msg;
    msg.setText("Signin page");
    msg.exec();
}

void LoginWidget::CancelButtonClicked() {
    QMessageBox msg;
    msg.setText("Cancel function");
    msg.exec();
}

void LoginWidget::LoginButtonClicked() {
    QMessageBox msg;
    msg.setText("Login function");
    msg.exec();
}