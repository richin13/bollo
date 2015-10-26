/********************************************************************************
** Form generated from reading UI file 'preferencespanelZK5290.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PREFERENCESPANELZK5290_H
#define PREFERENCESPANELZK5290_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreferencesPanel
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *networkingTab;
    QGroupBox *apiGBox;
    QLabel *title5;
    QLineEdit *apiHostUrl;
    QGroupBox *dbGBox;
    QLabel *title1;
    QLineEdit *dbHostUrl;
    QLabel *title2;
    QLineEdit *dbName;
    QLabel *title3;
    QLineEdit *dbUserName;
    QLabel *title4;
    QLineEdit *dbPassword;
    QWidget *bakerySettings;
    QGroupBox *generalSettingsGBox;
    QLabel *title6;
    QSpinBox *averageBreadSP;
    QLabel *title7;
    QSpinBox *doughPerBatchSP;
    QGroupBox *eventSettingsGBox;
    QSpinBox *badDoughProbabilitySP;
    QCheckBox *badDoughCB;
    QLabel *title8;
    QLabel *title9;
    QSpinBox *pollutantsProbabilitySP;
    QLabel *title10;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PreferencesPanel)
    {
        if (PreferencesPanel->objectName().isEmpty())
            PreferencesPanel->setObjectName(QStringLiteral("PreferencesPanel"));
        PreferencesPanel->resize(553, 476);
        PreferencesPanel->setMinimumSize(QSize(553, 476));
        PreferencesPanel->setMaximumSize(QSize(553, 476));
        PreferencesPanel->setModal(true);
        verticalLayout_2 = new QVBoxLayout(PreferencesPanel);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(PreferencesPanel);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        networkingTab = new QWidget();
        networkingTab->setObjectName(QStringLiteral("networkingTab"));
        apiGBox = new QGroupBox(networkingTab);
        apiGBox->setObjectName(QStringLiteral("apiGBox"));
        apiGBox->setGeometry(QRect(10, 10, 511, 91));
        title5 = new QLabel(apiGBox);
        title5->setObjectName(QStringLiteral("title5"));
        title5->setGeometry(QRect(20, 30, 71, 16));
        apiHostUrl = new QLineEdit(apiGBox);
        apiHostUrl->setObjectName(QStringLiteral("apiHostUrl"));
        apiHostUrl->setGeometry(QRect(20, 50, 291, 21));
        dbGBox = new QGroupBox(networkingTab);
        dbGBox->setObjectName(QStringLiteral("dbGBox"));
        dbGBox->setGeometry(QRect(10, 120, 511, 241));
        title1 = new QLabel(dbGBox);
        title1->setObjectName(QStringLiteral("title1"));
        title1->setGeometry(QRect(20, 30, 71, 16));
        dbHostUrl = new QLineEdit(dbGBox);
        dbHostUrl->setObjectName(QStringLiteral("dbHostUrl"));
        dbHostUrl->setGeometry(QRect(20, 50, 291, 21));
        title2 = new QLabel(dbGBox);
        title2->setObjectName(QStringLiteral("title2"));
        title2->setGeometry(QRect(20, 80, 161, 16));
        dbName = new QLineEdit(dbGBox);
        dbName->setObjectName(QStringLiteral("dbName"));
        dbName->setGeometry(QRect(20, 100, 111, 21));
        title3 = new QLabel(dbGBox);
        title3->setObjectName(QStringLiteral("title3"));
        title3->setGeometry(QRect(20, 130, 81, 16));
        dbUserName = new QLineEdit(dbGBox);
        dbUserName->setObjectName(QStringLiteral("dbUserName"));
        dbUserName->setGeometry(QRect(20, 150, 111, 21));
        title4 = new QLabel(dbGBox);
        title4->setObjectName(QStringLiteral("title4"));
        title4->setGeometry(QRect(20, 180, 81, 16));
        dbPassword = new QLineEdit(dbGBox);
        dbPassword->setObjectName(QStringLiteral("dbPassword"));
        dbPassword->setGeometry(QRect(20, 200, 111, 21));
        dbPassword->setEchoMode(QLineEdit::Password);
        tabWidget->addTab(networkingTab, QString());
        bakerySettings = new QWidget();
        bakerySettings->setObjectName(QStringLiteral("bakerySettings"));
        generalSettingsGBox = new QGroupBox(bakerySettings);
        generalSettingsGBox->setObjectName(QStringLiteral("generalSettingsGBox"));
        generalSettingsGBox->setGeometry(QRect(10, 20, 511, 131));
        title6 = new QLabel(generalSettingsGBox);
        title6->setObjectName(QStringLiteral("title6"));
        title6->setGeometry(QRect(10, 40, 181, 21));
        averageBreadSP = new QSpinBox(generalSettingsGBox);
        averageBreadSP->setObjectName(QStringLiteral("averageBreadSP"));
        averageBreadSP->setGeometry(QRect(200, 40, 121, 22));
        title7 = new QLabel(generalSettingsGBox);
        title7->setObjectName(QStringLiteral("title7"));
        title7->setGeometry(QRect(10, 70, 191, 21));
        doughPerBatchSP = new QSpinBox(generalSettingsGBox);
        doughPerBatchSP->setObjectName(QStringLiteral("doughPerBatchSP"));
        doughPerBatchSP->setGeometry(QRect(200, 70, 121, 22));
        eventSettingsGBox = new QGroupBox(bakerySettings);
        eventSettingsGBox->setObjectName(QStringLiteral("eventSettingsGBox"));
        eventSettingsGBox->setGeometry(QRect(10, 180, 511, 171));
        badDoughProbabilitySP = new QSpinBox(eventSettingsGBox);
        badDoughProbabilitySP->setObjectName(QStringLiteral("badDoughProbabilitySP"));
        badDoughProbabilitySP->setGeometry(QRect(120, 110, 61, 22));
        badDoughCB = new QCheckBox(eventSettingsGBox);
        badDoughCB->setObjectName(QStringLiteral("badDoughCB"));
        badDoughCB->setGeometry(QRect(10, 90, 171, 19));
        badDoughCB->setChecked(true);
        title8 = new QLabel(eventSettingsGBox);
        title8->setObjectName(QStringLiteral("title8"));
        title8->setGeometry(QRect(30, 110, 91, 21));
        title9 = new QLabel(eventSettingsGBox);
        title9->setObjectName(QStringLiteral("title9"));
        title9->setGeometry(QRect(10, 30, 191, 16));
        pollutantsProbabilitySP = new QSpinBox(eventSettingsGBox);
        pollutantsProbabilitySP->setObjectName(QStringLiteral("pollutantsProbabilitySP"));
        pollutantsProbabilitySP->setGeometry(QRect(120, 50, 61, 22));
        pollutantsProbabilitySP->setProperty("showGroupSeparator", QVariant(false));
        pollutantsProbabilitySP->setDisplayIntegerBase(10);
        title10 = new QLabel(eventSettingsGBox);
        title10->setObjectName(QStringLiteral("title10"));
        title10->setGeometry(QRect(30, 50, 91, 21));
        tabWidget->addTab(bakerySettings, QString());

        verticalLayout->addWidget(tabWidget);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(PreferencesPanel);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(PreferencesPanel);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(PreferencesPanel);
    } // setupUi

    void retranslateUi(QDialog *PreferencesPanel)
    {
        PreferencesPanel->setWindowTitle(QApplication::translate("PreferencesPanel", "Preferencias", 0));
        apiGBox->setTitle(QApplication::translate("PreferencesPanel", "API Web Host", 0));
        title5->setText(QApplication::translate("PreferencesPanel", "Host URL", 0));
        apiHostUrl->setText(QString());
        dbGBox->setTitle(QApplication::translate("PreferencesPanel", "Base de Datos", 0));
        title1->setText(QApplication::translate("PreferencesPanel", "Host URL", 0));
        title2->setText(QApplication::translate("PreferencesPanel", "Nombre base de datos", 0));
        title3->setText(QApplication::translate("PreferencesPanel", "Usuario", 0));
        title4->setText(QApplication::translate("PreferencesPanel", "Contrasena", 0));
        tabWidget->setTabText(tabWidget->indexOf(networkingTab), QApplication::translate("PreferencesPanel", "Networking", 0));
        generalSettingsGBox->setTitle(QApplication::translate("PreferencesPanel", "Ajustes Generales", 0));
        title6->setText(QApplication::translate("PreferencesPanel", "Cantidad de pan promedio", 0));
        averageBreadSP->setSuffix(QApplication::translate("PreferencesPanel", " unidades", 0));
        title7->setText(QApplication::translate("PreferencesPanel", "Cantidad de masa por tanda", 0));
        doughPerBatchSP->setSuffix(QApplication::translate("PreferencesPanel", " kilogramos", 0));
        eventSettingsGBox->setTitle(QApplication::translate("PreferencesPanel", "Ajuste de Eventos", 0));
        badDoughProbabilitySP->setSuffix(QApplication::translate("PreferencesPanel", " %", 0));
        badDoughCB->setText(QApplication::translate("PreferencesPanel", "Levadura defectuosa", 0));
        title8->setText(QApplication::translate("PreferencesPanel", "Probabilidad", 0));
        title9->setText(QApplication::translate("PreferencesPanel", "Aparicion de contaminantes", 0));
        pollutantsProbabilitySP->setSuffix(QApplication::translate("PreferencesPanel", " %", 0));
        title10->setText(QApplication::translate("PreferencesPanel", "Probabilidad", 0));
        tabWidget->setTabText(tabWidget->indexOf(bakerySettings), QApplication::translate("PreferencesPanel", "Panaderia", 0));
    } // retranslateUi

};

namespace Ui {
    class PreferencesPanel: public Ui_PreferencesPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PREFERENCESPANELZK5290_H
