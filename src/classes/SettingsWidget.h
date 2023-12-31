#ifndef SETTINGSWIDGET_H_
#define SETTINGSWIDGET_H_

#include <QtWidgets/QWidget>
#include <QtNetwork/QNetworkReply>
#include "../forms/ui_SettingsWidget.h"

class SettingsWidget : public QWidget {
    Q_OBJECT
    public:
        SettingsWidget(QWidget* parent = 0);
        ~SettingsWidget();
    private:
        Ui::SettingsWidget ui;
        void GetUserByToken();
    protected slots:
        void CancelButtonClicked();
        void UpdateButtonClicked();
        void DeleteButtonClicked();
        void GetRequestFinished(QNetworkReply*);
        void PutRequestFinished(QNetworkReply*);
        void DeleteRequestFinished(QNetworkReply*);
};

#endif