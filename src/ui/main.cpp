#include "mainwindow.h"
#include "themes.h"
#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;

    Ui::setDarkTheme();
    w.show();

    return a.exec();
}
