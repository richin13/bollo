//
// Created by ricardo on 05/10/15.
//


#include "logger.h"


Logger logbook;

QMutex mutex;

/**
 * Overloaded function for the '<<' operator.
 * Please use logBook.bakery(bakery_id) to add an entry
 * to the logbook.
 * @param x QString Event information.
 */
Logger& Logger::operator<<(const QString& x) {
    this->entry->setDescription(x);
    buffer->enqueue(this->entry);
    emptyBuffer->wakeAll();
    mutex.unlock();
    std::cout << "Current buffer size: " << buffer->size() << std::endl;
    return *this;
}

/**
 * Saves an entry into the logbook associated to the specified
 * bakery.
 *
 * @param bakery_id int Bakery id.
 */
Logger& Logger::general(int bakery_id) {
    mutex.lock();//One thread at a time
    this->entry = new Logbook(bakery_id, "");

    return *this;
}

/**
 * Saves an entry into the logbook associated to the specified
 * bakery.
 *
 * @param bakery_id int Bakery id.
 */
Logger& Logger::problem(int bakery_id, int dough) {
    mutex.lock();//One thread at a time
    this->entry = new LogbookProblem(bakery_id, "", dough);
    return *this;
}
