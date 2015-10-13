//
// Created by ricardo on 12/10/15.
//

#ifndef BOLLO_UI_LOGINDIALOG_H
#define BOLLO_UI_LOGINDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog {
public:
    QTabWidget* tabWidget;
    QWidget* tab;
    QWidget* verticalLayoutWidget_3;
    QVBoxLayout* verticalLayout_3;
    QVBoxLayout* verticalLayout_4;
    QLabel* label;
    QVBoxLayout* verticalLayout_5;
    QFormLayout* formLayout;
    QLabel* label_2;
    QLineEdit* qle_username;
    QLabel* label_3;
    QLineEdit* qle_password;
    QVBoxLayout* verticalLayout_6;
    QHBoxLayout* horizontalLayout;
    QPushButton* qb_login;
    QPushButton* qb_exit;
    QWidget* tab_2;
    QWidget* verticalLayoutWidget;
    QVBoxLayout* verticalLayout;
    QVBoxLayout* verticalLayout_7;
    QLabel* label_4;
    QFormLayout* formLayout_2;
    QLabel* label_5;
    QLineEdit* lineEdit;
    QLabel* label_6;
    QLineEdit* lineEdit_2;
    QLabel* label_7;
    QLineEdit* lineEdit_3;
    QLabel* label_8;
    QLineEdit* lineEdit_4;
    QLabel* label_9;
    QLineEdit* lineEdit_5;
    QVBoxLayout* verticalLayout_2;
    QHBoxLayout* horizontalLayout_2;
    QPushButton* pushButton_2;
    QPushButton* pushButton;

    void setupUi(QDialog* LoginDialog) {
        if(LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(BolloApp::windowTittle());
        LoginDialog->resize(273, 262);
        tabWidget = new QTabWidget(LoginDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 231, 241));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setTabBarAutoHide(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayoutWidget_3 = new QWidget(tab);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 10, 221, 179));
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

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 201, 192));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_7->addWidget(label_4, 0, Qt::AlignHCenter);


        verticalLayout->addLayout(verticalLayout_7);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_6);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_7);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_8);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setEchoMode(QLineEdit::Password);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lineEdit_4);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_9);

        lineEdit_5 = new QLineEdit(verticalLayoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, lineEdit_5);


        verticalLayout->addLayout(formLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_2);

        tabWidget->addTab(tab_2, QString());

        retranslateUi(LoginDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog* LoginDialog) {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "LoginDialog", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("LoginDialog", "Usuario:", 0));
        qle_username->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("LoginDialog", "Contrase\303\261a:", 0));
        qle_password->setPlaceholderText(QString());
        qb_login->setText(QApplication::translate("LoginDialog", "Entrar", 0));
        qb_exit->setText(QApplication::translate("LoginDialog", "Salir", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("LoginDialog", "Entrar", 0));
        label_4->setText(QApplication::translate("LoginDialog", "Registrarse", 0));
        label_5->setText(QApplication::translate("LoginDialog", "Nombre", 0));
        label_6->setText(QApplication::translate("LoginDialog", "Apellido", 0));
        label_7->setText(QApplication::translate("LoginDialog", "Usuario", 0));
        label_8->setText(QApplication::translate("LoginDialog", "Contrase\303\261a", 0));
        label_9->setText(QApplication::translate("LoginDialog", "Correo", 0));
        pushButton_2->setText(QApplication::translate("LoginDialog", "Registrarse", 0));
        pushButton->setText(QApplication::translate("LoginDialog", "Salir", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("LoginDialog", "Registrarse", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog : public Ui_LoginDialog {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H


#endif //BOLLO_UI_LOGINDIALOG_H
