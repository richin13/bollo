#ifndef SELECTWINDOW_H
#define SELECTWINDOW_H

#include <QWidget>
#include <QString>

#include "../core/classes/bakery.h"

namespace Ui {

    #define MARGIN 35
    class selectWindow;
}

class SelectWindow : public QWidget {

    Q_OBJECT

public:
    explicit SelectWindow(QWidget *parent = 0);
    ~SelectWindow();

    void buildBakeriesList();
    void addBakery(const Bakery& );
    QWidget* createHorizontalLine();
    void displayWebPage(QString url = "http://bollo-server.bitnamiapp.com/bollo_web/?thisTextMustBeSuperSecret!__-___");

private:
    Ui::selectWindow *ui;

signals:
    void bakerySelected(int);

private slots:
    void bakeryButtonClicked();

};

#endif // SELECTWINDOW_H