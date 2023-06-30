#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonValue>
#include <QtCore/QFile>
#include <QUrlQuery>
#include <QDebug>
#include <fstream>
#include <iostream>
#include "SettingsWidget.h"
#include "MainWindow.h"
#include "InitialWidget.h"

int* user_id = new int();

SettingsWidget::SettingsWidget(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);
    GetUserByToken();
}

SettingsWidget::~SettingsWidget() {
    delete user_id;
    delete this;
}

void SettingsWidget::CancelButtonClicked() {
    GetUserByToken();
}

void SettingsWidget::UpdateButtonClicked() {
    QLineEdit* usernameInput = this->ui.usernameInput;
    QLineEdit* emailInput = this->ui.emailInput;
    QLineEdit* passwordInput = this->ui.passwordInput;
    QLineEdit* reinsertPasswordInput = this->ui.reinsertPasswordInput;

    if ((*passwordInput).text() == (*reinsertPasswordInput).text()) {
        QLabel* emailLabel = this->ui.EmailLabel;
        QLabel* usernameLabel = this->ui.usernameLabel;
        QLabel* passwordLabel = this->ui.PasswordLabel;
        QLabel* reinsertPasswordLabel = this->ui.ReinsertPasswordLabel;
        QPushButton* updateButton = this->ui.updateButton;

        emailLabel->setText("Updating...");
        usernameLabel->setText("Updating...");
        passwordLabel->setText("Updating...");
        reinsertPasswordLabel->setText("Updating...");
        updateButton->setText("Updating...");

        QNetworkAccessManager* manager = new QNetworkAccessManager(this);
        connect(manager, &QNetworkAccessManager::finished, this, &SettingsWidget::PutRequestFinished);

        std::ifstream authFile("build/auth.txt");
        std::string token;
        authFile >> token;
        QString QToken = QString::fromStdString("Bearer " + token);

        QUrl url("https://food-organizer-backend.hopto.org/api/v1/users/" + QString::number(*user_id));
        QNetworkRequest request(url);

        request.setRawHeader(QByteArrayLiteral("Authorization"),QToken.toUtf8());

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    
        QUrlQuery params;
        params.addQueryItem("username", (*usernameInput).text());
        params.addQueryItem("email", (*emailInput).text());
        params.addQueryItem("password", (*passwordInput).text());

        manager->put(request, params.toString(QUrl::FullyEncoded).toUtf8());
    } else {
        QMessageBox msg;
        msg.setText("Passwords are not the same");
        msg.exec();
    };
}

void SettingsWidget::DeleteButtonClicked() {
    QMessageBox msg;
    msg.setText("delete button");
    msg.exec();
}

void SettingsWidget::GetUserByToken() {
    QLabel* emailLabel = this->ui.EmailLabel;
    QLabel* usernameLabel = this->ui.usernameLabel;
    QLabel* passwordLabel = this->ui.PasswordLabel;
    QLabel* reinsertPasswordLabel = this->ui.ReinsertPasswordLabel;

    emailLabel->setText("Loading...");
    usernameLabel->setText("Loading...");
    passwordLabel->setText("Loading...");
    reinsertPasswordLabel->setText("Loading...");

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &SettingsWidget::GetRequestFinished);

    std::ifstream authFile("build/auth.txt");
    std::string token;
    authFile >> token;
    QString QToken = QString::fromStdString("Bearer " + token);

    QUrl url("https://food-organizer-backend.hopto.org/api/v1/users/user");
    QNetworkRequest request(url);

    request.setRawHeader(QByteArrayLiteral("Authorization"),QToken.toUtf8());

    manager->get(request);
}

void SettingsWidget::GetRequestFinished(QNetworkReply* reply) {
    QByteArray responseData = reply->readAll();
    QVariant responseStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    QJsonDocument json = QJsonDocument::fromJson(responseData);
    QJsonObject replyObject = json.object();
    reply->deleteLater();

    if (responseStatus == 403 || responseStatus == 500) {
        QMessageBox msg;
        msg.setText("Unauthorized, you will be logged out");
        msg.exec();
        remove("build/auth.txt");

        MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
        InitialWidget* initialWidget = new InitialWidget();
        mainWindow->ChangeWidget(initialWidget);
    } else {
        QLabel* emailLabel = this->ui.EmailLabel;
        QLabel* usernameLabel = this->ui.usernameLabel;
        QLabel* passwordLabel = this->ui.PasswordLabel;
        QLabel* reinsertPasswordLabel = this->ui.ReinsertPasswordLabel;
        QLineEdit* emailInput = this->ui.emailInput;
        QLineEdit* usernameInput = this->ui.usernameInput;
        QLineEdit* passwordInput = this->ui.passwordInput;
        QLineEdit* reinsertPasswordInput = this->ui.reinsertPasswordInput;

        emailLabel->setText("Email");
        usernameLabel->setText("Username");
        passwordLabel->setText("Password");
        reinsertPasswordLabel->setText("Reinsert password");
        emailInput->setText(replyObject.value("email").toString());
        usernameInput->setText(replyObject.value("username").toString());
        passwordInput->setText(replyObject.value("password").toString());
        reinsertPasswordInput->setText(replyObject.value("password").toString());

        *user_id = replyObject.value("id").toInt();
    };
}

void SettingsWidget::PutRequestFinished(QNetworkReply* reply) {
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
        msg.setText("User updated successfully");
        msg.exec();
        QString token = replyObject.value("token").toString();
        QFile authFile("build/auth.txt");
        if (authFile.open(QIODevice::WriteOnly)) {
            QTextStream out(&authFile);
            out << token;
            authFile.close();
        };
        CancelButtonClicked();
    };

    QLabel* emailLabel = this->ui.EmailLabel;
    QLabel* usernameLabel = this->ui.usernameLabel;
    QLabel* passwordLabel = this->ui.PasswordLabel;
    QLabel* reinsertPasswordLabel = this->ui.ReinsertPasswordLabel;
    QPushButton* updateButton = this->ui.updateButton;

    emailLabel->setText("Email");
    usernameLabel->setText("Username");
    passwordLabel->setText("Password");
    reinsertPasswordLabel->setText("Reinsert password");
    updateButton->setText("Update");
};