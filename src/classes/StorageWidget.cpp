#include <QtWidgets/QMessageBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include <QUrlQuery>
#include <fstream>
#include <chrono>
#include <iostream>
#include "StorageWidget.h"
//#include "StorageSingleFrame.h"

StorageWidget::StorageWidget(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);
    GetStorageData();
}

StorageWidget::~StorageWidget() {
    delete this;
}

void StorageWidget::CancelButtonClicked() {
    QLineEdit* nameInput = this->ui.NameInput;
    QLineEdit* positionInput = this->ui.PositionInput;
    QLineEdit* quantityInput = this->ui.QuantityInput;
    QLineEdit* expireDateInput = this->ui.ExpireDateInput;

    (*nameInput).setText("");
    (*positionInput).setText("");
    (*quantityInput).setText("");
    (*expireDateInput).setText("");
}

void StorageWidget::CreateButtonClicked() {
    QLineEdit* nameInput = this->ui.NameInput;
    QLineEdit* positionInput = this->ui.PositionInput;
    QLineEdit* quantityInput = this->ui.QuantityInput;
    QLineEdit* expireDateInput = this->ui.ExpireDateInput;

    if ((*nameInput).text().size() > 0 && (*positionInput).text().size() && (*quantityInput).text().size() > 0 && (*expireDateInput).text().size() > 0) {
        QPushButton* button = this->ui.CreateButton;
        (*button).setText("Loading...");

        QNetworkAccessManager* manager = new QNetworkAccessManager(this);
        connect(manager, &QNetworkAccessManager::finished, this, &StorageWidget::PostRequestFinished);

        QUrl url("https://food-organizer-backend.hopto.org/api/v1/products");
        QNetworkRequest request(url);

        std::ifstream authFile("build/auth.txt");
        std::string token;
        authFile >> token;
        QString QToken = QString::fromStdString("Bearer " + token);

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        request.setRawHeader(QByteArrayLiteral("Authorization"),QToken.toUtf8());

        QUrlQuery params;
        params.addQueryItem("name", (*nameInput).text());
        params.addQueryItem("position", (*positionInput).text());
        params.addQueryItem("expire_date", (*expireDateInput).text());
        params.addQueryItem("remaining", (*quantityInput).text());
        params.addQueryItem("measure_unit", "kg");
        params.addQueryItem("quantity_alarm", 0);
        params.addQueryItem("quantity_alarm_threshold", 0);
        
        manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());
    } else {
        QMessageBox msg;
        msg.setText("Inputs are invalid");
        msg.exec();
    };
}

void StorageWidget::PostRequestFinished(QNetworkReply* reply) {
    QByteArray response_data = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response_data);
    QJsonObject replyObject = json.object();
    reply->deleteLater();

    if (replyObject.value("status") == 400) {
        QMessageBox msg;
        msg.setText("Storage product creation failed. Please try again");
        msg.exec();
    } else {
        QMessageBox msg;
        msg.setText("Storage product created successfully");
        msg.exec();
        CancelButtonClicked();
    };

    QPushButton* button = this->ui.CreateButton;
    (*button).setText("Create");

    QMessageBox msg;
    msg.setText("Please refresh the widget to update it.");
    msg.exec();
}

void StorageWidget::GetStorageData() {
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &StorageWidget::GetRequestFinished);

    std::ifstream authFile("build/auth.txt");
    std::string token;
    authFile >> token;
    QString QToken = QString::fromStdString("Bearer " + token);

    QUrl url("https://food-organizer-backend.hopto.org/api/v1/products");
    QNetworkRequest request(url);

    request.setRawHeader(QByteArrayLiteral("Authorization"),QToken.toUtf8());

    manager->get(request);
}

void StorageWidget::GetRequestFinished(QNetworkReply* reply) {
    QByteArray responseData = reply->readAll();
    QVariant responseStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    QJsonDocument json = QJsonDocument::fromJson(responseData);

    reply->deleteLater();

    /*QJsonArray jsonArray = json.array();
    QWidget* listArray = this->ui.ListFrameLine;
    QVBoxLayout* listArrayLayout = new QVBoxLayout();

    for (int x {}; x < jsonArray.size(); ++x) {
        QJsonValue singleJson = jsonArray[x];
        double price = singleJson["price"].toDouble();
        FinanceSingleFrame* singleFinance = new FinanceSingleFrame();
        singleFinance->InitializeFinanceSingleFrame(singleJson["id"].toInt(), singleJson["title"].toString(), singleJson["description"].toString(), QString::number(price), singleJson["shopping_date"].toString());
        listArrayLayout->addWidget(singleFinance);
    };

    listArray->setLayout(listArrayLayout);*/
}