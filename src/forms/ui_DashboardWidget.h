/********************************************************************************
** Form generated from reading UI file 'DashboardWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DASHBOARDWIDGET_H
#define DASHBOARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashboardWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *topSection;
    QGridLayout *gridLayout_2;
    QLabel *topTitle;

    void setupUi(QWidget *DashboardWidget)
    {
        if (DashboardWidget->objectName().isEmpty())
            DashboardWidget->setObjectName(QString::fromUtf8("DashboardWidget"));
        DashboardWidget->resize(400, 300);
        gridLayout = new QGridLayout(DashboardWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        topSection = new QFrame(DashboardWidget);
        topSection->setObjectName(QString::fromUtf8("topSection"));
        topSection->setFrameShape(QFrame::StyledPanel);
        topSection->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(topSection);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        topTitle = new QLabel(topSection);
        topTitle->setObjectName(QString::fromUtf8("topTitle"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        topTitle->setFont(font);
        topTitle->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(topTitle, 0, 0, 1, 1);


        gridLayout->addWidget(topSection, 0, 0, 1, 1);


        retranslateUi(DashboardWidget);

        QMetaObject::connectSlotsByName(DashboardWidget);
    } // setupUi

    void retranslateUi(QWidget *DashboardWidget)
    {
        DashboardWidget->setWindowTitle(QCoreApplication::translate("DashboardWidget", "Form", nullptr));
        topTitle->setText(QCoreApplication::translate("DashboardWidget", "Dashboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DashboardWidget: public Ui_DashboardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DASHBOARDWIDGET_H
