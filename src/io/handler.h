//
// Created by ricardo on 26/10/15.
//

#ifndef BOLLO_HANDLER_H
#define BOLLO_HANDLER_H


#include <QtCore/qvector.h>
#include <QtCore/qjsonobject.h>

class Handler {
private:
    static QString get_province_name(int code) {
        switch(code) {
            case 1:
                return QStringLiteral("San José");
            case 2:
                return QStringLiteral("Alajuela");
            case 3:
                return QStringLiteral("Cartago");
            case 4:
                return QStringLiteral("Heredia");
            case 5:
                return QStringLiteral("Guanacaste");
            case 6:
                return QStringLiteral("Puntarenas");
            case 7:
                return QStringLiteral("Limón");
            default:
                LOG(WARNING) << "Invalid province number -> " + std::to_string(code);
                return QStringLiteral("Run for your life");
        }
    }

public:
    static void get_bakeries_vector(QJsonArray* array) {
        int size = array->size();

        for(int i = 0; i < size; ++i) {
            QJsonObject bakery = array->at(i).toObject();

            //information
            int id = bakery.take("id").toInt();
            QString name = bakery.take("name").toString();
            QString province = Handler::get_province_name(bakery.take("province").toInt());
            QString city = bakery.take("city").toString();
            int stock = bakery.take("stock").toString().toInt();
            int progress = bakery.take("progress").toString().toInt();
            QString status = bakery.take("status").toString();


            BolloApp::get().bakeries.push_back(Bakery((unsigned int)id, name, province, city, stock, progress, status));
        }
    }
};


#endif //BOLLO_HANDLER_H
