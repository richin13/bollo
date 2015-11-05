#include <iostream>
#include <QApplication>

#include "mainwindow.h"
#include "menuactionmanager.h"
#include "telegramcpanel.h"
#include "themes.h"
#include "bakeryselect.h"
#include "preferencespanel.h"
#include "logbookdialog.h"

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

    BakerySelect* bakeryList = new BakerySelect ();
    bakeryList->show();
}

void MenuActionManager::showGraphs() {


}

void MenuActionManager::showLogbook() {

    LogbookDialog* logbookDialog = new LogbookDialog;
    logbookDialog->show();
    connect(logbookDialog, &QDialog::finished, logbookDialog, &LogbookDialog::deleteLater);
}

void MenuActionManager::continueProcess() {


}

void MenuActionManager::pauseProcess() {


}

void MenuActionManager::cancelProcess() {


}

void MenuActionManager::showBakeryLog() {


}


// =======================================
//          Menu bar actions
// =======================================

// ============ FILE MENU ================

void MenuActionManager::bakeryEdit() {


}

void MenuActionManager::signOut() {


}

void MenuActionManager::exit() {

    // Implement proper application closing action.
    qApp->quit();
}

// ============ EDIT MENU ================

void MenuActionManager::setDefaultTheme() {

    Ui::setLightTheme();
    mainWindow->setChecked(Ui::DEFAULT);
}

void MenuActionManager::setDarkTheme() {

    Ui::setDarkTheme();
    mainWindow->setChecked(Ui::DARK);
}

void MenuActionManager::changePassword() {


}

void MenuActionManager::preferencesPanel() {

    PreferencesPanel* prefPanel = new PreferencesPanel();
    prefPanel->show();
    connect(prefPanel, &QDialog::finished, prefPanel, &PreferencesPanel::deleteLater);
}

// ============ TOOLS MENU ================

void MenuActionManager::logBrowser() {


}

void MenuActionManager::graphViewer() {


}

void MenuActionManager::telegramMenu() {

    TelegramCpanel* teleCpanel = new TelegramCpanel();
    teleCpanel->show();
    connect(teleCpanel, &QDialog::finished, teleCpanel, &TelegramCpanel::deleteLater);
}

// ============ HELP MENU ================

void MenuActionManager::about() {


}

void MenuActionManager::help() {


}

