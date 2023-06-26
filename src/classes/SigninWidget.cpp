#include <QtWidgets/QMessageBox>
#include <QtDebug>
#include "SigninWidget.h"

SigninWidget::SigninWidget(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);
}

SigninWidget::~SigninWidget() {
    delete this;
}

void SigninWidget::LoginButtonClicked() {
    QMessageBox msg;
    msg.setText("Login page");
    msg.exec();
}

void SigninWidget::CancelButtonClicked() {
    QMessageBox msg;
    msg.setText("Cancel clicked");
    msg.exec();
}

void SigninWidget::SigninButtonClicked() {
    QMessageBox msg;
    msg.setText("Signin button");
    msg.exec();
}