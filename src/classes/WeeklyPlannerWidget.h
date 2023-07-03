#ifndef WEEKLYPLANNERWIDGET_H_
#define WEEKLYPLANNERWIDGET_H_

#include <QtWidgets/QWidget>
#include <QtNetwork/QNetworkReply>
#include "../forms/ui_WeeklyPlannerWidget.h"

class WeeklyPlannerWidget : public QWidget {
    Q_OBJECT
    public:
        WeeklyPlannerWidget(QWidget* parent = 0);
        ~WeeklyPlannerWidget();
    private:
        Ui::WeeklyPlannerWidget ui;
        void SwitchWeeklyPlanner(bool value);
        void GetWeeklyPlan(int day, int month, int year);
    protected slots:
        void CancelButtonClicked();
        void SaveButtonClicked();
        void WeekSelectorButtonClicked();
        void GetRequestFinished(QNetworkReply*);
};

#endif