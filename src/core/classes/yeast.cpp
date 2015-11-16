//
// Created by ricardo on 18/10/15.
//

#include <QtCore/qdatetime.h>
#include "yeast.h"
#include "../../io/settings.h"

Yeast::Yeast() {
    contaminated = false;
}

void Yeast::run() {
    int chance = get_setting("Operations", "badyeast_probability").toInt();
    qsrand((uint) QTime::currentTime().msec());

    int rnd = (qrand() % 100) - chance;
    if(rnd < 0) {
        contaminated = true;
    }
}

//TODO: This could be a nice algorithm to explain in the project's paper.
void Yeast::select_yeast(_operation op) {
    if(!(op.progress / 100)) {
        //Mixing the ingredients. At this point we decide whether contaminate the yeast or not.
        this->start();
    } else if(op.progress / 100 == 1 && contaminated) {
        qsrand((uint) QTime::currentTime().msec());
        if(qrand() % 2) {
            contaminated = false;
            emit contaminated_yeast();
        }
    } else if(op.progress / 100 == 4 && contaminated) {
        contaminated = false;
        emit contaminated_yeast();
    }
}

bool Yeast::isContaminated() const {
    return contaminated;
}