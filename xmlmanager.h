#ifndef XMLMANAGER_H
#define XMLMANAGER_H

/*!
  * \file xmlmanager.h
  * \brief Definition de la classe XmlManager
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Permet de passer d'un fichier XML à la BDD
  */

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


/*!
 * \brief The XmlManager class
 */
class XmlManager : public QObject
{
        Q_OBJECT

    public:
    /*!
         * \brief XmlManager
         * \param parent
         */
        explicit XmlManager(QObject *parent = 0);

    /*!
         * \brief getUV
         * \return
         */
        QVector<UV*>* getUV() const {return m_uvs;}
        /*!
         * \brief getTest
         * \return
         */
        QString getTest() const {return m_test;}
        /*!
         * \brief load
         * \param filename
         * \param db
         */
        void load(QString filename, DbManager* db);


    protected:
        /*!
         * \brief m_uvs
         */
        QVector<UV*>* m_uvs;
        /*!
           * \brief m_test
           */
        QString m_test;

    signals:

        void avancement(int);

    public slots:

};

#endif // XMLMANAGER_H
