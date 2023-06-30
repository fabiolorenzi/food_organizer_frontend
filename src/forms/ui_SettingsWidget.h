/********************************************************************************
** Form generated from reading UI file 'SettingsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *TopFrame;
    QGridLayout *gridLayout_2;
    QLabel *Title;
    QFrame *BottomFrame;
    QGridLayout *gridLayout_3;
    QFormLayout *Form;
    QLineEdit *usernameInput;
    QLabel *usernameLabel;
    QLineEdit *emailInput;
    QLabel *EmailLabel;
    QLineEdit *passwordInput;
    QLabel *PasswordLabel;
    QLineEdit *reinsertPasswordInput;
    QLabel *ReinsertPasswordLabel;
    QFrame *ButtonsLine;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *updateButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *SettingsWidget)
    {
        if (SettingsWidget->objectName().isEmpty())
            SettingsWidget->setObjectName(QString::fromUtf8("SettingsWidget"));
        SettingsWidget->resize(400, 300);
        gridLayout = new QGridLayout(SettingsWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TopFrame = new QFrame(SettingsWidget);
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

        BottomFrame = new QFrame(SettingsWidget);
        BottomFrame->setObjectName(QString::fromUtf8("BottomFrame"));
        BottomFrame->setFrameShape(QFrame::StyledPanel);
        BottomFrame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(BottomFrame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        Form = new QFormLayout();
        Form->setObjectName(QString::fromUtf8("Form"));
        usernameInput = new QLineEdit(BottomFrame);
        usernameInput->setObjectName(QString::fromUtf8("usernameInput"));

        Form->setWidget(0, QFormLayout::LabelRole, usernameInput);

        usernameLabel = new QLabel(BottomFrame);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        Form->setWidget(0, QFormLayout::FieldRole, usernameLabel);

        emailInput = new QLineEdit(BottomFrame);
        emailInput->setObjectName(QString::fromUtf8("emailInput"));

        Form->setWidget(1, QFormLayout::LabelRole, emailInput);

        EmailLabel = new QLabel(BottomFrame);
        EmailLabel->setObjectName(QString::fromUtf8("EmailLabel"));

        Form->setWidget(1, QFormLayout::FieldRole, EmailLabel);

        passwordInput = new QLineEdit(BottomFrame);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        passwordInput->setEchoMode(QLineEdit::Password);

        Form->setWidget(2, QFormLayout::LabelRole, passwordInput);

        PasswordLabel = new QLabel(BottomFrame);
        PasswordLabel->setObjectName(QString::fromUtf8("PasswordLabel"));

        Form->setWidget(2, QFormLayout::FieldRole, PasswordLabel);

        reinsertPasswordInput = new QLineEdit(BottomFrame);
        reinsertPasswordInput->setObjectName(QString::fromUtf8("reinsertPasswordInput"));
        reinsertPasswordInput->setEchoMode(QLineEdit::Password);

        Form->setWidget(3, QFormLayout::LabelRole, reinsertPasswordInput);

        ReinsertPasswordLabel = new QLabel(BottomFrame);
        ReinsertPasswordLabel->setObjectName(QString::fromUtf8("ReinsertPasswordLabel"));

        Form->setWidget(3, QFormLayout::FieldRole, ReinsertPasswordLabel);


        gridLayout_3->addLayout(Form, 0, 0, 1, 1);

        ButtonsLine = new QFrame(BottomFrame);
        ButtonsLine->setObjectName(QString::fromUtf8("ButtonsLine"));
        ButtonsLine->setFrameShape(QFrame::StyledPanel);
        ButtonsLine->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(ButtonsLine);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cancelButton = new QPushButton(ButtonsLine);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        updateButton = new QPushButton(ButtonsLine);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));

        horizontalLayout->addWidget(updateButton);

        deleteButton = new QPushButton(ButtonsLine);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout->addWidget(deleteButton);


        gridLayout_3->addWidget(ButtonsLine, 1, 0, 1, 1);


        gridLayout->addWidget(BottomFrame, 1, 0, 1, 1);


        retranslateUi(SettingsWidget);
        QObject::connect(cancelButton, SIGNAL(clicked()), SettingsWidget, SLOT(CancelButtonClicked()));
        QObject::connect(updateButton, SIGNAL(clicked()), SettingsWidget, SLOT(UpdateButtonClicked()));
        QObject::connect(deleteButton, SIGNAL(clicked()), SettingsWidget, SLOT(DeleteButtonClicked()));

        QMetaObject::connectSlotsByName(SettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *SettingsWidget)
    {
        SettingsWidget->setWindowTitle(QCoreApplication::translate("SettingsWidget", "Form", nullptr));
        Title->setText(QCoreApplication::translate("SettingsWidget", "Settings", nullptr));
        usernameLabel->setText(QCoreApplication::translate("SettingsWidget", "Username", nullptr));
        EmailLabel->setText(QCoreApplication::translate("SettingsWidget", "Email", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("SettingsWidget", "Password", nullptr));
        ReinsertPasswordLabel->setText(QCoreApplication::translate("SettingsWidget", "Reinsert password", nullptr));
        cancelButton->setText(QCoreApplication::translate("SettingsWidget", "Cancel", nullptr));
        updateButton->setText(QCoreApplication::translate("SettingsWidget", "Update", nullptr));
        deleteButton->setText(QCoreApplication::translate("SettingsWidget", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWidget: public Ui_SettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SETTINGSWIDGET_H
