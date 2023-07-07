/********************************************************************************
** Form generated from reading UI file 'StorageWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef STORAGEWIDGET_H
#define STORAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StorageWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *TopFrame;
    QGridLayout *gridLayout_2;
    QLabel *Title;
    QFrame *BottomFrame;
    QGridLayout *gridLayout_5;
    QFrame *ListFrame;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *ListFrameLine;
    QFrame *InputsFrame;
    QGridLayout *gridLayout_4;
    QFormLayout *Inputs;
    QLineEdit *NameInput;
    QLabel *NameLabel;
    QLabel *PositionLabel;
    QLineEdit *QuantityInput;
    QLabel *QuantityLabel;
    QLineEdit *ExpireDateInput;
    QLabel *ExpireDateLabel;
    QLineEdit *PositionInput;
    QFrame *InputsButtonsLine;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *CancelButton;
    QPushButton *CreateButton;

    void setupUi(QWidget *StorageWidget)
    {
        if (StorageWidget->objectName().isEmpty())
            StorageWidget->setObjectName(QString::fromUtf8("StorageWidget"));
        StorageWidget->resize(754, 593);
        gridLayout = new QGridLayout(StorageWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TopFrame = new QFrame(StorageWidget);
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

        BottomFrame = new QFrame(StorageWidget);
        BottomFrame->setObjectName(QString::fromUtf8("BottomFrame"));
        BottomFrame->setFrameShape(QFrame::StyledPanel);
        BottomFrame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(BottomFrame);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        ListFrame = new QFrame(BottomFrame);
        ListFrame->setObjectName(QString::fromUtf8("ListFrame"));
        ListFrame->setFrameShape(QFrame::StyledPanel);
        ListFrame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(ListFrame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        scrollArea = new QScrollArea(ListFrame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        ListFrameLine = new QWidget();
        ListFrameLine->setObjectName(QString::fromUtf8("ListFrameLine"));
        ListFrameLine->setGeometry(QRect(0, 0, 694, 282));
        scrollArea->setWidget(ListFrameLine);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout_5->addWidget(ListFrame, 0, 0, 1, 1);

        InputsFrame = new QFrame(BottomFrame);
        InputsFrame->setObjectName(QString::fromUtf8("InputsFrame"));
        InputsFrame->setFrameShape(QFrame::StyledPanel);
        InputsFrame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(InputsFrame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        Inputs = new QFormLayout();
        Inputs->setObjectName(QString::fromUtf8("Inputs"));
        NameInput = new QLineEdit(InputsFrame);
        NameInput->setObjectName(QString::fromUtf8("NameInput"));

        Inputs->setWidget(0, QFormLayout::LabelRole, NameInput);

        NameLabel = new QLabel(InputsFrame);
        NameLabel->setObjectName(QString::fromUtf8("NameLabel"));

        Inputs->setWidget(0, QFormLayout::FieldRole, NameLabel);

        PositionLabel = new QLabel(InputsFrame);
        PositionLabel->setObjectName(QString::fromUtf8("PositionLabel"));

        Inputs->setWidget(1, QFormLayout::FieldRole, PositionLabel);

        QuantityInput = new QLineEdit(InputsFrame);
        QuantityInput->setObjectName(QString::fromUtf8("QuantityInput"));

        Inputs->setWidget(2, QFormLayout::LabelRole, QuantityInput);

        QuantityLabel = new QLabel(InputsFrame);
        QuantityLabel->setObjectName(QString::fromUtf8("QuantityLabel"));

        Inputs->setWidget(2, QFormLayout::FieldRole, QuantityLabel);

        ExpireDateInput = new QLineEdit(InputsFrame);
        ExpireDateInput->setObjectName(QString::fromUtf8("ExpireDateInput"));

        Inputs->setWidget(3, QFormLayout::LabelRole, ExpireDateInput);

        ExpireDateLabel = new QLabel(InputsFrame);
        ExpireDateLabel->setObjectName(QString::fromUtf8("ExpireDateLabel"));

        Inputs->setWidget(3, QFormLayout::FieldRole, ExpireDateLabel);

        PositionInput = new QLineEdit(InputsFrame);
        PositionInput->setObjectName(QString::fromUtf8("PositionInput"));

        Inputs->setWidget(1, QFormLayout::LabelRole, PositionInput);


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


        gridLayout_5->addWidget(InputsFrame, 1, 0, 1, 1);


        gridLayout->addWidget(BottomFrame, 1, 0, 1, 1);


        retranslateUi(StorageWidget);
        QObject::connect(CancelButton, SIGNAL(clicked()), StorageWidget, SLOT(CancelButtonClicked()));
        QObject::connect(CreateButton, SIGNAL(clicked()), StorageWidget, SLOT(CreateButtonClicked()));

        QMetaObject::connectSlotsByName(StorageWidget);
    } // setupUi

    void retranslateUi(QWidget *StorageWidget)
    {
        StorageWidget->setWindowTitle(QCoreApplication::translate("StorageWidget", "Form", nullptr));
        Title->setText(QCoreApplication::translate("StorageWidget", "Storage", nullptr));
        NameLabel->setText(QCoreApplication::translate("StorageWidget", "Name", nullptr));
        PositionLabel->setText(QCoreApplication::translate("StorageWidget", "Position", nullptr));
        QuantityLabel->setText(QCoreApplication::translate("StorageWidget", "Quantity", nullptr));
        ExpireDateLabel->setText(QCoreApplication::translate("StorageWidget", "Expire Date (yyyy-mm-dd)", nullptr));
        CancelButton->setText(QCoreApplication::translate("StorageWidget", "Cancel", nullptr));
        CreateButton->setText(QCoreApplication::translate("StorageWidget", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StorageWidget: public Ui_StorageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // STORAGEWIDGET_H
