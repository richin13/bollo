#include "bakeryedit.h"
#include "ui_headers/ui_bakeryedit.h"

BakeryEdit::BakeryEdit(QWidget *parent) : QDialog(parent),
    ui(new Ui::BakeryEdit) {

    ui->setupUi(this);
    settings();

    fillBakeryListComboBox();
    connectEventChangeManagers();
}

BakeryEdit::~BakeryEdit() {

    delete ui;
}

/**
 * Apply settings that cant be applied with qt designer, and other settings such as
 * connects, widgets states, etc.
 */
void BakeryEdit::settings() {

    // Disable create and save button by default
    ui->createBakeryBtn->setEnabled(false);
    ui->saveBakery->setEnabled(false);

    connect(ui->createBakeryBtn, SIGNAL(clicked()), this, SLOT(createBakery()));
    connect(ui->saveBakery, SIGNAL(clicked()), this, SLOT(saveBakery()));

    // Each time a bakery is selected, load its values in to the fields of "Bakery Edit" tab.
    connect(ui->bakeriesList, SIGNAL(activated(int)), this, SLOT(loadEditBakeryFields(int)));

    // When a different bakery is selected clean the modify status of the previus one
    connect(ui->bakeriesList, SIGNAL(activated(int)), this, SLOT(clearEditStatus()));

    // When changing tabs clean create bakery fields.
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(clearCreateFields()));
}

void BakeryEdit::clearCreateFields() {

    ui->createBakeryStatus->clear();
    ui->bakeryName->clear();
    ui->bakeryCity->clear();
}

void BakeryEdit::clearEditStatus() {

    ui->editBakeryStatus->clear();
}


/**
 * Makes an API request to save the modified bakery name, state or city. No validation
 * is required since all the text fields are properly formatted.
 */
void BakeryEdit::saveBakery() {

    // Get the bakery object from list
    Bakery* bake = BolloApp::get().bakeries.at(ui->bakeriesList->currentIndex());

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    //Build the URL
    QHash<QString, QString> args;
    args["id"] = QString::number(bake->get_id());
    args["name"] = ui->bakeryNameEdit->text();
    args["state"] = QString::number(ui->stateListEdit->currentIndex() + 1);
    args["city"] = ui->bakeryCityEdit->text();

    QUrl url;
    url_builder(url, "bakeries", "modify", args);

    connect(manager, &QNetworkAccessManager::finished, this, &BakeryEdit::gotModifyReply);
    connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);
    manager->get(QNetworkRequest(url));

    LOG(INFO) << "Sent POST request to URL to API at section 'bakeries' module 'modify'";
}

void BakeryEdit::gotModifyReply(QNetworkReply *reply) {

    LOG(INFO) << "Got reply from server: modify bakery request";

    QJsonObject object;
    extract_json_object(reply, &object);

    int replyCode = object.take("code").toInt();

    switch(replyCode) {

        case 0:
            setStatus(Ui::MODIFY, Ui::OK, "Panaderia modificada satisfactoriamente");
            LOG(INFO) << "Bakery created succesfully";
            break;

        case 1:
            setStatus(Ui::MODIFY, Ui::ERROR, "El nombre utilizado ya se encuentra registrado.");
            LOG(WARNING) << "An error ocurred while modifying bakery";
            break;

        case 15:
            setStatus(Ui::MODIFY, Ui::ERROR, "Fatal error");
            LOG(DEBUG) << "Missing parameters at create bakery request";
            break;
    }

    connect(reply, &QNetworkReply::finished, reply, &QNetworkReply::deleteLater);
}

/**
 * Makes an API request to create a new bakery in the data base. No validation is required
 * since all the text fields are properly formatted.
 */
void BakeryEdit::createBakery() {

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    //Build the URL
    QHash<QString, QString> args;
    args["name"] = ui->bakeryName->text();
    args["state"] = QString::number(ui->stateList->currentIndex() + 1);
    args["city"] = ui->bakeryCity->text();

    QUrl url;
    url_builder(url, "bakeries", "create", args);

    connect(manager, &QNetworkAccessManager::finished, this, &BakeryEdit::gotCreateReply);
    connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);
    manager->get(QNetworkRequest(url));

    LOG(INFO) << "Sent POST request to URL to API at section 'bakeries' module 'create'";
}

