#include <QtWidgets/QMessageBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include <QUrlQuery>
#include <fstream>
#include <chrono>
#include <iostream>
#include "FinancesWidget.h"
#include "FinanceSingleFrame.h"

FinancesWidget::FinancesWidget(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);
    GetFinancesData();
}

FinancesWidget::~FinancesWidget() {
    delete this;
}

void FinancesWidget::CancelButtonClicked() {
    QLineEdit* titleInput = this->ui.TitleInput;
    QLineEdit* descriptionInput = this->ui.DescriptionInput;
    QLineEdit* priceInput = this->ui.PriceInput;
    QLineEdit* dateInput = this->ui.DateInput;

    (*titleInput).setText("");
    (*descriptionInput).setText("");
    (*priceInput).setText("");
    (*dateInput).setText("");
}

void FinancesWidget::CreateButtonClicked() {
    QLineEdit* titleInput = this->ui.TitleInput;
    QLineEdit* descriptionInput = this->ui.DescriptionInput;
    QLineEdit* priceInput = this->ui.PriceInput;
    QLineEdit* dateInput = this->ui.DateInput;

    if ((*titleInput).text().size() > 0 && (*descriptionInput).text().size() && (*priceInput).text().size() > 0 && (*dateInput).text().size() > 0) {
        QPushButton* button = this->ui.CreateButton;
        (*button).setText("Loading...");

        QNetworkAccessManager* manager = new QNetworkAccessManager(this);
        connect(manager, &QNetworkAccessManager::finished, this, &FinancesWidget::PostRequestFinished);

        QUrl url("https://food-organizer-backend.hopto.org/api/v1/expenses");
        QNetworkRequest request(url);

        std::ifstream authFile("build/auth.txt");
        std::string token;
        authFile >> token;
        QString QToken = QString::fromStdString("Bearer " + token);

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        request.setRawHeader(QByteArrayLiteral("Authorization"),QToken.toUtf8());

        QUrlQuery params;
        params.addQueryItem("title", (*titleInput).text());
        params.addQueryItem("description", (*descriptionInput).text());
        params.addQueryItem("currency", "£");
        params.addQueryItem("price", (*priceInput).text());
        params.addQueryItem("shopping_date", (*dateInput).text());
        
        manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());
    } else {
        QMessageBox msg;
        msg.setText("Inputs are invalid");
        msg.exec();
    };
}

void FinancesWidget::PostRequestFinished(QNetworkReply* reply) {
    QByteArray response_data = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response_data);
    QJsonObject replyObject = json.object();
    reply->deleteLater();

    if (replyObject.value("status") == 400) {
        QMessageBox msg;
        msg.setText("Expense creation failed. Please try again");
        msg.exec();
    } else {
        QMessageBox msg;
        msg.setText("Expense created successfully");
        msg.exec();
        CancelButtonClicked();
    };

    QPushButton* button = this->ui.CreateButton;
    (*button).setText("Create");

    QMessageBox msg;
    msg.setText("Please refresh the widget to update it.");
    msg.exec();
}

void FinancesWidget::GetFinancesData() {
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &FinancesWidget::GetRequestFinished);

    std::ifstream authFile("build/auth.txt");
    std::string token;
    authFile >> token;
    QString QToken = QString::fromStdString("Bearer " + token);

    QUrl url("https://food-organizer-backend.hopto.org/api/v1/expenses");
    QNetworkRequest request(url);

    request.setRawHeader(QByteArrayLiteral("Authorization"),QToken.toUtf8());

    manager->get(request);
}

void FinancesWidget::GetRequestFinished(QNetworkReply* reply) {
    QByteArray responseData = reply->readAll();
    QVariant responseStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    QJsonDocument json = QJsonDocument::fromJson(responseData);

    reply->deleteLater();

    QJsonArray jsonArray = json.array();
    QWidget* listArray = this->ui.ListFrameLine;
    QVBoxLayout* listArrayLayout = new QVBoxLayout();

    for (int x {}; x < jsonArray.size(); ++x) {
        QJsonValue singleJson = jsonArray[x];
        double price = singleJson["price"].toDouble();
        FinanceSingleFrame* singleFinance = new FinanceSingleFrame();
        singleFinance->InitializeFinanceSingleFrame(singleJson["id"].toInt(), singleJson["title"].toString(), singleJson["description"].toString(), QString::number(price), singleJson["shopping_date"].toString());
        listArrayLayout->addWidget(singleFinance);
    };

    listArray->setLayout(listArrayLayout);
}