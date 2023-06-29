#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
#include "SettingsWidget.h"

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

    QUrl url("https://food-organizer-backend.hopto.org/api/v1/users/1");
    QNetworkRequest request(url);

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