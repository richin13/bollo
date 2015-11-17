/********************************************************************************
** Form generated from reading UI file 'logbookdialogTi2757.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LOGBOOKDIALOG_H
#define LOGBOOKDIALOG_H

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

QT_BEGIN_NAMESPACE

class Ui_LogBookDialog
{
public:
    QPushButton *qbClose;
    QComboBox *qcbType;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTableWidget *qtGeneral;
    QWidget *page_2;
    QTableWidget *qtProblem;
    QComboBox *bakeryList;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::WindowModal);
        Dialog->resize(719, 440);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setWindowTitle(QString::fromUtf8("Bit\303\241cora"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/assets/hbread.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
#ifndef QT_NO_TOOLTIP
        Dialog->setToolTip(QStringLiteral(""));
#endif // QT_NO_TOOLTIP
        Dialog->setWindowFilePath(QStringLiteral(""));
        Dialog->setModal(true);
        qbClose = new QPushButton(Dialog);
        qbClose->setObjectName(QStringLiteral("qbClose"));
        qbClose->setGeometry(QRect(610, 400, 87, 26));
        qbClose->setText(QStringLiteral("Cerrar"));
        qcbType = new QComboBox(Dialog);
        qcbType->addItem(QString());
        qcbType->addItem(QStringLiteral("Problemas"));
        qcbType->setObjectName(QStringLiteral("qcbType"));
        qcbType->setGeometry(QRect(610, 20, 91, 28));
        qcbType->setCurrentText(QStringLiteral("General"));
        stackedWidget = new QStackedWidget(Dialog);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 59, 691, 341));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        qtGeneral = new QTableWidget(page);
        if (qtGeneral->columnCount() < 5)
            qtGeneral->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setText(QString::fromUtf8("C\303\263digo"));
        qtGeneral->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setText(QString::fromUtf8("Panader\303\255a"));
        qtGeneral->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setText(QString::fromUtf8("Descripci\303\263n"));
        qtGeneral->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setText(QStringLiteral("Fecha"));
        qtGeneral->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setText(QStringLiteral("Hora"));
        qtGeneral->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        qtGeneral->setObjectName(QStringLiteral("qtGeneral"));
        qtGeneral->setGeometry(QRect(10, 20, 681, 311));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qtGeneral->sizePolicy().hasHeightForWidth());
        qtGeneral->setSizePolicy(sizePolicy1);
        qtGeneral->setEditTriggers(QAbstractItemView::NoEditTriggers);
        qtGeneral->setAlternatingRowColors(true);
        qtGeneral->setSelectionBehavior(QAbstractItemView::SelectRows);
        qtGeneral->setSortingEnabled(true);
        qtGeneral->horizontalHeader()->setDefaultSectionSize(100);
        qtGeneral->horizontalHeader()->setStretchLastSection(true);
        qtGeneral->verticalHeader()->setStretchLastSection(false);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        qtProblem = new QTableWidget(page_2);
        if (qtProblem->columnCount() < 6)
            qtProblem->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        qtProblem->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        qtProblem->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        qtProblem->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        qtProblem->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        qtProblem->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        qtProblem->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        qtProblem->setObjectName(QStringLiteral("qtProblem"));
        qtProblem->setGeometry(QRect(10, 20, 681, 311));
        qtProblem->setSortingEnabled(true);
        qtProblem->horizontalHeader()->setStretchLastSection(true);
        stackedWidget->addWidget(page_2);
        bakeryList = new QComboBox(Dialog);
        bakeryList->setObjectName(QStringLiteral("bakeryList"));
        bakeryList->setGeometry(QRect(20, 23, 131, 28));

        retranslateUi(Dialog);
        QObject::connect(qcbType, SIGNAL(activated(int)), stackedWidget, SLOT(setCurrentIndex(int)));

        stackedWidget->setCurrentIndex(1);

        qcbType->setItemText(0, QApplication::translate("Dialog", "General", 0));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        qcbType->setItemText(0, QApplication::translate("Dialog", "General", 0));

        QTableWidgetItem *___qtablewidgetitem = qtProblem->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Dialog", "C\303\263digo", 0));
        QTableWidgetItem *___qtablewidgetitem1 = qtProblem->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Dialog", "Panader\303\255a", 0));
        QTableWidgetItem *___qtablewidgetitem2 = qtProblem->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Dialog", "Descripci\303\263n", 0));
        QTableWidgetItem *___qtablewidgetitem3 = qtProblem->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Dialog", "Cant. Masa", 0));
        QTableWidgetItem *___qtablewidgetitem4 = qtProblem->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Dialog", "Fecha", 0));
        QTableWidgetItem *___qtablewidgetitem5 = qtProblem->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Dialog", "Hora", 0));
        bakeryList->clear();
        bakeryList->insertItems(0, QStringList()
                                   << QApplication::translate("Dialog", "Todas", 0)
        );
        Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class LogbookDialog: public Ui_LogBookDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LOGBOOKDIALOGTI2757_H
