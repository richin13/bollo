/********************************************************************************
** Form generated from reading UI file 'bakeryEditVY2713.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef BAKERYEDITVY2713_H
#define BAKERYEDITVY2713_H

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

class Ui_dialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLineEdit *bakeryName;
    QLabel *label_2;
    QComboBox *stateList;
    QLabel *label_3;
    QLineEdit *bakeryCity;
    QPushButton *createBakeryBtn;
    QWidget *tab_2;
    QLabel *label_4;
    QLineEdit *bakeryNameEdit;
    QLineEdit *bakeryCityEdit;
    QPushButton *saveBakery;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *stateListEdit;
    QComboBox *bakeriesList;

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
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 17, 61, 31));
        bakeryName = new QLineEdit(tab);
        bakeryName->setObjectName(QStringLiteral("bakeryName"));
        bakeryName->setGeometry(QRect(80, 20, 211, 28));
        bakeryName->setClearButtonEnabled(true);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 57, 71, 31));
        stateList = new QComboBox(tab);
        stateList->setObjectName(QStringLiteral("stateList"));
        stateList->setGeometry(QRect(80, 60, 111, 28));
        stateList->setLayoutDirection(Qt::LeftToRight);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 100, 61, 31));
        bakeryCity = new QLineEdit(tab);
        bakeryCity->setObjectName(QStringLiteral("bakeryCity"));
        bakeryCity->setGeometry(QRect(80, 100, 211, 28));
        bakeryCity->setClearButtonEnabled(true);
        createBakeryBtn = new QPushButton(tab);
        createBakeryBtn->setObjectName(QStringLiteral("createBakeryBtn"));
        createBakeryBtn->setGeometry(QRect(210, 190, 85, 26));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 57, 61, 31));
        bakeryNameEdit = new QLineEdit(tab_2);
        bakeryNameEdit->setObjectName(QStringLiteral("bakeryNameEdit"));
        bakeryNameEdit->setGeometry(QRect(80, 60, 211, 28));
        bakeryNameEdit->setClearButtonEnabled(true);
        bakeryCityEdit = new QLineEdit(tab_2);
        bakeryCityEdit->setObjectName(QStringLiteral("bakeryCityEdit"));
        bakeryCityEdit->setGeometry(QRect(80, 140, 211, 28));
        bakeryCityEdit->setClearButtonEnabled(true);
        saveBakery = new QPushButton(tab_2);
        saveBakery->setObjectName(QStringLiteral("saveBakery"));
        saveBakery->setGeometry(QRect(210, 190, 85, 26));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 97, 71, 31));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 140, 61, 31));
        stateListEdit = new QComboBox(tab_2);
        stateListEdit->setObjectName(QStringLiteral("stateListEdit"));
        stateListEdit->setGeometry(QRect(80, 100, 111, 28));
        stateListEdit->setLayoutDirection(Qt::LeftToRight);
        bakeriesList = new QComboBox(tab_2);
        bakeriesList->setObjectName(QStringLiteral("bakeriesList"));
        bakeriesList->setGeometry(QRect(10, 10, 291, 28));
        tabWidget->addTab(tab_2, QString());

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
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("dialog", "Nueva panaderia", 0));
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
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("dialog", "Editar Panaderia", 0));
    } // retranslateUi

};

namespace Ui {
    class BakeryEdit: public Ui_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BAKERYEDITVY2713_H
