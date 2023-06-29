#include <QtWidgets/QMessageBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QBuffer>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QFile>
#include <QUrlQuery>
#include <fstream>
#include <iostream>
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
    QLineEdit* emailValue = this->ui.emailInput;
    QLineEdit* passwordValue = this->ui.passwordInput;

    if ((*emailValue).text().size() && (*passwordValue).text().size()) {
        QPushButton* button = this->ui.LoginButton;
        (*button).setText("Loading...");

        QNetworkAccessManager* manager = new QNetworkAccessManager(this);
        connect(manager, &QNetworkAccessManager::finished, this, &LoginWidget::PatchRequestFinished);

        QUrl url("https://food-organizer-backend.hopto.org/api/v1/users/login");
        QNetworkRequest request(url);

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        QUrlQuery params;
        params.addQueryItem("email", (*emailValue).text());
        params.addQueryItem("password", (*passwordValue).text());

        QBuffer* buffer = new QBuffer();
        buffer->open((QBuffer::ReadWrite));
        buffer->write(params.toString(QUrl::FullyEncoded).toUtf8());
        buffer->seek(0);
        manager->sendCustomRequest(request, "PATCH", buffer);
    } else {
        QMessageBox msg;
        msg.setText("Inputs are invalid");
        msg.exec();
    };
}

void LoginWidget::PatchRequestFinished(QNetworkReply* reply) {
    QByteArray responseData = reply->readAll();
    QVariant responseStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    QJsonDocument json = QJsonDocument::fromJson(responseData);
    QJsonObject replyObject = json.object();
    reply->deleteLater();

    if (responseStatus == 403) {
        QMessageBox msg;
        msg.setText("Wrong password");
        msg.exec();
    } else if (responseStatus == 404) {
        QMessageBox msg;
        msg.setText("User not found");
        msg.exec();
    } else {
        QString token = replyObject.value("token").toString();
        QFile authFile("build/auth.txt");
        if (authFile.open(QIODevice::WriteOnly)) {
            QTextStream out(&authFile);
            out << token;
            authFile.close();
        };

        QMessageBox msg;
        msg.setText("Login successfully");
        msg.exec();
        CancelButtonClicked();
    };

    QPushButton* button = this->ui.LoginButton;
    (*button).setText("Login");
}