/********************************************************************************
** Form generated from reading UI file 'graphbrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHBROWSER_H
#define UI_GRAPHBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartsBrowser
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *layout;
    QComboBox *bakeriesList;
    QScrollArea *scrollArea;
    QWidget *scrollAreaContents;

    void setupUi(QDialog *ChartsBrowser)
    {
        if (ChartsBrowser->objectName().isEmpty())
            ChartsBrowser->setObjectName(QStringLiteral("GraphBrowser"));
        ChartsBrowser->resize(808, 527);
        verticalLayout_2 = new QVBoxLayout(ChartsBrowser);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        layout = new QVBoxLayout();
        layout->setSpacing(6);
        layout->setObjectName(QStringLiteral("layout"));
        bakeriesList = new QComboBox(ChartsBrowser);
        bakeriesList->setObjectName(QStringLiteral("bakeriesList"));

        layout->addWidget(bakeriesList);

        scrollArea = new QScrollArea(ChartsBrowser);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaContents = new QWidget();
        scrollAreaContents->setObjectName(QStringLiteral("scrollAreaContents"));
        scrollAreaContents->setGeometry(QRect(0, 0, 786, 471));
        scrollArea->setWidget(scrollAreaContents);

        layout->addWidget(scrollArea);


        verticalLayout_2->addLayout(layout);


        retranslateUi(ChartsBrowser);

        QMetaObject::connectSlotsByName(ChartsBrowser);
    } // setupUi

    void retranslateUi(QDialog *ChartsBrowser)
    {
        ChartsBrowser->setWindowTitle(QApplication::translate("GraphBrowser", "Navegador de Graficos", 0));
        bakeriesList->clear();
        bakeriesList->insertItems(0, QStringList()
                                     << QApplication::translate("GraphBrowser", "General", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class ChartsBrowser: public Ui_ChartsBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHBROWSER_H