#include <QtWidgets/qmessagebox.h>
#include "core/build.h"
#include "logger/logger.h"
#include "core/bollo.h"
#include "ui/logindialog.h"

using namespace bollo;

int main(int argc, char** argv) {
    BolloApp app(argc, argv);

    cout << "Hello, World! I am Bollo\n";
    cout << "This... is... just... the beginning\n";
    cout << "Expect us!" << endl;

//    _log.bakery(1) << "Logging in PostgresSQL!";
//    _log.bakery(bakery->get_id()) << "Logging!";

    //FIXME: this should be in BolloApp:QApplication class.
    if(!BolloApp::success_connection) {
        QMessageBox::critical(nullptr, "Unable to connect to the database server",
                              "An error occurred while trying to reach the PosgreSQL server");
    } else {

    }

    LoginDialog loginDialog;
    loginDialog.show();

    return app.exec();
}