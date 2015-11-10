/********************************************************************************
** Form generated from reading UI file 'aboutfY2713.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ABOUTFY2713_H
#define ABOUTFY2713_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *icon;
    QTextBrowser *aboutText;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(514, 373);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/assets/hbread.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon1);
        Dialog->setStyleSheet(QStringLiteral(""));
        Dialog->setModal(true);
        icon = new QLabel(Dialog);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setGeometry(QRect(200, 10, 111, 111));
        icon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/hbread.png")));
        icon->setScaledContents(true);
        aboutText = new QTextBrowser(Dialog);
        aboutText->setObjectName(QStringLiteral("aboutText"));
        aboutText->setGeometry(QRect(10, 130, 491, 231));
        aboutText->setOpenExternalLinks(true);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Acerca de", 0));
        icon->setText(QString());
        aboutText->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
                "p, li { white-space: pre-wrap; }\n"
                "</style></head><body style=\" font-family:'Cantarell'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
                "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Bollo App</span></p>\n"
                "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Pre-Alpha (Baguette)</span></p>\n"
                "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-lef"
                "t:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Bollo</span> es un sencillo pero poderoso y extensible sistema de administraci\303\263n de panader\303\255as. Est\303\241 compuesto por una aplicaci\303\263n central de monitoreo (esta aplicacion) y un sistema web accesible desde cualquier parte del mundo para consultar y configurar el funcionamiento de las panader\303\255as que se administran mediante el sistema. Ambos sistemas coexisten gracias a una interfaz de programa de aplicaci\303\263n (API) que gestiona el acceso a los recursos de informaci\303\263n utilizados por ambos sistemas. </p>\n"
                "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ademas <span style=\" font-weight:600;\">Bollo</span> c"
                "uenta con la integracion de una de las mejores aplicaciones de mensajeria instantanea <span style=\" font-weight:600;\">Telegram</span>, con la cual puede recibir informacion acerca de sus panaderias y consultar el estado de ellas, atraves de <span style=\" font-weight:600;\">Bollo Bot</span>.</p>\n"
                "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Bollo </span>y sus servicios son desarrollados con:</p>\n"
                "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent"
                ":0px;\"><span style=\" font-weight:600;\">- Lenguages: </span>C++, PHP, Javascript.</p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">- Frameworks:</span>  QT, Node js, jQuery, Bootstrap, Doxygen.</p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">- Bases de datos: </span>PostgreSQL.</p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">- Web servers: </span>AWS, Heroku, Bitnami, Google Cloud.</p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">- Utilidades:</span> Clion (Jetbrains), Atom, Git, Github, "
                "Travis CI, Slack, Arch linux.</p>\n"
                "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Desarrolladores:</span></p>\n"
                "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;\"><br /></p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Ricardo Madriz Calderon - Software Developer.</p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Daniel Castillo Levia - Software Developer.</p>\n"
                "<p align=\"justify\""
                " style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Daniel Aguilar Soto - Software Developer.</p>\n"
                "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Puede consultar algunos de los servicios de <span style=\" font-weight:600;\">Bollo</span> aqui:</p>\n"
                "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"http://bollo-server.bitnamiapp.com/\"><span style=\" text-decoration: underline; color:#0000ff;\">Bollo"
                " Web</span></a></p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"http://bollostatus.tk/\"><span style=\" text-decoration: underline; color:#0000ff;\">Bollo Services Status</span></a></p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"http://bollobot.herokuapp.com/\"><span style=\" text-decoration: underline; color:#0000ff;\">Bollo Bot</span></a></p>\n"
                "<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; text-decoration: underline; color:#0000ff;\"><br /></p>\n"
                "<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Desarrollado con mucha pasion, cafe y amor.</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ABOUTFY2713_H
