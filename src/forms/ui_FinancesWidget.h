/********************************************************************************
** Form generated from reading UI file 'FinancesWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FINANCESWIDGET_H
#define FINANCESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FinancesWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *TopFrame;
    QGridLayout *gridLayout_2;
    QLabel *Title;
    QFrame *BottomFrame;
    QVBoxLayout *verticalLayout;
    QFrame *ListFrame;
    QGridLayout *gridLayout_3;
    QFrame *ListFrameLine;
    QLabel *PageNumberLabel;
    QFrame *InputsFrame;
    QGridLayout *gridLayout_4;
    QFormLayout *Inputs;
    QLineEdit *TitleInput;
    QLabel *TitleLabel;
    QLineEdit *DescriptionInput;
    QLabel *DescriptionLabel;
    QLineEdit *PriceInput;
    QLabel *PriceLabel;
    QLineEdit *DateInput;
    QLabel *DateLabel;
    QFrame *InputsButtonsLine;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *CancelButton;
    QPushButton *CreateButton;

    void setupUi(QWidget *FinancesWidget)
    {
        if (FinancesWidget->objectName().isEmpty())
            FinancesWidget->setObjectName(QString::fromUtf8("FinancesWidget"));
        FinancesWidget->resize(748, 516);
        gridLayout = new QGridLayout(FinancesWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TopFrame = new QFrame(FinancesWidget);
        TopFrame->setObjectName(QString::fromUtf8("TopFrame"));
        TopFrame->setFrameShape(QFrame::StyledPanel);
        TopFrame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(TopFrame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Title = new QLabel(TopFrame);
        Title->setObjectName(QString::fromUtf8("Title"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        Title->setFont(font);
        Title->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(Title, 0, 0, 1, 1);


        gridLayout->addWidget(TopFrame, 0, 0, 1, 1);

        BottomFrame = new QFrame(FinancesWidget);
        BottomFrame->setObjectName(QString::fromUtf8("BottomFrame"));
        BottomFrame->setFrameShape(QFrame::StyledPanel);
        BottomFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(BottomFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ListFrame = new QFrame(BottomFrame);
        ListFrame->setObjectName(QString::fromUtf8("ListFrame"));
        ListFrame->setFrameShape(QFrame::StyledPanel);
        ListFrame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(ListFrame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        ListFrameLine = new QFrame(ListFrame);
        ListFrameLine->setObjectName(QString::fromUtf8("ListFrameLine"));
        ListFrameLine->setFrameShape(QFrame::StyledPanel);
        ListFrameLine->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(ListFrameLine, 1, 0, 1, 1);

        PageNumberLabel = new QLabel(ListFrame);
        PageNumberLabel->setObjectName(QString::fromUtf8("PageNumberLabel"));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        PageNumberLabel->setFont(font1);
        PageNumberLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(PageNumberLabel, 0, 0, 1, 1);


        verticalLayout->addWidget(ListFrame);

        InputsFrame = new QFrame(BottomFrame);
        InputsFrame->setObjectName(QString::fromUtf8("InputsFrame"));
        InputsFrame->setFrameShape(QFrame::StyledPanel);
        InputsFrame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(InputsFrame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        Inputs = new QFormLayout();
        Inputs->setObjectName(QString::fromUtf8("Inputs"));
        TitleInput = new QLineEdit(InputsFrame);
        TitleInput->setObjectName(QString::fromUtf8("TitleInput"));

        Inputs->setWidget(0, QFormLayout::LabelRole, TitleInput);

        TitleLabel = new QLabel(InputsFrame);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));

        Inputs->setWidget(0, QFormLayout::FieldRole, TitleLabel);

        DescriptionInput = new QLineEdit(InputsFrame);
        DescriptionInput->setObjectName(QString::fromUtf8("DescriptionInput"));

        Inputs->setWidget(1, QFormLayout::LabelRole, DescriptionInput);

        DescriptionLabel = new QLabel(InputsFrame);
        DescriptionLabel->setObjectName(QString::fromUtf8("DescriptionLabel"));

        Inputs->setWidget(1, QFormLayout::FieldRole, DescriptionLabel);

        PriceInput = new QLineEdit(InputsFrame);
        PriceInput->setObjectName(QString::fromUtf8("PriceInput"));

        Inputs->setWidget(2, QFormLayout::LabelRole, PriceInput);

        PriceLabel = new QLabel(InputsFrame);
        PriceLabel->setObjectName(QString::fromUtf8("PriceLabel"));

        Inputs->setWidget(2, QFormLayout::FieldRole, PriceLabel);

        DateInput = new QLineEdit(InputsFrame);
        DateInput->setObjectName(QString::fromUtf8("DateInput"));

        Inputs->setWidget(3, QFormLayout::LabelRole, DateInput);

        DateLabel = new QLabel(InputsFrame);
        DateLabel->setObjectName(QString::fromUtf8("DateLabel"));

        Inputs->setWidget(3, QFormLayout::FieldRole, DateLabel);


        gridLayout_4->addLayout(Inputs, 0, 0, 1, 1);

        InputsButtonsLine = new QFrame(InputsFrame);
        InputsButtonsLine->setObjectName(QString::fromUtf8("InputsButtonsLine"));
        InputsButtonsLine->setFrameShape(QFrame::StyledPanel);
        InputsButtonsLine->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(InputsButtonsLine);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        CancelButton = new QPushButton(InputsButtonsLine);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        horizontalLayout_2->addWidget(CancelButton);

        CreateButton = new QPushButton(InputsButtonsLine);
        CreateButton->setObjectName(QString::fromUtf8("CreateButton"));

        horizontalLayout_2->addWidget(CreateButton);


        gridLayout_4->addWidget(InputsButtonsLine, 1, 0, 1, 1);


        verticalLayout->addWidget(InputsFrame);


        gridLayout->addWidget(BottomFrame, 1, 0, 1, 1);


        retranslateUi(FinancesWidget);
        QObject::connect(CancelButton, SIGNAL(clicked()), FinancesWidget, SLOT(CancelButtonClicked()));
        QObject::connect(CreateButton, SIGNAL(clicked()), FinancesWidget, SLOT(CreateButtonClicked()));

        QMetaObject::connectSlotsByName(FinancesWidget);
    } // setupUi

    void retranslateUi(QWidget *FinancesWidget)
    {
        FinancesWidget->setWindowTitle(QCoreApplication::translate("FinancesWidget", "Form", nullptr));
        Title->setText(QCoreApplication::translate("FinancesWidget", "Finances", nullptr));
        PageNumberLabel->setText(QCoreApplication::translate("FinancesWidget", "Page 1 / 1", nullptr));
        TitleLabel->setText(QCoreApplication::translate("FinancesWidget", "Title", nullptr));
        DescriptionLabel->setText(QCoreApplication::translate("FinancesWidget", "Description", nullptr));
        PriceLabel->setText(QCoreApplication::translate("FinancesWidget", "Price (\302\243)", nullptr));
        DateLabel->setText(QCoreApplication::translate("FinancesWidget", "Date (yyyy-mm-dd)", nullptr));
        CancelButton->setText(QCoreApplication::translate("FinancesWidget", "Cancel", nullptr));
        CreateButton->setText(QCoreApplication::translate("FinancesWidget", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FinancesWidget: public Ui_FinancesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FINANCESWIDGET_H
