#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QMap>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QDir>

class Manager : public QObject
{
        Q_OBJECT
    public:
        explicit Manager(QObject *parent = 0);
    protected:



    signals:

    public slots:

};




#endif // MANAGER_H