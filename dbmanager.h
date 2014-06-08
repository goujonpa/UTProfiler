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
#include "user.h"


class DbManager : public QObject
{
        Q_OBJECT
    public:
        explicit DbManager(QObject *parent = 0);

    public:
        bool openDB();
        bool deleteDB();

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

        int insertUV(QString code, unsigned int credits, unsigned int categorie);
        QString getUV(int id);

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
