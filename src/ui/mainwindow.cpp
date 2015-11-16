#include "ui_headers/ui_mainwindow.h"
#include "../logger/easylogging++.h"
#include "mainwindow.h"
#include "menuactionmanager.h"
#include "themes.h"
#include "assets.h"
#include "logindialog.h"

#include <QDesktopWidget>
#include <QMovie>

int value = 0;

MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {

    // MainWindow Setup
    ui->setupUi(this);
    applySettings();

    connectWidgets();
    showLoginAndValidate();
}

MainWindow::~MainWindow() {

    delete ui;

    if(!loadingGif) {
        delete loadingGif;
    }
}

/**
 * Used to apply various ui settings to the main window, that
 * can't be applied with qt designer
 */
void MainWindow::applySettings() {

    Ui::setLightTheme();

    // Center window
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter,
            this->size(), qApp->desktop()->availableGeometry()));

    // Check light theme toggle box, since its applied by default
    setChecked(Ui::LIGHT);

    // By default disable toolbar and dashboard
    widgetsEnabled(false);

    selectPane = nullptr;
}

/**
 * Show a login dialog and validates the user credentials, if
 * the user credentials are correct, show the bakery selectPane.
 */
void MainWindow::showLoginAndValidate() {

    LoginDialog* loginDialog = new LoginDialog;
    loginDialog->show();

    connect(loginDialog, &LoginDialog::logged_in, this, &MainWindow::showSelectPane);
    connect(loginDialog, &LoginDialog::accepted, loginDialog, &QObject::deleteLater);

    //FIXME: Sometimes work and dont work
    //connect(loginDialog, &LoginDialog::rejected, this, &MainWindow::exitApp);
}

void MainWindow::exitApp() {

    qApp->quit();
}

/**
 * Show the main select bakery pane, in which a bakery list is diplayed
 * and somo charts about the overall statistics of the bakeries. Those charts
 * are generated in the bollo web server and rendered in an html viewer in this
 * select pane.
 */
void MainWindow::showSelectPane() {

    LOG(DEBUG) << "Showing select panel";

    selectPane = new SelectWindow();
    selectPane->displayWebPage();
    ui->centralWidget->layout()->addWidget(selectPane);

    connect(selectPane, SIGNAL(bakerySelected(int)), this, SLOT(showDashBoard(int)));
}

/**
 * After a bakery is selected in the select pane, the toolbar, menubar actions and
 * dashboard are enabled and the dashboard for the selected bakery is shown.
 */
void MainWindow::showDashBoard (int bakeryId) {

    LOG(DEBUG) << "Showing dashboard for bakery: " + std::to_string(bakeryId);

    // If select pane is being shown, remove it.
    if (selectPane) {

        selectPane->deleteLater();
        selectPane = nullptr;
    }

    widgetsEnabled(true);

    // Set bakery operations
    connectBakeriesOperations();
    change_bakery_displayed(bakeryId);
}

/**
 * Enable and disable the select pane, the toolbar, and some menubar actions,
 * used when the application is launched in the bakery select pane and login,
 * and then when the dashboard is shown
 */
void MainWindow::widgetsEnabled(bool status) {

    LOG(DEBUG) << "Setting widgets status: " << status;

    ui->toolBar->setEnabled(status);

    // Edit bakeries action
    ui->menuEdit->actions().at(2)->setEnabled(status);

    // All tool menu actions
    ui->menuTools->actions().at(0)->setEnabled(status);
    ui->menuTools->actions().at(1)->setEnabled(status);
    ui->menuTools->actions().at(2)->setEnabled(status);

    ui->groupBox->setVisible(status);
}

/**
 * @brief MainWindow::setLoadingGif Set a "loading" gif in the
 * specied label (icon)
 * @param label Where the icon is going to be set.
 *
 * Used when a process start doing it job until it finish.
 * Each time the function is called creates a new object
 * and apply it to the specified label (icon). A new object
 * is created every time because when a process finish it loading gif
 * is destroyed by setDoneIcon() function.
 */
