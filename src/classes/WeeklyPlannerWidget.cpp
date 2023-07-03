#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
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

WeeklyPlannerWidget::WeeklyPlannerWidget(QWidget* parent) : QWidget(parent) {
    ui.setupUi(this);

    *currentDay = GetCurrentDay();
    *currentMonth = GetCurrentMonth();
    *currentYear = GetCurrentYear();
    *nextDay = GetNextDay();
    *nextMonth = GetNextMonth();
    *nextYear = GetNextYear();

    QString formattedDay;
    QString formattedMonth;

    if (*currentDay < 10) {
        formattedDay = "0" + QString::number(*currentDay);
    } else {
        formattedDay = QString::number(*currentDay);
    };

    if (*currentMonth < 10) {
        formattedMonth = "0" + QString::number(*currentMonth);
    } else {
        formattedMonth = QString::number(*currentMonth);
    };

    QLabel* dateLabel = this->ui.WeekPlanDate;
    (*dateLabel).setText("This week plan start the " + formattedDay + "/" + formattedMonth + "/" + QString::number(*currentYear));
}

WeeklyPlannerWidget::~WeeklyPlannerWidget() {
    delete this;
    delete currentYear;
    delete currentMonth;
    delete currentDay;
    delete nextDay;
    delete nextMonth;
    delete nextYear;
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
    QMessageBox msg;
    msg.setText("Week selector button clicked");
    msg.exec();
}