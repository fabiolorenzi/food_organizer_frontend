#ifndef INITIALWIDGET_H
#define INITIALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitialWidget
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *InitialWidget)
    {
        if (InitialWidget->objectName().isEmpty())
            InitialWidget->setObjectName(QString::fromUtf8("InitialWidget"));
        InitialWidget->resize(400, 300);
        label = new QLabel(InitialWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 401, 41));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(InitialWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 381, 191));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignCenter);

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