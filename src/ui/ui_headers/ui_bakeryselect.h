/********************************************************************************
** Form generated from reading UI file 'bakeryselectth4037.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef BAKERYSELECTTH4037_H
#define BAKERYSELECTTH4037_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bakerySelect
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *contents;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *layout;
    QLabel *noAvailableBakeries;

    void setupUi(QDialog *bakerySelect)
    {
        if (bakerySelect->objectName().isEmpty())
            bakerySelect->setObjectName(QStringLiteral("bakerySelect"));
        bakerySelect->resize(500, 399);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bakerySelect->sizePolicy().hasHeightForWidth());
        bakerySelect->setSizePolicy(sizePolicy);
        bakerySelect->setMinimumSize(QSize(500, 399));
        bakerySelect->setMaximumSize(QSize(500, 399));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/assets/hbread.png"), QSize(), QIcon::Normal, QIcon::Off);
        bakerySelect->setWindowIcon(icon);
        bakerySelect->setLayoutDirection(Qt::LeftToRight);
        bakerySelect->setWindowFilePath(QStringLiteral(""));
        bakerySelect->setSizeGripEnabled(false);
        bakerySelect->setModal(true);
        verticalLayout = new QVBoxLayout(bakerySelect);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scrollArea = new QScrollArea(bakerySelect);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        contents = new QWidget();
        contents->setObjectName(QStringLiteral("contents"));
        contents->setGeometry(QRect(0, 0, 480, 379));
        verticalLayout_2 = new QVBoxLayout(contents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        layout = new QFormLayout();
        layout->setObjectName(QStringLiteral("layout"));
        noAvailableBakeries = new QLabel(contents);
        noAvailableBakeries->setObjectName(QStringLiteral("noAvailableBakeries"));
        noAvailableBakeries->setAlignment(Qt::AlignCenter);

        layout->setWidget(0, QFormLayout::SpanningRole, noAvailableBakeries);


        verticalLayout_2->addLayout(layout);

        scrollArea->setWidget(contents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(bakerySelect);

        QMetaObject::connectSlotsByName(bakerySelect);
    } // setupUi

    void retranslateUi(QDialog *bakerySelect)
    {
        bakerySelect->setWindowTitle(QApplication::translate("bakerySelect", "Seleccione una panaderia", 0));
        noAvailableBakeries->setText(QApplication::translate("bakerySelect", "No hay panaderias disponibles", 0));
    } // retranslateUi

};

namespace Ui {
    class bakerySelect: public Ui_bakerySelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BAKERYSELECTTH4037_H
