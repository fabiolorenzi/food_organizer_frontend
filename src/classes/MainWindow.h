#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QtWidgets/QMainWindow>
#include "../forms/ui_MainWindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        MainWindow(QWidget* parent = 0);
        ~MainWindow();
        void UpdateMainWindow();
        void ChangeWidget(QWidget* widget);
    private:
        Ui::MainWindow ui;
    protected slots:
        void LoginMenuClicked();
        void LogoutMenuClicked();
        void ExitMenuClicked();
        void SettingsMenuClicked();
        void DashboardMenuClicked();
        void WeeklyPlannerMenuClicked();
        void StorageMenuClicked();
        void FinancesMenuClicked();
        void AboutMenuClicked();
};

#endif