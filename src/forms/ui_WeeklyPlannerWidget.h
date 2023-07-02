/********************************************************************************
** Form generated from reading UI file 'WeeklyPlannerWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WEEKLYPLANNERWIDGET_H
#define WEEKLYPLANNERWIDGET_H

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

class Ui_WeeklyPlannerWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *TopFrame;
    QGridLayout *gridLayout_2;
    QLabel *Title;
    QFrame *BottomFrame;
    QVBoxLayout *verticalLayout;
    QFrame *InputsSection;
    QVBoxLayout *verticalLayout_2;
    QFrame *WeekPlanLine;
    QGridLayout *gridLayout_3;
    QLabel *WeekPlanDate;
    QFrame *InputsLine;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *LeftInputs;
    QLineEdit *MondayBInput;
    QLabel *MondayB;
    QLineEdit *MondayLInput;
    QLabel *MondayL;
    QLineEdit *MondayDInput;
    QLabel *MondayD;
    QLineEdit *TuesdayBInput;
    QLabel *TuesdayB;
    QLineEdit *TuesdayLInput;
    QLabel *TuesdayL;
    QLineEdit *TuesdayDInput;
    QLabel *TuesdayD;
    QLineEdit *WednesdayBInput;
    QLabel *WednesdayB;
    QLineEdit *WednesdayLInput;
    QLabel *WednesdayL;
    QLineEdit *WednesdayDInput;
    QLabel *WednesdayD;
    QLineEdit *ThursdayBInput;
    QLabel *ThursdayB;
    QLineEdit *ThursdayLInput;
    QLabel *ThursdayL;
    QFormLayout *RightInputs;
    QLineEdit *ThursdayDInput;
    QLabel *ThursdayD;
    QLineEdit *FridayBInput;
    QLabel *FridayB;
    QLineEdit *FridayLInput;
    QLabel *FridayL;
    QLineEdit *FridayDInput;
    QLabel *FridayD;
    QLineEdit *SaturdayBInput;
    QLabel *SaturdayB;
    QLineEdit *SaturdayLInput;
    QLabel *SaturdayL;
    QLineEdit *SaturdayDInput;
    QLabel *SaturdayD;
    QLineEdit *SundayBInput;
    QLabel *SundayB;
    QLineEdit *SundayLInput;
    QLabel *SundayL;
    QLineEdit *SundayDInput;
    QLabel *SundayD;
    QLineEdit *EmptyInput;
    QFrame *ButtonsSection;
    QHBoxLayout *horizontalLayout;
    QPushButton *CancelButton;
    QPushButton *SaveButton;
    QPushButton *WeekSelectorButton;

    void setupUi(QWidget *WeeklyPlannerWidget)
    {
        if (WeeklyPlannerWidget->objectName().isEmpty())
            WeeklyPlannerWidget->setObjectName(QString::fromUtf8("WeeklyPlannerWidget"));
        WeeklyPlannerWidget->resize(757, 583);
        gridLayout = new QGridLayout(WeeklyPlannerWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TopFrame = new QFrame(WeeklyPlannerWidget);
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

        BottomFrame = new QFrame(WeeklyPlannerWidget);
        BottomFrame->setObjectName(QString::fromUtf8("BottomFrame"));
        BottomFrame->setEnabled(true);
        BottomFrame->setFrameShape(QFrame::StyledPanel);
        BottomFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(BottomFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        InputsSection = new QFrame(BottomFrame);
        InputsSection->setObjectName(QString::fromUtf8("InputsSection"));
        InputsSection->setFrameShape(QFrame::StyledPanel);
        InputsSection->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(InputsSection);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        WeekPlanLine = new QFrame(InputsSection);
        WeekPlanLine->setObjectName(QString::fromUtf8("WeekPlanLine"));
        WeekPlanLine->setFrameShape(QFrame::StyledPanel);
        WeekPlanLine->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(WeekPlanLine);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        WeekPlanDate = new QLabel(WeekPlanLine);
        WeekPlanDate->setObjectName(QString::fromUtf8("WeekPlanDate"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        WeekPlanDate->setFont(font1);
        WeekPlanDate->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(WeekPlanDate, 0, 0, 1, 1);


        verticalLayout_2->addWidget(WeekPlanLine);

        InputsLine = new QFrame(InputsSection);
        InputsLine->setObjectName(QString::fromUtf8("InputsLine"));
        InputsLine->setFrameShape(QFrame::StyledPanel);
        InputsLine->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(InputsLine);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LeftInputs = new QFormLayout();
        LeftInputs->setObjectName(QString::fromUtf8("LeftInputs"));
        MondayBInput = new QLineEdit(InputsLine);
        MondayBInput->setObjectName(QString::fromUtf8("MondayBInput"));

        LeftInputs->setWidget(0, QFormLayout::LabelRole, MondayBInput);

        MondayB = new QLabel(InputsLine);
        MondayB->setObjectName(QString::fromUtf8("MondayB"));

        LeftInputs->setWidget(0, QFormLayout::FieldRole, MondayB);

        MondayLInput = new QLineEdit(InputsLine);
        MondayLInput->setObjectName(QString::fromUtf8("MondayLInput"));

        LeftInputs->setWidget(1, QFormLayout::LabelRole, MondayLInput);

        MondayL = new QLabel(InputsLine);
        MondayL->setObjectName(QString::fromUtf8("MondayL"));

        LeftInputs->setWidget(1, QFormLayout::FieldRole, MondayL);

        MondayDInput = new QLineEdit(InputsLine);
        MondayDInput->setObjectName(QString::fromUtf8("MondayDInput"));

        LeftInputs->setWidget(2, QFormLayout::LabelRole, MondayDInput);

        MondayD = new QLabel(InputsLine);
        MondayD->setObjectName(QString::fromUtf8("MondayD"));

        LeftInputs->setWidget(2, QFormLayout::FieldRole, MondayD);

        TuesdayBInput = new QLineEdit(InputsLine);
        TuesdayBInput->setObjectName(QString::fromUtf8("TuesdayBInput"));

        LeftInputs->setWidget(3, QFormLayout::LabelRole, TuesdayBInput);

        TuesdayB = new QLabel(InputsLine);
        TuesdayB->setObjectName(QString::fromUtf8("TuesdayB"));

        LeftInputs->setWidget(3, QFormLayout::FieldRole, TuesdayB);

        TuesdayLInput = new QLineEdit(InputsLine);
        TuesdayLInput->setObjectName(QString::fromUtf8("TuesdayLInput"));

        LeftInputs->setWidget(4, QFormLayout::LabelRole, TuesdayLInput);

        TuesdayL = new QLabel(InputsLine);
        TuesdayL->setObjectName(QString::fromUtf8("TuesdayL"));

        LeftInputs->setWidget(4, QFormLayout::FieldRole, TuesdayL);

        TuesdayDInput = new QLineEdit(InputsLine);
        TuesdayDInput->setObjectName(QString::fromUtf8("TuesdayDInput"));

        LeftInputs->setWidget(5, QFormLayout::LabelRole, TuesdayDInput);

        TuesdayD = new QLabel(InputsLine);
        TuesdayD->setObjectName(QString::fromUtf8("TuesdayD"));

        LeftInputs->setWidget(5, QFormLayout::FieldRole, TuesdayD);

        WednesdayBInput = new QLineEdit(InputsLine);
        WednesdayBInput->setObjectName(QString::fromUtf8("WednesdayBInput"));

        LeftInputs->setWidget(6, QFormLayout::LabelRole, WednesdayBInput);

        WednesdayB = new QLabel(InputsLine);
        WednesdayB->setObjectName(QString::fromUtf8("WednesdayB"));

        LeftInputs->setWidget(6, QFormLayout::FieldRole, WednesdayB);

        WednesdayLInput = new QLineEdit(InputsLine);
        WednesdayLInput->setObjectName(QString::fromUtf8("WednesdayLInput"));

        LeftInputs->setWidget(7, QFormLayout::LabelRole, WednesdayLInput);

        WednesdayL = new QLabel(InputsLine);
        WednesdayL->setObjectName(QString::fromUtf8("WednesdayL"));

        LeftInputs->setWidget(7, QFormLayout::FieldRole, WednesdayL);

        WednesdayDInput = new QLineEdit(InputsLine);
        WednesdayDInput->setObjectName(QString::fromUtf8("WednesdayDInput"));

        LeftInputs->setWidget(8, QFormLayout::LabelRole, WednesdayDInput);

        WednesdayD = new QLabel(InputsLine);
        WednesdayD->setObjectName(QString::fromUtf8("WednesdayD"));

        LeftInputs->setWidget(8, QFormLayout::FieldRole, WednesdayD);

        ThursdayBInput = new QLineEdit(InputsLine);
        ThursdayBInput->setObjectName(QString::fromUtf8("ThursdayBInput"));

        LeftInputs->setWidget(9, QFormLayout::LabelRole, ThursdayBInput);

        ThursdayB = new QLabel(InputsLine);
        ThursdayB->setObjectName(QString::fromUtf8("ThursdayB"));

        LeftInputs->setWidget(9, QFormLayout::FieldRole, ThursdayB);

        ThursdayLInput = new QLineEdit(InputsLine);
        ThursdayLInput->setObjectName(QString::fromUtf8("ThursdayLInput"));

        LeftInputs->setWidget(10, QFormLayout::LabelRole, ThursdayLInput);

        ThursdayL = new QLabel(InputsLine);
        ThursdayL->setObjectName(QString::fromUtf8("ThursdayL"));

        LeftInputs->setWidget(10, QFormLayout::FieldRole, ThursdayL);


        horizontalLayout_2->addLayout(LeftInputs);

        RightInputs = new QFormLayout();
        RightInputs->setObjectName(QString::fromUtf8("RightInputs"));
        ThursdayDInput = new QLineEdit(InputsLine);
        ThursdayDInput->setObjectName(QString::fromUtf8("ThursdayDInput"));

        RightInputs->setWidget(0, QFormLayout::LabelRole, ThursdayDInput);

        ThursdayD = new QLabel(InputsLine);
        ThursdayD->setObjectName(QString::fromUtf8("ThursdayD"));

        RightInputs->setWidget(0, QFormLayout::FieldRole, ThursdayD);

        FridayBInput = new QLineEdit(InputsLine);
        FridayBInput->setObjectName(QString::fromUtf8("FridayBInput"));

        RightInputs->setWidget(1, QFormLayout::LabelRole, FridayBInput);

        FridayB = new QLabel(InputsLine);
        FridayB->setObjectName(QString::fromUtf8("FridayB"));

        RightInputs->setWidget(1, QFormLayout::FieldRole, FridayB);

        FridayLInput = new QLineEdit(InputsLine);
        FridayLInput->setObjectName(QString::fromUtf8("FridayLInput"));

        RightInputs->setWidget(2, QFormLayout::LabelRole, FridayLInput);

        FridayL = new QLabel(InputsLine);
        FridayL->setObjectName(QString::fromUtf8("FridayL"));

        RightInputs->setWidget(2, QFormLayout::FieldRole, FridayL);

        FridayDInput = new QLineEdit(InputsLine);
        FridayDInput->setObjectName(QString::fromUtf8("FridayDInput"));

        RightInputs->setWidget(3, QFormLayout::LabelRole, FridayDInput);

        FridayD = new QLabel(InputsLine);
        FridayD->setObjectName(QString::fromUtf8("FridayD"));

        RightInputs->setWidget(3, QFormLayout::FieldRole, FridayD);

        SaturdayBInput = new QLineEdit(InputsLine);
        SaturdayBInput->setObjectName(QString::fromUtf8("SaturdayBInput"));

        RightInputs->setWidget(4, QFormLayout::LabelRole, SaturdayBInput);

        SaturdayB = new QLabel(InputsLine);
        SaturdayB->setObjectName(QString::fromUtf8("SaturdayB"));

        RightInputs->setWidget(4, QFormLayout::FieldRole, SaturdayB);

        SaturdayLInput = new QLineEdit(InputsLine);
        SaturdayLInput->setObjectName(QString::fromUtf8("SaturdayLInput"));

        RightInputs->setWidget(5, QFormLayout::LabelRole, SaturdayLInput);

        SaturdayL = new QLabel(InputsLine);
        SaturdayL->setObjectName(QString::fromUtf8("SaturdayL"));

        RightInputs->setWidget(5, QFormLayout::FieldRole, SaturdayL);

        SaturdayDInput = new QLineEdit(InputsLine);
        SaturdayDInput->setObjectName(QString::fromUtf8("SaturdayDInput"));

        RightInputs->setWidget(6, QFormLayout::LabelRole, SaturdayDInput);

        SaturdayD = new QLabel(InputsLine);
        SaturdayD->setObjectName(QString::fromUtf8("SaturdayD"));

        RightInputs->setWidget(6, QFormLayout::FieldRole, SaturdayD);

        SundayBInput = new QLineEdit(InputsLine);
        SundayBInput->setObjectName(QString::fromUtf8("SundayBInput"));

        RightInputs->setWidget(7, QFormLayout::LabelRole, SundayBInput);

        SundayB = new QLabel(InputsLine);
        SundayB->setObjectName(QString::fromUtf8("SundayB"));

        RightInputs->setWidget(7, QFormLayout::FieldRole, SundayB);

        SundayLInput = new QLineEdit(InputsLine);
        SundayLInput->setObjectName(QString::fromUtf8("SundayLInput"));

        RightInputs->setWidget(8, QFormLayout::LabelRole, SundayLInput);

        SundayL = new QLabel(InputsLine);
        SundayL->setObjectName(QString::fromUtf8("SundayL"));

        RightInputs->setWidget(8, QFormLayout::FieldRole, SundayL);

        SundayDInput = new QLineEdit(InputsLine);
        SundayDInput->setObjectName(QString::fromUtf8("SundayDInput"));

        RightInputs->setWidget(9, QFormLayout::LabelRole, SundayDInput);

        SundayD = new QLabel(InputsLine);
        SundayD->setObjectName(QString::fromUtf8("SundayD"));

        RightInputs->setWidget(9, QFormLayout::FieldRole, SundayD);

        EmptyInput = new QLineEdit(InputsLine);
        EmptyInput->setObjectName(QString::fromUtf8("EmptyInput"));
        EmptyInput->setEnabled(false);

        RightInputs->setWidget(10, QFormLayout::LabelRole, EmptyInput);


        horizontalLayout_2->addLayout(RightInputs);


        verticalLayout_2->addWidget(InputsLine);


        verticalLayout->addWidget(InputsSection);

        ButtonsSection = new QFrame(BottomFrame);
        ButtonsSection->setObjectName(QString::fromUtf8("ButtonsSection"));
        ButtonsSection->setFrameShape(QFrame::StyledPanel);
        ButtonsSection->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(ButtonsSection);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CancelButton = new QPushButton(ButtonsSection);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        horizontalLayout->addWidget(CancelButton);

        SaveButton = new QPushButton(ButtonsSection);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));

        horizontalLayout->addWidget(SaveButton);

        WeekSelectorButton = new QPushButton(ButtonsSection);
        WeekSelectorButton->setObjectName(QString::fromUtf8("WeekSelectorButton"));

        horizontalLayout->addWidget(WeekSelectorButton);


        verticalLayout->addWidget(ButtonsSection);


        gridLayout->addWidget(BottomFrame, 1, 0, 1, 1);


        retranslateUi(WeeklyPlannerWidget);
        QObject::connect(CancelButton, SIGNAL(clicked()), WeeklyPlannerWidget, SLOT(CancelButtonClicked()));
        QObject::connect(SaveButton, SIGNAL(clicked()), WeeklyPlannerWidget, SLOT(SaveButtonClicked()));
        QObject::connect(WeekSelectorButton, SIGNAL(clicked()), WeeklyPlannerWidget, SLOT(WeekSelectorButtonClicked()));

        QMetaObject::connectSlotsByName(WeeklyPlannerWidget);
    } // setupUi

    void retranslateUi(QWidget *WeeklyPlannerWidget)
    {
        WeeklyPlannerWidget->setWindowTitle(QCoreApplication::translate("WeeklyPlannerWidget", "Form", nullptr));
        Title->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Weekly Planner", nullptr));
        WeekPlanDate->setText(QCoreApplication::translate("WeeklyPlannerWidget", "This week plan start the 03/07/2023", nullptr));
        MondayB->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Monday breakfast", nullptr));
        MondayL->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Monday lunch", nullptr));
        MondayD->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Monday dinner", nullptr));
        TuesdayB->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Tuesday breakfast", nullptr));
        TuesdayL->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Tuesday lunch", nullptr));
        TuesdayD->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Tuesday dinner", nullptr));
        WednesdayB->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Wednesday breakfast", nullptr));
        WednesdayL->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Wednesday lunch", nullptr));
        WednesdayD->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Wednesday dinner", nullptr));
        ThursdayB->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Thursday breakfast", nullptr));
        ThursdayL->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Thursday lunch", nullptr));
        ThursdayD->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Thursday dinner", nullptr));
        FridayB->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Friday breakfast", nullptr));
        FridayL->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Friday lunch", nullptr));
        FridayD->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Friday dinner", nullptr));
        SaturdayB->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Saturday breakfast", nullptr));
        SaturdayL->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Saturday lunch", nullptr));
        SaturdayD->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Saturday dinner", nullptr));
        SundayB->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Sunday breakfast", nullptr));
        SundayL->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Sunday lunch", nullptr));
        SundayD->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Sunday dinner", nullptr));
        CancelButton->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Cancel", nullptr));
        SaveButton->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Save", nullptr));
        WeekSelectorButton->setText(QCoreApplication::translate("WeeklyPlannerWidget", "Next week", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeeklyPlannerWidget: public Ui_WeeklyPlannerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WEEKLYPLANNERWIDGET_H
