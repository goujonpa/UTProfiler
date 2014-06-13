#include "dbmanager.h"

DbManager::DbManager(QObject *parent) :
    QObject(parent)
{
    m_users = new QMap<unsigned int, User*>;
    m_uvs = new QMap<unsigned int, UV*>;
    m_branches = new QMap<unsigned int, Branche*>;
    m_filieres = new QMap<unsigned int, Filiere*>;
    m_semestres = new QMap<unsigned int, Semestre*>;
    m_categories = new QMap<unsigned int, Categorie*>;
    m_cursus = new QMap<unsigned int, Cursus*>;
    m_notes = new QMap<unsigned int, Note*>;
    m_inscriptions = new QMap<unsigned int, Inscription*>;
    m_profils = new QMap<unsigned int, Profil*>;
    m_etrangers = new QMap<unsigned int, Etranger*>;
    m_prefEtrangers = new QMap<unsigned int, Etranger*>;
    m_desirs = new QMap<unsigned int, DesirUV*>;
    m_bonus = new QMap<unsigned int, BonusUV*>;
    m_simulations = new QMap<unsigned int, Simulation*>;



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

    loadBranches();
    loadSemestres();
    loadFilieres();
    loadCategories();
    loadNotes();
    loadCursus();
    loadUvs();
    loadProfils();
    loadUsers();

}

// ===== DESTRUCTEUR ==========================================================

void DbManager::save()
{
    QMap<unsigned int, User*>::Iterator it;
    for(it = m_users->begin(); it != m_users->end(); ++it)
    {
        insertItem(it.value());
    }

    QMap<unsigned int, Branche*>::Iterator it3;
    for(it3 = m_branches->begin(); it3 != m_branches->end(); ++it3)
    {
        insertItem(it3.value());
    }

    QMap<unsigned int, Semestre*>::Iterator it4;
    for(it4 = m_semestres->begin(); it4 != m_semestres->end(); ++it4)
    {
        insertItem(it4.value());
    }

    QMap<unsigned int, Filiere*>::Iterator it5;
    for(it5 = m_filieres->begin(); it5 != m_filieres->end(); ++it5)
    {
        insertItem(it5.value());
    }

    QMap<unsigned int, Categorie*>::Iterator it6;
    for(it6 = m_categories->begin(); it6 != m_categories->end(); ++it6)
    {
        insertItem(it6.value());
    }

    QMap<unsigned int, Cursus*>::Iterator it7;
    for(it7 = m_cursus->begin(); it7 != m_cursus->end(); ++it7)
    {
        insertItem(it7.value());
    }

    QMap<unsigned int, Note*>::Iterator it8;
    for(it8 = m_notes->begin(); it8 != m_notes->end(); ++it8)
    {
        insertItem(it8.value());
    }

    QMap<unsigned int, Inscription*>::Iterator it9;
    for(it9 = m_inscriptions->begin(); it9 != m_inscriptions->end(); ++it9)
    {
        insertItem(it9.value());
    }

    QMap<unsigned int, Etranger*>::Iterator it10;
    for(it10 = m_etrangers->begin(); it10 != m_etrangers->end(); ++it10)
    {
        insertItem(it10.value());
    }

    QMap<unsigned int, Etranger*>::Iterator it11;
    for(it11 = m_prefEtrangers->begin(); it11 != m_prefEtrangers->end(); ++it11)
    {
        insertItem(it11.value());
    }

    QMap<unsigned int, Profil*>::Iterator it12;
    for(it12 = m_profils->begin(); it12 != m_profils->end(); ++it12)
    {
        insertItem(it12.value());
    }

    QMap<unsigned int, DesirUV*>::Iterator it13;
    for(it13 = m_desirs->begin(); it13 != m_desirs->end(); ++it13)
    {
        insertItem(it13.value());
    }

    QMap<unsigned int, BonusUV*>::Iterator it14;
    for(it14 = m_bonus->begin(); it14 != m_bonus->end(); ++it14)
    {
        insertItem(it14.value());
    }

    QMap<unsigned int, Simulation*>::Iterator it15;
    for(it15 = m_simulations->begin(); it15 != m_simulations->end(); ++it15)
    {
        insertItem(it15.value());
    }

    QMap<unsigned int, UV*>::Iterator it2;
    for(it2 = m_uvs->begin(); it2 != m_uvs->end(); ++it2)
    {
        insertItem(it2.value());
    }

}

