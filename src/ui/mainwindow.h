#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QtWidgets/QLabel>

#include "selectpane.h"

namespace Ui {

/**
 * Max value that all the progress bars
 * can have.
 */
#define MAX_BAR_VALUE 99
#define MIN_BAR_VALUE 0

/**
 * Value used to set the progress bars
 * increments. If the value is 20 the
 * bar will increment by 20% each time.
 */
#define BAR_INCREMENT 20

/**
 * @brief Available GUI themes
 * All the available themes to be
 * applied to the GUI.
 */
enum Theme {
    DARK, LIGHT
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
    void exitApp();
    void showSelectPane();
    void showDashBoard(int );
    void signOut();

public slots:
    void progress_operation(_operation current_operation);

private:
    Ui::MainWindow* ui;
    SelectWindow* selectPane;

    void showLoginAndValidate();
    void applySettings();
    void widgetsEnabled(bool);

    QMovie* loadingGif;
    void setLoadingGif (QLabel* );
    void setDoneIcon (QLabel* );
    void setDefaultIcon(QLabel* );

    void connectWidgets();
    void connectToolBarActions();

    void connectMenuActions();

    void connectBakeriesOperations();


    //***********Bakery Variables*************//
    int current_bakery_id;
    Bakery *current_bakery;

    void set_current_bakery(int bakery_id);


    //*******Updating Methods************//
    void update_bakery_operations(_operation bakery_progress);
    void change_bakery_displayed(int bakery_id);
    void _update();


    //*************Progress Bars Methods*************//
    void setProgressBar(int progress);

    void set_mixIngredients_progress(int progress_value);
    void set_firstFermentBar(int progress_value);
    void set_doughDivisionBar(int progress_value);
    void set_doughFormingBar(int progress_value);
    void set_finalFermentBar(int progress_value);
    void set_bakingBar(int progress_value);
    void set_onSaleBar(int progress_value);
    void set_shippedBar(int progress_value);

    //*********Update Bakery Progress Operations Methods***********//
    void update_from_mix_ingredients();
    void update_from_first_fermentation();
    void update_from_bread_distribution();
    void update_from_sale();
    void update_from_baking();
    void update_from_final_fermentation();
    void update_from_forming_dough();
    void update_from_divide_dough();

    //*******Cleaning Progress Bars Methods**********//
    void clean_mixIngredients_progress();
    void clean_firstFermentBar();
    void clean_doughDivisionBar();
    void clean_doughFormingBar();
    void clean_finalFermentBar();
    void clean_bakingBar();
    void clean_onSaleBar();
    void clean_shippedBar();

    void clean_all();
};

#endif // MAINWINDOW_H