void MainWindow::setLoadingGif(QLabel* label) {

    loadingGif = new QMovie(Ui::LOADING_GIFF_DARK);
    label->setMovie(loadingGif);
    loadingGif->start();
}

/**
 * @brief MainWindow::setDoneIcon Set a "done" icon in the
 * specied label (icon)
 * @param label Where the icon is going to be set.
 *
 * Used when the process has finished it job.
 * When the progress bar value is 100, the loading
 * gif is replaced by a check (done) icon. After that
 * the loading gif object is destroyed to free up
 * allocated heap memory.
 */
void MainWindow::setDoneIcon(QLabel* label) {

    label->setPixmap(QPixmap(Ui::DONE_ICON));
    //delete loadingGif;
}


/*
 * @brief MainWindow::setDefaultIcon --> Sets the default image
 * in the specified label(pending image)
 *
 * @param --> the label that will be set by the pending image
 *
 * --> This method is used when a process needs to restart its execution
 */
void MainWindow::setDefaultIcon(QLabel* label) {

    label->setPixmap(QPixmap(Ui::DEFAULT_ICON));
}


/*
 * @brief MainWindow::setInactiveIcon --> Sets the icons or labels corresponding
 * to the processes of the bakery, representing that the Bakery is 'Inactive'
 *
 * @param --> The label that will be set with a 'inactive icon'
 *
 * --> This method is used every time a Bakery is set as 'inactive', so it
 * --> shows in the GUI all the icons indicating it
 *
 */
void MainWindow::setInactiveIcon(QLabel *label) {

    label->setPixmap(QPixmap(Ui::IDLE_ICON));
}


/*
 * @brief MainWindow::setClosedIcon --> Sets the icons or labels corresponding
 * to the processes of the bakery, representing that the Bakery is 'Closed'
 *
 * @param --> The label that will be set with a 'closed icon'
 *
 * --> This method is used every time a Bakery is set as 'closed', so it
 * --> shows in the GUI all the icons indicating it
 *
 */
void MainWindow::setClosedIcon(QLabel *label) {

    label->setPixmap(QPixmap(Ui::CLOSED_ICON));
}


/*
 * @brief MainWindow::setClosureIcon --> Sets the icons or labels corresponding
 * to the processes of the bakery, representing that the Bakery is 'Closure'
 *
 * @param --> The label that will be set with a 'closure icon'
 *
 * --> This method is used every time a Bakery is set as 'closure', so it
 * --> shows in the GUI all the icons indicating it
 *
 */
void MainWindow::setClosureIcon(QLabel *label) {

    label->setPixmap(QPixmap(Ui::SHUT_DOWN));
}



/*
 * @brief MainWindow::setQuarantineIcon --> Sets the icons or labels corresponding
 * to the processes of the bakery, representing that the Bakery is 'Quarantine'
 *
 * @param --> The label that will be set with a 'quarantine icon'
 *
 * --> This method is used every time a Bakery is set as 'quarantine', so it
 * --> shows in the GUI all the icons indicating it
 *
 */
void MainWindow::setQuarantineIcon(QLabel *label) {

    label->setPixmap(QPixmap(Ui::QUARANTINE_ICON));
}

/**
 * @brief MainWindow::setChecked Encapsulates theme action
 * toggle box to be toggled by other objects.
 *
 * @param theme Theme type used to toggle the correct action.
 *
 * Since only one theme can be used at a time, when an action
 * is toggled, the other one is "untoggled".
 */
void MainWindow::setChecked(Ui::Theme theme) {

    if(theme == Ui::DARK) {

        ui->actionThemeLight->setChecked(false);
        ui->actionThemeDark->setChecked(true);
    }

    else {

        ui->actionThemeDark->setChecked(false);
        ui->actionThemeLight->setChecked(true);
    }
}

