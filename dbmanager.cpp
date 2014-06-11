#include "dbmanager.h"

DbManager::DbManager(QObject *parent) :
    QObject(parent)
{
    m_user = new User;
    m_users = new QMap<unsigned int, User*>;
    m_uvs = new QMap<unsigned int, UV*>;
    m_branches = new QMap<unsigned int, Branche*>;
    m_filieres = new QMap<unsigned int, Filiere*>;
    m_semestres = new QMap<unsigned int, Semestre*>;
    m_categories = new QMap<unsigned int, Categorie*>;
    m_cursuss = new QMap<unsigned int, Cursus*>;
    m_notes = new QMap<unsigned int, Note*>;
    m_inscriptions = new QMap<unsigned int, Inscription*>;
    m_userInscriptions = new QMap<unsigned int, Inscription*>;

    openDb();
    load();


}
// ===== Init ===========================================================


bool DbManager::openDb()
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

void DbManager::load()
{
    loadUvs();
    loadBranches();
    loadSemestres();
    loadFilieres();
    loadCategories();
    loadCursus();
    loadNotes();
    loadUsers();
}



// ===== LOAD ===========================================================


void DbManager::loadBranches()
{
    m_branches->clear();

    QSqlQuery query("SELECT * FROM Branche");

    while (query.next())
    {
        Branche* branche = new Branche;
        branche->setId(query.value(0).toInt());
        branche->setCode(query.value(1).toString());
        branche->setNom(query.value(2).toString());
        m_branches->insert(branche->getId(), branche);
    }
}

void DbManager::loadUsers()
{
    m_users->clear();

    QSqlQuery query("SELECT * FROM User");

    while (query.next())
    {
        User* user = new User;
        user->setId(query.value(0).toInt());
        user->setNom(query.value(1).toString());
        user->setPrenom(query.value(2).toString());
        m_users->insert(user->getId(), user);
    }
}


void DbManager::loadNotes()
{
    m_notes->clear();

    QSqlQuery query("SELECT * FROM Note");

    while (query.next())
    {
        Note* note = new Note;
        note->setId(query.value(0).toInt());
        note->setCode(query.value(1).toString());
        m_notes->insert(note->getId(), note);
    }
}


void DbManager::loadSemestres()
{
    m_semestres->clear();

    QSqlQuery query("SELECT * FROM Semestre");
    unsigned int idSaison;
    Saison saison;

    while (query.next())
    {
        Semestre* semestre = new Semestre;
        semestre->setId(query.value(0).toInt());
        idSaison = query.value(1).toInt();
        if (idSaison == 1)
            saison = Printemps;
        else
            saison = Automne;
        semestre->setSaison(saison);
        semestre->setAnnee(query.value(2).toInt());
        m_semestres->insert(semestre->getId(), semestre);
    }
}


void DbManager::loadUvs()
{
    m_uvs->clear();

    QSqlQuery query("SELECT * FROM UV");

    while (query.next())
    {
        UV* uv = new UV;
        uv->setId(query.value(0).toInt());
        uv->setCode(query.value(1).toString());
        uv->setCredits(query.value(2).toInt());
        m_uvs->insert(uv->getId(), uv);
    }
}

void DbManager::loadFilieres()
{
    m_filieres->clear();

    QSqlQuery query("SELECT * FROM Filiere");

    while (query.next())
    {
        Filiere* filiere = new Filiere;
        filiere->setId(query.value(0).toInt());
        filiere->setCode(query.value(1).toString());
        filiere->setNom(query.value(2).toString());
        m_filieres->insert(filiere->getId(), filiere);
    }
}

void DbManager::loadCategories()
{
    m_categories->clear();

    QSqlQuery query("SELECT * FROM Categorie");

    while (query.next())
    {
        Categorie* categorie = new Categorie;
        categorie->setId(query.value(0).toInt());
        categorie->setCode(query.value(1).toString());
        categorie->setNom(query.value(2).toString());
        m_categories->insert(categorie->getId(), categorie);
    }
}

void DbManager::loadCursus()
{
    m_cursuss->clear();

    QSqlQuery query("SELECT * FROM Cursus");

    while (query.next())
    {
        Cursus* cursus = new Cursus;
        cursus->setId(query.value(0).toInt());
        cursus->setBranche(m_branches->find(query.value(1).toInt()).value());
        cursus->setFiliere(m_filieres->find(query.value(2).toInt()).value());
        m_cursuss->insert(cursus->getId(), cursus);
    }
}




// =====


QSqlError DbManager::lastError()
{
    return db.lastError();
}

