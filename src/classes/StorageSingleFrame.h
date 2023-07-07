#ifndef STORAGESINGLEFRAME_H_
#define STORAGESINGLEFRAME_H_

#include <QtWidgets/QWidget>
#include <QtNetwork/QNetworkReply>
#include "../forms/ui_StorageSingleFrame.h"

class StorageSingleFrame : public QWidget {
    Q_OBJECT
    public:
        StorageSingleFrame(QWidget* parent = 0);
        ~StorageSingleFrame();
        void InitializeStorageSingleFrame(int _id, QString _name, QString _position, QString _quantity, QString _expire_date);
    private:
        Ui::StorageSingleFrame ui;
    protected slots:
        void DeleteButtonClicked();
        void DeleteRequestFinished(QNetworkReply*);
};

#endif