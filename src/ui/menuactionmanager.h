#ifndef MENUACTIONMANAGER_H
#define MENUACTIONMANAGER_H

#include <QObject>
#include "mainwindow.h"

#define HELP_URL "http://bollo-server.bitnamiapp.com/bollo_web/?faqs"

class MenuActionManager : public QObject {

    Q_OBJECT

public:
     MenuActionManager(MainWindow* mainWindow, QObject *parent = 0);
    ~MenuActionManager();

public slots:
    // Tool bar action
    void showBakeryList();
    void showGraphs();
    void logBrowser(); // Used in tools menu
    void continueProcess();
    void pauseProcess();
    void cancelProcess();

    // Menu bar actions

    // File Menu
    void bakeryEdit(); // Used in edit menu
    void exit();

    // Edit menu
    void setDefaultTheme();
    void setDarkTheme();
    void preferencesPanel();

    // Tools menu
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
