/********************************************************************************
** Form generated from reading UI file 'bakeryselect.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAKERYSELECT_H
#define UI_BAKERYSELECT_H

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
    QLabel *label;

    void setupUi(QDialog *bakerySelect)
    {
        if (bakerySelect->objectName().isEmpty())
            bakerySelect->setObjectName(QStringLiteral("bakerySelect"));
        bakerySelect->resize(371, 399);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bakerySelect->sizePolicy().hasHeightForWidth());
        bakerySelect->setSizePolicy(sizePolicy);
        bakerySelect->setMinimumSize(QSize(371, 399));
        bakerySelect->setMaximumSize(QSize(371, 399));
        bakerySelect->setLayoutDirection(Qt::LeftToRight);
        bakerySelect->setSizeGripEnabled(false);
        bakerySelect->setModal(true);
        verticalLayout = new QVBoxLayout(bakerySelect);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        layout = new QFormLayout();
        layout->setObjectName(QStringLiteral("layout"));
        label = new QLabel(bakerySelect);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        layout->setWidget(0, QFormLayout::FieldRole, label);


        verticalLayout->addLayout(layout);


        retranslateUi(bakerySelect);

        QMetaObject::connectSlotsByName(bakerySelect);
    } // setupUi

    void retranslateUi(QDialog *bakerySelect)
    {
        bakerySelect->setWindowTitle(QApplication::translate("bakerySelect", "Panaderias", 0));
        label->setText(QApplication::translate("bakerySelect", "No hay panaderias disponibles", 0));
    } // retranslateUi

};

namespace Ui {
    class bakerySelect: public Ui_bakerySelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAKERYSELECT_H
