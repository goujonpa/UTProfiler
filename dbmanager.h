#ifndef DBMANAGER_H
#define DBMANAGER_H

/*!
  * \file dbmanager.h
  * \brief Description du DbManager
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Descritpion du DataBaseManager
  */


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


/*!
 * \class DbManager
 * \brief The DbManager class
 * Classe qui permet la gestion avec la base de données
 */
class DbManager : public QObject
{
        Q_OBJECT

    protected:

        /*!
         * \brief m_user : pointeur vers User initilaisé à NULL
         */
        User* m_user = NULL;

        /*!
         * \brief m_users : pointeur vers conteneur de User
         */
        QMap<unsigned int, User*>* m_users;

        /*!
         * \brief m_uvs : pointeur vers conteneur d'UVs
         */
        QMap<unsigned int, UV*>* m_uvs;

        /*!
         * \brief m_branches pointeur vers conteneur de Branche
         */
        QMap<unsigned int, Branche*>* m_branches;

        /*!
         * \brief m_semestres : pointeur vers conteneur de Semestre
         */
        QMap<unsigned int, Semestre*>* m_semestres;

        /*!
         * \brief m_filieres : pointeur vers conteneur de Filière
         */
        QMap<unsigned int, Filiere*>* m_filieres;

        /*!
         * \brief m_categories : pointeur vers conteneur de Categorie
         */
        QMap<unsigned int, Categorie*>* m_categories;

        /*!
         * \brief m_cursus : pointeur vers conteneur de Cursus
         */
        QMap<unsigned int, Cursus*>* m_cursus;

        /*!
         * \brief m_notes : pointeur vers conteneur de Note
         */
        QMap<unsigned int, Note*>* m_notes;

        /*!
         * \brief m_inscriptions : pointeur vers conteneur d'Inscription
         */
        QMap<unsigned int, Inscription*>* m_inscriptions;

        /*!
         * \brief m_etrangers : pointeur vers conteneur de semestre à l'étranger
         */
        QMap<unsigned int, Etranger*>* m_etrangers;

        /*!
         * \brief m_prefEtrangers : pointeur vers conteneur de souhait de semestre à l'étranger
         */
        QMap<unsigned int, Etranger*>* m_prefEtrangers;

        /*!
         * \brief m_profils : pointeur vers conteneur de Profil
         */
        QMap<unsigned int, Profil*>* m_profils;

        /*!
         * \brief m_desirs : pointeur vers conteneur de DesirUV
         */
        QMap<unsigned int, DesirUV*>* m_desirs;

        /*!
         * \brief m_bonus : pointeur vers conteneur de BonusUV
         */
        QMap<unsigned int, BonusUV*>* m_bonus;

        /*!
         * \brief m_simulations : pointeur vers conteneur de Simulation
         */
        QMap<unsigned int, Simulation*>* m_simulations;

        QString m_test;

        /*!
         * \Relation d'amitié entre la classe DbManager et MainWindow
         */
        friend class MainWindow;

        /*!
         *\Relation d'amitié entre la classe XmlManager et MainWindow
         */
        friend class XmlManager;

    public:

        /*!
          *\brief Initialisation de la base de données
          */
        // ===== Init db =====

        /*!
         * \brief méthode openDb
         * Ouvre un BDD
         * \return
         */
        bool openDb();

        /*!
         * \brief méthode deleteDb
         * Efface une BDD
         * \return
         */
        bool deleteDb();

        /*!
         * \brief méthode createTables
         * Créer une table
         * \return
         */
        bool createTables();

        /*!
         * \brief méthode lastError
         * Renvoie la dernière erreur
         * \return
         */
        QSqlError lastError();

        /*!
         * \brief Constructeur par défaut de DbManager
         * \param parent : pointeur vers l'objet parent, ici initilisé à nul
         */
        explicit DbManager(QObject *parent = 0);

        /*!
          * \brief Destructeur de DbManager
          */
        ~DbManager();

        /*!
         * \brief méthode getDbCat
         * Retourne un pointeur de conteneur de catégories
         * \return pointeur vers conteneur de catégories
         */
        QMap<unsigned int, Categorie*>* getDbCat() const {return m_categories;}
        QMap<unsigned int, Branche*>* getDbBranches() const {return m_branches;}
        Filiere* getSansFiliere() const {return m_filieres->find(0).value();}
        QMap<unsigned int, Cursus*>* getDbCursus() const {return m_cursus;}


        /*!
          * \brief Création des tables
          */
        // ===== create tables =====

        /*!
         * \brief méthode createUVTable
         * Création de la table d'UV
         * \return
         */
        bool createUVTable();
        /*!
         * \brief méthode createUserTable
         * Création de la table d'utilisateur
         * \return
         */
        bool createUserTable();
        /*!
         * \brief méthode createProfilTable
         * Création de la table des profils
         * \return
         */
        bool createProfilTable();
        /*!
         * \brief méthode createInscriptionTable
         * Création de la table des inscriptions
         * \return
         */
        bool createInscriptionTable();
        /*!
         * \brief méthode createEtrangerTable
         * Création de la table des semestres à l'étranger
         * \return
         */
        bool createEtrangerTable();
        /*!
         * \brief méthode createSemestreTable
         * Création de la table des semestres
         * \return
         */
        bool createSemestreTable();
        /*!
         * \brief méthode createBonusTable
         * Création de la table des UV Bonus
         * \return
         */
        bool createBonusTable();
        /*!
         * \brief méthode createBrancheTable
         * \return
         */
        bool createBrancheTable();
        /*!
         * \brief méthode createDesirTable
         * Création de la table des UV désirées
         * \return
         */
        bool createDesirTable();
        /*!
         * \brief méthode createSimulationTable
         * Création de la table des simulations
         * \return
         */
        bool createSimulationTable();
        /*!
         * \brief méthode createCategorieTable
         * Création de la table Catégorie
         * \return
         */
        bool createCategorieTable();
        /*!
         * \brief méthode createCursusTable
         * Création de la table Cursus
         * \return
         */
        bool createCursusTable();
        /*!
         * \brief méthode createFiliereTable
         * Création de la table des filières
         * \return
         */
        bool createFiliereTable();
        /*!
         * \brief méthode createNoteTable
         * Création de la table des notes
         * \return
         */
        bool createNoteTable();
        /*!
         * \brief méthode createPreferenceTable
         * Création de la table des préférences
         * \return
         */
        bool createPreferenceTable();

        /*!
          *\brief Insertion des attributs
          */
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

        /*!
          * \brief Chargement des objets
          */
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
        void loadBonus();
        void loadDesirs();
        void loadEtrangers();


        /*!
          * \brief Mise à jour
          */
        // ===== Update =====

        void update();

        /*!
          * \brief destructeurs
          */

        // ===== destructeur =====

        void save();
        bool remove();
        bool removeUVs();

        /*!
          * \brief Récupère les listes des différents objet
          */
        // ===== getLists =====

        QSqlQueryModel* getUserList();
        QSqlQueryModel* getBranchList();
        QSqlQueryModel* getCatList();
        QSqlQueryModel* getFiliereList();
        QSqlQueryModel* getUVList();
        QSqlQueryModel* getNoteList();


    private:
        /*!
         * \brief db : BBD en SQLite
         */
        QSqlDatabase db;

    signals:


    public slots:

};





#endif // DBMANAGER_H