// TODO: Connect all the remaining widgets

/**
 * The connect tool bar & connect menu actions are called here to start connecting
 * the actions to each function in MenuActionManager.
 */
void MainWindow::connectWidgets() {

    connectToolBarActions();
    connectMenuActions();
}

/**
 * All Tool bar actions (buttons) are connected here.
 */
void MainWindow::connectToolBarActions() {

    MenuActionManager* actManager = new MenuActionManager(this);

    connect(ui->actionBakeryList, SIGNAL(triggered(bool)), actManager, SLOT(showBakeryList()));
    connect(ui->actionBakeryLog, &QAction::triggered, actManager, &MenuActionManager::logBrowser);
    connect(ui->actionContinueProcess, SIGNAL(triggered(bool)), actManager, SLOT(continueProcess()));
    connect(ui->actionPauseProcess, SIGNAL(triggered(bool)), actManager, SLOT(pauseProcess()));
    connect(ui->actionCancelProcess, SIGNAL(triggered(bool)), actManager, SLOT(cancelProcess()));

}

/**
 * All the menu actions are connected here. File, Edit, Tools and Help menus.
 */
void MainWindow::connectMenuActions() {

    MenuActionManager* actManager = new MenuActionManager(this);

    // File menu
    connect(ui->actionExit, SIGNAL(triggered(bool)), actManager, SLOT(exit()));
    connect(ui->actionSignOut, SIGNAL(triggered(bool)), this, SLOT(signOut()));
    connect(ui->actionNewBakery, SIGNAL(triggered(bool)), actManager, SLOT(bakeryEdit()));

    // Edit menu
    connect(ui->actionEditBakerys, SIGNAL(triggered(bool)), actManager, SLOT(bakeryEdit()));
    connect(ui->actionThemeLight, SIGNAL(triggered(bool)), actManager, SLOT(setDefaultTheme()));
    connect(ui->actionThemeDark, SIGNAL(triggered(bool)), actManager, SLOT(setDarkTheme()));
    connect(ui->actionPreferencesPanel, SIGNAL(triggered(bool)), actManager, SLOT(preferencesPanel()));

    // Tools menu
    connect(ui->actionTelegram, SIGNAL(triggered(bool)), actManager, SLOT(telegramMenu()));
    connect(ui->actionLogBrowser, &QAction::triggered, actManager, &MenuActionManager::logBrowser);

    // Help menu
    connect(ui->actionAbout, SIGNAL(triggered(bool)), actManager, SLOT(about()));
    connect(ui->actionHelp, SIGNAL(triggered(bool)), actManager, SLOT(help()));
}

/**
 * Disables and set to not visible the menu, tool bar and dashboard. And if the user
 * is signing out from the select pane deletes the selectpane, and shows the login dialog.
 */
void MainWindow::signOut() {

    LOG(DEBUG) << "Signing out...";

    widgetsEnabled(false);

    if (selectPane) {

        LOG(DEBUG) << "Select pane found while signing out, deleting it...";

        selectPane->deleteLater();
        selectPane = nullptr;
    }

    showLoginAndValidate();
}

/*
 * @brief MainWindow::progress_operation --> Updates the GUI according to
 * the bakery operation that has changed
 *
 * @param --> a struct 'bakery_operation', that contains/encapsulates variables that represent:
 * -Percentage of progress
 * -The stage where the execution is being carried out in the bakery
 * -ID that belongs to the bakery that is being displayed in the GUI
 *
 * --> This method is used every single time that a bakery operation has changed
 * --> The code inside the if conditional only if the bakery id
 * --> belongs to the bakery that is being displayed
 */
void MainWindow::progress_operation(_operation current_operation) {


//    std::string request = "*** Current Bakery ID: " + to_string(this->current_bakery->get_id()) + " Request from Bakery with ID: " + to_string(current_operation.bakery_id) + " ***";
//    LOG(DEBUG) << request;

    if (this->current_bakery->get_id() == current_operation.bakery_id) {

//        LOG(DEBUG) << "Setting the GUI for Bakery with ID: " << to_string(this->current_bakery->get_id());
        setProgressBar(current_operation.progress);
    }
}


