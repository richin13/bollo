//
// Created by ricardo on 30/10/15.
//

#ifndef BOLLO_UI_LOGBOOKDIALOG_H
#define BOLLO_UI_LOGBOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtCore/qurl.h>
#include "../../io/http.h"

QT_BEGIN_NAMESPACE

class Ui_LogbookDialog {
public:
    QPushButton* qbClose;
    QComboBox* qcbType;
    QStackedWidget* stackedWidget;
    QWidget* page;
    QTableWidget* qtGeneral;
    QWidget* page_2;
    QTableWidget* qtProblem;

    void setupUi(QDialog* Dialog) {
        if(Dialog->objectName().isEmpty()) {
            Dialog->setObjectName(QStringLiteral("LogbookDialog"));
        }

        Dialog->setWindowModality(Qt::ApplicationModal);
        Dialog->resize(612, 368);

        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());

        Dialog->setSizePolicy(sizePolicy);
        Dialog->setFixedSize(Dialog->size());
        Dialog->setWindowTitle(QStringLiteral("Bitácora"));
        Dialog->setModal(true);

        qbClose = new QPushButton(Dialog);
        qbClose->setObjectName(QStringLiteral("qbClose"));
        qbClose->setGeometry(QRect(500, 330, 87, 26));
        qbClose->setText(QStringLiteral("Cerrar"));

        qcbType = new QComboBox(Dialog);
        qcbType->addItem(QStringLiteral("General"));
        qcbType->addItem(QStringLiteral("Problemas"));
        qcbType->setObjectName(QStringLiteral("qcbType"));
        qcbType->setGeometry(QRect(500, 20, 78, 24));
        qcbType->setCurrentIndex(0);

        stackedWidget = new QStackedWidget(Dialog);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 59, 581, 261));

        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));

        qtGeneral = new QTableWidget(page);
        qtGeneral->setColumnCount(5);

        QStringList qtGeneralHeaders;
        qtGeneralHeaders << QStringLiteral("Código")
        << QStringLiteral("Panadería")
        << QStringLiteral("Descripción")
        << QStringLiteral("Fecha")
        << QStringLiteral("Hora");

        qtGeneral->setHorizontalHeaderLabels(qtGeneralHeaders);
        qtGeneral->setColumnWidth(0, 50);
        qtGeneral->setColumnWidth(1, 115);
        qtGeneral->setColumnWidth(2, 193);
        qtGeneral->verticalHeader()->setVisible(false);
        qtGeneral->setEditTriggers(QAbstractItemView::NoEditTriggers);
        qtGeneral->setSelectionBehavior(QAbstractItemView::SelectRows);

        qtGeneral->setObjectName(QStringLiteral("qtGeneral"));
        qtGeneral->setGeometry(QRect(10, 10, 561, 241));

        stackedWidget->addWidget(page);

        //Problems page
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));

        qtProblem = new QTableWidget(page_2);
        qtProblem->setColumnCount(6);

        QStringList qtProblemHeaders;
        qtProblemHeaders << QStringLiteral("Código")
                            << QStringLiteral("Panadería")
                               << QStringLiteral("Descripción")
                                  << QStringLiteral("Cant. Masa")
                                     << QStringLiteral("Fecha")
                                        << QStringLiteral("Hora");
        qtProblem->setHorizontalHeaderLabels(qtProblemHeaders);
        qtProblem->setColumnWidth(0, 50);
        qtProblem->setColumnWidth(1, 110);
        qtProblem->setColumnWidth(2, 163);
        qtProblem->setColumnWidth(3, 80);
        qtProblem->setColumnWidth(4, 80);
        qtProblem->setColumnWidth(5, 75);
        qtProblem->verticalHeader()->setVisible(false);
        qtProblem->setEditTriggers(QAbstractItemView::NoEditTriggers);
        qtProblem->setSelectionBehavior(QAbstractItemView::SelectRows);

        qtProblem->setObjectName(QStringLiteral("qtProblem"));
        qtProblem->setGeometry(QRect(10, 10, 561, 241));
        stackedWidget->addWidget(page_2);

        QObject::connect(qcbType, SIGNAL(activated(int)), stackedWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(qbClose, &QPushButton::clicked, qtGeneral, &QTableWidget::clear);
        QObject::connect(qbClose, &QPushButton::clicked, qtProblem, &QTableWidget::clear);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

};

namespace Ui {
    class LogbookDialog : public Ui_LogbookDialog {
    };
} // namespace Ui

QT_END_NAMESPACE
#endif //BOLLO_UI_LOGBOOKDIALOG_H
