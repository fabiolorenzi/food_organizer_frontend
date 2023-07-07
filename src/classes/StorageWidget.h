#ifndef STORAGEWIDGET_H_
#define STORAGEWIDGET_H_

#include <QtWidgets/QWidget>
#include <QtNetwork/QNetworkReply>
#include "../forms/ui_StorageWidget.h"

class StorageWidget : public QWidget {
    Q_OBJECT
    public:
        StorageWidget(QWidget* parent = 0);
        ~StorageWidget();
    private:
        Ui::StorageWidget ui;
    protected slots:
        void CancelButtonClicked();
        void CreateButtonClicked();
        void GetStorageData();
        void GetRequestFinished(QNetworkReply*);
        void PostRequestFinished(QNetworkReply*);
};

#endif