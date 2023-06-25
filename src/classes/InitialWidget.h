#ifndef INITIALWIDGET_H_
#define INITIALWIDGET_H_

#include <QtWidgets/QWidget>
#include "../forms/ui_InitialWidget.h"

class InitialWidget : public QWidget {
    Q_OBJECT
    public:
        InitialWidget(QWidget* parent = 0);
        ~InitialWidget();
    private:
        Ui::InitialWidget ui;
};

#endif