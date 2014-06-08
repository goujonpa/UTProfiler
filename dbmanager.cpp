#include "dbmanager.h"

DbManager::DbManager(QObject *parent) :
    QObject(parent)
{
}


bool DbManager::openDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    #ifdef Q_OS_LINUX

    QString path(QDir::home().path());
    path.append(QDir::separator()).append("my.db.sqlite");
    path = QDir::toNativeSeparators(path);
    db.setDatabaseName(path);

    #else

    db.setDatabaseName("my.db.sqlite");

    #endif
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

    QString path(QDir::home().path());

    path.append(QDir::separator()).append("my.db.sqlite");
    path = QDir::toNativeSeparators(path);

    return QFile::remove(path);

    #else
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
            ret = query.exec("CREATE TABLE UVCursus (id INTEGER PRIMARY KEY, idUV INTEGER, idCursus INTEGER)");
    }
    return ret;
}

bool DbManager::createUserTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE User (id INTEGER PRIMARY KEY, nom VARCHAR(40), prenom VARCHAR(40), simulation INTEGER, profil INTEGER, preference INTEGER)");
    }
    return ret;
}

bool DbManager::createProfilTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE Profil (id INTEGER PRIMARY KEY, actuel INTEGER, vise INTEGER)");
        if (ret == true)
            ret = query.exec("CREATE TABLE ProfilInscr (id INTEGER PRIMARY KEY, idProfil INTEGER, idInscription INTEGER)");
        if (ret == true)
            ret = query.exec("CREATE TABLE ProfilEtr (id INTEGER PRIMARY KEY, idProfil INTEGER, idEtranger INTEGER)");
    }
    return ret;
}

bool DbManager::createInscriptionTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE Inscription (id INTEGER PRIMARY KEY, uv INTEGER, semestre INTEGER, note INTEGER, cursus INTEGER, categorie INTEGER)");
    }
    return ret;
}

bool DbManager::createEtrangerTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE Etranger (id INTEGER PRIMARY KEY, titre VARCHAR(100), semestre INTEGER)");
    }
    return ret;
}

bool DbManager::createSemestreTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE Semestre (id INTEGER PRIMARY KEY, saison VARCHAR(30), annee INTEGER)");
    }
    return ret;
}

bool DbManager::createPreferenceTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE Preference (id INTEGER PRIMARY KEY, idProfil INTEGER)");
        if (ret == true)
            ret = query.exec("CREATE TABLE PreferenceEtr (id INTEGER PRIMARY KEY, idPreference INTEGER, idEtranger INTEGER)");
        if (ret == true)
            ret = query.exec("CREATE TABLE PreferenceDesirs (id INTEGER PRIMARY KEY, idPreference INTEGER, idDesir INTEGER)");
        if (ret == true)
            ret = query.exec("CREATE TABLE PreferenceBonus (id INTEGER PRIMARY KEY, idPreference INTEGER, idBonus INTEGER)");
    }
    return ret;
}

bool DbManager::createBonusTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE Bonus (id INTEGER PRIMARY KEY, uv INTEGER, bonus INTEGER)");
    }
    return ret;
}

bool DbManager::createBrancheTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE Branche (id INTEGER PRIMARY KEY, code VARCHAR(10), nom VARCHAR(100))");
    }
    return ret;
}

bool DbManager::createDesirTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE Desir (id INTEGER PRIMARY KEY, uv INTEGER, semestre INTEGER)");
    }
    return ret;
}

bool DbManager::createFiliereTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE Filiere (id INTEGER PRIMARY KEY, code VARCHAR(10), nom VARCHAR(100))");
    }
    return ret;
}

bool DbManager::createNoteTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE Note (id INTEGER PRIMARY KEY, code VARCHAR(10))");
    }
    return ret;
}

bool DbManager::createSimulationTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE Simulation (id INTEGER PRIMARY KEY, preference INTEGER, cursus INTEGER)");
        if (ret == true)
            ret = query.exec("CREATE TABLE SimulationInscr (id INTEGER PRIMARY KEY, idSimu INTEGER, inscription INTEGER)");

    }
    return ret;
}

bool DbManager::createCategorieTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE Categorie (id INTEGER PRIMARY KEY, code VARCHAR(10), nom VARCHAR(100))");
    }
    return ret;
}

bool DbManager::createCursusTable()
{
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("CREATE TABLE Cursus (id INTEGER PRIMARY KEY, branche INTEGER, filiere INTEGER)");
    }
    return ret;
}

/*
int DbManager::insertUser(User* user)
{
    int newId = -1;
    bool ret = false;

    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into USER values(NULL,'%1','%2','%3', '%4')").arg(user->getNom()).arg(user->getPrenom()).arg(user->getSimulation()->getId()).arg(user->getProfil()->getId).arg(user->getPreference()->getId()));
        if (ret)
        {
            newId = query.lastInsertId().toInt();
        }
    }
    return newId;
}
*/

QString DbManager::getUV(int id)
{
    bool ret = false;

    unsigned int idUV, credits, categorie;
    QString code;

    QSqlQuery query(QString("SELECT * FROM UV WHERE id = %1").arg(id));

    if (query.next())
    {
        idUV = query.value(0).toInt();
        code = query.value(1).toString();
        credits = query.value(2).toInt();
        categorie = query.value(3).toInt();
        ret = true;
    }

    return code;
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
    bool ret;
    ret = createUVTable();
    if (ret == true)
        ret = createUserTable();
    if (ret == true)
        ret = createProfilTable();
    if (ret == true)
        ret = createInscriptionTable();
    if (ret == true)
        ret = createEtrangerTable();
    if (ret == true)
        ret = createSemestreTable();
    if (ret == true)
        ret = createBonusTable();
    if (ret == true)
        ret = createBrancheTable();
    if (ret == true)
        ret = createDesirTable();
    if (ret == true)
        ret = createSimulationTable();
    if (ret == true)
        ret = createCategorieTable();
    if (ret == true)
        ret = createCursusTable();
    if (ret == true)
        ret = createFiliereTable();
    if (ret == true)
        ret = createNoteTable();
    if (ret == true)
        ret = createPreferenceTable();

    return ret;
}





