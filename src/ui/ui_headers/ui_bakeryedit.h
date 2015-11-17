/********************************************************************************
** Form generated from reading UI file 'bakeryEditju2963.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef BAKERYEDITJU2963_H
#define BAKERYEDITJU2963_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BakeryEditDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *createTab;
    QLabel *label;
    QLineEdit *bakeryName;
    QLabel *label_2;
    QComboBox *stateList;
    QLabel *label_3;
    QLineEdit *bakeryCity;
    QPushButton *createBakeryBtn;
    QLabel *createBakeryStatus;
    QWidget *editTab;
    QLabel *label_4;
    QLineEdit *bakeryNameEdit;
    QLineEdit *bakeryCityEdit;
    QPushButton *saveBakery;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *stateListEdit;
    QComboBox *bakeriesList;
    QLabel *editBakeryStatus;

    void setupUi(QDialog *dialog)
    {
        if (dialog->objectName().isEmpty())
            dialog->setObjectName(QStringLiteral("dialog"));
        dialog->setWindowModality(Qt::NonModal);
        dialog->setEnabled(true);
        dialog->resize(333, 279);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/assets/hbread.png"), QSize(), QIcon::Normal, QIcon::Off);
        dialog->setWindowIcon(icon);
        dialog->setModal(true);
        verticalLayout = new QVBoxLayout(dialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        createTab = new QWidget();
        createTab->setObjectName(QStringLiteral("createTab"));
        label = new QLabel(createTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 17, 61, 31));
        bakeryName = new QLineEdit(createTab);
        bakeryName->setObjectName(QStringLiteral("bakeryName"));
        bakeryName->setGeometry(QRect(80, 20, 211, 28));
        bakeryName->setClearButtonEnabled(true);
        label_2 = new QLabel(createTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 57, 71, 31));
        stateList = new QComboBox(createTab);
        stateList->setObjectName(QStringLiteral("stateList"));
        stateList->setGeometry(QRect(80, 60, 111, 28));
        stateList->setLayoutDirection(Qt::LeftToRight);
        label_3 = new QLabel(createTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 100, 61, 31));
        bakeryCity = new QLineEdit(createTab);
        bakeryCity->setObjectName(QStringLiteral("bakeryCity"));
        bakeryCity->setGeometry(QRect(80, 100, 211, 28));
        bakeryCity->setClearButtonEnabled(true);
        createBakeryBtn = new QPushButton(createTab);
        createBakeryBtn->setObjectName(QStringLiteral("createBakeryBtn"));
        createBakeryBtn->setGeometry(QRect(210, 190, 85, 26));
        createBakeryStatus = new QLabel(createTab);
        createBakeryStatus->setObjectName(QStringLiteral("createBakeryStatus"));
        createBakeryStatus->setGeometry(QRect(10, 180, 191, 31));
        createBakeryStatus->setWordWrap(true);
        tabWidget->addTab(createTab, QString());
        editTab = new QWidget();
        editTab->setObjectName(QStringLiteral("editTab"));
        label_4 = new QLabel(editTab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 57, 61, 31));
        bakeryNameEdit = new QLineEdit(editTab);
        bakeryNameEdit->setObjectName(QStringLiteral("bakeryNameEdit"));
        bakeryNameEdit->setGeometry(QRect(80, 60, 211, 28));
        bakeryNameEdit->setClearButtonEnabled(true);
        bakeryCityEdit = new QLineEdit(editTab);
        bakeryCityEdit->setObjectName(QStringLiteral("bakeryCityEdit"));
        bakeryCityEdit->setGeometry(QRect(80, 140, 211, 28));
        bakeryCityEdit->setClearButtonEnabled(true);
        saveBakery = new QPushButton(editTab);
        saveBakery->setObjectName(QStringLiteral("saveBakery"));
        saveBakery->setGeometry(QRect(210, 190, 85, 26));
        label_5 = new QLabel(editTab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 97, 71, 31));
        label_6 = new QLabel(editTab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 140, 61, 31));
        stateListEdit = new QComboBox(editTab);
        stateListEdit->setObjectName(QStringLiteral("stateListEdit"));
        stateListEdit->setGeometry(QRect(80, 100, 111, 28));
        stateListEdit->setLayoutDirection(Qt::LeftToRight);
        bakeriesList = new QComboBox(editTab);
        bakeriesList->setObjectName(QStringLiteral("bakeriesList"));
        bakeriesList->setGeometry(QRect(10, 10, 291, 28));
        editBakeryStatus = new QLabel(editTab);
        editBakeryStatus->setObjectName(QStringLiteral("editBakeryStatus"));
        editBakeryStatus->setGeometry(QRect(10, 180, 191, 41));
        editBakeryStatus->setWordWrap(true);
        tabWidget->addTab(editTab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(dialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(dialog);
    } // setupUi

    void retranslateUi(QDialog *dialog)
    {
        dialog->setWindowTitle(QApplication::translate("dialog", "Panaderias", 0));
        label->setText(QApplication::translate("dialog", "Nombre", 0));
        label_2->setText(QApplication::translate("dialog", "Provincia", 0));
        stateList->clear();
        stateList->insertItems(0, QStringList()
                                  << QApplication::translate("dialog", "San Jose", 0)
                                  << QApplication::translate("dialog", "Alajuela", 0)
                                  << QApplication::translate("dialog", "Cartago", 0)
                                  << QApplication::translate("dialog", "Heredia", 0)
                                  << QApplication::translate("dialog", "Guanacaste", 0)
                                  << QApplication::translate("dialog", "Puntarenas", 0)
                                  << QApplication::translate("dialog", "Limon", 0)
        );
        label_3->setText(QApplication::translate("dialog", "Ciudad", 0));
        createBakeryBtn->setText(QApplication::translate("dialog", "Crear", 0));
        createBakeryStatus->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(createTab), QApplication::translate("dialog", "Nueva panaderia", 0));
        label_4->setText(QApplication::translate("dialog", "Nombre", 0));
        saveBakery->setText(QApplication::translate("dialog", "Guardar", 0));
        label_5->setText(QApplication::translate("dialog", "Provincia", 0));
        label_6->setText(QApplication::translate("dialog", "Ciudad", 0));
        stateListEdit->clear();
        stateListEdit->insertItems(0, QStringList()
                                      << QApplication::translate("dialog", "San Jose", 0)
                                      << QApplication::translate("dialog", "Alajuela", 0)
                                      << QApplication::translate("dialog", "Cartago", 0)
                                      << QApplication::translate("dialog", "Heredia", 0)
                                      << QApplication::translate("dialog", "Guanacaste", 0)
                                      << QApplication::translate("dialog", "Puntarenas", 0)
                                      << QApplication::translate("dialog", "Limon", 0)
        );
        editBakeryStatus->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(editTab), QApplication::translate("dialog", "Editar Panaderia", 0));
    } // retranslateUi

};

namespace Ui {
    class BakeryEdit: public Ui_BakeryEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BAKERYEDITJU2963_H
