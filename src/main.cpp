#include "core/bollo.h"
#include "ui/logindialog.h"

#include "ui/mainwindow.h"
#include "ui/themes.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    BolloApp& a = BolloApp::get();

    LoginDialog loginDialog;
    MainWindow w;
    Ui::setDarkTheme();
    //loginDialog.show();
    w.show();

    return app.exec();
}