bool DbManager::remove()
{
    QSqlQuery query;
    bool ret = false;
    ret = query.exec("DELETE FROM UVCursus");
    if (ret)
        ret = query.exec("DELETE FROM User");
    if (ret)
        ret = query.exec("DELETE FROM Profil");
    if (ret)
        ret = query.exec("DELETE FROM ProfilInscr");
    if (ret)
        ret = query.exec("DELETE FROM ProfilEtr");
    if (ret)
        ret = query.exec("DELETE FROM ProPrefEtr");
    if (ret)
        ret = query.exec("DELETE FROM ProPrefDesirs");
    if (ret)
        ret = query.exec("DELETE FROM ProPrefBonus");
    if (ret)
        ret = query.exec("DELETE FROM Inscription");
    if (ret)
        ret = query.exec("DELETE FROM Etranger");
    if (ret)
        ret = query.exec("DELETE FROM Semestre");
    if (ret)
        ret = query.exec("DELETE FROM Bonus");
    if (ret)
        ret = query.exec("DELETE FROM Branche");
    if (ret)
        ret = query.exec("DELETE FROM Desir");
    if (ret)
        ret = query.exec("DELETE FROM Simulation");
    if (ret)
        ret = query.exec("DELETE FROM SimulationInscr");
    if (ret)
        ret = query.exec("DELETE FROM Categorie");
    if (ret)
        ret = query.exec("DELETE FROM Cursus");
    if (ret)
        ret = query.exec("DELETE FROM Filiere");
    if (ret)
        ret = query.exec("DELETE FROM Note");
    if (ret)
        ret = query.exec("DELETE FROM UV");

    return ret;
}


// ===== LOAD ===========================================================

void DbManager::update()
{
    remove();
    save();
    load();
}


void DbManager::loadProfils()
{

        m_profils->clear();

        QSqlQuery query("SELECT * FROM Profil");
        QSqlQuery query2("SELECT * FROM ProfilInscr");
        QSqlQuery query3("SELECT * FROM ProfilEtr");
        QSqlQuery query4("SELECT * FROM ProPrefEtr");
        QSqlQuery query5("SELECT * FROM ProPrefDesirs");
        QSqlQuery query6("SELECT * FROM ProPrefBonus");

        while (query.next())
        {
            Profil* profil = new Profil;
            profil->setId(query.value(0).toInt());
            profil->setActuel(0);
            profil->setVise(0);

            if (query.value(1).toInt() != 0)
            {
                profil->setActuel(m_cursus->find(query.value(1).toInt()).value());
            }

            if (query.value(2).toInt() != 0)
            {
                profil->setVise(m_cursus->find(query.value(2).toInt()).value());
            }
            profil->setEtrangers(0);
            profil->setInscriptions(0);
            profil->setPrefEtrangers(0);
            profil->setDesirs(0);
            profil->setBonus(0);
            m_profils->insert(profil->getId(), profil);
        }

        Inscription* inscription = new Inscription;

        while (query2.next())
        {
            if (m_profils->find(query.value(1).toInt()).value()->getInscriptions() == 0)
            {
                QMap<unsigned int, Inscription*>* inscriptions = new QMap<unsigned int, Inscription*>;
                m_profils->find(query.value(1).toInt()).value()->setInscriptions(inscriptions);
            }

            inscription = m_inscriptions->find(query2.value(2).toInt()).value();
            m_profils->find(query.value(2).toInt()).value()->getInscriptions()->insert(inscription->getId(), inscription);
        }

        Etranger* etranger = new Etranger;

        while (query3.next())
        {
            if (m_profils->find(query.value(1).toInt()).value()->getEtrangers() == 0)
            {
                QMap<unsigned int, Etranger*>* etrangers = new QMap<unsigned int, Etranger*>;
                m_profils->find(query.value(1).toInt()).value()->setEtrangers(etrangers);
            }

            etranger = m_etrangers->find(query2.value(2).toInt()).value();
            m_profils->find(query.value(2).toInt()).value()->getEtrangers()->insert(etranger->getId(), etranger);
        }

        while (query4.next())
        {
            if (m_profils->find(query.value(1).toInt()).value()->getPrefEtrangers() == 0)
            {
                QMap<unsigned int, Etranger*>* etrangers = new QMap<unsigned int, Etranger*>;
                m_profils->find(query.value(1).toInt()).value()->setPrefEtrangers(etrangers);
            }

            etranger = m_prefEtrangers->find(query2.value(2).toInt()).value();
            m_profils->find(query.value(2).toInt()).value()->getPrefEtrangers()->insert(etranger->getId(), etranger);
        }

        DesirUV* desir = new DesirUV;

        while (query5.next())
        {
            if (m_profils->find(query.value(1).toInt()).value()->getDesirs() == 0)
            {
                QMap<unsigned int, DesirUV*>* desirs = new QMap<unsigned int, DesirUV*>;
                m_profils->find(query.value(1).toInt()).value()->setDesirs(desirs);
            }

            desir = m_desirs->find(query2.value(2).toInt()).value();
            m_profils->find(query.value(2).toInt()).value()->getDesirs()->insert(desir->getId(), desir);
        }

        BonusUV* bonus = new BonusUV;

        while (query6.next())
        {
            if (m_profils->find(query.value(1).toInt()).value()->getBonus() == 0)
            {
                QMap<unsigned int, BonusUV*>* bonuss = new QMap<unsigned int, BonusUV*>;
                m_profils->find(query.value(1).toInt()).value()->setBonus(bonuss);
            }

            bonus = m_bonus->find(query2.value(2).toInt()).value();
            m_profils->find(query.value(2).toInt()).value()->getBonus()->insert(bonus->getId(), bonus);
        }
}




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
        user->setSimulation(0);
        user->setProfil(0);
        if (query.value(3).toInt() != 0)
        {
            user->setSimulation(0);
            //Simulation* simulation = new Simulation;
        }
        if (query.value(4).toInt() != 0)
        {
            user->setProfil(m_profils->find(query.value(4).toInt()).value());
            m_test = "Dernier utilisateur loadé : "+ QString::number(user->getId());
        }
        m_users->insert(user->getId(), user);
    }
}

