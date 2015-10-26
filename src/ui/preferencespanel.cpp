#include <QDebug>

#include "preferencespanel.h"
#include "ui_headers/ui_preferencespanel.h"

PreferencesPanel::PreferencesPanel(QWidget *parent) : QDialog(parent),
    ui(new Ui::PreferencesPanel) {

    ui->setupUi(this);
    fillSettingsValue();
    connectEventChangeManagers();
}

PreferencesPanel::~PreferencesPanel() {

    delete ui;
}

/**
 * @brief PreferencesPanel::fillSettinsValue Fill all the values with the
 * ones in the .ini file
 *
 * Fills each value or edit line, with the ones from the .ini file.
 */
void PreferencesPanel::fillSettingsValue() {

    // TODO: GET values from .ini file and set the values.

    // NetWorking tab
    ui->apiHostUrl->setText("Load this bitch up");
    ui->dbHostUrl->setText("");
    ui->dbName->setText("");
    ui->dbUserName->setText("");
    ui->dbPassword->setText("");

    // Bakery tab
    ui->averageBreadSP->setValue(0);
    ui->doughPerBatchSP->setValue(0);
    ui->pollutantsProbabilitySP->setValue(0);
    ui->badDoughCB->setChecked(true);
    ui->badDoughProbabilitySP->setValue(0);
}

/**
 * @brief PreferencesPanel::connectEventChangeManagers Detects if a widget value
 * has changed if so, those values will be written to the .ini file otherwise they
 * are ignored since they already are in the .ini file.
 *
 * Note: It detects changes for each tab of the preferences window, it dont detect
 * changes for each value. If only one value in networking tab is changed ALL the other
 * values in networking tab will be written, and so on. Yeah not the best way I know.
 */
void PreferencesPanel::connectEventChangeManagers() {

    // NetWorking tab
    connect(ui->apiHostUrl, SIGNAL(editingFinished()), this, SLOT(networkingChanged()));
    connect(ui->dbHostUrl, SIGNAL(editingFinished()), this, SLOT(networkingChanged()));
    connect(ui->dbName, SIGNAL(editingFinished()), this, SLOT(networkingChanged()));
    connect(ui->dbUserName, SIGNAL(editingFinished()), this, SLOT(networkingChanged()));
    connect(ui->dbPassword, SIGNAL(editingFinished()), this, SLOT(networkingChanged()));

    // Bakery tab
    connect(ui->averageBreadSP, SIGNAL(editingFinished()), this, SLOT(bakerySettingsChanged()));
    connect(ui->doughPerBatchSP, SIGNAL(editingFinished()), this, SLOT(bakerySettingsChanged()));

    connect(ui->pollutantsProbabilitySP, SIGNAL(editingFinished()), this,
            SLOT(bakerySettingsChanged()));

    connect(ui->badDoughProbabilitySP, SIGNAL(editingFinished()), this,
            SLOT(bakerySettingsChanged()));
}

void PreferencesPanel::networkingChanged() {

    networkingHasChanged = true;
}

void PreferencesPanel::bakerySettingsChanged() {

    bakerySettingsHasChanged = true;
}

void PreferencesPanel::on_buttonBox_accepted() {

    writePreferencesToFile();
}

/**
 * @brief PreferencesPanel::writePreferencesToFile Write user
 * preferences to .ini file
 *
 * If the settings have change, extract all the values from the line edits,
 * spinner, etc to be written in the .ini file.
 */
void PreferencesPanel::writePreferencesToFile() {

    if (networkingHasChanged) {

        QString apiHostURl = ui->apiHostUrl->text();

        QString dbHostUrl = ui->dbHostUrl->text();
        QString dbName = ui->dbName->text();
        QString dbUserName = ui->dbUserName->text();
        QString dbPswd = ui->dbPassword->text();

        // Do your thing bitch
    }

    if (bakerySettingsHasChanged) {

        int averageBread = ui->averageBreadSP->value();
        int doughPerBatch = ui->doughPerBatchSP->value();

        int pollutantsProbability = ui->pollutantsProbabilitySP->value();
        int badDoughProbability = ui->badDoughProbabilitySP->value();

        // Do your thing motherfucker
    }
}

void PreferencesPanel::on_buttonBox_rejected() {

    this->close();
}

/**
 * @brief PreferencesPanel::on_badDoughCB_toggled Enables and
 * disables the bad dough options
 *
 * @param checked Status of the check box
 *
 * If the check box is checked enables a probability spinner
 * otherwise the spinner is disabled.
 */
void PreferencesPanel::on_badDoughCB_toggled(bool checked) {

    ui->badDoughProbabilitySP->setEnabled(checked);
    ui->title8->setEnabled(checked);
}
