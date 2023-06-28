#include <QtWidgets/QMessageBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
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
            connect(manager, &QNetworkAccessManager::finished, this, &SigninWidget::PostRequestFinished);

            QUrl url("https://food-organizer-backend.hopto.org/api/v1/users");
            QNetworkRequest request(url);

            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
 
            QUrlQuery params;
            params.addQueryItem("username", (*usernameInput).text());
            params.addQueryItem("email", (*emailInput).text());
            params.addQueryItem("password", (*passwordInput).text());
            
            manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());
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

void SigninWidget::PostRequestFinished(QNetworkReply* reply) {
    QByteArray response_data = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response_data);
    QJsonObject replyObject = json.object();
    reply->deleteLater();

    if (replyObject.value("status") == 400) {
        QMessageBox msg;
        msg.setText("The email must be unique");
        msg.exec();
    } else {
        QMessageBox msg;
        msg.setText("User created successfully");
        msg.exec();
        CancelButtonClicked();
    };
}