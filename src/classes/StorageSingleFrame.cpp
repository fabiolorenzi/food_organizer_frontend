#include <QtWidgets/QMessageBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QUrlQuery>
#include <fstream>
#include <chrono>
#include <iostream>
#include "StorageSingleFrame.h"

int* singleStorageId = new int();

StorageSingleFrame::StorageSingleFrame(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);
}

StorageSingleFrame::~StorageSingleFrame() {
    delete this;
    delete singleStorageId;
}

void StorageSingleFrame::InitializeStorageSingleFrame(int _id, QString _name, QString _position, QString _quantity, QString _expire_date) {
    QLabel* nameValue = this->ui.NameValue;
    QLabel* positionValue = this->ui.PositionValue;
    QLabel* quantityValue = this->ui.QuantityValue;
    QLabel* expireDateValue = this->ui.ExpireDateValue;

    nameValue->setText(_name);
    positionValue->setText(_position);
    quantityValue->setText(_quantity);
    expireDateValue->setText(_expire_date);
    *singleStorageId = _id;
}

void StorageSingleFrame::DeleteButtonClicked() {
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &StorageSingleFrame::DeleteRequestFinished);

    std::ifstream authFile("build/auth.txt");
    std::string token;
    authFile >> token;
    QString QToken = QString::fromStdString("Bearer " + token);

    QUrl url("https://food-organizer-backend.hopto.org/api/v1/products/" + QString::number(*singleStorageId));
    QNetworkRequest request(url);

    request.setRawHeader(QByteArrayLiteral("Authorization"),QToken.toUtf8());

    manager->deleteResource(request);
}

void StorageSingleFrame::DeleteRequestFinished(QNetworkReply* reply) {
    QVariant responseStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    reply->deleteLater();

    QMessageBox msg;
    msg.setText("Please refresh the widget to update it.");
    msg.exec();
}