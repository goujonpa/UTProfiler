#include "xmlmanager.h"

XmlManager::XmlManager(QObject *parent) :
    QObject(parent)
{
}




void XmlManager::load(QString filename, UV* uv, DbManager* db)
{
    QFile* file = new QFile(filename);
    QXmlStreamReader reader;
    QString code;
    QString nom;
    QString input;
    int credits, idCategorie, idUV, i = 0;
    QString categorie;
    QString branche;
    QVector<QString> branches;
    QString mess;
    QString message;

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


            QMap<unsigned int, Cursus*> newCursus;
            //Categorie* newCategorie = new Categorie(0, categorie, "");
            //idCategorie = db->find(newCategorie); // bug
            //newCategorie->setId(idCategorie);

            UV* newUV = new UV;//(0, code, credits, 0, newCursus);
            newUV->setCode(code);
            newUV->setCredits(credits);
            newUV->setCategorie(0);
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