/*
 * @brief MainWindow::setProgressBar --> Sets the progress bar that
 * corresponds to the process or stage that is on execution
 *
 * @param --> a stage that describes that current process and the
 * progress, that represents that actual value for the progress bar
 *
 * --> The percentage of the progress bar that corresponds to the actual process
 * --> will be incrementing every time this method is called
 *
 */
void MainWindow::setProgressBar(int progress) {

    int progress_value = progress % 100;

    //LOG(DEBUG) << "Stage: " << to_string(progress / 100) << " ||| Progress Value: " << to_string(progress_value);

    switch(progress / 100) {

        case 0: set_mixIngredients_progress(progress_value);
            break;

        case 1: set_firstFermentBar(progress_value);
            break;

        case 2: set_doughDivisionBar(progress_value);
            break;

        case 3: set_doughFormingBar(progress_value);
            break;

        case 4: set_finalFermentBar(progress_value);
            break;

        case 5: set_bakingBar(progress_value);
            break;

        case 6: set_onSaleBar(progress_value);
            break;

        case 7: set_shippedBar(progress_value);
            break;

        case 8: //display message INACTIVA
            clean_all();
            set_inactive_bakery();
            break;

        case 9: //display message CLAUSURADA
            clean_all();
            set_closure_bakery();
            break;

        case 10: //display message EN CUARENTENA
            clean_all();
            set_quarantine_bakery();
            break;

        case 11: //display message CERRADA
            clean_all();
            set_closed_bakery();
            break;

        default: //progress out of the process range
            break;
    }

}


void MainWindow::set_mixIngredients_progress(int progress_value) {

    if(progress_value == 0) { // 1 is the initial value for the whole process

        setLoadingGif(ui->mixingIcon);
    }

    if(progress_value == MAX_BAR_VALUE) {

        setDoneIcon(ui->mixingIcon);
        setLoadingGif(ui->firstFermentIcon);
    }
}

void MainWindow::set_firstFermentBar(int progress_value) {

    ui->firstFermentBar->setValue(progress_value);
    ui->firstFermentBar->update();

    if(progress_value == MAX_BAR_VALUE) {

        setDoneIcon(ui->firstFermentIcon);
        setLoadingGif(ui->doughDivisionIcon);
    }
}

void MainWindow::set_doughDivisionBar(int progress_value) {

    ui->doughDivisionBar->setValue(progress_value);
    ui->doughDivisionBar->update();

    if(progress_value == MAX_BAR_VALUE) {

        setDoneIcon(ui->doughDivisionIcon);
        setLoadingGif(ui->doughFormingIcon);
    }
}

void MainWindow::set_doughFormingBar(int progress_value) {

    ui->doughFormingBar->setValue(progress_value);
    ui->doughFormingBar->update();

    if(progress_value == MAX_BAR_VALUE) {

        setDoneIcon(ui->doughFormingIcon);
        setLoadingGif(ui->finalFermentIcon);
    }
}

void MainWindow::set_finalFermentBar(int progress_value) {

    ui->finalFermentBar->setValue(progress_value);
    ui->finalFermentBar->update();

    if(progress_value == MAX_BAR_VALUE) {

        setDoneIcon(ui->finalFermentIcon);
        setLoadingGif(ui->bakingIcon);
    }
}

void MainWindow::set_bakingBar(int progress_value) {

    ui->bakingBar->setValue(progress_value);
    ui->bakingBar->update();

    if(progress_value == MAX_BAR_VALUE) {

        setDoneIcon(ui->bakingIcon);
        setLoadingGif(ui->onSaleIcon);
    }
}

