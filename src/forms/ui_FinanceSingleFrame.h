/********************************************************************************
** Form generated from reading UI file 'FinanceSingleFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FINANCESINGLEFRAME_H
#define FINANCESINGLEFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FinanceSingleFrame
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *FirstLine;
    QVBoxLayout *verticalLayout_3;
    QLabel *TitleLabel;
    QLabel *TitleValue;
    QFrame *SecondLine;
    QVBoxLayout *verticalLayout_4;
    QLabel *DescriptionLabel;
    QLabel *DescriptionValue;
    QFrame *ThirdLine;
    QVBoxLayout *verticalLayout_5;
    QLabel *PriceLabel;
    QLabel *PriceValue;
    QFrame *FourthLine;
    QVBoxLayout *verticalLayout_6;
    QLabel *DateLabel;
    QLabel *DateValue;
    QFrame *ButtonLine;
    QVBoxLayout *verticalLayout_2;
    QPushButton *DeleteButton;

    void setupUi(QWidget *FinanceSingleFrame)
    {
        if (FinanceSingleFrame->objectName().isEmpty())
            FinanceSingleFrame->setObjectName(QString::fromUtf8("FinanceSingleFrame"));
        FinanceSingleFrame->resize(550, 99);
        horizontalLayout = new QHBoxLayout(FinanceSingleFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        FirstLine = new QFrame(FinanceSingleFrame);
        FirstLine->setObjectName(QString::fromUtf8("FirstLine"));
        FirstLine->setFrameShape(QFrame::StyledPanel);
        FirstLine->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(FirstLine);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        TitleLabel = new QLabel(FirstLine);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));

        verticalLayout_3->addWidget(TitleLabel);

        TitleValue = new QLabel(FirstLine);
        TitleValue->setObjectName(QString::fromUtf8("TitleValue"));

        verticalLayout_3->addWidget(TitleValue);


        horizontalLayout->addWidget(FirstLine);

        SecondLine = new QFrame(FinanceSingleFrame);
        SecondLine->setObjectName(QString::fromUtf8("SecondLine"));
        SecondLine->setFrameShape(QFrame::StyledPanel);
        SecondLine->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(SecondLine);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        DescriptionLabel = new QLabel(SecondLine);
        DescriptionLabel->setObjectName(QString::fromUtf8("DescriptionLabel"));

        verticalLayout_4->addWidget(DescriptionLabel);

        DescriptionValue = new QLabel(SecondLine);
        DescriptionValue->setObjectName(QString::fromUtf8("DescriptionValue"));

        verticalLayout_4->addWidget(DescriptionValue);


        horizontalLayout->addWidget(SecondLine);

        ThirdLine = new QFrame(FinanceSingleFrame);
        ThirdLine->setObjectName(QString::fromUtf8("ThirdLine"));
        ThirdLine->setFrameShape(QFrame::StyledPanel);
        ThirdLine->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(ThirdLine);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        PriceLabel = new QLabel(ThirdLine);
        PriceLabel->setObjectName(QString::fromUtf8("PriceLabel"));

        verticalLayout_5->addWidget(PriceLabel);

        PriceValue = new QLabel(ThirdLine);
        PriceValue->setObjectName(QString::fromUtf8("PriceValue"));

        verticalLayout_5->addWidget(PriceValue);


        horizontalLayout->addWidget(ThirdLine);

        FourthLine = new QFrame(FinanceSingleFrame);
        FourthLine->setObjectName(QString::fromUtf8("FourthLine"));
        FourthLine->setFrameShape(QFrame::StyledPanel);
        FourthLine->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(FourthLine);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        DateLabel = new QLabel(FourthLine);
        DateLabel->setObjectName(QString::fromUtf8("DateLabel"));

        verticalLayout_6->addWidget(DateLabel);

        DateValue = new QLabel(FourthLine);
        DateValue->setObjectName(QString::fromUtf8("DateValue"));

        verticalLayout_6->addWidget(DateValue);


        horizontalLayout->addWidget(FourthLine);

        ButtonLine = new QFrame(FinanceSingleFrame);
        ButtonLine->setObjectName(QString::fromUtf8("ButtonLine"));
        ButtonLine->setFrameShape(QFrame::StyledPanel);
        ButtonLine->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(ButtonLine);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        DeleteButton = new QPushButton(ButtonLine);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));

        verticalLayout_2->addWidget(DeleteButton);


        horizontalLayout->addWidget(ButtonLine);


        retranslateUi(FinanceSingleFrame);
        QObject::connect(DeleteButton, SIGNAL(clicked()), FinanceSingleFrame, SLOT(DeleteButtonClicked()));

        QMetaObject::connectSlotsByName(FinanceSingleFrame);
    } // setupUi

    void retranslateUi(QWidget *FinanceSingleFrame)
    {
        FinanceSingleFrame->setWindowTitle(QCoreApplication::translate("FinanceSingleFrame", "Form", nullptr));
        TitleLabel->setText(QCoreApplication::translate("FinanceSingleFrame", "Title:", nullptr));
        TitleValue->setText(QCoreApplication::translate("FinanceSingleFrame", "titleValue", nullptr));
        DescriptionLabel->setText(QCoreApplication::translate("FinanceSingleFrame", "Description:", nullptr));
        DescriptionValue->setText(QCoreApplication::translate("FinanceSingleFrame", "descriptionValue", nullptr));
        PriceLabel->setText(QCoreApplication::translate("FinanceSingleFrame", "Price (in \302\243):", nullptr));
        PriceValue->setText(QCoreApplication::translate("FinanceSingleFrame", "priceValue", nullptr));
        DateLabel->setText(QCoreApplication::translate("FinanceSingleFrame", "Date:", nullptr));
        DateValue->setText(QCoreApplication::translate("FinanceSingleFrame", "dateValue", nullptr));
        DeleteButton->setText(QCoreApplication::translate("FinanceSingleFrame", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FinanceSingleFrame: public Ui_FinanceSingleFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FINANCESINGLEFRAME_H
