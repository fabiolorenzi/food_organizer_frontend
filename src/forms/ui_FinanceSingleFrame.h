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
    QVBoxLayout *verticalLayout;
    QFrame *FirstLine;
    QHBoxLayout *horizontalLayout;
    QLabel *TitleLabel;
    QLabel *TitleValue;
    QFrame *SecondLine;
    QHBoxLayout *horizontalLayout_4;
    QLabel *DescriptionLabel;
    QLabel *DescriptionValue;
    QFrame *ThirdLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *PriceLabel;
    QLabel *PriceValue;
    QFrame *FourthLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *DateLabel;
    QLabel *DateValue;
    QFrame *ButtonLine;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *DeleteButton;

    void setupUi(QWidget *FinanceSingleFrame)
    {
        if (FinanceSingleFrame->objectName().isEmpty())
            FinanceSingleFrame->setObjectName(QString::fromUtf8("FinanceSingleFrame"));
        FinanceSingleFrame->resize(400, 300);
        verticalLayout = new QVBoxLayout(FinanceSingleFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        FirstLine = new QFrame(FinanceSingleFrame);
        FirstLine->setObjectName(QString::fromUtf8("FirstLine"));
        FirstLine->setFrameShape(QFrame::StyledPanel);
        FirstLine->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(FirstLine);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        TitleLabel = new QLabel(FirstLine);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));

        horizontalLayout->addWidget(TitleLabel);

        TitleValue = new QLabel(FirstLine);
        TitleValue->setObjectName(QString::fromUtf8("TitleValue"));

        horizontalLayout->addWidget(TitleValue);


        verticalLayout->addWidget(FirstLine);

        SecondLine = new QFrame(FinanceSingleFrame);
        SecondLine->setObjectName(QString::fromUtf8("SecondLine"));
        SecondLine->setFrameShape(QFrame::StyledPanel);
        SecondLine->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(SecondLine);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        DescriptionLabel = new QLabel(SecondLine);
        DescriptionLabel->setObjectName(QString::fromUtf8("DescriptionLabel"));

        horizontalLayout_4->addWidget(DescriptionLabel);

        DescriptionValue = new QLabel(SecondLine);
        DescriptionValue->setObjectName(QString::fromUtf8("DescriptionValue"));

        horizontalLayout_4->addWidget(DescriptionValue);


        verticalLayout->addWidget(SecondLine);

        ThirdLine = new QFrame(FinanceSingleFrame);
        ThirdLine->setObjectName(QString::fromUtf8("ThirdLine"));
        ThirdLine->setFrameShape(QFrame::StyledPanel);
        ThirdLine->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(ThirdLine);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        PriceLabel = new QLabel(ThirdLine);
        PriceLabel->setObjectName(QString::fromUtf8("PriceLabel"));

        horizontalLayout_3->addWidget(PriceLabel);

        PriceValue = new QLabel(ThirdLine);
        PriceValue->setObjectName(QString::fromUtf8("PriceValue"));

        horizontalLayout_3->addWidget(PriceValue);


        verticalLayout->addWidget(ThirdLine);

        FourthLine = new QFrame(FinanceSingleFrame);
        FourthLine->setObjectName(QString::fromUtf8("FourthLine"));
        FourthLine->setFrameShape(QFrame::StyledPanel);
        FourthLine->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(FourthLine);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        DateLabel = new QLabel(FourthLine);
        DateLabel->setObjectName(QString::fromUtf8("DateLabel"));

        horizontalLayout_2->addWidget(DateLabel);

        DateValue = new QLabel(FourthLine);
        DateValue->setObjectName(QString::fromUtf8("DateValue"));

        horizontalLayout_2->addWidget(DateValue);


        verticalLayout->addWidget(FourthLine);

        ButtonLine = new QFrame(FinanceSingleFrame);
        ButtonLine->setObjectName(QString::fromUtf8("ButtonLine"));
        ButtonLine->setFrameShape(QFrame::StyledPanel);
        ButtonLine->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(ButtonLine);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        DeleteButton = new QPushButton(ButtonLine);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));

        horizontalLayout_5->addWidget(DeleteButton);


        verticalLayout->addWidget(ButtonLine);


        retranslateUi(FinanceSingleFrame);
        QObject::connect(DeleteButton, SIGNAL(clicked()), FinanceSingleFrame, SLOT(show()));

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
