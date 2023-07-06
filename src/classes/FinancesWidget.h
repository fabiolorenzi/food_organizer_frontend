#ifndef FINANCESWIDGET_H_
#define FINANCESWIDGET_H_

#include <QtWidgets/QWidget>
#include <QtNetwork/QNetworkReply>
#include "../forms/ui_FinancesWidget.h"

class FinancesWidget : public QWidget {
    Q_OBJECT
    public:
        FinancesWidget(QWidget* parent = 0);
        ~FinancesWidget();
    private:
        Ui::FinancesWidget ui;
    protected slots:
        void CancelButtonClicked();
        void CreateButtonClicked();
        void GetFinancesData();
        void GetRequestFinished(QNetworkReply*);
        void PostRequestFinished(QNetworkReply*);
};

#endif