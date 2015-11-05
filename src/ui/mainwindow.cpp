#include "ui_headers/ui_mainwindow.h"
#include "../logger/easylogging++.h"
#include "mainwindow.h"
#include "menuactionmanager.h"
#include "themes.h"
#include "assets.h"
#include "logindialog.h"

#include <QDesktopWidget>
#include <QMovie>
#include <string>

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
}

/**
 * Used to apply various ui settings to the main window, that
 * can't be applied with qt designer
 */
void MainWindow::applySettings() {

    // Center window
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter,
            this->size(), qApp->desktop()->availableGeometry()));

    // Check dark theme toggle box, since its applied by default
    setChecked(Ui::DARK);

    // By default disable toolbar and dashboard
    widgetsEnabled(false);
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
    selectPane->displayWebPage("");

    ui->centralWidget->layout()->addWidget(selectPane);

    connect(selectPane, SIGNAL(bakerySelected(int)), this, SLOT(showDashBoard(int)));
}

/**
 * After a bakery is selected in the select pane, the toolbar, menubar actions and
 * dashboard are enabled and the dashboard for the selected bakery is shown.
 */
void MainWindow::showDashBoard (int bakeryId) {

    LOG(DEBUG) << "Showing dashboard for bakery: " + std::to_string(bakeryId);
    selectPane->deleteLater();
    widgetsEnabled(true);
}

/**
 * Enable and disable the select pane, the toolbar, and some menubar actions,
 * used when the application is launched in the bakery select pane and login,
 * and then when the dashboard is shown
 */
void MainWindow::widgetsEnabled(bool status) {

    ui->toolBar->setEnabled(status);

    // Edit bakeries action
    ui->menuEdit->actions().at(1)->setEnabled(status);

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
    delete loadingGif;
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

// USED FOR TESTING

void MainWindow::on_firstFermentBar_valueChanged(int value) {

    // Set loading gif the first time the bar value has changed
    if(value == BAR_INCREMENT) {

        setLoadingGif(ui->firstFermentIcon);
    }

    if(value == MAX_BAR_VALUE) {

        setDoneIcon(ui->firstFermentIcon);
        setLoadingGif(ui->doughDivisionIcon);
    }
}

void MainWindow::on_incrementBtn_clicked() {

    ui->firstFermentBar->setValue(value += BAR_INCREMENT);
}

// TODO: Connect all the remaining widgets

void MainWindow::connectWidgets() {

    connectToolBarActions();
    connectMenuActions();
}

void MainWindow::connectToolBarActions() {

    MenuActionManager* actManager = new MenuActionManager(this);

    connect(ui->actionBakeryList, SIGNAL(triggered(bool)), actManager, SLOT(showBakeryList()));
    connect(ui->actionBakeryLog, &QAction::triggered, actManager, &MenuActionManager::showLogbook);
}

void MainWindow::connectMenuActions() {

    MenuActionManager* actManager = new MenuActionManager(this);

    connect(ui->actionTelegram, SIGNAL(triggered(bool)), actManager, SLOT(telegramMenu()));

    // File menu
    connect(ui->actionExit, SIGNAL(triggered(bool)), actManager, SLOT(exit()));

    // Edit menu
    connect(ui->actionThemeLight, SIGNAL(triggered(bool)), actManager, SLOT(setDefaultTheme()));
    connect(ui->actionThemeDark, SIGNAL(triggered(bool)), actManager, SLOT(setDarkTheme()));
    connect(ui->actionPreferencesPanel, SIGNAL(triggered(bool)), actManager, SLOT(preferencesPanel()));
}
