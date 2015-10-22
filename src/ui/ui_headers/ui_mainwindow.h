/********************************************************************************
** Form generated from reading UI file 'mainwindowbZ1444.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWBZ1444_H
#define MAINWINDOWBZ1444_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionBakeryList;
    QAction *actionShowGraphs;
    QAction *actionContinueProcess;
    QAction *actionPauseProcess;
    QAction *actionCancelProcess;
    QAction *actionBakeryLog;
    QAction *actionAbout;
    QAction *actionHelp;
    QAction *actionNewBakery;
    QAction *actionExit;
    QAction *actionSignOut;
    QAction *actionLogBrowser;
    QAction *actionGraphViewer;
    QAction *actionTelegram;
    QAction *actionThemeLight;
    QAction *actionThemeDark;
    QAction *actionChangePassword;
    QAction *actionEditBakerys;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *mixingIcon;
    QLabel *firstFermentIcon;
    QLabel *doughDivisionIcon;
    QLabel *doughFormingIcon;
    QLabel *finalFermentIcon;
    QLabel *bakingIcon;
    QLabel *shippedIcon;
    QLabel *onSaleIcon;
    QProgressBar *firstFermentBar;
    QProgressBar *doughDivisionBar;
    QProgressBar *doughFormingBar;
    QProgressBar *finalFermentBar;
    QProgressBar *bakingBar;
    QProgressBar *onSaleBar;
    QProgressBar *shippedBar;
    QLabel *title1;
    QLabel *title2;
    QLabel *title3;
    QLabel *title4;
    QLabel *title5;
    QLabel *title6;
    QLabel *title7;
    QLabel *title8;
    QPushButton *incrementBtn;
    QLabel *statusLabel;
    QLabel *timeRemainingLabel;
    QLabel *elapsedTimeLabel;
    QLabel *createdBreadsLabel;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTemas;
    QMenu *menuLog;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1022, 552);
        actionBakeryList = new QAction(MainWindow);
        actionBakeryList->setObjectName(QString::fromUtf8("actionBakeryList"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/assets/bread-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBakeryList->setIcon(icon);
        actionShowGraphs = new QAction(MainWindow);
        actionShowGraphs->setObjectName(QString::fromUtf8("actionShowGraphs"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/assets/graph-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowGraphs->setIcon(icon1);
        actionContinueProcess = new QAction(MainWindow);
        actionContinueProcess->setObjectName(QString::fromUtf8("actionContinueProcess"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/assets/continue-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionContinueProcess->setIcon(icon2);
        actionPauseProcess = new QAction(MainWindow);
        actionPauseProcess->setObjectName(QString::fromUtf8("actionPauseProcess"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/assets/pause-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPauseProcess->setIcon(icon3);
        actionCancelProcess = new QAction(MainWindow);
        actionCancelProcess->setObjectName(QString::fromUtf8("actionCancelProcess"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/assets/cancel-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCancelProcess->setIcon(icon4);
        actionBakeryLog = new QAction(MainWindow);
        actionBakeryLog->setObjectName(QString::fromUtf8("actionBakeryLog"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/assets/log-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBakeryLog->setIcon(icon5);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionNewBakery = new QAction(MainWindow);
        actionNewBakery->setObjectName(QString::fromUtf8("actionNewBakery"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSignOut = new QAction(MainWindow);
        actionSignOut->setObjectName(QString::fromUtf8("actionSignOut"));
        actionLogBrowser = new QAction(MainWindow);
        actionLogBrowser->setObjectName(QString::fromUtf8("actionLogBrowser"));
        actionGraphViewer = new QAction(MainWindow);
        actionGraphViewer->setObjectName(QString::fromUtf8("actionGraphViewer"));
        actionTelegram = new QAction(MainWindow);
        actionTelegram->setObjectName(QString::fromUtf8("actionTelegram"));
        actionThemeLight = new QAction(MainWindow);
        actionThemeLight->setObjectName(QString::fromUtf8("actionThemeLight"));
        actionThemeLight->setCheckable(true);
        actionThemeDark = new QAction(MainWindow);
        actionThemeDark->setObjectName(QString::fromUtf8("actionThemeDark"));
        actionThemeDark->setCheckable(true);
        actionChangePassword = new QAction(MainWindow);
        actionChangePassword->setObjectName(QString::fromUtf8("actionChangePassword"));
        actionEditBakerys = new QAction(MainWindow);
        actionEditBakerys->setObjectName(QString::fromUtf8("actionEditBakerys"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(9, 9, 1004, 311));
        mixingIcon = new QLabel(groupBox);
        mixingIcon->setObjectName(QString::fromUtf8("mixingIcon"));
        mixingIcon->setGeometry(QRect(20, 60, 48, 48));
        mixingIcon->setMinimumSize(QSize(48, 48));
        mixingIcon->setMaximumSize(QSize(48, 48));
        mixingIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        firstFermentIcon = new QLabel(groupBox);
        firstFermentIcon->setObjectName(QString::fromUtf8("firstFermentIcon"));
        firstFermentIcon->setGeometry(QRect(150, 60, 48, 48));
        firstFermentIcon->setMinimumSize(QSize(48, 48));
        firstFermentIcon->setMaximumSize(QSize(48, 48));
        firstFermentIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        doughDivisionIcon = new QLabel(groupBox);
        doughDivisionIcon->setObjectName(QString::fromUtf8("doughDivisionIcon"));
        doughDivisionIcon->setGeometry(QRect(280, 60, 48, 48));
        doughDivisionIcon->setMinimumSize(QSize(48, 48));
        doughDivisionIcon->setMaximumSize(QSize(48, 48));
        doughDivisionIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        doughFormingIcon = new QLabel(groupBox);
        doughFormingIcon->setObjectName(QString::fromUtf8("doughFormingIcon"));
        doughFormingIcon->setGeometry(QRect(410, 60, 48, 48));
        doughFormingIcon->setMinimumSize(QSize(48, 48));
        doughFormingIcon->setMaximumSize(QSize(48, 48));
        doughFormingIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        finalFermentIcon = new QLabel(groupBox);
        finalFermentIcon->setObjectName(QString::fromUtf8("finalFermentIcon"));
        finalFermentIcon->setGeometry(QRect(540, 60, 48, 48));
        finalFermentIcon->setMinimumSize(QSize(48, 48));
        finalFermentIcon->setMaximumSize(QSize(48, 48));
        finalFermentIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        bakingIcon = new QLabel(groupBox);
        bakingIcon->setObjectName(QString::fromUtf8("bakingIcon"));
        bakingIcon->setGeometry(QRect(670, 60, 48, 48));
        bakingIcon->setMinimumSize(QSize(48, 48));
        bakingIcon->setMaximumSize(QSize(48, 48));
        bakingIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        shippedIcon = new QLabel(groupBox);
        shippedIcon->setObjectName(QString::fromUtf8("shippedIcon"));
        shippedIcon->setGeometry(QRect(930, 60, 48, 48));
        shippedIcon->setMinimumSize(QSize(48, 48));
        shippedIcon->setMaximumSize(QSize(48, 48));
        shippedIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        onSaleIcon = new QLabel(groupBox);
        onSaleIcon->setObjectName(QString::fromUtf8("onSaleIcon"));
        onSaleIcon->setGeometry(QRect(800, 60, 48, 48));
        onSaleIcon->setMinimumSize(QSize(48, 48));
        onSaleIcon->setMaximumSize(QSize(48, 48));
        onSaleIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        firstFermentBar = new QProgressBar(groupBox);
        firstFermentBar->setObjectName(QString::fromUtf8("firstFermentBar"));
        firstFermentBar->setGeometry(QRect(70, 80, 81, 6));
        firstFermentBar->setMaximumSize(QSize(16777215, 6));
        firstFermentBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    background-color: #808080;\n"
"	border-radius: 2px;\n"
" }\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #5BC614;\n"
" }"));
        firstFermentBar->setValue(0);
        firstFermentBar->setTextVisible(false);
        doughDivisionBar = new QProgressBar(groupBox);
        doughDivisionBar->setObjectName(QString::fromUtf8("doughDivisionBar"));
        doughDivisionBar->setGeometry(QRect(200, 80, 81, 6));
        doughDivisionBar->setMaximumSize(QSize(16777215, 6));
        doughDivisionBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    background-color: #808080;\n"
"	border-radius: 2px;\n"
" }\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #5BC614;\n"
" }"));
        doughDivisionBar->setValue(0);
        doughDivisionBar->setTextVisible(false);
        doughFormingBar = new QProgressBar(groupBox);
        doughFormingBar->setObjectName(QString::fromUtf8("doughFormingBar"));
        doughFormingBar->setGeometry(QRect(330, 80, 81, 6));
        doughFormingBar->setMaximumSize(QSize(16777215, 6));
        doughFormingBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    background-color: #808080;\n"
"	border-radius: 2px;\n"
" }\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #5BC614;\n"
" }"));
        doughFormingBar->setValue(0);
        doughFormingBar->setTextVisible(false);
        finalFermentBar = new QProgressBar(groupBox);
        finalFermentBar->setObjectName(QString::fromUtf8("finalFermentBar"));
        finalFermentBar->setGeometry(QRect(460, 80, 81, 6));
        finalFermentBar->setMaximumSize(QSize(16777215, 6));
        finalFermentBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    background-color: #808080;\n"
"	border-radius: 2px;\n"
" }\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #5BC614;\n"
" }"));
        finalFermentBar->setValue(0);
        finalFermentBar->setTextVisible(false);
        bakingBar = new QProgressBar(groupBox);
        bakingBar->setObjectName(QString::fromUtf8("bakingBar"));
        bakingBar->setGeometry(QRect(590, 80, 81, 6));
        bakingBar->setMaximumSize(QSize(16777215, 6));
        bakingBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    background-color: #808080;\n"
"	border-radius: 2px;\n"
" }\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #5BC614;\n"
" }"));
        bakingBar->setValue(0);
        bakingBar->setTextVisible(false);
        onSaleBar = new QProgressBar(groupBox);
        onSaleBar->setObjectName(QString::fromUtf8("onSaleBar"));
        onSaleBar->setGeometry(QRect(720, 80, 81, 6));
        onSaleBar->setMaximumSize(QSize(16777215, 6));
        onSaleBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    background-color: #808080;\n"
"	border-radius: 2px;\n"
" }\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #5BC614;\n"
" }"));
        onSaleBar->setValue(0);
        onSaleBar->setTextVisible(false);
        shippedBar = new QProgressBar(groupBox);
        shippedBar->setObjectName(QString::fromUtf8("shippedBar"));
        shippedBar->setGeometry(QRect(850, 80, 81, 6));
        shippedBar->setMaximumSize(QSize(16777215, 6));
        shippedBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    background-color: #808080;\n"
"	border-radius: 2px;\n"
" }\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #5BC614;\n"
" }"));
        shippedBar->setValue(0);
        shippedBar->setTextVisible(false);
        title1 = new QLabel(groupBox);
        title1->setObjectName(QString::fromUtf8("title1"));
        title1->setGeometry(QRect(6, 110, 81, 31));
        title1->setMaximumSize(QSize(16777215, 16777215));
        title1->setStyleSheet(QString::fromUtf8(""));
        title1->setAlignment(Qt::AlignCenter);
        title1->setWordWrap(true);
        title2 = new QLabel(groupBox);
        title2->setObjectName(QString::fromUtf8("title2"));
        title2->setGeometry(QRect(123, 110, 101, 31));
        title2->setMaximumSize(QSize(120, 16777215));
        title2->setAlignment(Qt::AlignCenter);
        title2->setWordWrap(true);
        title3 = new QLabel(groupBox);
        title3->setObjectName(QString::fromUtf8("title3"));
        title3->setGeometry(QRect(264, 110, 81, 31));
        title3->setMaximumSize(QSize(100, 16777215));
        title3->setAlignment(Qt::AlignCenter);
        title3->setWordWrap(true);
        title4 = new QLabel(groupBox);
        title4->setObjectName(QString::fromUtf8("title4"));
        title4->setGeometry(QRect(394, 110, 81, 31));
        title4->setMaximumSize(QSize(100, 16777215));
        title4->setAlignment(Qt::AlignCenter);
        title4->setWordWrap(true);
        title5 = new QLabel(groupBox);
        title5->setObjectName(QString::fromUtf8("title5"));
        title5->setGeometry(QRect(515, 110, 101, 31));
        title5->setMaximumSize(QSize(120, 16777215));
        title5->setAlignment(Qt::AlignCenter);
        title5->setWordWrap(true);
        title6 = new QLabel(groupBox);
        title6->setObjectName(QString::fromUtf8("title6"));
        title6->setGeometry(QRect(660, 110, 71, 21));
        title6->setMaximumSize(QSize(120, 16777215));
        title6->setAlignment(Qt::AlignCenter);
        title6->setWordWrap(true);
        title7 = new QLabel(groupBox);
        title7->setObjectName(QString::fromUtf8("title7"));
        title7->setGeometry(QRect(790, 110, 71, 21));
        title7->setMaximumSize(QSize(120, 16777215));
        title7->setAlignment(Qt::AlignCenter);
        title7->setWordWrap(true);
        title8 = new QLabel(groupBox);
        title8->setObjectName(QString::fromUtf8("title8"));
        title8->setGeometry(QRect(909, 110, 91, 21));
        title8->setMaximumSize(QSize(120, 16777215));
        title8->setAlignment(Qt::AlignCenter);
        title8->setWordWrap(true);
        incrementBtn = new QPushButton(groupBox);
        incrementBtn->setObjectName(QString::fromUtf8("incrementBtn"));
        incrementBtn->setGeometry(QRect(20, 260, 80, 21));
        statusLabel = new QLabel(groupBox);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(20, 180, 111, 16));
        timeRemainingLabel = new QLabel(groupBox);
        timeRemainingLabel->setObjectName(QString::fromUtf8("timeRemainingLabel"));
        timeRemainingLabel->setGeometry(QRect(20, 200, 151, 16));
        elapsedTimeLabel = new QLabel(groupBox);
        elapsedTimeLabel->setObjectName(QString::fromUtf8("elapsedTimeLabel"));
        elapsedTimeLabel->setGeometry(QRect(20, 220, 151, 20));
        createdBreadsLabel = new QLabel(groupBox);
        createdBreadsLabel->setObjectName(QString::fromUtf8("createdBreadsLabel"));
        createdBreadsLabel->setGeometry(QRect(220, 180, 111, 16));
        MainWindow->setCentralWidget(centralWidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1022, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTemas = new QMenu(menuEdit);
        menuTemas->setObjectName(QString::fromUtf8("menuTemas"));
        menuLog = new QMenu(menubar);
        menuLog->setObjectName(QString::fromUtf8("menuLog"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuLog->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNewBakery);
        menuFile->addAction(actionSignOut);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionChangePassword);
        menuEdit->addAction(actionEditBakerys);
        menuEdit->addAction(menuTemas->menuAction());
        menuTemas->addAction(actionThemeLight);
        menuTemas->addAction(actionThemeDark);
        menuLog->addAction(actionLogBrowser);
        menuLog->addAction(actionGraphViewer);
        menuLog->addAction(actionTelegram);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionHelp);
        toolBar->addAction(actionBakeryList);
        toolBar->addAction(actionShowGraphs);
        toolBar->addAction(actionBakeryLog);
        toolBar->addSeparator();
        toolBar->addAction(actionContinueProcess);
        toolBar->addAction(actionPauseProcess);
        toolBar->addAction(actionCancelProcess);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Bollo - Pre-alpha [Codename: Ajonjoli]", 0, QApplication::UnicodeUTF8));
        actionBakeryList->setText(QApplication::translate("MainWindow", "bakeryList", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionBakeryList->setToolTip(QApplication::translate("MainWindow", "Lista de panaderias", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionShowGraphs->setText(QApplication::translate("MainWindow", "showGraphs", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionShowGraphs->setToolTip(QApplication::translate("MainWindow", "Estadisticas y Graficos de la panaderia", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionContinueProcess->setText(QApplication::translate("MainWindow", "continueProcess", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionContinueProcess->setToolTip(QApplication::translate("MainWindow", "Reanuda el proceso de creacion del pan.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPauseProcess->setText(QApplication::translate("MainWindow", "pauseProcess", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPauseProcess->setToolTip(QApplication::translate("MainWindow", "Detiene el proceso de creacion del pan.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCancelProcess->setText(QApplication::translate("MainWindow", "cancelProcess", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCancelProcess->setToolTip(QApplication::translate("MainWindow", "Cancela el proceso de creacion del pan (Irreversible)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionBakeryLog->setText(QApplication::translate("MainWindow", "bakeryLog", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionBakeryLog->setToolTip(QApplication::translate("MainWindow", "Bitacora de eventos de la panaderia", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "Informacion de la aplicacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionHelp->setToolTip(QApplication::translate("MainWindow", "Guia de ayuda", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNewBakery->setText(QApplication::translate("MainWindow", "Nueva panaderia", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNewBakery->setToolTip(QApplication::translate("MainWindow", "Agregar nueva panaderia", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("MainWindow", "Salir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "Cerrar la aplicacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSignOut->setText(QApplication::translate("MainWindow", "Cerrar sesion", 0, QApplication::UnicodeUTF8));
        actionLogBrowser->setText(QApplication::translate("MainWindow", "Navegador de bitacoras", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLogBrowser->setToolTip(QApplication::translate("MainWindow", "Explorar las bitacoras del sistema", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionGraphViewer->setText(QApplication::translate("MainWindow", "Visor de graficos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionGraphViewer->setToolTip(QApplication::translate("MainWindow", "Graficos estadisticos de las panaderias", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionTelegram->setText(QApplication::translate("MainWindow", "Telegram", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionTelegram->setToolTip(QApplication::translate("MainWindow", "Ajustes de integracion con Telegram", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionThemeLight->setText(QApplication::translate("MainWindow", "Light", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionThemeLight->setToolTip(QApplication::translate("MainWindow", "Tema por defecto (Light)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionThemeDark->setText(QApplication::translate("MainWindow", "Dark", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionThemeDark->setToolTip(QApplication::translate("MainWindow", "Tema oscuro (Dark)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionChangePassword->setText(QApplication::translate("MainWindow", "Cambiar contrasena", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionChangePassword->setToolTip(QApplication::translate("MainWindow", "Cambiar contrasena de usuario", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionEditBakerys->setText(QApplication::translate("MainWindow", "Editar panaderias", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Estado de panaderia", 0, QApplication::UnicodeUTF8));
        mixingIcon->setText(QString());
        firstFermentIcon->setText(QString());
        doughDivisionIcon->setText(QString());
        doughFormingIcon->setText(QString());
        finalFermentIcon->setText(QString());
        bakingIcon->setText(QString());
        shippedIcon->setText(QString());
        onSaleIcon->setText(QString());
        title1->setText(QApplication::translate("MainWindow", "Mezcla de ingredientes", 0, QApplication::UnicodeUTF8));
        title2->setText(QApplication::translate("MainWindow", "Fermentacion primaria", 0, QApplication::UnicodeUTF8));
        title3->setText(QApplication::translate("MainWindow", "Division de la masa", 0, QApplication::UnicodeUTF8));
        title4->setText(QApplication::translate("MainWindow", "Formando panes", 0, QApplication::UnicodeUTF8));
        title5->setText(QApplication::translate("MainWindow", "Fermentacion final", 0, QApplication::UnicodeUTF8));
        title6->setText(QApplication::translate("MainWindow", "Horneo", 0, QApplication::UnicodeUTF8));
        title7->setText(QApplication::translate("MainWindow", "Venta", 0, QApplication::UnicodeUTF8));
        title8->setText(QApplication::translate("MainWindow", "Distribucion", 0, QApplication::UnicodeUTF8));
        incrementBtn->setText(QApplication::translate("MainWindow", "Increment", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("MainWindow", "Estado:  ----", 0, QApplication::UnicodeUTF8));
        timeRemainingLabel->setText(QApplication::translate("MainWindow", "Tiempo restante:       --:--", 0, QApplication::UnicodeUTF8));
        elapsedTimeLabel->setText(QApplication::translate("MainWindow", "Tiempo transcurrido:  --:--", 0, QApplication::UnicodeUTF8));
        createdBreadsLabel->setText(QApplication::translate("MainWindow", "Panes creados: ----", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuTemas->setTitle(QApplication::translate("MainWindow", "Temas", 0, QApplication::UnicodeUTF8));
        menuLog->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWBZ1444_H

