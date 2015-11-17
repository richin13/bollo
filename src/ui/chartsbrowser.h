#ifndef GRAPHBROWSER_H
#define GRAPHBROWSER_H

#include <QDialog>
#include <QtWebKitWidgets/QWebView>

#include "../core/classes/bakery.h"

namespace Ui {

class ChartsBrowser;
}

class ChartsBrowser : public QDialog {

    Q_OBJECT

public:
    explicit ChartsBrowser(QWidget *parent = 0);
    ~ChartsBrowser();

private:
    Ui::ChartsBrowser *ui;
    QWebView* viewer;

    void settings();
    void fillBakeriesList();
    QUrl buildUrl(int bakeryId);

private slots:
    void loadPage(int);
};

#endif // GRAPHBROWSER_H
