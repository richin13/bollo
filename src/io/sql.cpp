//
// Created by ricardo on 05/10/15.
//
#include "../core/build.h"
#include "sql.h"

#include <QtSql/qsqlquery.h>
#include <QtCore/qvariant.h>
#include <QtCore/qcryptographichash.h>
#include <QDebug>

using namespace bollo::query;

int bollo::query::login(const QString username, const QByteArray raw_pw) {
    int user_id = 0;
    const char* std_str = raw_pw.constData();
    QString _pw = QString(QCryptographicHash::hash(std_str, QCryptographicHash::Sha1).toHex());
    QSqlQuery query;
    query.prepare("SELECT user_id FROM bollo_user WHERE user_username = ? AND user_password = ?");

    query.addBindValue(QVariant(username));
    query.addBindValue(QVariant(_pw));

    query.exec();

    if(query.next()) {
        //TODO: log that login was successful!
        user_id = query.value(0).toInt();
    }

    return user_id;

}