bool DbManager::deleteDb()
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
        ret = query.exec("CREATE TABLE User (id INTEGER PRIMARY KEY, nom VARCHAR(40), prenom VARCHAR(40), simulation INTEGER, profil INTEGER)");
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
        if (ret == true)
            ret = query.exec("CREATE TABLE ProPrefEtr (id INTEGER PRIMARY KEY, idPreference INTEGER, idEtranger INTEGER)");
        if (ret == true)
            ret = query.exec("CREATE TABLE ProPrefDesirs (id INTEGER PRIMARY KEY, idPreference INTEGER, idDesir INTEGER)");
        if (ret == true)
            ret = query.exec("CREATE TABLE ProPrefBonus (id INTEGER PRIMARY KEY, idPreference INTEGER, idBonus INTEGER)");
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
        ret = query.exec("CREATE TABLE Semestre (id INTEGER PRIMARY KEY, saison INTEGER, annee INTEGER)");
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
        ret = query.exec("CREATE TABLE Simulation (id INTEGER PRIMARY KEY, profil INTEGER, cursus INTEGER)");
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

int DbManager::insertItem(User* user)
{
    bool ret = false;
    int newId = -1;
    if (db.isOpen()) // A AJOUTER : Condition de test, pour le cas ou profil etc sont = 0 => faire en fonction par la suite.
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into User values(NULL,'%1','%2','%3', '%4')").arg(user->getNom()).arg(user->getPrenom()).arg(0).arg(0));
        if (ret)
            newId = query.lastInsertId().toInt();
    }
    return newId;
}

int DbManager::insertItem(UV* uv)
{
    bool ret = false;
    int newId = -1;
    if (db.isOpen())
    {
        QSqlQuery query;
        int idCategorie = 0;
        /*
        if (uv->getCategorie() != 0)
            idCategorie = uv->getCategorie()->getId();
        */
        ret = query.exec(QString("INSERT into UV values(NULL,'%1','%2','%3')").arg(uv->getCode()).arg(uv->getCredits()).arg(idCategorie));

        if (ret)
        {
            newId = query.lastInsertId().toInt();
/*
            QSqlQuery query2;
            QMap<unsigned int, Cursus*> map = uv->getCursus();
            for (QMap<unsigned int, Cursus*>::Iterator it = map.begin(); it != map.end(); ++it)
            {
                ret = query2.exec(QString("INSERT into UVCursus values(NULL,'%1','%2')").arg(newId).arg(it.key()));
            }
*/
        }
    }
    return newId;
}

int DbManager::insertItem(Cursus* cursus)
{
    bool ret = false;
    int newId = -1;
    if (db.isOpen()) // A AJOUTER : Condition de test, pour le cas ou profil etc sont = 0 => faire en fonction par la suite.
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into Cursus values(NULL,'%1','%2')").arg(cursus->getBranche()->getId()).arg(cursus->getFiliere()->getId()));
        if (ret)
            newId = query.lastInsertId().toInt();
    }
    return newId;
}

int DbManager::insertItem(Branche* branche)
{
    bool ret = false;
    int newId = -1;
    if (db.isOpen()) // A AJOUTER : Condition de test, pour le cas ou profil etc sont = 0 => faire en fonction par la suite.
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into Branche values(NULL,'%1','%2')").arg(branche->getCode()).arg(branche->getNom()));
        if (ret)
            newId = query.lastInsertId().toInt();
    }
    return newId;
}

int DbManager::insertItem(Filiere* filiere)
{
    bool ret = false;
    int newId = -1;
    if (db.isOpen()) // A AJOUTER : Condition de test, pour le cas ou profil etc sont = 0 => faire en fonction par la suite.
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into Filiere values(NULL,'%1','%2')").arg(filiere->getCode()).arg(filiere->getNom()));
        if (ret)
            newId = query.lastInsertId().toInt();
    }
    return newId;
}

int DbManager::insertItem(BonusUV* bonus)
{
    bool ret = false;
    int newId = -1;
    if (db.isOpen()) // A AJOUTER : Condition de test, pour le cas ou profil etc sont = 0 => faire en fonction par la suite.
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into Bonus values(NULL,'%1','%2')").arg(bonus->getUV()->getId()).arg(bonus->getBonus()));
        if (ret)
            newId = query.lastInsertId().toInt();
    }
    return newId;
}

int DbManager::insertItem(Categorie* categorie)
{
    bool ret = false;
    int newId = -1;
    if (db.isOpen()) // A AJOUTER : Condition de test, pour le cas ou profil etc sont = 0 => faire en fonction par la suite.
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into Categorie values(NULL,'%1','%2')").arg(categorie->getCode()).arg(categorie->getNom()));
        if (ret)
            newId = query.lastInsertId().toInt();
    }
    return newId;
}

