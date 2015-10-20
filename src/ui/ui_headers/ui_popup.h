/********************************************************************************
** Form generated from reading UI file 'popup.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUP_H
#define UI_POPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Popup
{
public:
    QLabel *title;
    QFrame *divider;
    QPushButton *closeButton;
    QLabel *message;

    void setupUi(QDialog *Popup)
    {
        if (Popup->objectName().isEmpty())
            Popup->setObjectName(QStringLiteral("Popup"));
        Popup->resize(248, 100);
        title = new QLabel(Popup);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(20, 10, 211, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        divider = new QFrame(Popup);
        divider->setObjectName(QStringLiteral("divider"));
        divider->setGeometry(QRect(10, 30, 231, 16));
        divider->setFrameShape(QFrame::HLine);
        divider->setFrameShadow(QFrame::Sunken);
        closeButton = new QPushButton(Popup);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(220, 3, 20, 21));
        closeButton->setStyleSheet(QLatin1String("QPushButton {\n"
"	font: bold;\n"
"}"));
        closeButton->setFlat(false);
        message = new QLabel(Popup);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(20, 50, 221, 41));
        message->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        message->setWordWrap(true);

        retranslateUi(Popup);

        QMetaObject::connectSlotsByName(Popup);
    } // setupUi

    void retranslateUi(QDialog *Popup)
    {
        Popup->setWindowTitle(QApplication::translate("Popup", "Dialog", 0));
        title->setText(QApplication::translate("Popup", "Title", 0));
        closeButton->setText(QApplication::translate("Popup", "x", 0));
        message->setText(QApplication::translate("Popup", "Message", 0));
    } // retranslateUi

};

namespace Ui {
    class Popup: public Ui_Popup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUP_H
