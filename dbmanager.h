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
#include <QMessageBox>

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
        bool createUVTable();

        int insertItem(QString firstname, QString lastname, int age);
        bool getItem(int id, PersonData*& person);
        bool deleteItem(int id);
        QSqlError lastError();

    private:
        QSqlDatabase db;

    signals:

    public slots:
        bool opendb();
        bool deletedb();
        bool createTables();

};





#endif // DBMANAGER_H
