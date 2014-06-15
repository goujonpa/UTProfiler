#include "xmlmanager.h"

XmlManager::XmlManager(QObject *parent) :
    QObject(parent)
{
}




void XmlManager::load(QString filename, DbManager* db)
{
    QFile* file = new QFile(filename);
    QXmlStreamReader reader;
    QString code;
    QString nom;
    QString input;
    int credits, idUV, i = 0, idCursus;
    Categorie* newCategorie;
    QMap<unsigned int, Categorie*>* dbCat = db->getDbCat();
    QString categorie;
    QString branche;
    QVector<QString> branches;
    QMap<unsigned int, Categorie*>::Iterator it;
    QVector<QString>::Iterator it2;
    QMap<unsigned int, Branche*>::Iterator it3;
    QMap<unsigned int, Cursus*>::Iterator it4;


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


            QMap<unsigned int, Cursus*>* newCursus = new QMap<unsigned int, Cursus*>;
            for (it2 = branches.begin(); it2 != branches.end(); ++it2)
            {
                Branche* newBranche = new Branche;
                for (it3 = db->getDbBranches()->begin(); it3 != db->getDbBranches()->end(); ++it3)
                {
                    if (it3.value()->getCode() == it2->data()->decomposition())
                    {
                        newBranche = it3.value();
                    }
                }
                Cursus* cursus = new Cursus(0, newBranche, db->getSansFiliere());
                for (it4 = db->getDbCursus()->begin(); it4 != db->getDbCursus()->end(); ++it4)
                {
                    if (cursus->getBranche() == it4.value()->getBranche() && cursus->getFiliere() == it4.value()->getFiliere())
                    {
                        cursus = it4.value();
                    }

                    if (cursus->getId() == 0)
                    {
                        idCursus = db->insertItem(cursus);
                        cursus->setId(idCursus);
                    }
                }
                newCursus->insert(cursus->getId(), cursus);


            }


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
            newUV->setCursus(newCursus);
            idUV = db->insertItem(newUV);
            newUV->setId(idUV);
            i++;
            emit avancement(i);
        }

        reader.readNext();

    }

    //m_test = mess;//code + nom + input + categorie + branche;
}
