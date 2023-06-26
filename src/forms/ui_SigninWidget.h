/********************************************************************************
** Form generated from reading UI file 'SigninWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

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

class Ui_SigninWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *topFrame;
    QGridLayout *gridLayout_2;
    QLabel *Title;
    QFrame *bottomFrame;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLineEdit *usernameInput;
    QLabel *usernameLabel;
    QLineEdit *emailInput;
    QLabel *emailLabel;
    QLineEdit *passwordInput;
    QLabel *passwordLabel;
    QLineEdit *reinsertPasswordInput;
    QLabel *reinsertPasswordLabel;
    QHBoxLayout *buttonsLine;
    QPushButton *LoginButton;
    QPushButton *CancelButton;
    QPushButton *SigninButton;

    void setupUi(QWidget *SigninWidget)
    {
        if (SigninWidget->objectName().isEmpty())
            SigninWidget->setObjectName(QString::fromUtf8("SigninWidget"));
        SigninWidget->resize(400, 300);
        gridLayout = new QGridLayout(SigninWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        topFrame = new QFrame(SigninWidget);
        topFrame->setObjectName(QString::fromUtf8("topFrame"));
        topFrame->setFrameShape(QFrame::StyledPanel);
        topFrame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(topFrame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Title = new QLabel(topFrame);
        Title->setObjectName(QString::fromUtf8("Title"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        Title->setFont(font);
        Title->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(Title, 0, 0, 1, 1);


        gridLayout->addWidget(topFrame, 0, 0, 1, 1);

        bottomFrame = new QFrame(SigninWidget);
        bottomFrame->setObjectName(QString::fromUtf8("bottomFrame"));
        bottomFrame->setFrameShape(QFrame::StyledPanel);
        bottomFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(bottomFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        usernameInput = new QLineEdit(bottomFrame);
        usernameInput->setObjectName(QString::fromUtf8("usernameInput"));

        formLayout->setWidget(0, QFormLayout::LabelRole, usernameInput);

        usernameLabel = new QLabel(bottomFrame);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameLabel);

        emailInput = new QLineEdit(bottomFrame);
        emailInput->setObjectName(QString::fromUtf8("emailInput"));

        formLayout->setWidget(1, QFormLayout::LabelRole, emailInput);

        emailLabel = new QLabel(bottomFrame);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, emailLabel);

        passwordInput = new QLineEdit(bottomFrame);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        passwordInput->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::LabelRole, passwordInput);

        passwordLabel = new QLabel(bottomFrame);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout->setWidget(2, QFormLayout::FieldRole, passwordLabel);

        reinsertPasswordInput = new QLineEdit(bottomFrame);
        reinsertPasswordInput->setObjectName(QString::fromUtf8("reinsertPasswordInput"));
        reinsertPasswordInput->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::LabelRole, reinsertPasswordInput);

        reinsertPasswordLabel = new QLabel(bottomFrame);
        reinsertPasswordLabel->setObjectName(QString::fromUtf8("reinsertPasswordLabel"));

        formLayout->setWidget(3, QFormLayout::FieldRole, reinsertPasswordLabel);


        verticalLayout->addLayout(formLayout);

        buttonsLine = new QHBoxLayout();
        buttonsLine->setObjectName(QString::fromUtf8("buttonsLine"));
        LoginButton = new QPushButton(bottomFrame);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));

        buttonsLine->addWidget(LoginButton);

        CancelButton = new QPushButton(bottomFrame);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        buttonsLine->addWidget(CancelButton);

        SigninButton = new QPushButton(bottomFrame);
        SigninButton->setObjectName(QString::fromUtf8("SigninButton"));

        buttonsLine->addWidget(SigninButton);


        verticalLayout->addLayout(buttonsLine);


        gridLayout->addWidget(bottomFrame, 1, 0, 1, 1);


        retranslateUi(SigninWidget);
        QObject::connect(SigninButton, SIGNAL(clicked()), SigninWidget, SLOT(SigninButtonClicked()));
        QObject::connect(CancelButton, SIGNAL(clicked()), SigninWidget, SLOT(CancelButtonClicked()));
        QObject::connect(LoginButton, SIGNAL(clicked()), SigninWidget, SLOT(LoginButtonClicked()));

        QMetaObject::connectSlotsByName(SigninWidget);
    } // setupUi

    void retranslateUi(QWidget *SigninWidget)
    {
        SigninWidget->setWindowTitle(QCoreApplication::translate("SigninWidget", "Form", nullptr));
        Title->setText(QCoreApplication::translate("SigninWidget", "Sign in", nullptr));
        usernameLabel->setText(QCoreApplication::translate("SigninWidget", "Username", nullptr));
        emailLabel->setText(QCoreApplication::translate("SigninWidget", "Email", nullptr));
        passwordLabel->setText(QCoreApplication::translate("SigninWidget", "Password", nullptr));
        reinsertPasswordLabel->setText(QCoreApplication::translate("SigninWidget", "Reinsert password", nullptr));
        LoginButton->setText(QCoreApplication::translate("SigninWidget", "Login", nullptr));
        CancelButton->setText(QCoreApplication::translate("SigninWidget", "Cancel", nullptr));
        SigninButton->setText(QCoreApplication::translate("SigninWidget", "Sign in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SigninWidget: public Ui_SigninWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SIGNINWIDGET_H
