#ifndef INITIALWIDGET_H
#define INITIALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitialWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *InitialWidget)
    {
        if (InitialWidget->objectName().isEmpty())
            InitialWidget->setObjectName(QString::fromUtf8("InitialWidget"));
        InitialWidget->resize(501, 307);
        gridLayout = new QGridLayout(InitialWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(InitialWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(InitialWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        retranslateUi(InitialWidget);

        QMetaObject::connectSlotsByName(InitialWidget);
    } // setupUi

    void retranslateUi(QWidget *InitialWidget)
    {
        InitialWidget->setWindowTitle(QCoreApplication::translate("InitialWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("InitialWidget", "Welcome to Food Organizer", nullptr));
        label_2->setText(QCoreApplication::translate("InitialWidget", "Please login throught the Login menu on top left", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitialWidget: public Ui_InitialWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // INITIALWIDGET_H