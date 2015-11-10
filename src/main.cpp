#include "core/bollo.h"
#include "ui/logindialog.h"

#include "ui/mainwindow.h"
#include "ui/themes.h"

#include "ui/logbookdialog.h"

INITIALIZE_EASYLOGGINGPP

void init_log();
std::string* _app_dir();

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    qRegisterMetaType<operation>("operation");
    START_EASYLOGGINGPP(argc, argv);
    init_log();

    LOG(INFO) << "Application starting";
    BolloApp& a = BolloApp::get();

    MainWindow w;

    w.show();
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