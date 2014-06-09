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
    public:
        explicit DbManager(QObject *parent = 0);

    public:
        bool openDB();
        bool deleteDB();
        bool createTables();

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


        User* getItem(User*, int id);
        Simulation* getItem(Simulation*, unsigned int id);
        Profil* getItem(Profil*, unsigned int id);

        QSqlQueryModel* getUserList();

        bool deleteItem(int id);

        QSqlError lastError();

    private:
        QSqlDatabase db;

    signals:

    public slots:
};





#endif // DBMANAGER_H
