//
// Created by ricardo on 18/10/15.
//

#include <QtCore/qdatetime.h>
#include "yeast.h"
#include "../../io/settings.h"

/**
 * @brief Run method of 'Yeast' thread. Used to determine whether
 * a batch is affected by contaminated yeast or not.
 */
void Yeast::run() {
    int chance = get_setting("Operations", "badyeast_probability").toInt();
    qsrand((uint) QTime::currentTime().msec());

    int rnd = (qrand() % 100) - chance;
    if(rnd < 0) {
        contaminated = true;
    }
}

/**
 * @brief Algorithm that performs a yeast selection based of the current
 * stage of bread production in a bakery. The bad yeast can only appear or
 * be detected when dough is being fermented so here we decide if the bad
 * yeast with strike at the initial ferment of dough or the final one.
 *
 * @param op Struct containing the information of the bakery's current operation.
 */
void Yeast::select_yeast(_operation op) {
    //TODO: This could be a nice algorithm to explain in the project's paper.
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

/**
 * @brief Checks whether the yeast is contaminated or not.
 * @return true if the yeast is contaminated, false otherwise.
 */
bool Yeast::isContaminated() const {
    return contaminated;
}