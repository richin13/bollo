//
// Created by ricardo on 18/10/15.
//

#include <QtCore/qdatetime.h>
#include "yeast.h"
#include "../../io/settings.h"

Yeast::Yeast() {
    /*
     * Should stay forever waiting for operation_changed signal
     * And when the code inside operation struct corresponds to
     * final step, decide whether the yeast will be contaminated
     * for the next round or not?
     * The negative part is the busy waiting of the thread is we
     * decide to implement it as a QThread.
     * Because we could just let it as an object with a couple
     * of slots and signals and interact with it only through
     * those but in that case wouldn't be a thread, as specified
     * in the project's requirements.
     *
     * Keeping the QThread idea it'd be something as follows:
     * Thread runs forever generating a random probability of
     * 'contaminated yeast', when the operation_changed signal
     * is emitted by Bakery and it contains a code operation
     * (a.k.a progress) corresponding to final step (Distribution
     * of bread) it'll set a 'contaminated yeast' flag into the
     * bakery so that affect the normal process of bread production.
     * The main problem with this implementation is the busy waiting
     * of the thread, which could be avoided by sending the thread to
     * sleep and wake it up when the mentioned signal is emitted
     *
     * */
    contaminated = false;
}

void Yeast::run() {
    int chance = get_setting("Operations", "badyeast_probability").toInt();
    qsrand((uint) QTime::currentTime().msec());

    if(on) {//Yes! It can be turned off.
        int rnd = (qrand() % 100) - chance;
        if(rnd < 0) {
            contaminated = true;
        }
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

bool Yeast::isOn() const {
    return on;
}