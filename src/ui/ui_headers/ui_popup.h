/********************************************************************************
** Form generated from reading UI file 'popupJy2713.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef POPUPJY2713_H
#define POPUPJY2713_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Popup
{
public:
    QLabel *message;

    void setupUi(QDialog *Popup)
    {
        if (Popup->objectName().isEmpty())
            Popup->setObjectName(QStringLiteral("Popup"));
        Popup->resize(248, 100);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/assets/hbread.png"), QSize(), QIcon::Normal, QIcon::Off);
        Popup->setWindowIcon(icon);
        message = new QLabel(Popup);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(20, 10, 221, 81));
        message->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        message->setWordWrap(true);

        retranslateUi(Popup);

        QMetaObject::connectSlotsByName(Popup);
    } // setupUi

    void retranslateUi(QDialog *Popup)
    {
        Popup->setWindowTitle(QApplication::translate("Popup", "Dialog", 0));
        message->setText(QApplication::translate("Popup", "Message", 0));
    } // retranslateUi

};

namespace Ui {
    class Popup: public Ui_Popup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // POPUPJY2713_H
