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
#include <QSqlQueryModel>
#include <QMap>
#include "user.h"
#include "uv.h"



class DbManager : public QObject
{
        Q_OBJECT

    protected:

        User* m_user;
        QMap<unsigned int, User*>* m_users;
        QMap<unsigned int, UV*>* m_uvs;
        QMap<unsigned int, Branche*>* m_branches;
        QMap<unsigned int, Semestre*>* m_semestres;
        QMap<unsigned int, Filiere*>* m_filieres;
        QMap<unsigned int, Categorie*>* m_categories;
        QMap<unsigned int, Cursus*>* m_cursuss;
        QMap<unsigned int, Note*>* m_notes;
        QMap<unsigned int, Inscription*>* m_inscriptions;
        QMap<unsigned int, Inscription*>* m_userInscriptions;
        QString m_test;

        friend class MainWindow;

    public:

        // ===== Init db =====

        bool openDb();
        bool deleteDb();
        bool createTables();
        explicit DbManager(QObject *parent = 0);


        // ===== create tables =====

        bool createUVTable();
        bool createUserTable();
        bool createProfilTable();
        bool createInscriptionTable();
        bool createEtrangerTable();
        bool createSemestreTable();
        bool createBonusTable();
        bool createBrancheTable();
        bool createDesirTable();
        bool createSimulationTable();
        bool createCategorieTable();
        bool createCursusTable();
        bool createFiliereTable();
        bool createNoteTable();
        bool createPreferenceTable();

        // ===== Insert items =====

        int insertItem(User* user);
        int insertItem(UV* uv);
        int insertItem(Cursus* cursus);
        int insertItem(Branche* branche);
        int insertItem(Filiere* filiere);
        int insertItem(BonusUV* bonus);
        int insertItem(Categorie* categorie);
        int insertItem(DesirUV* desir);
        int insertItem(Etranger* etranger);
        int insertItem(Inscription* inscription);
        int insertItem(Note* note);
        int insertItem(Profil* profil);
        int insertItem(Semestre* semestre);
        int insertItem(Simulation* simulation);

        // ===== Load =====

        void load();
        void loadUvs();
        void loadBranches();
        void loadSemestres();
        void loadFilieres();
        void loadCategories();
        void loadCursus();
        void loadNotes();
        void loadUsers();

        // ===== Divers =====

        int find(Branche* branche);
        int find(Categorie* categorie);

        User* getItem(User* user, int id);
        Simulation* getItem(Simulation* simulation, unsigned int id);
        Profil* getItem(Profil* profil, unsigned int id);
        Filiere* getItem(Filiere* filiere, unsigned int id);
        Branche* getItem(Branche* branche, unsigned int id);
        UV* getItem(UV* uv, int id);

        // ===== getLists =====

        QSqlQueryModel* getUserList();
        QSqlQueryModel* getBranchList();
        QSqlQueryModel* getCatList();
        QSqlQueryModel* getFiliereList();
        QSqlQueryModel* getUVList();
        QSqlQueryModel* getNoteList();

        bool deleteItem(int id);

        QSqlError lastError();

    private:
        QSqlDatabase db;

    signals:

    public slots:
};





#endif // DBMANAGER_H
