#include <QtWidgets/QMessageBox>
#include <QtDebug>
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
    QString emailValue = this->ui.emailInput->text();
    QString passwordValue = this->ui.passwordInput->text();

    // The code below is to debug, like a console.log for Qt
    //qDebug() << emailValue;
}