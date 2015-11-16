//
// Created by Daniel on 09/11/15.
//
#include "about.h"
#include "ui_headers/ui_about.h"

using namespace std;

About::About(QWidget *parent) : QDialog(parent),
                                ui(new Ui::About) {

    ui->setupUi(this);
}

About::~About() {

    delete ui;
}
