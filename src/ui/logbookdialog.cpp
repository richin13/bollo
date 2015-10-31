//
// Created by ricardo on 30/10/15.
//

#include "logbookdialog.h"


LogbookDialog::LogbookDialog(QWidget* parent) :
        QDialog(parent),
        ui(new Ui::LogbookDialog()) {
    ui->setupUi(this);
}

LogbookDialog::~LogbookDialog() {
    delete ui;
}

void LogbookDialog::on_qbClose_clicked() {
    this->close();
}
