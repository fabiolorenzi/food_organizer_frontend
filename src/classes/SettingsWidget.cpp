#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QDebug>
#include <fstream>
#include <iostream>
#include "SettingsWidget.h"
#include "MainWindow.h"
#include "InitialWidget.h"

SettingsWidget::SettingsWidget(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);

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

SettingsWidget::~SettingsWidget() {
    delete this;
}

void SettingsWidget::CancelButtonClicked() {
    QMessageBox msg;
    msg.setText("cancel button");
    msg.exec();
}

void SettingsWidget::UpdateButtonClicked() {
    QMessageBox msg;
    msg.setText("update button");
    msg.exec();
}

void SettingsWidget::DeleteButtonClicked() {
    QMessageBox msg;
    msg.setText("delete button");
    msg.exec();
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
    };
}