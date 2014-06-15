/*!
 * \file xmlmanager.cpp
 * \brief Méthodes de la classe XmlManager
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la XmlManager
 *
 */

#include "xmlmanager.h"

/*!
 * \brief XmlManager::XmlManager
 * \param parent
 */
XmlManager::XmlManager(QObject *parent) :
    QObject(parent)
{
}



/*!
 * \brief méthode XmlManager::load
 * Permet de compléter une BDD à partir d'un XML
 * \param filename : fichier XML source
 * \param db : pointeur vers la BDD
 */
void XmlManager::load(QString filename, DbManager* db)
{
    QFile* file = new QFile(filename);
    QXmlStreamReader reader;
    QString code;
    QString nom;
    QString input;
    int credits, idUV, i = 0;
    Categorie* newCategorie;
    QMap<unsigned int, Categorie*>* dbCat = db->getDbCat();
    QString categorie;
    QString branche;
    QVector<QString> branches;
    QMap<unsigned int, Categorie*>::Iterator it;

    if (!file->open(QFile::ReadOnly | QFile::Text))
        m_test = "NOK";

    reader.setDevice(file);

    while(!reader.atEnd() && !reader.hasError())
    {
        if (reader.isStartElement() && (reader.name() == "uv"))
        {
            do
            {
                reader.readNext();
                if (reader.isStartElement() && (reader.name() == "code"))
                {
                    code = reader.readElementText();
                }
                if (reader.isStartElement() && (reader.name() == "nom"))
                {
                    nom = reader.readElementText();
                }
                if (reader.isStartElement() && (reader.name() == "credit"))
                {
                    categorie = reader.attributes().value("type").toString();
                    input = reader.readElementText();
                    credits = input.toInt();
                }
                if (reader.isStartElement() && (reader.name() == "branche"))
                {
                    branche = reader.readElementText();
                    branches.push_back(branche);
                }
            } while(!(reader.isEndElement() && (reader.name() == "uv")));


            //QMap<unsigned int, Cursus*>* newCursus;
            //Categorie* newCategorie = new Categorie(0, categorie, "");
            //idCategorie = db->find(newCategorie); // bug
            //newCategorie->setId(idCategorie);

            for (it = dbCat->begin(); it != dbCat->end(); ++it)
            {
                if (it.value()->getCode() == categorie)
                {
                    newCategorie = it.value();
                }
            }


            UV* newUV = new UV;
            newUV->setCode(code);
            newUV->setCredits(credits);
            newUV->setCategorie(newCategorie);
            newUV->setCursus(0);
            idUV = db->insertItem(newUV);
            newUV->setId(idUV);
            i++;
            emit avancement(i);
        }

        reader.readNext();

    }

    //m_test = mess;//code + nom + input + categorie + branche;
}
