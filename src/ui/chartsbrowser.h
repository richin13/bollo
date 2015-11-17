#ifndef GRAPHBROWSER_H
#define GRAPHBROWSER_H

#include <QDialog>

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
};

#endif // GRAPHBROWSER_H
