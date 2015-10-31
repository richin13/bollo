#include "core/bollo.h"
#include "ui/logindialog.h"

#include "ui/mainwindow.h"
#include "ui/themes.h"

#include "logger/easylogging++.h"
#include "ui/logbookdialog.h"

INITIALIZE_EASYLOGGINGPP

void init_log();
std::string* _app_dir();

int main(int argc, char** argv) {
    START_EASYLOGGINGPP(argc, argv);
    init_log();

    LOG(INFO) << "Application starting";
    QApplication app(argc, argv);
    BolloApp& a = BolloApp::get();

    Ui::setDarkTheme();
//    LoginDialog loginDialog;
//    MainWindow w;
//
//    QObject::connect(&loginDialog, &LoginDialog::logged_in, &w, &MainWindow::show);
//    loginDialog.show();
    LogbookDialog ld;
    ld.show();
    return app.exec();
}

void init_log() {
    el::Configurations defaultConf;
    defaultConf.setToDefault();
    // Values are always std::string
    defaultConf.set(el::Level::Global,
                    el::ConfigurationType::Format,
                    "< %level>[%datetime]: %msg");
    defaultConf.set(el::Level::Global,
                    el::ConfigurationType::ToStandardOutput,
                    "true");
    defaultConf.set(el::Level::Global,
                    el::ConfigurationType::ToFile,
                    "true");
    defaultConf.set(el::Level::Global,
                    el::ConfigurationType::Filename,
                    *_app_dir() + "/logs/bollo.log");

    el::Loggers::reconfigureLogger("default", defaultConf);
}

std::string* _app_dir() {
    QDir* app_dir = new QDir(QDir().homePath() + "/bollo");
    std::string* dir = new string(app_dir->absolutePath().toStdString());
    delete app_dir;
    return dir;
}