#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonValue>
#include <QtCore/QFile>
#include <QUrlQuery>
#include <QDebug>
#include <fstream>
#include <chrono>
#include <iostream>
#include "../functions/DateManager.h"
#include "WeeklyPlannerWidget.h"

int* currentDay = new int();
int* currentMonth = new int();
int* currentYear = new int();
int* nextDay = new int();
int* nextMonth = new int();
int* nextYear = new int();
bool* isCurrentPlan = new bool();

WeeklyPlannerWidget::WeeklyPlannerWidget(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);

    *currentDay = GetCurrentDay();
    *currentMonth = GetCurrentMonth();
    *currentYear = GetCurrentYear();
    *nextDay = GetNextDay();
    *nextMonth = GetNextMonth();
    *nextYear = GetNextYear();
    *isCurrentPlan = true;

    SwitchWeeklyPlanner(*isCurrentPlan);
    GetWeeklyPlan(*currentDay, *currentMonth, *currentYear);
}

WeeklyPlannerWidget::~WeeklyPlannerWidget() {
    delete this;
    delete currentYear;
    delete currentMonth;
    delete currentDay;
    delete nextDay;
    delete nextMonth;
    delete nextYear;
    delete isCurrentPlan;
}

void WeeklyPlannerWidget::CancelButtonClicked() {
    QMessageBox msg;
    msg.setText("Cancel button clicked");
    msg.exec();
}

void WeeklyPlannerWidget::SaveButtonClicked() {
    QMessageBox msg;
    msg.setText("Save button clicked");
    msg.exec();
}

void WeeklyPlannerWidget::WeekSelectorButtonClicked() {
    *isCurrentPlan = !*isCurrentPlan;
    SwitchWeeklyPlanner(*isCurrentPlan);
}

void WeeklyPlannerWidget::SwitchWeeklyPlanner(bool currentState) {
    QString formattedDay;
    QString formattedMonth;

    int day {};
    int month {};
    int year {};

    if (currentState) {
        day = *currentDay;
        month = *currentMonth;
        year = *currentYear;
    } else {
        day = *nextDay;
        month = *nextMonth;
        year = *nextYear;
    };

    if (day < 10) {
        formattedDay = "0" + QString::number(day);
    } else {
        formattedDay = QString::number(day);
    };

    if (month < 10) {
        formattedMonth = "0" + QString::number(month);
    } else {
        formattedMonth = QString::number(month);
    };

    QLabel* dateLabel = this->ui.WeekPlanDate;
    (*dateLabel).setText("This week plan start the " + formattedDay + "/" + formattedMonth + "/" + QString::number(year));
}

