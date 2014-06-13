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

        User* m_user = NULL;
        QMap<unsigned int, User*>* m_users;
        QMap<unsigned int, UV*>* m_uvs;
        QMap<unsigned int, Branche*>* m_branches;
        QMap<unsigned int, Semestre*>* m_semestres;
        QMap<unsigned int, Filiere*>* m_filieres;
        QMap<unsigned int, Categorie*>* m_categories;
        QMap<unsigned int, Cursus*>* m_cursus;
        QMap<unsigned int, Note*>* m_notes;
        QMap<unsigned int, Inscription*>* m_inscriptions;
        QMap<unsigned int, Etranger*>* m_etrangers;
        QMap<unsigned int, Etranger*>* m_prefEtrangers;
        QMap<unsigned int, Profil*>* m_profils;
        QMap<unsigned int, DesirUV*>* m_desirs;
        QMap<unsigned int, BonusUV*>* m_bonus;
        QMap<unsigned int, Simulation*>* m_simulations;

        QString m_test;

        friend class MainWindow;
        friend class XmlManager;

    public:

        // ===== Init db =====

        bool openDb();
        bool deleteDb();
        bool createTables();
        QSqlError lastError();

        explicit DbManager(QObject *parent = 0);
        ~DbManager();
        QMap<unsigned int, Categorie*>* getDbCat() const {return m_categories;}


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
        void loadProfils();
        void loadInscriptions();
        void update();

        // ===== destructeur =====

        void save();
        bool remove();

        // ===== getLists =====

        QSqlQueryModel* getUserList();
        QSqlQueryModel* getBranchList();
        QSqlQueryModel* getCatList();
        QSqlQueryModel* getFiliereList();
        QSqlQueryModel* getUVList();
        QSqlQueryModel* getNoteList();


    private:
        QSqlDatabase db;

    signals:


    public slots:
};





#endif // DBMANAGER_H
