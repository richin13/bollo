/********************************************************************************
** Form generated from reading UI file 'logindialogPu5106.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LOGINDIALOGPU5106_H
#define LOGINDIALOGPU5106_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *qle_username;
    QLabel *label_3;
    QLineEdit *qle_password;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *qb_login;
    QPushButton *qb_exit;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(273, 225);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/assets/hbread.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoginDialog->setWindowIcon(icon);
        LoginDialog->setModal(true);
        verticalLayoutWidget_3 = new QWidget(LoginDialog);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(30, 30, 214, 160));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::NoFrame);
        label->setPixmap(QPixmap(QString::fromUtf8("resource/user.png")));
        label->setScaledContents(false);

        verticalLayout_4->addWidget(label, 0, Qt::AlignHCenter);


        verticalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, -1, 5, -1);
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        qle_username = new QLineEdit(verticalLayoutWidget_3);
        qle_username->setObjectName(QStringLiteral("qle_username"));

        formLayout->setWidget(0, QFormLayout::FieldRole, qle_username);

        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        qle_password = new QLineEdit(verticalLayoutWidget_3);
        qle_password->setObjectName(QStringLiteral("qle_password"));
        qle_password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, qle_password);


        verticalLayout_5->addLayout(formLayout);


        verticalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, -1, -1);
        qb_login = new QPushButton(verticalLayoutWidget_3);
        qb_login->setObjectName(QStringLiteral("qb_login"));

        horizontalLayout->addWidget(qb_login);

        qb_exit = new QPushButton(verticalLayoutWidget_3);
        qb_exit->setObjectName(QStringLiteral("qb_exit"));

        horizontalLayout->addWidget(qb_exit);


        verticalLayout_6->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_6);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "LoginDialog", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("LoginDialog", "Usuario:", 0));
        qle_username->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("LoginDialog", "Contrase\303\261a:", 0));
        qle_password->setPlaceholderText(QString());
        qb_login->setText(QApplication::translate("LoginDialog", "Entrar", 0));
        qb_exit->setText(QApplication::translate("LoginDialog", "Salir", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LOGINDIALOGPU5106_H
