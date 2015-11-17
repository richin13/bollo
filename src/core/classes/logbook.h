//
// Created by ricardo on 30/10/15.
//

#ifndef BOLLO_LOGBOOK_H
#define BOLLO_LOGBOOK_H


#include <QtCore/qstring.h>

/**
 * This class contains the information of a Logbook entry.
 *
 * @author Ricardo Madriz
 */
class Logbook {
protected:
    /**
     * The logbook entry id
     */
    int id;

    /**
     * The bakery name corresponding to the logbook entry.
     */
    QString bakery_name;

    /**
     * The bakery id corresponding to the logbook entry.
     */
    int bakery_id;

    /**
     * The logbook entry description
     */
    QString description;

    /**
     * The logbook entry date
     */
    QString date;

    /**
     * The logbook entry hour
     */
    QString hour;

public:
    Logbook() { }

    /**
     * @brief Class constructor
     * @param _id The id
     * @param _bak The bakery name
     * @param _des The description
     * @param _date The date
     * @param _hour The hour
     */
    Logbook(int _id, const QString& _bak,
            const QString& _des,
            const QString& _date,
            const QString& _hour) :
            id(_id), bakery_name(_bak), bakery_id(0),
            description(_des), date(_date), hour(_hour) {

    }

    /**
     * @brief Another class constructor
     * @param _bakery The bakery id
     * @param _des The entry description.
     */
    Logbook(int _bakery, const QString& _des) :
            id(0), bakery_name(""), bakery_id(_bakery), description(_des),
            date(""), hour("") {

    }

    virtual ~Logbook() { }

    int get_id() const;
    const QString& getBakery() const;
    int getBakeryId() const;
    const QString& getDescription() const;
    const QString& getDate() const;
    const QString& getHour() const;

    bool operator==(const Logbook&);
    bool operator==(const QString&);//Compare to bakery name!
};

/**
 * This class contains the information of a logbook problem entry.
 * @see Logbook
 *
 * @author Ricardo Madriz
 */
class LogbookProblem : public Logbook {
private:
    int dough;
public:
    LogbookProblem() { }

    LogbookProblem(const LogbookProblem& c) : Logbook(c) {
        this->id = c.id;
        this->bakery_name = c.bakery_name;
        this->bakery_id = c.bakery_id;
        this->date = c.date;
        this->hour = c.hour;
        this->dough = c.dough;
    }

    LogbookProblem(int _id, const QString& _bak,
                   const QString& _des,
                   const QString& _date,
                   const QString& _hour,
                   int _dh) : Logbook(_id, _bak, _des, _date, _hour),
                              dough(_dh) { }

    LogbookProblem(int _bakery, const QString& _des, int _dgh) :
            Logbook(_bakery, _des), dough(_dgh) { }

    int get_dough() const;
    void set_dough(int);
};


#endif //BOLLO_LOGBOOK_H
