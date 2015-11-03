/********************************************************************************
** Form generated from reading UI file 'bakeryselectn27101.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef BAKERYSELECTN27101_H
#define BAKERYSELECTN27101_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_bakerySelect
{
public:
    QVBoxLayout *verticalLayout;
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
        bakerySelect->setLayoutDirection(Qt::LeftToRight);
        bakerySelect->setWindowFilePath(QStringLiteral(""));
        bakerySelect->setSizeGripEnabled(false);
        bakerySelect->setModal(true);
        verticalLayout = new QVBoxLayout(bakerySelect);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        layout = new QFormLayout();
        layout->setObjectName(QStringLiteral("layout"));
        noAvailableBakeries = new QLabel(bakerySelect);
        noAvailableBakeries->setObjectName(QStringLiteral("noAvailableBakeries"));
        noAvailableBakeries->setAlignment(Qt::AlignCenter);

        layout->setWidget(0, QFormLayout::FieldRole, noAvailableBakeries);


        verticalLayout->addLayout(layout);


        retranslateUi(bakerySelect);

        QMetaObject::connectSlotsByName(bakerySelect);
    } // setupUi

    void retranslateUi(QDialog *bakerySelect)
    {
        bakerySelect->setWindowTitle(QApplication::translate("bakerySelect", "Panaderias", 0));
        noAvailableBakeries->setText(QApplication::translate("bakerySelect", "No hay panaderias disponibles", 0));
    } // retranslateUi

};

namespace Ui {
    class bakerySelect: public Ui_bakerySelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BAKERYSELECTN27101_H
