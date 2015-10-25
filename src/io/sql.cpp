//
// Created by ricardo on 05/10/15.
//
#include "../core/build.h"
#include "sql.h"

#include <QtSql/qsqlquery.h>
#include <QtCore/qvariant.h>
#include <QtCore/qcryptographichash.h>
#include <QDebug>


int login(const QString username, const QByteArray raw_pw) {
    int user_id = 0;
    QString _pw = QString(QCryptographicHash::hash(raw_pw.constData(), QCryptographicHash::Sha256).toHex());
    QSqlQuery query;
    query.prepare("SELECT user_id FROM bollo_user WHERE user_username = :usr AND user_password = :pw");

    query.bindValue(":usr", QVariant(username));
    query.bindValue(":pw", QVariant(_pw));
    query.exec();

    if(query.next()) {
        //TODO: log that login was successful!
        user_id = query.value(0).toInt();
    }
    return user_id;

}