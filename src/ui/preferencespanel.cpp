#include <QDebug>

#include "preferencespanel.h"

PreferencesPanel::PreferencesPanel(QWidget* parent) : QDialog(parent),
                                                      ui(new Ui::PreferencesPanel) {
    ui->setupUi(this);
    fillSettingsValue();
    connectEventChangeManagers();

    networkingHasChanged = false;
    bakerySettingsHasChanged = false;
}

PreferencesPanel::~PreferencesPanel() {

    delete ui;
}

/**
 * @brief PreferencesPanel::fillSettingsValue Fill all the values with the
 * ones in the .ini file
 *
 * Fills each value or edit line, with the ones from the .ini file.
 */
void PreferencesPanel::fillSettingsValue() {

    // NetWorking tab
    ui->apiHostUrl->setText(Constants::API_HOST);
    ui->dbHostUrl->setText("NULL");
    ui->dbName->setText("NULL");
    ui->dbUserName->setText("NULL");
    ui->dbPassword->setText("NULL");

    // Bakery tab
    ui->averageBreadSP->setValue(get_setting("Operations", "average_production").toInt());
    ui->doughPerBatchSP->setValue(get_setting("Operations", "dough_per_batch").toInt());
    ui->pollutantsProbabilitySP->setValue(get_setting("Operations", "poll_probability").toInt());
    ui->badDoughCB->setChecked(true);
    ui->badDoughProbabilitySP->setValue(get_setting("Operations", "badyeast_probability").toInt());
    ui->ministryRaidProbabilitySP->setValue(get_setting("Operations", "raid_probability").toInt());
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

    connect(ui->ministryRaidProbabilitySP, SIGNAL(editingFinished()), this,
            SLOT(bakerySettingsChanged()));
}

void PreferencesPanel::networkingChanged() {
    networkingHasChanged = true;
}

void PreferencesPanel::bakerySettingsChanged() {
    bakerySettingsHasChanged = true;
}

void PreferencesPanel::on_buttonBox_accepted() {
    this->setCursor(QCursor(Qt::WaitCursor));
    writePreferencesToFile();
    this->close();
}

/**
 * @brief PreferencesPanel::writePreferencesToFile Write user
 * preferences to .ini file
 *
 * If the settings have change, extract all the values from the line edits,
 * spinner, etc to be written in the .ini file.
 */
void PreferencesPanel::writePreferencesToFile() {

    if(networkingHasChanged) {

        QString host_url = ui->apiHostUrl->text();

        QString db_host = ui->dbHostUrl->text();
        QString db_scheme = ui->dbName->text();
        QString db_username = ui->dbUserName->text();
        QString db_password = ui->dbPassword->text();

        set_setting("Networking", QStringLiteral("host_url"), QVariant(host_url));

        set_setting("Database", QStringLiteral("db_host"), QVariant(db_host));
        set_setting("Database", QStringLiteral("db_user"), QVariant(db_username));
        set_setting("Database", QStringLiteral("db_pass"), QVariant(db_password));
        set_setting("Database", QStringLiteral("db_schema"), QVariant(db_scheme));

        LOG(DEBUG) << "Updated networking || database settings";
    }

    if(bakerySettingsHasChanged) {

        int averageBread = ui->averageBreadSP->value();
        int doughPerBatch = ui->doughPerBatchSP->value();

        int poll_prob = ui->pollutantsProbabilitySP->value();
        int bad_yeast_prob = ui->badDoughProbabilitySP->value();

        // Use me bitch | I already did
        int ministry_raid_prob = ui->ministryRaidProbabilitySP->value();

        set_setting("Operations", QStringLiteral("average_production"), QVariant(averageBread));
        set_setting("Operations", QStringLiteral("dough_per_batch"), QVariant(doughPerBatch));
        set_setting("Operations", QStringLiteral("poll_probability"), QVariant(poll_prob));
        set_setting("Operations", QStringLiteral("badyeast_probability"), QVariant(bad_yeast_prob));
        set_setting("Operations", QStringLiteral("raid_probability"), QVariant(ministry_raid_prob));

        LOG(DEBUG) << "Updated operations settings";
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
