#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QMap>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QDir>
#include <QSqlQuery>
#include <QVariant>
#include <QString>

class PersonData // classe exemple
{
    public:
        int id;
        QString firstname;
        QString lastname;
        int age;
};



class DbManager : public QObject
{
        Q_OBJECT
    public:
        explicit DbManager(QObject *parent = 0);

    public:
        bool openDB();
        bool deleteDB();
        bool createProfilTable(); // il va falloir créer un template pour ce db manager.
        int insertPerson(QString firstname, QString lastname, int age);
        bool getPerson(int id, PersonData*& person);
        bool deletePerson(int id);
        QSqlError lastError();

    private:
        QSqlDatabase db;

    signals:

    public slots:

};





#endif // DBMANAGER_H