void DbManager::loadInscriptions()
{
    m_inscriptions->clear();

    QSqlQuery query("SELECT * FROM Inscription");

    while (query.next())
    {
        Inscription* inscription = new Inscription;
        inscription->setId(query.value(0).toInt());
        inscription->setUV(0);
        if (query.value(1).toInt() != 0)
        {
            inscription->setUV(m_uvs->find(query.value(1).toInt()).value());
        }
        inscription->setSemestre(0);
        if (query.value(2).toInt() != 0)
        {
            inscription->setSemestre(m_semestres->find(query.value(2).toInt()).value());
        }
        inscription->setNote(0);
        if (query.value(3).toInt() != 0)
        {
            inscription->setNote(m_notes->find(query.value(3).toInt()).value());
        }
        inscription->setCursus(0);
        if (query.value(4).toInt() != 0)
        {
            inscription->setCursus(m_cursus->find(query.value(4).toInt()).value());
        }
        inscription->setCategorie(0);
        if (query.value(5).toInt() != 0)
        {
            inscription->setCategorie(m_categories->find(query.value(5).toInt()).value());
        }
        m_inscriptions->insert(inscription->getId(), inscription);
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
    Categorie* categorie;

    QSqlQuery query("SELECT * FROM UV");

    while (query.next())
    {
        UV* uv = new UV;
        uv->setId(query.value(0).toInt());
        uv->setCode(query.value(1).toString());
        uv->setCredits(query.value(2).toInt());
        uv->setCategorie(0);
        if (query.value(3).toInt() != 0)
        {
            categorie = m_categories->find(query.value(3).toInt()).value();
            uv->setCategorie(categorie);
        }
        uv->setCursus(0);
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
    m_cursus->clear();
    QSqlQuery query("SELECT * FROM Cursus");

    while (query.next())
    {
        Cursus* cursus = new Cursus;
        cursus->setId(query.value(0).toInt());
        cursus->setBranche(0);
        cursus->setFiliere(0);
        if (query.value(1).toInt() != 0)
        {
            cursus->setBranche(m_branches->find(query.value(1).toInt()).value());
        }
        if (query.value(2).toInt() != 0)
        {
            cursus->setFiliere(m_filieres->find(query.value(2).toInt()).value());
        }
        m_cursus->insert(cursus->getId(), cursus);
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
            ret = query.exec("CREATE TABLE ProPrefEtr (id INTEGER PRIMARY KEY, idProfil INTEGER, idEtranger INTEGER)");
        if (ret == true)
            ret = query.exec("CREATE TABLE ProPrefDesirs (id INTEGER PRIMARY KEY, idProfil INTEGER, idDesir INTEGER)");
        if (ret == true)
            ret = query.exec("CREATE TABLE ProPrefBonus (id INTEGER PRIMARY KEY, idProfil INTEGER, idBonus INTEGER)");
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
    unsigned int idProfil = 0, idSimulation = 0;
    if (user->getProfil() != 0)
        idProfil = user->getProfil()->getId();
    if (user->getSimulation() != 0)
        idSimulation = user->getSimulation()->getId();
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into User values(NULL,'%1','%2','%3', '%4')").arg(user->getNom()).arg(user->getPrenom()).arg(idProfil).arg(idSimulation));
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
        unsigned int idCategorie = 0;
        if (uv->getCategorie() != 0)
            idCategorie = uv->getCategorie()->getId();
        ret = query.exec(QString("INSERT into UV values(NULL,'%1','%2','%3')").arg(uv->getCode()).arg(uv->getCredits()).arg(idCategorie));

        if (ret)
        {
            newId = query.lastInsertId().toInt();
            unsigned int idCursus = 0;

            if (uv->getCursus() != 0)
            {
                QSqlQuery query2;
                QMap<unsigned int, Cursus*>* map = uv->getCursus();
                QMap<unsigned int, Cursus*>::Iterator it;
                for (it = map->begin(); it != map->end(); ++it)
                {
                    idCursus = it.value()->getId();
                    ret = query2.exec(QString("INSERT into UVCursus values(NULL,'%1','%2')").arg(newId).arg(idCursus));
                }
            }
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
    unsigned int idUV = 0, idSemestre = 0, idNote = 0, idCursus = 0, idCategorie = 0;

    idUV = inscription->getUV()->getId();
    idSemestre = inscription->getSemestre()->getId();
    idNote = inscription->getNote()->getId();
    idCursus = inscription->getCursus()->getId();
    idCategorie = inscription->getCategorie()->getId();

    if (db.isOpen()) // A AJOUTER : Condition de test, pour le cas ou profil etc sont = 0 => faire en fonction par la suite.
    {
        QSqlQuery query;
        ret = query.exec(QString("INSERT into Inscription values(NULL,'%1','%2', '3', '4', '5')").arg(idUV).arg(idSemestre).arg(idNote).arg(idCursus).arg(idCategorie));
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
    unsigned int idInscription = 0, idEtranger = 0, idPrefEtranger = 0, idDesir = 0, idBonus = 0;
    if (db.isOpen())
    {
        QSqlQuery query;
        QSqlQuery query2;
        ret = query.exec(QString("INSERT into Profil values(NULL,'%1', '%2')").arg(profil->getActuel()->getId()).arg(profil->getVise()->getId()));

        if (ret)
        {
            newId = query.lastInsertId().toInt();
            if (profil->getInscriptions() != 0)
            {

                QSqlQuery query2;
                QMap<unsigned int, Inscription*>* map = profil->getInscriptions();
                QMap<unsigned int, Inscription*>::Iterator it;
                for ( it = map->begin(); it != map->end(); ++it)
                {
                    idInscription = it.value()->getId();
                    ret = query2.exec(QString("INSERT into ProfilInscr values(NULL,'%1','%2')").arg(newId).arg(idInscription));
                }
            }

            if (profil->getEtrangers() != 0)
            {
                QMap<unsigned int, Etranger*>* map2 = profil->getEtrangers();
                QMap<unsigned int, Etranger*>::Iterator it2;
                for ( it2 = map2->begin(); it2 != map2->end(); ++it2)
                {
                    idEtranger = it2.value()->getId();
                    ret = query2.exec(QString("INSERT into ProfilEtr values(NULL,'%1','%2')").arg(newId).arg(idEtranger));
                }
            }

            if (profil->getPrefEtrangers() != 0)
            {
                QMap<unsigned int, Etranger*>* map3 = profil->getPrefEtrangers();
                QMap<unsigned int, Etranger*>::Iterator it3;
                for (QMap<unsigned int, Etranger*>::Iterator it3 = map3->begin(); it3 != map3->end(); ++it3)
                {
                    idPrefEtranger = it3.value()->getId();
                    ret = query2.exec(QString("INSERT into ProPrefEtr values(NULL,'%1','%2')").arg(newId).arg(idPrefEtranger));
                }
            }

            if (profil->getDesirs() != 0)
            {
                QMap<unsigned int, DesirUV*>* map4 = profil->getDesirs();
                QMap<unsigned int, DesirUV*>::Iterator it4;
                for (it4 = map4->begin(); it4 != map4->end(); ++it4)
                {
                    idDesir = it4.value()->getId();
                    ret = query2.exec(QString("INSERT into ProPrefDesirs values(NULL,'%1','%2')").arg(newId).arg(idDesir));
                }
            }

            if (profil->getBonus() != 0)
            {
                QMap<unsigned int, BonusUV*>* map5 = profil->getBonus();
                QMap<unsigned int, BonusUV*>::Iterator it5;
                for (it5 = map5->begin(); it5 != map5->end(); ++it5)
                {
                    idBonus = it5.value()->getId();
                    ret = query2.exec(QString("INSERT into ProPrefBonus values(NULL,'%1','%2')").arg(newId).arg(idBonus));
                }
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
    uvList->setQuery("SELECT id, code, credits, categorie FROM UV");
    return uvList;
}

QSqlQueryModel* DbManager::getNoteList()
{
    QSqlQueryModel* noteList = new QSqlQueryModel;
    noteList->setQuery("SELECT * FROM Note");
    return noteList;
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

DbManager::~DbManager()
{
    remove();
    save();
}



