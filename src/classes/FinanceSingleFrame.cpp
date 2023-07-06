#include <QtWidgets/QMessageBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QUrlQuery>
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