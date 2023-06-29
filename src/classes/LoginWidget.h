#ifndef LOGINWIDGET_H_
#define LOGINWIDGET_H_

#include <QtWidgets/QWidget>
#include <QtNetwork/QNetworkReply>
#include "../forms/ui_LoginWidget.h"

class LoginWidget : public QWidget {
    Q_OBJECT
    public:
        LoginWidget(QWidget* parent = 0);
        ~LoginWidget();
    private:
        Ui::LoginWidget ui;
    protected slots:
        void SigninButtonClicked();
        void CancelButtonClicked();
        void LoginButtonClicked();
        void PatchRequestFinished(QNetworkReply*);
};

#endif