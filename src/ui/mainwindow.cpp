#include "mainwindow.h"
#include "ui_headers/ui_mainwindow.h"
#include "menuactionmanager.h"

#include <QDebug>
#include <QMovie>

int value = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {

    // MainWindow Setup
    ui->setupUi(this);

    connectWidgets();
}

MainWindow::~MainWindow() {

    delete ui;
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

    loadingGif = new QMovie(LOADING_GIFF_DARK);
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


    label->setPixmap(QPixmap(QString::fromUtf8(DONE_ICON)));

    qDebug() << "OBJECT -> " << loadingGif << " destroyed";
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

    if (theme == Ui::DARK) {

        ui->actionThemeLight->setChecked(false);
    }

    else {

        ui->actionThemeDark->setChecked(false);
    }
}

// USED FOR TESTING

void MainWindow::on_firstFermentBar_valueChanged(int value) {

    // Set loading gif the first time the bar value has changed
    if (value == BAR_INCREMENT) {

        setLoadingGif(ui->firstFermentIcon);
    }

    if (value == MAX_BAR_VALUE) {

        setDoneIcon(ui->firstFermentIcon);
        setLoadingGif(ui->doughDivisionIcon);
    }
}

void MainWindow::on_incrementBtn_clicked() {

    ui->firstFermentBar->setValue(value += 20);
}

// TODO: Connect all the remaining widgets

void MainWindow::connectWidgets() {

    connectToolBarActions();
    connectMenuActions();
}

void MainWindow::connectToolBarActions() {

    MenuActionManager* actManager = new MenuActionManager(this);

    connect(ui->actionBakeryList, SIGNAL(triggered(bool)), actManager, SLOT(showBakeryList()));
}

void MainWindow::connectMenuActions() {

    MenuActionManager* actManager = new MenuActionManager(this);

    connect(ui->actionTelegram, SIGNAL(triggered(bool)), actManager, SLOT(telegramMenu()));

    // Edit menu
    connect(ui->actionThemeLight, SIGNAL(triggered(bool)), actManager,SLOT(setDefaultTheme()));
    connect(ui->actionThemeDark, SIGNAL(triggered(bool)), actManager,SLOT(setDarkTheme()));
}
