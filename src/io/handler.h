//
// Created by ricardo on 26/10/15.
//

#ifndef BOLLO_HANDLER_H
#define BOLLO_HANDLER_H


#include <QtCore/qvector.h>
#include <QtCore/qjsonobject.h>
#include "../logger/easylogging++.h"
#include "../core/classes/bakery.h"

class Bakery;

struct _operation;

/**
 * Helper class to handle a API response.
 *
 * @author Ricardo Madriz
 */
class Handler {
public:
    static QString get_province_name(int code);
    static void get_bakeries_vector(std::vector<Bakery*>* const b, QJsonArray* const array);
};


#endif //BOLLO_HANDLER_H
