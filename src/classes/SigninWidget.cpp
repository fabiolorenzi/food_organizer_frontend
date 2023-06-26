#include <QtWidgets/QMessageBox>
#include <QtDebug>
#include "SigninWidget.h"
#include "MainWindow.h"
#include "LoginWidget.h"

SigninWidget::SigninWidget(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);
}

SigninWidget::~SigninWidget() {
    delete this;
}

void SigninWidget::LoginButtonClicked() {
    MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
    LoginWidget* loginWidget = new LoginWidget();
    mainWindow->ChangeWidget(loginWidget);
}

void SigninWidget::CancelButtonClicked() {
    QLineEdit* usernameInput = this->ui.usernameInput;
    QLineEdit* emailInput = this->ui.emailInput;
    QLineEdit* passwordInput = this->ui.passwordInput;
    QLineEdit* reinsertPasswordInput = this->ui.reinsertPasswordInput;

    (*usernameInput).setText("");
    (*emailInput).setText("");
    (*passwordInput).setText("");
    (*reinsertPasswordInput).setText("");
}

void SigninWidget::SigninButtonClicked() {
    QMessageBox msg;
    msg.setText("Signin button");
    msg.exec();
}