/********************************************************************************
** Form generated from reading UI file 'StorageSingleFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef STORAGESINGLEFRAME_H
#define STORAGESINGLEFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StorageSingleFrame
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *FirstLine;
    QVBoxLayout *verticalLayout_3;
    QLabel *NameLabel;
    QLabel *NameValue;
    QFrame *SecondLine;
    QVBoxLayout *verticalLayout_4;
    QLabel *PositionLabel;
    QLabel *PositionValue;
    QFrame *ThirdLine;
    QVBoxLayout *verticalLayout_5;
    QLabel *QuantityLabel;
    QLabel *QuantityValue;
    QFrame *FourthLine;
    QVBoxLayout *verticalLayout_6;
    QLabel *ExpireDateLabel;
    QLabel *ExpireDateValue;
    QFrame *ButtonLine;
    QVBoxLayout *verticalLayout_2;
    QPushButton *DeleteButton;

    void setupUi(QWidget *StorageSingleFrame)
    {
        if (StorageSingleFrame->objectName().isEmpty())
            StorageSingleFrame->setObjectName(QString::fromUtf8("StorageSingleFrame"));
        StorageSingleFrame->resize(550, 99);
        horizontalLayout = new QHBoxLayout(StorageSingleFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        FirstLine = new QFrame(StorageSingleFrame);
        FirstLine->setObjectName(QString::fromUtf8("FirstLine"));
        FirstLine->setFrameShape(QFrame::StyledPanel);
        FirstLine->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(FirstLine);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        NameLabel = new QLabel(FirstLine);
        NameLabel->setObjectName(QString::fromUtf8("NameLabel"));

        verticalLayout_3->addWidget(NameLabel);

        NameValue = new QLabel(FirstLine);
        NameValue->setObjectName(QString::fromUtf8("NameValue"));

        verticalLayout_3->addWidget(NameValue);


        horizontalLayout->addWidget(FirstLine);

        SecondLine = new QFrame(StorageSingleFrame);
        SecondLine->setObjectName(QString::fromUtf8("SecondLine"));
        SecondLine->setFrameShape(QFrame::StyledPanel);
        SecondLine->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(SecondLine);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        PositionLabel = new QLabel(SecondLine);
        PositionLabel->setObjectName(QString::fromUtf8("PositionLabel"));

        verticalLayout_4->addWidget(PositionLabel);

        PositionValue = new QLabel(SecondLine);
        PositionValue->setObjectName(QString::fromUtf8("PositionValue"));

        verticalLayout_4->addWidget(PositionValue);


        horizontalLayout->addWidget(SecondLine);

        ThirdLine = new QFrame(StorageSingleFrame);
        ThirdLine->setObjectName(QString::fromUtf8("ThirdLine"));
        ThirdLine->setFrameShape(QFrame::StyledPanel);
        ThirdLine->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(ThirdLine);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        QuantityLabel = new QLabel(ThirdLine);
        QuantityLabel->setObjectName(QString::fromUtf8("QuantityLabel"));

        verticalLayout_5->addWidget(QuantityLabel);

        QuantityValue = new QLabel(ThirdLine);
        QuantityValue->setObjectName(QString::fromUtf8("QuantityValue"));

        verticalLayout_5->addWidget(QuantityValue);


        horizontalLayout->addWidget(ThirdLine);

        FourthLine = new QFrame(StorageSingleFrame);
        FourthLine->setObjectName(QString::fromUtf8("FourthLine"));
        FourthLine->setFrameShape(QFrame::StyledPanel);
        FourthLine->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(FourthLine);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        ExpireDateLabel = new QLabel(FourthLine);
        ExpireDateLabel->setObjectName(QString::fromUtf8("ExpireDateLabel"));

        verticalLayout_6->addWidget(ExpireDateLabel);

        ExpireDateValue = new QLabel(FourthLine);
        ExpireDateValue->setObjectName(QString::fromUtf8("ExpireDateValue"));

        verticalLayout_6->addWidget(ExpireDateValue);


        horizontalLayout->addWidget(FourthLine);

        ButtonLine = new QFrame(StorageSingleFrame);
        ButtonLine->setObjectName(QString::fromUtf8("ButtonLine"));
        ButtonLine->setFrameShape(QFrame::StyledPanel);
        ButtonLine->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(ButtonLine);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        DeleteButton = new QPushButton(ButtonLine);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));

        verticalLayout_2->addWidget(DeleteButton);


        horizontalLayout->addWidget(ButtonLine);


        retranslateUi(StorageSingleFrame);
        QObject::connect(DeleteButton, SIGNAL(clicked()), StorageSingleFrame, SLOT(DeleteButtonClicked()));

        QMetaObject::connectSlotsByName(StorageSingleFrame);
    } // setupUi

    void retranslateUi(QWidget *StorageSingleFrame)
    {
        StorageSingleFrame->setWindowTitle(QCoreApplication::translate("StorageSingleFrame", "Form", nullptr));
        NameLabel->setText(QCoreApplication::translate("StorageSingleFrame", "Name:", nullptr));
        NameValue->setText(QCoreApplication::translate("StorageSingleFrame", "nameValue", nullptr));
        PositionLabel->setText(QCoreApplication::translate("StorageSingleFrame", "Position:", nullptr));
        PositionValue->setText(QCoreApplication::translate("StorageSingleFrame", "positionValue", nullptr));
        QuantityLabel->setText(QCoreApplication::translate("StorageSingleFrame", "Quantity:", nullptr));
        QuantityValue->setText(QCoreApplication::translate("StorageSingleFrame", "quantityValue", nullptr));
        ExpireDateLabel->setText(QCoreApplication::translate("StorageSingleFrame", "Expire date:", nullptr));
        ExpireDateValue->setText(QCoreApplication::translate("StorageSingleFrame", "expireDateValue", nullptr));
        DeleteButton->setText(QCoreApplication::translate("StorageSingleFrame", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StorageSingleFrame: public Ui_StorageSingleFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // STORAGESINGLEFRAME_H
