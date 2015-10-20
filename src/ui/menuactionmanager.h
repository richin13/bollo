#ifndef MENUACTIONMANAGER_H
#define MENUACTIONMANAGER_H

#include <QObject>
#include "mainwindow.h"

class MenuActionManager : public QObject {

    Q_OBJECT

public:
     MenuActionManager(MainWindow* mainWindow, QObject *parent = 0);
    ~MenuActionManager();

public slots:
    // Tool bar action
    void showBakeryList();
    void showGraphs();
    void continueProcess();
    void pauseProcess();
    void cancelProcess();
    void showBakeryLog();

    // Menu bar actions

    // File Menu
    void bakeryEdit(); // Used in edit menu as editBakery
    void signOut();
    void exit();

    // Edit menu
    void setDefaultTheme();
    void setDarkTheme();
    void changePassword();

    // Tools menu
    void logBrowser();
    void graphViewer();
    void telegramMenu();

    // Help menu
    void about();
    void help();

private:

    /**
     * @brief mainWindow Used to access some GUI update functions
     */
    MainWindow* mainWindow;
};

#endif // MENUACTIONMANAGER_H
