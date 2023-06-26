#include <QtWidgets/QMessageBox>
#include <QtDebug>
#include "LoginWidget.h"
#include "MainWindow.h"
#include "SigninWidget.h"

LoginWidget::LoginWidget(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);
}

LoginWidget::~LoginWidget() {
    delete this;
}

void LoginWidget::SigninButtonClicked() {
    MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
    SigninWidget* signinWidget = new SigninWidget();
    mainWindow->ChangeWidget(signinWidget);
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