void MainWindow::set_onSaleBar(int progress_value) {

    ui->onSaleBar->setValue(progress_value);
    ui->onSaleBar->update();

    if(progress_value == MAX_BAR_VALUE) {

        setDoneIcon(ui->onSaleIcon);
        setLoadingGif(ui->shippedIcon);
    }
}

void MainWindow::set_shippedBar(int progress_value) {

    ui->shippedBar->setValue(progress_value);
    ui->shippedBar->update();

    if(progress_value == MAX_BAR_VALUE) {

        setDoneIcon(ui->shippedIcon);

        clean_all();//Once the process finished, it starts over so it's needed to clean all
    }
}


/*
 * @brief MainWindow::update_bakery_operations --> Updates all the progress bars
 * that belong to the bakery that is being displayed on the screen
 *
 * @param --> a struct 'bakery_operation', that determines the current stage
 * and its percentage of progress
 *
 * --> This method is used every time that a new bakery has been selected from
 * --> 'Bakery List' in order to control its progress
 *
 */
void MainWindow::update_bakery_operations(_operation bakery_progress) {

    int progress_value = bakery_progress.progress % 100;
    switch(bakery_progress.progress / 100) {

        case 0:
            update_from_mix_ingredients();
            set_mixIngredients_progress(progress_value);
            break;

        case 1:
            update_from_first_fermentation();
            set_firstFermentBar(progress_value);
            break;

        case 2:
            update_from_divide_dough();
            set_doughDivisionBar(progress_value);
            break;

        case 3:
            update_from_forming_dough();
            set_doughFormingBar(progress_value);
            break;

        case 4:
            update_from_final_fermentation();
            set_finalFermentBar(progress_value);
            break;

        case 5:
            update_from_baking();
            set_bakingBar(progress_value);
            break;

        case 6:
            update_from_sale();
            set_onSaleBar(progress_value);
            break;

        case 7:
            update_from_bread_distribution();
            set_shippedBar(progress_value);
            break;

        case 8: //display message INACTIVA
            clean_all();
            set_inactive_bakery();
            break;

        case 9: //display message CLAUSURADA
            clean_all();
            set_closure_bakery();
            break;

        case 10: //display message EN CUARENTENA
            clean_all();
            set_quarantine_bakery();
            break;

        case 11: //display message CERRADA
            clean_all();
            set_closed_bakery();
            break;

        default: //progress out of the process range
            break;
    }

}


void MainWindow::update_from_bread_distribution() {
    set_mixIngredients_progress(MAX_BAR_VALUE);
    set_firstFermentBar(MAX_BAR_VALUE);
    set_doughDivisionBar(MAX_BAR_VALUE);
    set_doughFormingBar(MAX_BAR_VALUE);
    set_finalFermentBar(MAX_BAR_VALUE);
    set_bakingBar(MAX_BAR_VALUE);
    set_onSaleBar(MAX_BAR_VALUE);
}

void MainWindow::update_from_sale() {
    set_mixIngredients_progress(MAX_BAR_VALUE);
    set_firstFermentBar(MAX_BAR_VALUE);
    set_doughDivisionBar(MAX_BAR_VALUE);
    set_doughFormingBar(MAX_BAR_VALUE);
    set_finalFermentBar(MAX_BAR_VALUE);
    set_bakingBar(MAX_BAR_VALUE);
    clean_shippedBar();
}

void MainWindow::update_from_baking() {
    set_mixIngredients_progress(MAX_BAR_VALUE);
    set_firstFermentBar(MAX_BAR_VALUE);
    set_doughDivisionBar(MAX_BAR_VALUE);
    set_doughFormingBar(MAX_BAR_VALUE);
    set_finalFermentBar(MAX_BAR_VALUE);
    clean_onSaleBar();
    clean_shippedBar();
}