int DbManager::insertItem(DesirUV* desir)
{
    bool ret = false;
    int newId = -1;
    if (db.isOpen()) // A AJOUTER : Condition de test, pour le cas ou profil etc sont = 0 => faire en fonction par la suite.
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into Desir values(NULL,'%1','%2')").arg(desir->getUV()->getId()).arg(desir->getSemestre()->getId()));
        if (ret)
            newId = query.lastInsertId().toInt();
    }
    return newId;
}

int DbManager::insertItem(Etranger* etranger)
{
    bool ret = false;
    int newId = -1;
    if (db.isOpen()) // A AJOUTER : Condition de test, pour le cas ou profil etc sont = 0 => faire en fonction par la suite.
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into Desir values(NULL,'%1','%2')").arg(etranger->getTitre()).arg(etranger->getSemestre()->getId()));
        if (ret)
            newId = query.lastInsertId().toInt();
    }
    return newId;
}

int DbManager::insertItem(Inscription* inscription)
{
    bool ret = false;
    int newId = -1;
    if (db.isOpen()) // A AJOUTER : Condition de test, pour le cas ou profil etc sont = 0 => faire en fonction par la suite.
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into Inscription values(NULL,'%1','%2', '3', '4', '5')").arg(inscription->getUV()->getId()).arg(inscription->getSemestre()->getId()).arg(inscription->getNote()->getId()).arg(inscription->getCursus()->getId()).arg(inscription->getCategorie()->getId()));
        if (ret)
            newId = query.lastInsertId().toInt();
    }
    return newId;
}

int DbManager::insertItem(Note* note)
{
    bool ret = false;
    int newId = -1;
    if (db.isOpen()) // A AJOUTER : Condition de test, pour le cas ou profil etc sont = 0 => faire en fonction par la suite.
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into Note values(NULL,'%1')").arg(note->getCode()));
        if (ret)
            newId = query.lastInsertId().toInt();
    }
    return newId;
}


int DbManager::insertItem(Profil* profil)
{
    bool ret = false;
    int newId = -1;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into Profil values(NULL,'%1', '%2')").arg(profil->getActuel()->getId()).arg(profil->getVise()->getId()));
        if (ret)
        {
            newId = query.lastInsertId().toInt();

            QSqlQuery query2;
            QMap<unsigned int, Inscription*> map = profil->getInscriptions();
            for (QMap<unsigned int, Inscription*>::Iterator it = map.begin(); it != map.end(); ++it)
            {
                ret = query2.exec(QString("INSERT into ProfilInscr values(NULL,'%1','%2')").arg(newId).arg(it.key()));
            }
            QMap<unsigned int, Etranger*> map2 = profil->getEtranger();
            for (QMap<unsigned int, Etranger*>::Iterator it = map2.begin(); it != map2.end(); ++it)
            {
                ret = query2.exec(QString("INSERT into ProfilEtr values(NULL,'%1','%2')").arg(newId).arg(it.key()));
            }
            QMap<unsigned int, Etranger*> map3 = profil->getPrefEtranger();
            for (QMap<unsigned int, Etranger*>::Iterator it = map3.begin(); it != map3.end(); ++it)
            {
                ret = query2.exec(QString("INSERT into ProPrefEtr values(NULL,'%1','%2')").arg(newId).arg(it.key()));
            }
            QMap<unsigned int, DesirUV*> map4 = profil->getDesirs();
            for (QMap<unsigned int, DesirUV*>::Iterator it = map4.begin(); it != map4.end(); ++it)
            {
                ret = query2.exec(QString("INSERT into ProPrefDesirs values(NULL,'%1','%2')").arg(newId).arg(it.key()));
            }
            QMap<unsigned int, BonusUV*> map5 = profil->getBonus();
            for (QMap<unsigned int, BonusUV*>::Iterator it = map5.begin(); it != map5.end(); ++it)
            {
                ret = query2.exec(QString("INSERT into ProPrefBonus values(NULL,'%1','%2')").arg(newId).arg(it.key()));
            }

        }
    }
    return newId;
}

int DbManager::insertItem(Semestre* semestre)
{
    bool ret = false;
    int newId = -1, idSaison = 1;
    if (semestre->getSaison() == Automne)
        idSaison = 0;

    if (db.isOpen()) // A AJOUTER : Condition de test, pour le cas ou profil etc sont = 0 => faire en fonction par la suite.
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into Semestre values(NULL,'%1','%2')").arg(idSaison).arg(semestre->getAnnee()));
        if (ret)
            newId = query.lastInsertId().toInt();
    }
    return newId;
}

