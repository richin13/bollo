#include <iostream>
#include <QApplication>

#include "mainwindow.h"
#include "menuactionmanager.h"
#include "telegramcpanel.h"
#include "themes.h"

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

    cout << "Works bitch" << endl;
}

void MenuActionManager::showGraphs() {


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

    Ui::setDefaultTheme();
    mainWindow->setChecked(Ui::DEFAULT);
}

void MenuActionManager::setDarkTheme() {

    Ui::setDarkTheme();
    mainWindow->setChecked(Ui::DARK);
}

void MenuActionManager::changePassword() {


}

// ============ TOOLS MENU ================

void MenuActionManager::logBrowser() {


}

void MenuActionManager::graphViewer() {


}

void MenuActionManager::telegramMenu() {

    TelegramCpanel* teleCpanel = new TelegramCpanel();

    teleCpanel->show();
}

// ============ HELP MENU ================

void MenuActionManager::about() {


}

void MenuActionManager::help() {


}

