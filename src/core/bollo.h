//
// Created by ricardo on 11/10/15.
//

#ifndef BOLLO_BOLLO_H
#define BOLLO_BOLLO_H
#define APP_NAME "Bollo"
#define HOST "104.154.49.207"
#define USER "root"
#define PASSWORD "W3aS28yt"
#define SCHEMA "bollo_test"

#include <QtWidgets/qapplication.h>
#include "build.h"
#include "classes/person.h"

class BolloApp : public QApplication {
private:
    string app_name;
    string codename;
    string version;
    bool success_connection;
    Person current_user;
public:
    explicit BolloApp(int argc, char** argv);

    Person* get_current_user();

    void set_user(Person*);
};


#endif //BOLLO_BOLLO_H
