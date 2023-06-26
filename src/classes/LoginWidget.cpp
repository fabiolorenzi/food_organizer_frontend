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
    QLineEdit* emailInput = this->ui.emailInput;
    QLineEdit* passwordInput = this->ui.passwordInput;
    (*emailInput).setText("");
    (*passwordInput).setText("");
}

void LoginWidget::LoginButtonClicked() {
    QMessageBox msg;
    msg.setText("Login function");
    msg.exec();
}