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
#include "MainWindow.h"
#include "InitialWidget.h"

int* currentDay = new int();
int* currentMonth = new int();
int* currentYear = new int();
int* currentPlanId = new int();
int* nextDay = new int();
int* nextMonth = new int();
int* nextYear = new int();
int* nextPlanId = new int();
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
    delete currentPlanId;
    delete nextDay;
    delete nextMonth;
    delete nextYear;
    delete nextPlanId;
    delete isCurrentPlan;
}

void WeeklyPlannerWidget::CancelButtonClicked() {
    if (*isCurrentPlan) {
        GetWeeklyPlan(*currentDay, *currentMonth, *currentYear);
    } else {
        GetWeeklyPlan(*nextDay, *nextMonth, *nextYear);
    };
}

void WeeklyPlannerWidget::SaveButtonClicked() {
    if ((*isCurrentPlan && *currentPlanId > 0) || (!*isCurrentPlan && *nextPlanId > 0)) {
        QMessageBox msg;
        msg.setText("Save button clicked");
        msg.exec();
    } else {
        CreateWeeklyPlan();
    };
}

void WeeklyPlannerWidget::WeekSelectorButtonClicked() {
    *isCurrentPlan = !*isCurrentPlan;
    SwitchWeeklyPlanner(*isCurrentPlan);
    if (*isCurrentPlan) {
        GetWeeklyPlan(*currentDay, *currentMonth, *currentYear);
    } else {
        GetWeeklyPlan(*nextDay, *nextMonth, *nextYear);
    };
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

void WeeklyPlannerWidget::CreateWeeklyPlan() {
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
    QPushButton* saveButton = this->ui.SaveButton;
    QPushButton* weekSelectorButton = this->ui.WeekSelectorButton;
    QLineEdit* mondayBInput = this->ui.MondayBInput;
    QLineEdit* mondayLInput = this->ui.MondayLInput;
    QLineEdit* mondayDInput = this->ui.MondayDInput;
    QLineEdit* tuesdayBInput = this->ui.TuesdayBInput;
    QLineEdit* tuesdayLInput = this->ui.TuesdayLInput;
    QLineEdit* tuesdayDInput = this->ui.TuesdayDInput;
    QLineEdit* wednesdayBInput = this->ui.WednesdayBInput;
    QLineEdit* wednesdayLInput = this->ui.WednesdayLInput;
    QLineEdit* wednesdayDInput = this->ui.WednesdayDInput;
    QLineEdit* thursdayBInput = this->ui.ThursdayBInput;
    QLineEdit* thursdayLInput = this->ui.ThursdayLInput;
    QLineEdit* thursdayDInput = this->ui.ThursdayDInput;
    QLineEdit* fridayBInput = this->ui.FridayBInput;
    QLineEdit* fridayLInput = this->ui.FridayLInput;
    QLineEdit* fridayDInput = this->ui.FridayDInput;
    QLineEdit* saturdayBInput = this->ui.SaturdayBInput;
    QLineEdit* saturdayLInput = this->ui.SaturdayLInput;
    QLineEdit* saturdayDInput = this->ui.SaturdayDInput;
    QLineEdit* sundayBInput = this->ui.SundayBInput;
    QLineEdit* sundayLInput = this->ui.SundayLInput;
    QLineEdit* sundayDInput = this->ui.SundayDInput;

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
    saveButton->setText("Loading...");

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &WeeklyPlannerWidget::PostRequestFinished);

    QUrl url("https://food-organizer-backend.hopto.org/api/v1/week-plans");
    QNetworkRequest request(url);

    std::ifstream authFile("build/auth.txt");
    std::string token;
    authFile >> token;
    QString QToken = QString::fromStdString("Bearer " + token);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader(QByteArrayLiteral("Authorization"),QToken.toUtf8());

    QString formattedDay;
    QString formattedMonth;

    int day {};
    int month {};
    int year {};

    if (*isCurrentPlan) {
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

    QUrlQuery params;
    params.addQueryItem("monday_breakfast", (*mondayBInput).text());
    params.addQueryItem("monday_lunch", (*mondayLInput).text());
    params.addQueryItem("monday_dinner", (*mondayDInput).text());
    params.addQueryItem("tuesday_breakfast", (*tuesdayBInput).text());
    params.addQueryItem("tuesday_lunch", (*tuesdayLInput).text());
    params.addQueryItem("tuesday_dinner", (*tuesdayDInput).text());
    params.addQueryItem("wednesday_breakfast", (*wednesdayBInput).text());
    params.addQueryItem("wednesday_lunch", (*wednesdayLInput).text());
    params.addQueryItem("wednesday_dinner", (*wednesdayDInput).text());
    params.addQueryItem("thursday_breakfast", (*thursdayBInput).text());
    params.addQueryItem("thursday_lunch", (*thursdayLInput).text());
    params.addQueryItem("thursday_dinner", (*thursdayDInput).text());
    params.addQueryItem("friday_breakfast", (*fridayBInput).text());
    params.addQueryItem("friday_lunch", (*fridayLInput).text());
    params.addQueryItem("friday_dinner", (*fridayDInput).text());
    params.addQueryItem("saturday_breakfast", (*saturdayBInput).text());
    params.addQueryItem("saturday_lunch", (*saturdayLInput).text());
    params.addQueryItem("saturday_dinner", (*saturdayDInput).text());
    params.addQueryItem("sunday_breakfast", (*sundayBInput).text());
    params.addQueryItem("sunday_lunch", (*sundayLInput).text());
    params.addQueryItem("sunday_dinner", (*sundayDInput).text());
    params.addQueryItem("monday_position", formattedDay + "-" + formattedMonth + "-" + QString::number(year));

    manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());
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
    QPushButton* saveButton = this->ui.SaveButton;
    QPushButton* weekSelectorButton = this->ui.WeekSelectorButton;
    QLineEdit* mondayBInput = this->ui.MondayBInput;
    QLineEdit* mondayLInput = this->ui.MondayLInput;
    QLineEdit* mondayDInput = this->ui.MondayDInput;
    QLineEdit* tuesdayBInput = this->ui.TuesdayBInput;
    QLineEdit* tuesdayLInput = this->ui.TuesdayLInput;
    QLineEdit* tuesdayDInput = this->ui.TuesdayDInput;
    QLineEdit* wednesdayBInput = this->ui.WednesdayBInput;
    QLineEdit* wednesdayLInput = this->ui.WednesdayLInput;
    QLineEdit* wednesdayDInput = this->ui.WednesdayDInput;
    QLineEdit* thursdayBInput = this->ui.ThursdayBInput;
    QLineEdit* thursdayLInput = this->ui.ThursdayLInput;
    QLineEdit* thursdayDInput = this->ui.ThursdayDInput;
    QLineEdit* fridayBInput = this->ui.FridayBInput;
    QLineEdit* fridayLInput = this->ui.FridayLInput;
    QLineEdit* fridayDInput = this->ui.FridayDInput;
    QLineEdit* saturdayBInput = this->ui.SaturdayBInput;
    QLineEdit* saturdayLInput = this->ui.SaturdayLInput;
    QLineEdit* saturdayDInput = this->ui.SaturdayDInput;
    QLineEdit* sundayBInput = this->ui.SundayBInput;
    QLineEdit* sundayLInput = this->ui.SundayLInput;
    QLineEdit* sundayDInput = this->ui.SundayDInput;

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
    saveButton->setText("Loading...");
    weekSelectorButton->setText("Loading...");
    mondayBInput->setText("");
    mondayLInput->setText("");
    mondayDInput->setText("");
    tuesdayBInput->setText("");
    tuesdayLInput->setText("");
    tuesdayDInput->setText("");
    wednesdayBInput->setText("");
    wednesdayLInput->setText("");
    wednesdayDInput->setText("");
    thursdayBInput->setText("");
    thursdayLInput->setText("");
    thursdayDInput->setText("");
    fridayBInput->setText("");
    fridayLInput->setText("");
    fridayDInput->setText("");
    saturdayBInput->setText("");
    saturdayLInput->setText("");
    saturdayDInput->setText("");
    sundayBInput->setText("");
    sundayLInput->setText("");
    sundayDInput->setText("");

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

    QJsonDocument json = QJsonDocument::fromJson(responseData);

    if (responseStatus == 403 || responseStatus == 500) {
        QMessageBox msg;
        msg.setText("Unauthorized, you will be logged out");
        msg.exec();
        remove("build/auth.txt");

        MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
        InitialWidget* initialWidget = new InitialWidget();
        mainWindow->ChangeWidget(initialWidget);
    } else {
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
        QPushButton* saveButton = this->ui.SaveButton;
        QPushButton* weekSelectorButton = this->ui.WeekSelectorButton;
        QLineEdit* mondayBInput = this->ui.MondayBInput;
        QLineEdit* mondayLInput = this->ui.MondayLInput;
        QLineEdit* mondayDInput = this->ui.MondayDInput;
        QLineEdit* tuesdayBInput = this->ui.TuesdayBInput;
        QLineEdit* tuesdayLInput = this->ui.TuesdayLInput;
        QLineEdit* tuesdayDInput = this->ui.TuesdayDInput;
        QLineEdit* wednesdayBInput = this->ui.WednesdayBInput;
        QLineEdit* wednesdayLInput = this->ui.WednesdayLInput;
        QLineEdit* wednesdayDInput = this->ui.WednesdayDInput;
        QLineEdit* thursdayBInput = this->ui.ThursdayBInput;
        QLineEdit* thursdayLInput = this->ui.ThursdayLInput;
        QLineEdit* thursdayDInput = this->ui.ThursdayDInput;
        QLineEdit* fridayBInput = this->ui.FridayBInput;
        QLineEdit* fridayLInput = this->ui.FridayLInput;
        QLineEdit* fridayDInput = this->ui.FridayDInput;
        QLineEdit* saturdayBInput = this->ui.SaturdayBInput;
        QLineEdit* saturdayLInput = this->ui.SaturdayLInput;
        QLineEdit* saturdayDInput = this->ui.SaturdayDInput;
        QLineEdit* sundayBInput = this->ui.SundayBInput;
        QLineEdit* sundayLInput = this->ui.SundayLInput;
        QLineEdit* sundayDInput = this->ui.SundayDInput;

        mondayBLabel->setText("Monday breakfast");
        mondayLLabel->setText("Monday lunch");
        mondayDLabel->setText("Monday dinner");
        tuesdayBLabel->setText("Tuesday breakfast");
        tuesdayLLabel->setText("Tuesday lunch");
        tuesdayDLabel->setText("Tuesday dinner");
        wednesdayBLabel->setText("Wednesday breakfast");
        wednesdayLLabel->setText("Wednesday lunch");
        wednesdayDLabel->setText("Wednesday dinner");
        thursdayBLabel->setText("Thursday breakfast");
        thursdayLLabel->setText("Thursday lunch");
        thursdayDLabel->setText("Thursday dinner");
        fridayBLabel->setText("Friday breakfast");
        fridayLLabel->setText("Friday lunch");
        fridayDLabel->setText("Friday dinner");
        saturdayBLabel->setText("Saturday breakfast");
        saturdayLLabel->setText("Saturday lunch");
        saturdayDLabel->setText("Saturday dinner");
        sundayBLabel->setText("Sunday breakfast");
        sundayLLabel->setText("Sunday lunch");
        sundayDLabel->setText("Sunday dinner");
        cancelButton->setText("Cancel");
        if (*isCurrentPlan) {
            weekSelectorButton->setText("Next week");
        } else {
            weekSelectorButton->setText("Previous week");
        };
        mondayBInput->setText(json[0]["monday_breakfast"].toString());
        mondayLInput->setText(json[0]["monday_lunch"].toString());
        mondayDInput->setText(json[0]["monday_dinner"].toString());
        tuesdayBInput->setText(json[0]["tuesday_breakfast"].toString());
        tuesdayLInput->setText(json[0]["tuesday_lunch"].toString());
        tuesdayDInput->setText(json[0]["tuesday_dinner"].toString());
        wednesdayBInput->setText(json[0]["wednesday_breakfast"].toString());
        wednesdayLInput->setText(json[0]["wednesday_lunch"].toString());
        wednesdayDInput->setText(json[0]["wednesday_dinner"].toString());
        thursdayBInput->setText(json[0]["thursday_breakfast"].toString());
        thursdayLInput->setText(json[0]["thursday_lunch"].toString());
        thursdayDInput->setText(json[0]["thursday_dinner"].toString());
        fridayBInput->setText(json[0]["friday_breakfast"].toString());
        fridayLInput->setText(json[0]["friday_lunch"].toString());
        fridayDInput->setText(json[0]["friday_dinner"].toString());
        saturdayBInput->setText(json[0]["saturday_breakfast"].toString());
        saturdayLInput->setText(json[0]["saturday_lunch"].toString());
        saturdayDInput->setText(json[0]["saturday_dinner"].toString());
        sundayBInput->setText(json[0]["sunday_breakfast"].toString());
        sundayLInput->setText(json[0]["sunday_lunch"].toString());
        sundayDInput->setText(json[0]["sunday_dinner"].toString());

        if (*isCurrentPlan) {
            *currentPlanId = json[0]["id"].toInt() || 0;
        } else {
            *nextPlanId = json[0]["id"].toInt() || 0;
        };

        if ((*isCurrentPlan && *currentPlanId > 0) || (!*isCurrentPlan && *nextPlanId > 0)) {
            saveButton->setText("Update");
        } else {
            saveButton->setText("Create");
        };
    };
}

void WeeklyPlannerWidget::PostRequestFinished(QNetworkReply* reply) {
    QByteArray response_data = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response_data);
    QJsonObject replyObject = json.object();
    reply->deleteLater();

    if (replyObject.value("status") != 200) {
        QMessageBox msg;
        msg.setText("Weekly plan creation failed. Please try again");
        msg.exec();
    } else {
        QMessageBox msg;
        msg.setText("Weekly plan created successfully");
        msg.exec();
    };
    CancelButtonClicked();
}