void BakeryEdit::gotCreateReply(QNetworkReply *reply) {

    LOG(INFO) << "Got reply from server: create bakery request";

    QJsonObject object;
    extract_json_object(reply, &object);

    int replyCode = object.take("code").toInt();

    switch(replyCode) {

        case 0:
            setStatus(Ui::CREATE, Ui::OK, "Panaderia creada satisfactoriamente");
            LOG(INFO) << "Bakery created succesfully";
            break;

        case 1:
            setStatus(Ui::CREATE, Ui::ERROR, "Ocurrio un error al crear la panaderia o ya existe");
            LOG(WARNING) << "An error ocurred while creating bakery or the bakery already exist";
            break;

        case 15:
            setStatus(Ui::CREATE, Ui::ERROR, "Fatal error");
            LOG(DEBUG) << "Missing parameters at create bakery request";
            break;
    }

    connect(reply, &QNetworkReply::finished, reply, &QNetworkReply::deleteLater);
}

void BakeryEdit::setStatus(Ui::Mode mode , Ui::Status status, QString message) {

    QLabel* statusLabel;
    QString fontColor;

    if (mode == Ui::CREATE) {

        statusLabel = ui->createBakeryStatus;
    }

    else {

        statusLabel = ui->editBakeryStatus;
    }

    // Set color of status label depending on the request status
    if (status == Ui::ERROR) {

       fontColor = "red";
    }

    else {

        fontColor = "green";
    }

    statusLabel->setStyleSheet("QLabel { color : " + fontColor +"; }");
    statusLabel->setText(message);
}

/**
 * Fills the bakeries combo box at the "Edit Bakery" tab, for the user to choose
 * which bakery to edit. Also fills all the "Edit Bakery" input fields, with the
 * first bakery on the list. If the bakery list is empty the tab is disabled completely.
 */
void BakeryEdit::fillBakeryListComboBox() {

    int listSize = (int) BolloApp::get().bakeries.size();

    if (listSize != 0) {

        for(int i = 0; i < listSize; ++i) {

            ui->bakeriesList->addItem(BolloApp::get().bakeries.at(i)->get_name());
        }

        // Fill the edit fields with the first bakery, so its not empty
        // when the user see it for the first time.
        loadEditBakeryFields(0);
    }

    else {

        ui->editTab->setEnabled(false);
    }
}

/**
 * @param index The bakery index at the bakeries list in BolloApp and gui combo box.
 *
 * When a bakery is selected the signal is directed to this function, in which
 * the index of the bakery at the Bakery list combo box (the same as the BolloApp list)
 * is passed for querying the Bakery object. Then the name, state, and city are extracted
 * from the Bakery object and used to fill the gui input fields.
 */
void BakeryEdit::loadEditBakeryFields(int index) {

    selectedBakery = BolloApp::get().bakeries.at(index);

    ui->bakeryNameEdit->setText(selectedBakery->get_name());
    ui->stateListEdit->setCurrentText(selectedBakery->get_state());
    ui->bakeryCityEdit->setText(selectedBakery->get_city());
}

/**
 * All the event changes monitoring functions are connected to the widgets. The "create bakery"
 * widgets and "edit bakery".
 */
void BakeryEdit::connectEventChangeManagers() {

    connect(ui->bakeryName, SIGNAL(textChanged(const QString &)), this, SLOT(validateNewBakeInput()));
    connect(ui->bakeryCity, SIGNAL(textChanged(const QString &)), this, SLOT(validateNewBakeInput()));
    connect(ui->bakeryNameEdit, SIGNAL(textChanged(const QString &)), this, SLOT(validateEditBakeInput()));
    connect(ui->bakeryCityEdit, SIGNAL(textChanged(const QString &)), this, SLOT(validateEditBakeInput()));
    connect(ui->stateListEdit, SIGNAL(activated(int)), this, SLOT(stateSelectChanged()));
}

/**
 * Validates if the gui input fields are empty, if they are the create button is disabled, otherwise
 * the button is enabled again.
 */
void BakeryEdit::validateNewBakeInput() {

    ui->createBakeryBtn->setDisabled(ui->bakeryName->text().isEmpty() || ui->bakeryCity->text().isEmpty());
}

/**
 * Validates if the gui input fields are empty, if they are the save button is disabled, otherwise
 * the button is enabled again.
 */
void BakeryEdit::validateEditBakeInput() {

    ui->saveBakery->setDisabled(ui->bakeryNameEdit->text().isEmpty() || ui->bakeryCityEdit->text().isEmpty());
}

/**
 * If the state list combo box current selected text or element is equal to the state from the
 * selecte bakery at the bakeries combox the save button is disabled since nothing has changed
 * and saving the same values it's redundant and some reources can be saved.
 */
void BakeryEdit::stateSelectChanged () {

    ui->saveBakery->setDisabled(ui->stateListEdit->currentText() == selectedBakery->get_state());
}
