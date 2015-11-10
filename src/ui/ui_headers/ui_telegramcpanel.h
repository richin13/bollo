/********************************************************************************
** Form generated from reading UI file 'telegramcpanelPS2713.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TELEGRAMCPANELPS2713_H
#define TELEGRAMCPANELPS2713_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_TelegramCpanel
{
public:
    QTextBrowser *instructionsText;
    QLineEdit *chatIDInput;
    QPushButton *sendButton;

    void setupUi(QDialog *TelegramCpanel)
    {
        if (TelegramCpanel->objectName().isEmpty())
            TelegramCpanel->setObjectName(QStringLiteral("TelegramCpanel"));
        TelegramCpanel->resize(449, 387);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/assets/hbread.png"), QSize(), QIcon::Normal, QIcon::Off);
        TelegramCpanel->setWindowIcon(icon);
        TelegramCpanel->setModal(true);
        instructionsText = new QTextBrowser(TelegramCpanel);
        instructionsText->setObjectName(QStringLiteral("instructionsText"));
        instructionsText->setGeometry(QRect(9, 9, 431, 331));
        chatIDInput = new QLineEdit(TelegramCpanel);
        chatIDInput->setObjectName(QStringLiteral("chatIDInput"));
        chatIDInput->setGeometry(QRect(160, 350, 81, 21));
        sendButton = new QPushButton(TelegramCpanel);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(250, 350, 51, 21));
        sendButton->setFocusPolicy(Qt::StrongFocus);
        sendButton->setAutoDefault(false);

        retranslateUi(TelegramCpanel);

        QMetaObject::connectSlotsByName(TelegramCpanel);
    } // setupUi

    void retranslateUi(QDialog *TelegramCpanel)
    {
        TelegramCpanel->setWindowTitle(QApplication::translate("TelegramCpanel", "Telegram Integration", 0));
        instructionsText->setHtml(QApplication::translate("TelegramCpanel", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
                "p, li { white-space: pre-wrap; }\n"
                "</style></head><body style=\" font-family:'Cantarell'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
                "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">Bollo app es capaz de notificarle acerca del estado de su panaderia atravez de la aplicacion de mensajeria instantanea Telegram, gracias a su poderosa API es posible integrar de manera agil los servicios de esta aplicacion para su beneficio. Para poder disponer de estos servicios tan solo debe seguir estos pasos:</span></p>\n"
                "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'"
                "; font-size:8.25pt;\"><br /></p>\n"
                "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">1)  Descargar la aplicacion para cualquier plataforma. En la </span><a href=\"https://telegram.org/\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; text-decoration: underline; color:#007af4;\">pagina oficial </span></a><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">puede encontrar los enlaces para cada una.</span></p>\n"
                "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p>\n"
                "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">2) Registrarse y crear una cuenta.</span></p>\n"
                "<"
                "p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p>\n"
                "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">3) Debera crear un chat con el </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-style:italic;\">BolloBot  </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">en este </span><a href=\"telegram.me/bollo_bot\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; text-decoration: underline; color:#007af4;\">enlace.</span></a></p>\n"
                "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt; text-decoration: underline; color:#007af4;\"><br /></p>\n"
                ""
                "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">4) Aparecera un boton de start (hacer click en el) o de inmediato el bot le dara una bienvenida y le dara su ID.</span></p>\n"
                "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p>\n"
                "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">5) Debe introducir el ID brindado por </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-style:italic;\">BolloBot</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">  e introducirlo en el recuadro ubicado abajo de estas instrucciones.</span></p>\n"
                "<p style=\"-qt-paragra"
                "ph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p>\n"
                "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">6) Si el ID es correcto recibira un mensaje de confirmacion de </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-style:italic;\">BolloBot  </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">y</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-style:italic;\"> </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">estara listo para usarse.</span></p>\n"
                "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p>\n"
                "<"
                "p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">7) En caso de no recibir confirmacion de </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-style:italic;\">BolloBot  </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">intente de nuevo despues de varios minutos o revise si el ID es correcto.</span></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        chatIDInput->setToolTip(QApplication::translate("TelegramCpanel", "Agregue aqui su ID", 0));
#endif // QT_NO_TOOLTIP
        sendButton->setText(QApplication::translate("TelegramCpanel", "Enviar", 0));
    } // retranslateUi

};

namespace Ui {
    class TelegramCpanel: public Ui_TelegramCpanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TELEGRAMCPANELPS2713_H
