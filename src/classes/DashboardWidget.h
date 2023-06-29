#ifndef DASHBOARDWIDGET_H_
#define DASHBOARDWIDGET_H_

#include <QtWidgets/QWidget>
#include "../forms/ui_DashboardWidget.h"

class DashboardWidget : public QWidget {
    Q_OBJECT
    public:
        DashboardWidget(QWidget* parent = 0);
        ~DashboardWidget();
    private:
        Ui::DashboardWidget ui;
};

#endif