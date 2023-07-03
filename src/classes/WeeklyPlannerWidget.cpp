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