#include "chartsbrowser.h"
#include "ui_headers/ui_chartsBrowser.h"

ChartsBrowser::ChartsBrowser(QWidget *parent) : QDialog(parent),
    ui(new Ui::ChartsBrowser) {

    ui->setupUi(this);
}

ChartsBrowser::~ChartsBrowser() {

    delete ui;
}