void MainWindow::update_from_final_fermentation() {
    set_mixIngredients_progress(MAX_BAR_VALUE);
    set_firstFermentBar(MAX_BAR_VALUE);
    set_doughDivisionBar(MAX_BAR_VALUE);
    set_doughFormingBar(MAX_BAR_VALUE);
    clean_bakingBar();
    clean_onSaleBar();
    clean_shippedBar();
}

void MainWindow::update_from_forming_dough() {
    set_mixIngredients_progress(MAX_BAR_VALUE);
    set_firstFermentBar(MAX_BAR_VALUE);
    set_doughDivisionBar(MAX_BAR_VALUE);
    clean_finalFermentBar();
    clean_bakingBar();
    clean_onSaleBar();
    clean_shippedBar();
}

void MainWindow::update_from_divide_dough() {
    set_mixIngredients_progress(MAX_BAR_VALUE);
    set_firstFermentBar(MAX_BAR_VALUE);
    clean_doughFormingBar();
    clean_finalFermentBar();
    clean_bakingBar();
    clean_onSaleBar();
    clean_shippedBar();
}

void MainWindow::update_from_first_fermentation() {
    set_mixIngredients_progress(MAX_BAR_VALUE);
    clean_doughDivisionBar();
    clean_doughFormingBar();
    clean_finalFermentBar();
    clean_bakingBar();
    clean_onSaleBar();
    clean_shippedBar();
}

void MainWindow::update_from_mix_ingredients() {
    setLoadingGif(ui->mixingIcon);
    clean_firstFermentBar();
    clean_doughDivisionBar();
    clean_doughFormingBar();
    clean_finalFermentBar();
    clean_bakingBar();
    clean_onSaleBar();
    clean_shippedBar();
}

void MainWindow::clean_mixIngredients_progress() {

    setDefaultIcon(ui->mixingIcon);
}

void MainWindow::clean_firstFermentBar() {

    ui->firstFermentBar->setValue(MIN_BAR_VALUE);
    setDefaultIcon(ui->firstFermentIcon);
}


void MainWindow::clean_doughDivisionBar() {

    ui->doughDivisionBar->setValue(MIN_BAR_VALUE);
    setDefaultIcon(ui->doughDivisionIcon);
}

void MainWindow::clean_doughFormingBar() {

    ui->doughFormingBar->setValue(MIN_BAR_VALUE);
    setDefaultIcon(ui->doughFormingIcon);
}

void MainWindow::clean_finalFermentBar() {

    ui->finalFermentBar->setValue(MIN_BAR_VALUE);
    setDefaultIcon(ui->finalFermentIcon);
}

void MainWindow::clean_bakingBar() {

    ui->bakingBar->setValue(MIN_BAR_VALUE);
    setDefaultIcon(ui->bakingIcon);
}

void MainWindow::clean_onSaleBar() {

    ui->onSaleBar->setValue(MIN_BAR_VALUE);
    setDefaultIcon(ui->onSaleIcon);
}

void MainWindow::clean_shippedBar() {

    ui->shippedBar->setValue(MIN_BAR_VALUE);
    setDefaultIcon(ui->shippedIcon);
}


void MainWindow::clean_all() {

    clean_mixIngredients_progress();
    clean_firstFermentBar();
    clean_doughDivisionBar();
    clean_doughFormingBar();
    clean_finalFermentBar();
    clean_bakingBar();
    clean_onSaleBar();
    clean_shippedBar();
}


/*
 * @brief MainWindow::change_bakery_displayed --> Sets the bakery_id/Bakery object
 * for the values of the new bakery selected
 *
 * @param --> the ID of the new bakery selected
 *
 * --> This method calls 'update_bakery_progress' method that is in charge to update all new GUI
 * --> Once this slot is called the class variables corresponding to the current bakery
 * --> are set/changed for the values of the new bakery selected.
 */
void MainWindow::change_bakery_displayed(int bakery_id) {

    set_current_bakery(bakery_id);

    LOG(DEBUG) << "Starting the update of the GUI for: " << this->current_bakery->get_name().toStdString()
    << " with the ID: " << to_string(bakery_id);
    update_bakery_operations(this->current_bakery->get_current_op());
}


