/********************************************************************************
** Form generated from reading UI file 'LoginWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

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

class Ui_LoginWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *bottomFrame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *buttonLine;
    QPushButton *SigninButton;
    QPushButton *CancelButton;
    QPushButton *LoginButton;
    QFormLayout *forms;
    QLabel *emailLabel;
    QLineEdit *emailInput;
    QLabel *passwordLabel;
    QLineEdit *passwordInput;
    QFrame *topFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *Title;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(474, 321);
        gridLayout = new QGridLayout(LoginWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bottomFrame = new QFrame(LoginWidget);
        bottomFrame->setObjectName(QString::fromUtf8("bottomFrame"));
        bottomFrame->setContextMenuPolicy(Qt::DefaultContextMenu);
        bottomFrame->setFrameShape(QFrame::StyledPanel);
        bottomFrame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(bottomFrame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        buttonLine = new QHBoxLayout();
        buttonLine->setObjectName(QString::fromUtf8("buttonLine"));
        SigninButton = new QPushButton(bottomFrame);
        SigninButton->setObjectName(QString::fromUtf8("SigninButton"));

        buttonLine->addWidget(SigninButton);

        CancelButton = new QPushButton(bottomFrame);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        buttonLine->addWidget(CancelButton);

        LoginButton = new QPushButton(bottomFrame);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));

        buttonLine->addWidget(LoginButton);


        gridLayout_2->addLayout(buttonLine, 1, 0, 1, 1);

        forms = new QFormLayout();
        forms->setObjectName(QString::fromUtf8("forms"));
        emailLabel = new QLabel(bottomFrame);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));

        forms->setWidget(0, QFormLayout::LabelRole, emailLabel);

        emailInput = new QLineEdit(bottomFrame);
        emailInput->setObjectName(QString::fromUtf8("emailInput"));

        forms->setWidget(0, QFormLayout::FieldRole, emailInput);

        passwordLabel = new QLabel(bottomFrame);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        forms->setWidget(1, QFormLayout::LabelRole, passwordLabel);

        passwordInput = new QLineEdit(bottomFrame);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));

        forms->setWidget(1, QFormLayout::FieldRole, passwordInput);


        gridLayout_2->addLayout(forms, 0, 0, 1, 1);


        gridLayout->addWidget(bottomFrame, 1, 0, 1, 1);

        topFrame = new QFrame(LoginWidget);
        topFrame->setObjectName(QString::fromUtf8("topFrame"));
        topFrame->setFrameShape(QFrame::StyledPanel);
        topFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(topFrame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Title = new QLabel(topFrame);
        Title->setObjectName(QString::fromUtf8("Title"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        Title->setFont(font);
        Title->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(Title);


        gridLayout->addWidget(topFrame, 0, 0, 1, 1);


        retranslateUi(LoginWidget);
        QObject::connect(SigninButton, SIGNAL(clicked()), LoginWidget, SLOT(SigninButtonClicked()));
        QObject::connect(LoginButton, SIGNAL(clicked()), LoginWidget, SLOT(LoginButtonClicked()));
        QObject::connect(CancelButton, SIGNAL(clicked()), LoginWidget, SLOT(CancelButtonClicked()));

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "Form", nullptr));
        SigninButton->setText(QCoreApplication::translate("LoginWidget", "Signin", nullptr));
        CancelButton->setText(QCoreApplication::translate("LoginWidget", "Cancel", nullptr));
        LoginButton->setText(QCoreApplication::translate("LoginWidget", "Login", nullptr));
        emailLabel->setText(QCoreApplication::translate("LoginWidget", "Email", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginWidget", "Password", nullptr));
        Title->setText(QCoreApplication::translate("LoginWidget", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LOGINWIDGET_H
