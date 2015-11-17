/********************************************************************************
** Form generated from reading UI file 'mainwindowjd3343.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWJD3343_H
#define MAINWINDOWJD3343_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
public:
    QAction* actionBakeryList, * actionShowGraphs, * actionContinueProcess, * actionPauseProcess;
    QAction* actionCancelProcess, * actionBakeryLog, * actionAbout, * actionHelp, * actionNewBakery;
    QAction* actionExit, * actionSignOut, * actionLogBrowser, * actionGraphViewer, * actionTelegram;
    QAction* actionThemeLight, * actionThemeDark, * actionChangePassword, * actionEditBakeries, * actionPreferencesPanel;

    QWidget* centralWidget;
    QVBoxLayout* verticalLayout;
    QGroupBox* groupBox;

    QLabel* mixingIcon, * firstFermentIcon, * doughDivisionIcon, * doughFormingIcon, * finalFermentIcon;
    QLabel* bakingIcon, * shippedIcon, * onSaleIcon;
    QLabel *statusBarLabel;

    QProgressBar* firstFermentBar, * doughDivisionBar, * doughFormingBar, * finalFermentBar;
    QProgressBar* bakingBar, * onSaleBar, * shippedBar;

    QLabel* title1, * title2, * title3, * title4, * title5, * title6, * title7, * title8;
    QLabel* statusLabel, * createdBreadsLabel, * bakeryName;

    QMenuBar* menuBar;
    QMenu* menuFile, * menuEdit, * menuThemes, * menuTools, * menuHelp;
    QStatusBar* statusbar;
    QToolBar* toolBar;

    void setupUi(QMainWindow* MainWindow) {
        if(MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1027, 552);
        MainWindow->setWindowTitle(QStringLiteral("Bollo"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/assets/hbread.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowFilePath(QStringLiteral(""));

        actionBakeryList = new QAction(MainWindow);
        actionBakeryList->setObjectName(QStringLiteral("actionBakeryList"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/assets/bread-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBakeryList->setIcon(icon1);
        actionShowGraphs = new QAction(MainWindow);
        actionShowGraphs->setObjectName(QStringLiteral("actionShowGraphs"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/assets/graph-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowGraphs->setIcon(icon2);
        actionContinueProcess = new QAction(MainWindow);
        actionContinueProcess->setObjectName(QStringLiteral("actionContinueProcess"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/assets/continue-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionContinueProcess->setIcon(icon3);
        actionPauseProcess = new QAction(MainWindow);
        actionPauseProcess->setObjectName(QStringLiteral("actionPauseProcess"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/assets/pause-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPauseProcess->setIcon(icon4);
        actionCancelProcess = new QAction(MainWindow);
        actionCancelProcess->setObjectName(QStringLiteral("actionCancelProcess"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/assets/cancel-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCancelProcess->setIcon(icon5);
        actionBakeryLog = new QAction(MainWindow);
        actionBakeryLog->setObjectName(QStringLiteral("actionBakeryLog"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/assets/log-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBakeryLog->setIcon(icon6);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionNewBakery = new QAction(MainWindow);
        actionNewBakery->setObjectName(QStringLiteral("actionNewBakery"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSignOut = new QAction(MainWindow);
        actionSignOut->setObjectName(QStringLiteral("actionSignOut"));
        actionLogBrowser = new QAction(MainWindow);
        actionLogBrowser->setObjectName(QStringLiteral("actionLogBrowser"));
        actionGraphViewer = new QAction(MainWindow);
        actionGraphViewer->setObjectName(QStringLiteral("actionGraphViewer"));
        actionTelegram = new QAction(MainWindow);
        actionTelegram->setObjectName(QStringLiteral("actionTelegram"));
        actionThemeLight = new QAction(MainWindow);
        actionThemeLight->setObjectName(QStringLiteral("actionThemeLight"));
        actionThemeLight->setCheckable(true);
        actionThemeDark = new QAction(MainWindow);
        actionThemeDark->setObjectName(QStringLiteral("actionThemeDark"));
        actionThemeDark->setCheckable(true);
        actionChangePassword = new QAction(MainWindow);
        actionChangePassword->setObjectName(QStringLiteral("actionChangePassword"));
        actionEditBakeries = new QAction(MainWindow);
        actionEditBakeries->setObjectName(QStringLiteral("actionEditBakeries"));
        actionPreferencesPanel = new QAction(MainWindow);
        actionPreferencesPanel->setObjectName(QStringLiteral("actionPreferencesPanel"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));

        mixingIcon = new QLabel(groupBox);
        mixingIcon->setObjectName(QStringLiteral("mixingIcon"));
        mixingIcon->setGeometry(QRect(20, 60, 48, 48));
        mixingIcon->setMinimumSize(QSize(48, 48));
        mixingIcon->setMaximumSize(QSize(48, 48));
        mixingIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        mixingIcon->setText(QStringLiteral(""));

        firstFermentIcon = new QLabel(groupBox);
        firstFermentIcon->setObjectName(QStringLiteral("firstFermentIcon"));
        firstFermentIcon->setGeometry(QRect(150, 60, 48, 48));
        firstFermentIcon->setMinimumSize(QSize(48, 48));
        firstFermentIcon->setMaximumSize(QSize(48, 48));
        firstFermentIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        firstFermentIcon->setText(QStringLiteral(""));

        doughDivisionIcon = new QLabel(groupBox);
        doughDivisionIcon->setObjectName(QStringLiteral("doughDivisionIcon"));
        doughDivisionIcon->setGeometry(QRect(280, 60, 48, 48));
        doughDivisionIcon->setMinimumSize(QSize(48, 48));
        doughDivisionIcon->setMaximumSize(QSize(48, 48));
        doughDivisionIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        doughDivisionIcon->setText(QStringLiteral(""));

        doughFormingIcon = new QLabel(groupBox);
        doughFormingIcon->setObjectName(QStringLiteral("doughFormingIcon"));
        doughFormingIcon->setGeometry(QRect(410, 60, 48, 48));
        doughFormingIcon->setMinimumSize(QSize(48, 48));
        doughFormingIcon->setMaximumSize(QSize(48, 48));
        doughFormingIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        doughFormingIcon->setText(QStringLiteral(""));

        finalFermentIcon = new QLabel(groupBox);
        finalFermentIcon->setObjectName(QStringLiteral("finalFermentIcon"));
        finalFermentIcon->setGeometry(QRect(540, 60, 48, 48));
        finalFermentIcon->setMinimumSize(QSize(48, 48));
        finalFermentIcon->setMaximumSize(QSize(48, 48));
        finalFermentIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        finalFermentIcon->setText(QStringLiteral(""));

        bakingIcon = new QLabel(groupBox);
        bakingIcon->setObjectName(QStringLiteral("bakingIcon"));
        bakingIcon->setGeometry(QRect(670, 60, 48, 48));
        bakingIcon->setMinimumSize(QSize(48, 48));
        bakingIcon->setMaximumSize(QSize(48, 48));
        bakingIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        bakingIcon->setText(QStringLiteral(""));

        shippedIcon = new QLabel(groupBox);
        shippedIcon->setObjectName(QStringLiteral("shippedIcon"));
        shippedIcon->setGeometry(QRect(930, 60, 48, 48));
        shippedIcon->setMinimumSize(QSize(48, 48));
        shippedIcon->setMaximumSize(QSize(48, 48));
        shippedIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        shippedIcon->setText(QStringLiteral(""));

        onSaleIcon = new QLabel(groupBox);
        onSaleIcon->setObjectName(QStringLiteral("onSaleIcon"));
        onSaleIcon->setGeometry(QRect(800, 60, 48, 48));
        onSaleIcon->setMinimumSize(QSize(48, 48));
        onSaleIcon->setMaximumSize(QSize(48, 48));
        onSaleIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/assets/pending-icon.png")));
        onSaleIcon->setText(QStringLiteral(""));

        statusBarLabel = new QLabel();
        firstFermentBar = new QProgressBar(groupBox);
        firstFermentBar->setObjectName(QStringLiteral("firstFermentBar"));
        firstFermentBar->setGeometry(QRect(70, 80, 81, 6));
        firstFermentBar->setMaximumSize(QSize(16777215, 6));
        firstFermentBar->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        doughDivisionBar->setObjectName(QStringLiteral("doughDivisionBar"));
        doughDivisionBar->setGeometry(QRect(200, 80, 81, 6));
        doughDivisionBar->setMaximumSize(QSize(16777215, 6));
        doughDivisionBar->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        doughFormingBar->setObjectName(QStringLiteral("doughFormingBar"));
        doughFormingBar->setGeometry(QRect(330, 80, 81, 6));
        doughFormingBar->setMaximumSize(QSize(16777215, 6));
        doughFormingBar->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        finalFermentBar->setObjectName(QStringLiteral("finalFermentBar"));
        finalFermentBar->setGeometry(QRect(460, 80, 81, 6));
        finalFermentBar->setMaximumSize(QSize(16777215, 6));
        finalFermentBar->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        bakingBar->setObjectName(QStringLiteral("bakingBar"));
        bakingBar->setGeometry(QRect(590, 80, 81, 6));
        bakingBar->setMaximumSize(QSize(16777215, 6));
        bakingBar->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        onSaleBar->setObjectName(QStringLiteral("onSaleBar"));
        onSaleBar->setGeometry(QRect(720, 80, 81, 6));
        onSaleBar->setMaximumSize(QSize(16777215, 6));
        onSaleBar->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        shippedBar->setObjectName(QStringLiteral("shippedBar"));
        shippedBar->setGeometry(QRect(850, 80, 81, 6));
        shippedBar->setMaximumSize(QSize(16777215, 6));
        shippedBar->setStyleSheet(QLatin1String("QProgressBar {\n"
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
        title1->setObjectName(QStringLiteral("title1"));
        title1->setGeometry(QRect(4, 110, 81, 31));
        title1->setMaximumSize(QSize(100, 16777215));
        title1->setAlignment(Qt::AlignCenter);
        title1->setWordWrap(true);
        title1->setText(QStringLiteral("Mezcla de ingredientes"));

        title2 = new QLabel(groupBox);
        title2->setObjectName(QStringLiteral("title2"));
        title2->setGeometry(QRect(125, 110, 101, 31));
        title2->setMaximumSize(QSize(120, 16777215));
        title2->setAlignment(Qt::AlignCenter);
        title2->setWordWrap(true);
        title2->setText(QStringLiteral("Fermentación primaria"));

        title3 = new QLabel(groupBox);
        title3->setObjectName(QStringLiteral("title3"));
        title3->setGeometry(QRect(265, 110, 81, 31));
        title3->setMaximumSize(QSize(100, 16777215));
        title3->setAlignment(Qt::AlignCenter);
        title3->setWordWrap(true);
        title3->setText(QStringLiteral("División de la masa"));

        title4 = new QLabel(groupBox);
        title4->setObjectName(QStringLiteral("title4"));
        title4->setGeometry(QRect(394, 110, 81, 31));
        title4->setMaximumSize(QSize(100, 16777215));
        title4->setAlignment(Qt::AlignCenter);
        title4->setWordWrap(true);
        title4->setText(QStringLiteral("Formando panes"));

        title5 = new QLabel(groupBox);
        title5->setObjectName(QStringLiteral("title5"));
        title5->setGeometry(QRect(513, 110, 101, 31));
        title5->setMaximumSize(QSize(120, 16777215));
        title5->setAlignment(Qt::AlignCenter);
        title5->setWordWrap(true);
        title5->setText(QStringLiteral("Fermentación final"));

        title6 = new QLabel(groupBox);
        title6->setObjectName(QStringLiteral("title6"));
        title6->setGeometry(QRect(660, 110, 71, 21));
        title6->setMaximumSize(QSize(120, 16777215));
        title6->setAlignment(Qt::AlignCenter);
        title6->setWordWrap(true);
        title6->setText(QStringLiteral("Horneo"));

        title7 = new QLabel(groupBox);
        title7->setObjectName(QStringLiteral("title7"));
        title7->setGeometry(QRect(790, 110, 71, 21));
        title7->setMaximumSize(QSize(120, 16777215));
        title7->setAlignment(Qt::AlignCenter);
        title7->setWordWrap(true);
        title7->setText(QStringLiteral("Venta"));

        title8 = new QLabel(groupBox);
        title8->setObjectName(QStringLiteral("title8"));
        title8->setGeometry(QRect(910, 110, 91, 21));
        title8->setMaximumSize(QSize(120, 16777215));
        title8->setAlignment(Qt::AlignCenter);
        title8->setWordWrap(true);
        title8->setText(QStringLiteral("Distribución"));

        bakeryName = new QLabel(groupBox);
        bakeryName->setObjectName(QStringLiteral("bakeryName"));
        bakeryName->setGeometry(QRect(20, 160, 221, 18));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        bakeryName->setFont(font);
        bakeryName->setText(QStringLiteral("Panaderia:"));

        statusLabel = new QLabel(groupBox);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(20, 180, 341, 16));
        statusLabel->setText(QStringLiteral("Estado:"));

        createdBreadsLabel = new QLabel(groupBox);
        createdBreadsLabel->setObjectName(QStringLiteral("createdBreadsLabel"));
        createdBreadsLabel->setGeometry(QRect(20, 200, 151, 16));
        createdBreadsLabel->setText(QStringLiteral("Panes creados:"));

        verticalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1027, 26));

        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFile->setTitle(QStringLiteral("Bollo"));

        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuEdit->setTitle(QStringLiteral("Editar"));

        menuThemes = new QMenu(menuEdit);
        menuThemes->setObjectName(QStringLiteral("menuThemes"));
        menuThemes->setTitle(QStringLiteral("Temas"));

        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuTools->setTitle(QStringLiteral("Herramientas"));

        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp->setTitle(QStringLiteral("Ayuda"));
        MainWindow->setMenuBar(menuBar);

        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNewBakery);
        menuFile->addAction(actionSignOut);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionEditBakeries);
        menuEdit->addAction(menuThemes->menuAction());
        menuEdit->addAction(actionPreferencesPanel);
        menuThemes->addAction(actionThemeLight);
        menuThemes->addAction(actionThemeDark);
        menuTools->addAction(actionLogBrowser);
        menuTools->addAction(actionGraphViewer);
        menuTools->addAction(actionTelegram);
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
        toolBar->setWindowTitle(QStringLiteral("Barra de herramientas"));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow* MainWindow) {
        actionBakeryList->setText(QStringLiteral("bakeryList"));
        actionBakeryList->setToolTip(QStringLiteral("Lista de panaderías"));
        actionShowGraphs->setText(QStringLiteral("showGraphs"));
        actionShowGraphs->setToolTip(QStringLiteral("Estadisticas y Gráficos de la panadería"));
        actionContinueProcess->setText(QStringLiteral("continueProcess"));
        actionContinueProcess->setToolTip(QStringLiteral("Reanuda el proceso de creación del pan."));
        actionPauseProcess->setText(QStringLiteral("pauseProcess"));
        actionPauseProcess->setToolTip(QStringLiteral("Detiene el proceso de creación del pan."));
        actionCancelProcess->setText(QStringLiteral("cancelProcess"));
        actionCancelProcess->setToolTip(QStringLiteral("Cancela el proceso de creación del pan (Irreversible)"));
        actionBakeryLog->setText(QStringLiteral("bakeryLog"));
        actionBakeryLog->setToolTip(QStringLiteral("Bitacora de eventos de la panadería"));
        actionAbout->setText(QStringLiteral("Acerca"));
        actionAbout->setToolTip(QStringLiteral("Información de la aplicación"));
        actionHelp->setText(QStringLiteral("Ayuda"));
        actionHelp->setToolTip(QStringLiteral("Guia de ayuda"));
        actionNewBakery->setText(QStringLiteral("Nueva panadería"));
        actionNewBakery->setToolTip(QStringLiteral("Agregar nueva panadería"));
        actionExit->setText(QStringLiteral("Salir"));
        actionExit->setToolTip(QStringLiteral("Cerrar la aplicación"));
        actionSignOut->setText(QStringLiteral("Cerrar sesión"));
        actionLogBrowser->setText(QStringLiteral("Navegador de bitácoras"));
        actionLogBrowser->setToolTip(QStringLiteral("Explorar las bitácoras del sistema"));
        actionGraphViewer->setText(QStringLiteral("Visor de graficos"));
        actionGraphViewer->setToolTip(QStringLiteral("Gráficos estadísticos de las panaderías"));
        actionTelegram->setText(QStringLiteral("Telegram"));
        actionTelegram->setToolTip(QStringLiteral("Ajustes de integración con Telegram"));
        actionThemeLight->setText(QStringLiteral("Light"));
        actionThemeLight->setToolTip(QStringLiteral("Tema por defecto (Light)"));
        actionThemeDark->setText(QStringLiteral("Dark"));
        actionThemeDark->setToolTip(QStringLiteral("Tema oscuro (Dark)"));
        actionChangePassword->setText(QStringLiteral("Cambiar constraseña"));
        actionChangePassword->setToolTip(QStringLiteral("Cambiar constraseña de usuario"));
        actionEditBakeries->setText(QStringLiteral("Editar panaderías"));
        actionPreferencesPanel->setText(QStringLiteral("Preferencias"));
        actionPreferencesPanel->setToolTip(QStringLiteral("Preferencias de la aplicación"));
        groupBox->setTitle(QStringLiteral("Estado de panadería"));
    }
};

namespace Ui {
    class MainWindow : public Ui_MainWindow {
    };
}

QT_END_NAMESPACE

#endif // MAINWINDOWJD3343_H
