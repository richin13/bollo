//
// Created by ricardo on 30/10/15.
//

#ifndef BOLLO_LOGBOOKDIALOG_H
#define BOLLO_LOGBOOKDIALOG_H

#include <QDialog>
#include "ui_headers/ui_logbookdialog.h"

namespace Ui {
    class LogbookDialog;
}

class LogbookDialog : public QDialog {
Q_OBJECT

public:
    explicit LogbookDialog(QWidget* parent = 0);
    ~LogbookDialog();

private slots:
    void on_qbClose_clicked();

private:
    Ui::LogbookDialog* ui;
};


#endif //BOLLO_LOGBOOKDIALOG_H
