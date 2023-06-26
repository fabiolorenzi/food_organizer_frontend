#ifndef SIGNINWIDGET_H_
#define SIGNINWIDGET_H_

#include <QtWidgets/QWidget>
#include "../forms/ui_SigninWidget.h"

class SigninWidget : public QWidget {
    Q_OBJECT
    public:
        SigninWidget(QWidget* parent = 0);
        ~SigninWidget();
    private:
        Ui::SigninWidget ui;
    protected slots:
        void LoginButtonClicked();
        void CancelButtonClicked();
        void SigninButtonClicked();
};

#endif