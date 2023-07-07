#include <QtWidgets/QMessageBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QUrlQuery>
#include <fstream>
#include <chrono>
#include <iostream>
#include "FinanceSingleFrame.h"

int* singleFinanceId = new int();

FinanceSingleFrame::FinanceSingleFrame(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);
}

FinanceSingleFrame::~FinanceSingleFrame() {
    delete this;
    delete singleFinanceId;
}

void FinanceSingleFrame::InitializeFinanceSingleFrame(int _id, QString _title, QString _desc, QString _price, QString _date) {
    QLabel* titleValue = this->ui.TitleValue;
    QLabel* descriptionValue = this->ui.DescriptionValue;
    QLabel* priceValue = this->ui.PriceValue;
    QLabel* dateValue = this->ui.DateValue;

    titleValue->setText(_title);
    descriptionValue->setText(_desc);
    priceValue->setText(_price);
    dateValue->setText(_date);
    *singleFinanceId = _id;
}

void FinanceSingleFrame::DeleteButtonClicked() {
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &FinanceSingleFrame::DeleteRequestFinished);

    std::ifstream authFile("build/auth.txt");
    std::string token;
    authFile >> token;
    QString QToken = QString::fromStdString("Bearer " + token);

    QUrl url("https://food-organizer-backend.hopto.org/api/v1/expenses/" + QString::number(*singleFinanceId));
    QNetworkRequest request(url);

    request.setRawHeader(QByteArrayLiteral("Authorization"),QToken.toUtf8());

    manager->deleteResource(request);
}

void FinanceSingleFrame::DeleteRequestFinished(QNetworkReply* reply) {
    QVariant responseStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    reply->deleteLater();

    QMessageBox msg;
    if (responseStatus == 403 || responseStatus == 500) {
        msg.setText("Unauthorized");
    } else {
        msg.setText("Finance data deleted successfully");
    };
}