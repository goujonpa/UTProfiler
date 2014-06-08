#include "dbmanager.h"

DbManager::DbManager(QObject *parent) :
    QObject(parent)
{
}



bool DbManager::openDB()
{
    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");

    #ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux

    QString path(QDir::home().path());
    path.append(QDir::separator()).append("my.db.sqlite");
    path = QDir::toNativeSeparators(path);
    db.setDatabaseName(path);

    #else

    // NOTE: File exists in the application private folder, in Symbian Qt implementation

    db.setDatabaseName("my.db.sqlite");

    #endif

    // Open databasee

    return db.open();
}

QSqlError DbManager::lastError()
{
    // If opening database has failed user can ask
    // error description by QSqlError::text()

    return db.lastError();
}

bool DbManager::deleteDB()
{
    // Close database
    db.close();

    #ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux

    QString path(QDir::home().path());

    path.append(QDir::separator()).append("my.db.sqlite");
    path = QDir::toNativeSeparators(path);

    return QFile::remove(path);

    #else

    // Remove created database binary file

    return QFile::remove("my.db.sqlite");

    #endif
}



bool DbManager::createUVTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE UV (id INTEGER PRIMARY KEY, code VARCHAR(10), credits INTEGER, categorie INTEGER)");
        if (ret == true)
            ret = query.exec("CREATE TABLE UV (id INTEGER PRIMARY KEY, idUV INTEGER, idCursus INTEGER)");
    }
    return ret;
}

int DbManager::insertItem(QString firstname, QString lastname, int age)
{
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
    {

        //http://www.sqlite.org/autoinc.html
        // NULL = is the keyword for the autoincrement to generate next value

        QSqlQuery query;
        ret = query.exec(QString("insert into person values(NULL,'%1','%2',%3)").arg(firstname).arg(lastname).arg(age));

        // Get database given autoincrement value

        if (ret)
        {
            // http://www.sqlite.org/c3ref/last_insert_rowid.html

            newId = query.lastInsertId().toInt();
        }

    }
    return newId;
}


bool DbManager::getItem(int id, PersonData*& person)
{
    bool ret = false;

    QSqlQuery query(QString("select * from person where id = %1").arg(id));

    if (query.next())
    {
        person->id = query.value(0).toInt();
        person->firstname = query.value(1).toString();
        person->lastname = query.value(2).toString();
        person->age = query.value(3).toInt();
        ret = true;
    }

    return ret;
}


bool DbManager::deleteItem(int id)
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec(QString("delete from person where id=%1").arg(id));
    }
    return ret;
}

bool DbManager::opendb()
{
    return this->openDB();
}

bool DbManager::deletedb()
{
    return this->deleteDB();
}

bool DbManager::createTables()
{
    createUVTable();
    return true;
}
