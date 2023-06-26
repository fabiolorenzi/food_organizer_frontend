#ifndef LOGINWIDGET_H_
#define LOGINWIDGET_H_

#include <QtWidgets/QWidget>
#include "../forms/ui_LoginWidget.h"

class LoginWidget : public QWidget {
    public:
        LoginWidget(QWidget* parent = 0);
        ~LoginWidget();
    private:
        Ui::LoginWidget ui;
    protected slots:
        void SigninButtonClicked();
        void CancelButtonClicked();
        void LoginButtonClicked();
};

#endif