int DbManager::insertItem(Simulation* simulation)
{
    bool ret = false;
    int newId = -1;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into Simulation values(NULL,'%1', '%2')").arg(simulation->getProfil()->getId()).arg(simulation->getCursus()->getId()));
        if (ret)
        {
            newId = query.lastInsertId().toInt();

            QSqlQuery query2;
            QMap<unsigned int, Inscription*> map = simulation->getInscriptions();
            for (QMap<unsigned int, Inscription*>::Iterator it = map.begin(); it != map.end(); ++it)
            {
                ret = query2.exec(QString("INSERT into SimulationInscr values(NULL,'%1','%2')").arg(newId).arg(it.key()));
            }
        }
    }
    return newId;
}

QSqlQueryModel* DbManager::getUserList()
{
    QSqlQueryModel* userList = new QSqlQueryModel;
    userList->setQuery("SELECT id, nom, prenom FROM User");
    return userList;
}

QSqlQueryModel* DbManager::getBranchList()
{
    QSqlQueryModel* branchList = new QSqlQueryModel;
    branchList->setQuery("SELECT * FROM Branche");
    return branchList;
}

QSqlQueryModel* DbManager::getCatList()
{
    QSqlQueryModel* catList = new QSqlQueryModel;
    catList->setQuery("SELECT * FROM Categorie");
    return catList;
}

QSqlQueryModel* DbManager::getFiliereList()
{
    QSqlQueryModel* filiereList = new QSqlQueryModel;
    filiereList->setQuery("SELECT * FROM Filiere");
    return filiereList;
}

QSqlQueryModel* DbManager::getUVList()
{
    QSqlQueryModel* uvList = new QSqlQueryModel;
    uvList->setQuery("SELECT id, code, credits FROM UV");
    return uvList;
}

QSqlQueryModel* DbManager::getNoteList()
{
    QSqlQueryModel* noteList = new QSqlQueryModel;
    noteList->setQuery("SELECT * FROM Note");
    return noteList;
}


int DbManager::find(Branche* branche)
{
    QSqlQuery query;
    int ret = -1;
    query.exec(QString("SELECT * FROM Branche WHERE code = '%1'").arg(branche->getCode()));
    if (query.next())
    {
        ret = query.value(0).toInt();
    }
    return ret;
}

int DbManager::find(Categorie* categorie)
{
    QSqlQuery query;
    int ret = -1;
    query.exec(QString("SELECT * FROM Categorie WHERE code = '%1'").arg(categorie->getCode()));
    if (query.next())
    {
        ret = query.value(0).toInt();
    }
    return ret;
}


User* DbManager::getItem(User* user, int id)
{
    QSqlQuery query(QString("SELECT * FROM User WHERE id = '%1'").arg(id));
    int idSimu, idProfil;

    if (query.next())
    {
        user->setId(query.value(0).toInt());
        user->setNom(query.value(1).toString());
        user->setPrenom(query.value(2).toString());
        idSimu = query.value(3).toInt();
        idProfil = query.value(4).toInt();

        if (idSimu != 0)
        {
            Simulation* simulation = new Simulation;
            user->setSimulation(this->getItem(simulation, idSimu));
        }
        if (idProfil != 0)
        {
            Profil* profil = new Profil;
            user->setProfil(this->getItem(profil, idProfil));
        }
    }
    return user;
}

Filiere* DbManager::getItem(Filiere* filiere, unsigned int id)
{
    QSqlQuery query(QString("SELECT * FROM Filiere WHERE id = '%1'").arg(id));

    if (query.next())
    {
        filiere->setId(query.value(0).toInt());
        filiere->setCode(query.value(1).toString());
        filiere->setNom(query.value(2).toString());
    }
    return filiere;
}

Branche* DbManager::getItem(Branche* branche, unsigned int id)
{
    QSqlQuery query(QString("SELECT * FROM Branche WHERE id = '%1'").arg(id));

    if (query.next())
    {
        branche->setId(query.value(0).toInt());
        branche->setCode(query.value(1).toString());
        branche->setNom(query.value(2).toString());
    }
    return branche;
}

Simulation* DbManager::getItem(Simulation* simulation, unsigned int id)
{
    return NULL;
}

Profil* DbManager::getItem(Profil* profil, unsigned int id)
{
    return NULL;
}


UV* DbManager::getItem(UV* uv, int id)
{
    /*
    QSqlQuery query(QString("SELECT * FROM User WHERE id = '%1'").arg(id));
    int idSimu, idProfil;

    if (query.next())
    {
        uv->setId(query.value(0).toInt());
        user->setNom(query.value(1).toString());
        user->setPrenom(query.value(2).toString());
        idSimu = query.value(3).toInt();
        idProfil = query.value(4).toInt();

        if (idSimu != 0)
        {
            Simulation* simulation = new Simulation;
            user->setSimulation(this->getItem(simulation, idSimu));
        }
        if (idProfil != 0)
        {
            Profil* profil = new Profil;
            user->setProfil(this->getItem(profil, idProfil));
        }
    }
    return user;
    */

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

    return ret;
}





