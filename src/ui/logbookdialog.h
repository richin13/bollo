//
// Created by ricardo on 30/10/15.
//

#ifndef BOLLO_LOGBOOKDIALOG_H
#define BOLLO_LOGBOOKDIALOG_H

#include <QtCore/qjsonarray.h>
#include <QDialog>

#include "ui_headers/ui_logbookdialog.h"
#include "../core/bollo.h"

namespace Ui {
    class LogbookDialog;
}

class LogbookDialog : public QDialog {
Q_OBJECT

public:
    explicit LogbookDialog(QWidget* parent = 0);
    ~LogbookDialog();
    void load_events(int filtering = 0);
    void load_problems(int filtering = 0);
private slots:
    void on_qbClose_clicked();
    void loaded_events(QNetworkReply*);
    void setup_events(const QJsonArray&);
    void loaded_problems(QNetworkReply*);
    void setup_problems(const QJsonArray&);
    void filter(int);

private:
    Ui::LogbookDialog* ui;
    void fillBakeryListComboBox();
};


#endif //BOLLO_LOGBOOKDIALOG_H
