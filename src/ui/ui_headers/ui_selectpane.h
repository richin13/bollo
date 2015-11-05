/********************************************************************************
** Form generated from reading UI file 'selectpanepN8967.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SELECTPANEPN8967_H
#define SELECTPANEPN8967_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectWindow
{
public:
    QScrollArea *chartsWebView;
    QWidget *content;
    QLabel *title1;
    QWidget *formWidget;
    QFormLayout *bakeriesView;
    QLabel *noAvailableBakeries;

    void setupUi(QWidget *selectWindow)
    {
        if (selectWindow->objectName().isEmpty())
            selectWindow->setObjectName(QStringLiteral("selectWindow"));
        selectWindow->resize(990, 440);
        chartsWebView = new QScrollArea(selectWindow);
        chartsWebView->setObjectName(QStringLiteral("chartsWebView"));
        chartsWebView->setGeometry(QRect(360, 10, 621, 421));
        chartsWebView->setWidgetResizable(true);
        content = new QWidget();
        content->setObjectName(QStringLiteral("content"));
        content->setGeometry(QRect(0, 0, 619, 419));
        chartsWebView->setWidget(content);
        title1 = new QLabel(selectWindow);
        title1->setObjectName(QStringLiteral("title1"));
        title1->setGeometry(QRect(150, 10, 81, 18));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        title1->setFont(font);
        formWidget = new QWidget(selectWindow);
        formWidget->setObjectName(QStringLiteral("formWidget"));
        formWidget->setGeometry(QRect(10, 30, 341, 401));
        bakeriesView = new QFormLayout(formWidget);
        bakeriesView->setObjectName(QStringLiteral("bakeriesView"));
        noAvailableBakeries = new QLabel(formWidget);
        noAvailableBakeries->setObjectName(QStringLiteral("noAvailableBakeries"));
        noAvailableBakeries->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        bakeriesView->setWidget(0, QFormLayout::SpanningRole, noAvailableBakeries);


        retranslateUi(selectWindow);

        QMetaObject::connectSlotsByName(selectWindow);
    } // setupUi

    void retranslateUi(QWidget *selectWindow)
    {
        selectWindow->setWindowTitle(QApplication::translate("selectWindow", "Form", 0));
        title1->setText(QApplication::translate("selectWindow", "Panaderias", 0));
        noAvailableBakeries->setText(QApplication::translate("selectWindow", "No hay panaderias disponibles", 0));
    } // retranslateUi

};

namespace Ui {
    class selectWindow: public Ui_selectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SELECTPANEPN8967_H
