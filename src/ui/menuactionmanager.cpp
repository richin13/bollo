#include <iostream>
#include <QApplication>
#include <QDesktopServices>

#include "mainwindow.h"
#include "telegramcpanel.h"
#include "themes.h"
#include "bakeryselect.h"
#include "preferencespanel.h"
#include "logbookdialog.h"
#include "bakeryedit.h"
#include "about.h"

using namespace std;

MenuActionManager::MenuActionManager(MainWindow* mainWindow, QObject *parent)
    : QObject(parent) {

    this->mainWindow = mainWindow;
}

MenuActionManager::~MenuActionManager() {


}

// =======================================
//          Tool bar actions
// =======================================

void MenuActionManager::showBakeryList() {

    BakerySelect*bakerySelect = new BakerySelect ();
    bakerySelect->show();

    connect(bakerySelect, SIGNAL(bakerySelected(int)), mainWindow, SLOT(showDashBoard(int)));
    connect(bakerySelect, &QDialog::finished, bakerySelect, &BakerySelect::deleteLater);
}

void MenuActionManager::showGraphs() {


}

void MenuActionManager::logBrowser() {

    LogbookDialog* logbookDialog = new LogbookDialog;
    logbookDialog->show();
    connect(logbookDialog, &QDialog::finished, logbookDialog, &LogbookDialog::deleteLater);
}

void MenuActionManager::continueProcess() {
    mainWindow->current_bakery->resume_operations();

}

void MenuActionManager::pauseProcess() {
    mainWindow->current_bakery->stop_operations();

}

void MenuActionManager::cancelProcess() {
    mainWindow->current_bakery->stop_operations(true);

}


// =======================================
//          Menu bar actions
// =======================================

// ============ FILE MENU ================

void MenuActionManager::bakeryEdit() {

    BakeryEdit* bakeryEdit = new BakeryEdit();
    bakeryEdit->show();
    connect(bakeryEdit, &QDialog::finished, bakeryEdit, &BakeryEdit::deleteLater);
}

void MenuActionManager::exit() {

    // Implement proper application closing action.
    qApp->quit();
}

// ============ EDIT MENU ================

void MenuActionManager::setDefaultTheme() {

    Ui::setLightTheme();
    mainWindow->setChecked(Ui::LIGHT);
}

void MenuActionManager::setDarkTheme() {

    Ui::setDarkTheme();
    mainWindow->setChecked(Ui::DARK);
}

void MenuActionManager::preferencesPanel() {

    PreferencesPanel* prefPanel = new PreferencesPanel();
    prefPanel->show();
    connect(prefPanel, &QDialog::finished, prefPanel, &PreferencesPanel::deleteLater);
}

// ============ TOOLS MENU ================

void MenuActionManager::graphViewer() {


}

void MenuActionManager::telegramMenu() {

    TelegramCpanel* teleCpanel = new TelegramCpanel();
    teleCpanel->show();
    connect(teleCpanel, &QDialog::finished, teleCpanel, &TelegramCpanel::deleteLater);
}

// ============ HELP MENU ================

void MenuActionManager::about() {

    About* about = new About();
    about->show();
    connect(about, &QDialog::finished, about, &About::deleteLater);
}

void MenuActionManager::help() {

    QDesktopServices::openUrl(QUrl(HELP_URL));
}

