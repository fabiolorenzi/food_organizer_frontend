#ifndef FINANCESINGLEFRAME_H_
#define FINANCESINGLEFRAME_H_

#include <QtWidgets/QWidget>
#include <QtNetwork/QNetworkReply>
#include "../forms/ui_FinanceSingleFrame.h"

class FinanceSingleFrame : public QWidget {
    Q_OBJECT
    public:
        FinanceSingleFrame(QWidget* parent = 0);
        ~FinanceSingleFrame();
        void InitializeFinanceSingleFrame(int _id, QString _title, QString _desc, QString _price, QString _date);
    private:
        Ui::FinanceSingleFrame ui;
};

#endif