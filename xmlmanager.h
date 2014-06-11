#ifndef XMLMANAGER_H
#define XMLMANAGER_H

#include <QObject>
#include <QtXml>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QFile>
#include <QVector>
#include <QMap>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QXmlStreamAttributes>
#include "uv.h"
#include "dbmanager.h"


class XmlManager : public QObject
{
        Q_OBJECT

    public:

        explicit XmlManager(QObject *parent = 0);

        QVector<UV*>* getUV() const {return m_uvs;}
        QString getTest() const {return m_test;}

        void load(QString filename, UV* uv, DbManager* db);


    protected:

        //QDomDocument* dom;
        //QFile* file;
        QVector<UV*>* m_uvs;
        QString m_test;
        //Manager(const QString& f="");
        //virtual ~Manager();

    signals:

        void avancement(int);

    public slots:

};

#endif // XMLMANAGER_H
