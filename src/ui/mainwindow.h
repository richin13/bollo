#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QtWidgets/QLabel>

namespace Ui {

/**
 * Max value that all the progress bars
 * can have.
 */
#define MAX_BAR_VALUE 100

/**
 * Value used to set the progress bars
 * increments. If the value is 20 the
 * bar will increment by 20% each time.
 */
#define BAR_INCREMENT 20

/**
 * Path alias were all the GUI resources
 * are located images, sounds, gifs, etc.
 */
#define ASSETS_PATH ":/images/assets"

#define DONE_ICON  ASSETS_PATH "/check-icon.png"
#define LOADING_GIFF_DARK ASSETS_PATH "/loadDark.GIF"

/**
 * @brief Available GUI themes
 * All the available themes to be
 * applied to the GUI.
 */
enum Theme {
    DARK, DEFAULT
};

class MainWindow;
}

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setChecked(Ui::Theme);

signals:
    void setProgBarValue(int);

private slots:
    void on_firstFermentBar_valueChanged(int value);
    void on_incrementBtn_clicked();

private:
    Ui::MainWindow* ui;

    QMovie* loadingGif;
    void setLoadingGif (QLabel* );
    void setDoneIcon (QLabel* );

    void connectWidgets();
    void connectToolBarActions();
    void connectMenuActions();
    void connectHelpMenuActions();
    void connectFileMenuActions();
    void connectToolMenuActions();
    void connectEditMenuActions();
};

#endif // MAINWINDOW_H