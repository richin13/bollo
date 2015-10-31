//
// Created by ricardo on 30/10/15.
//

#ifndef BOLLO_LOGBOOK_H
#define BOLLO_LOGBOOK_H


#include <QtCore/qstring.h>

class Logbook {
protected:
    int id;
    QString bakery;
    int bakery_id;
    QString description;
    QString date;
    QString hour;

public:
    Logbook() { }

    Logbook(int _id, const QString& _bak,
            const QString& _des,
            const QString& _date,
            const QString& _hour) :
            id(_id), bakery(_bak), bakery_id(0),
            description(_des), date(_date), hour(_hour) {

    }

    Logbook(int _bakery, const QString& _des) :
            id(0), bakery(""), bakery_id(_bakery), description(_des),
            date(""), hour("") {

    }

    virtual ~Logbook() { }

    int get_id() const;
    void setId(int id);
    const QString& getBakery() const;
    void setBakery(const QString& bakery);
    int getBakeryId() const;
    void setBakery(int);
    const QString& getDescription() const;
    void setDescription(const QString& description);
    const QString& getDate() const;
    void setDate(const QString& date);
    const QString& getHour() const;
    void setHour(const QString& hour);

    bool operator==(const Logbook&);
    bool operator==(const QString&);//Compare to bakery name!
};

class LogbookProblem : public Logbook {
private:
    int dough;
public:
    LogbookProblem() { }

    LogbookProblem(int _id, const QString& _bak,
                   const QString& _des,
                   const QString& _date,
                   const QString& _hour,
                   int _dh) : Logbook(_id, _bak, _des, _date, _hour),
                              dough(_dh) {
        //TODO
    }

    LogbookProblem(int _bakery, const QString& _des, int _dgh) :
            Logbook(_bakery, _des), dough(_dgh) {

    }

    int get_dough() const;
    void set_dough(int);
};


#endif //BOLLO_LOGBOOK_H