/*
 * @brief MainWindow::connectBakeriesOperations --> Creates the connects between
 * the operations of the bakeries in order to update and set the GUI
 *
 */
void MainWindow::connectBakeriesOperations() {

    for (int i = 0; i < BolloApp::get().bakeries.size(); ++i) {

        Bakery *bakery = BolloApp::get().bakeries.at(i);

        connect(bakery, &Bakery::operation_changed, this, &MainWindow::progress_operation);
    }

}


/*
 * @brief MainWindow::set_current_bakery --> Sets the Bakery object that represents the
 * current_bakery that is being displayed on the screen
 *
 * @param --> the bakery_id of the new bakery that will be displayed on the screen
 *
 * --> every time that a bakery is selected, the 'current_bakery' object is set
 * in order to know which is the bakery that is being displayed
 */
void MainWindow::set_current_bakery(int bakery_id) {

    for (int i = 0; i < BolloApp::get().bakeries.size(); ++i) {

        Bakery *bakery = BolloApp::get().bakeries.at(i);

        if(bakery->get_id() == bakery_id) {

            this->current_bakery = bakery;
            break;
            //i = BolloApp::get().bakeries.size(); //***optional
        }
    }
}


void MainWindow::_update() {

    ui->mixingIcon->update();
    ui->firstFermentBar->update();
    ui->firstFermentIcon->update();
    ui->doughDivisionBar->update();
    ui->doughDivisionIcon->update();
    ui->doughFormingBar->update();
    ui->doughFormingIcon->update();
    ui->finalFermentBar->update();
    ui->finalFermentIcon->update();
    ui->bakingBar->update();
    ui->bakingIcon->update();
    ui->onSaleBar->update();
    ui->onSaleIcon->update();
    ui->shippedBar->update();
    ui->shippedIcon->update();
}


void MainWindow::set_inactive_bakery() {

    setInactiveIcon(ui->mixingIcon);
    setInactiveIcon(ui->firstFermentIcon);
    setInactiveIcon(ui->doughDivisionIcon);
    setInactiveIcon(ui->doughFormingIcon);
    setInactiveIcon(ui->finalFermentIcon);
    setInactiveIcon(ui->bakingIcon);
    setInactiveIcon(ui->onSaleIcon);
    setInactiveIcon(ui->shippedIcon);
}

void MainWindow::set_closure_bakery() {

    setClosureIcon(ui->mixingIcon);
    setClosureIcon(ui->firstFermentIcon);
    setClosureIcon(ui->doughDivisionIcon);
    setClosureIcon(ui->doughFormingIcon);
    setClosureIcon(ui->finalFermentIcon);
    setClosureIcon(ui->bakingIcon);
    setClosureIcon(ui->onSaleIcon);
    setClosureIcon(ui->shippedIcon);
}

void MainWindow::set_closed_bakery() {

    setClosedIcon(ui->mixingIcon);
    setClosedIcon(ui->firstFermentIcon);
    setClosedIcon(ui->doughDivisionIcon);
    setClosedIcon(ui->doughFormingIcon);
    setClosedIcon(ui->finalFermentIcon);
    setClosedIcon(ui->bakingIcon);
    setClosedIcon(ui->onSaleIcon);
    setClosedIcon(ui->shippedIcon);
}

void MainWindow::set_quarantine_bakery() {

    setQuarantineIcon(ui->mixingIcon);
    setQuarantineIcon(ui->firstFermentIcon);
    setQuarantineIcon(ui->doughDivisionIcon);
    setQuarantineIcon(ui->doughFormingIcon);
    setQuarantineIcon(ui->finalFermentIcon);
    setQuarantineIcon(ui->bakingIcon);
    setQuarantineIcon(ui->onSaleIcon);
    setQuarantineIcon(ui->shippedIcon);
}