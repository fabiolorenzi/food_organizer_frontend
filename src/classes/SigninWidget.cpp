#include <QtWidgets/QMessageBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrlQuery>
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
    QLineEdit* usernameInput = this->ui.usernameInput;
    QLineEdit* emailInput = this->ui.emailInput;
    QLineEdit* passwordInput = this->ui.passwordInput;
    QLineEdit* reinsertPasswordInput = this->ui.reinsertPasswordInput;

    if ((*usernameInput).text().size() > 0 && (*emailInput).text().size() && (*passwordInput).text().size() > 0 && (*reinsertPasswordInput).text().size() > 0) {
        if ((*passwordInput).text() == (*reinsertPasswordInput).text()) {
            QNetworkAccessManager* manager = new QNetworkAccessManager(this);
            QUrl url("https://food-organizer-backend.hopto.org/api/v1/users");
            QNetworkRequest request(url);

            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
 
            QUrlQuery params;
            params.addQueryItem("username", (*usernameInput).text());
            params.addQueryItem("email", (*emailInput).text());
            params.addQueryItem("password", (*passwordInput).text());
            
            manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());

            QMessageBox msg;
            msg.setText("User created successfully");
            msg.exec();
            CancelButtonClicked();
        } else {
            QMessageBox msg;
            msg.setText("Passwords are not the same");
            msg.exec();
        };
    } else {
        QMessageBox msg;
        msg.setText("Inputs are invalid");
        msg.exec();
    };
}