void WeeklyPlannerWidget::GetWeeklyPlan(int day, int month, int year) {
    QLabel* mondayBLabel = this->ui.MondayB;
    QLabel* mondayLLabel = this->ui.MondayL;
    QLabel* mondayDLabel = this->ui.MondayD;
    QLabel* tuesdayBLabel = this->ui.TuesdayB;
    QLabel* tuesdayLLabel = this->ui.TuesdayL;
    QLabel* tuesdayDLabel = this->ui.TuesdayD;
    QLabel* wednesdayBLabel = this->ui.WednesdayB;
    QLabel* wednesdayLLabel = this->ui.WednesdayL;
    QLabel* wednesdayDLabel = this->ui.WednesdayD;
    QLabel* thursdayBLabel = this->ui.ThursdayB;
    QLabel* thursdayLLabel = this->ui.ThursdayL;
    QLabel* thursdayDLabel = this->ui.ThursdayD;
    QLabel* fridayBLabel = this->ui.FridayB;
    QLabel* fridayLLabel = this->ui.FridayL;
    QLabel* fridayDLabel = this->ui.FridayD;
    QLabel* saturdayBLabel = this->ui.SaturdayB;
    QLabel* saturdayLLabel = this->ui.SaturdayL;
    QLabel* saturdayDLabel = this->ui.SaturdayD;
    QLabel* sundayBLabel = this->ui.SundayB;
    QLabel* sundayLLabel = this->ui.SundayL;
    QLabel* sundayDLabel = this->ui.SundayD;
    QPushButton* cancelButton = this->ui.CancelButton;

    mondayBLabel->setText("Loading...");
    mondayLLabel->setText("Loading...");
    mondayDLabel->setText("Loading...");
    tuesdayBLabel->setText("Loading...");
    tuesdayLLabel->setText("Loading...");
    tuesdayDLabel->setText("Loading...");
    wednesdayBLabel->setText("Loading...");
    wednesdayLLabel->setText("Loading...");
    wednesdayDLabel->setText("Loading...");
    thursdayBLabel->setText("Loading...");
    thursdayLLabel->setText("Loading...");
    thursdayDLabel->setText("Loading...");
    fridayBLabel->setText("Loading...");
    fridayLLabel->setText("Loading...");
    fridayDLabel->setText("Loading...");
    saturdayBLabel->setText("Loading...");
    saturdayLLabel->setText("Loading...");
    saturdayDLabel->setText("Loading...");
    sundayBLabel->setText("Loading...");
    sundayLLabel->setText("Loading...");
    sundayDLabel->setText("Loading...");
    cancelButton->setText("Loading...");

    QString formattedDay;
    QString formattedMonth;

    if (day < 10) {
        formattedDay = "0" + QString::number(day);
    } else {
        formattedDay = QString::number(day);
    };

    if (month < 10) {
        formattedMonth = "0" + QString::number(month);
    } else {
        formattedMonth = QString::number(month);
    };

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &WeeklyPlannerWidget::GetRequestFinished);

    std::ifstream authFile("build/auth.txt");
    std::string token;
    authFile >> token;
    QString QToken = QString::fromStdString("Bearer " + token);

    QString dateString = QString::number(year) + "-" + formattedMonth + "-" + formattedDay;

    QUrl url("https://food-organizer-backend.hopto.org/api/v1/week-plans?min_date=" + dateString + "&max_date=" + dateString);
    QNetworkRequest request(url);

    request.setRawHeader(QByteArrayLiteral("Authorization"),QToken.toUtf8());

    manager->get(request);
}

void WeeklyPlannerWidget::GetRequestFinished(QNetworkReply* reply) {
    QByteArray responseData = reply->readAll();
    QVariant responseStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    /*QLabel* mondayBLabel = this->ui.MondayB;
    QLabel* mondayLLabel = this->ui.MondayL;
    QLabel* mondayDLabel = this->ui.MondayD;
    QLabel* tuesdayBLabel = this->ui.TuesdayB;
    QLabel* tuesdayLLabel = this->ui.TuesdayL;
    QLabel* tuesdayDLabel = this->ui.TuesdayD;
    QLabel* wednesdayBLabel = this->ui.WednesdayB;
    QLabel* wednesdayLLabel = this->ui.WednesdayL;
    QLabel* wednesdayDLabel = this->ui.WednesdayD;
    QLabel* thursdayBLabel = this->ui.ThursdayB;
    QLabel* thursdayLLabel = this->ui.ThursdayL;
    QLabel* thursdayDLabel = this->ui.ThursdayD;
    QLabel* fridayBLabel = this->ui.FridayB;
    QLabel* fridayLLabel = this->ui.FridayL;
    QLabel* fridayDLabel = this->ui.FridayD;
    QLabel* saturdayBLabel = this->ui.SaturdayB;
    QLabel* saturdayLLabel = this->ui.SaturdayL;
    QLabel* saturdayDLabel = this->ui.SaturdayD;
    QLabel* sundayBLabel = this->ui.SundayB;
    QLabel* sundayLLabel = this->ui.SundayL;
    QLabel* sundayDLabel = this->ui.SundayD;
    QPushButton* cancelButton = this->ui.CancelButton;*/
}