#include "uv.h"

UV::UV(QObject *parent) :
    QObject(parent)
{
}

bool UV::setCode(QString code)
{
    m_code = code;
    return true;
}

bool UV::setCredits(unsigned int credits)
{
    m_credits = credits;
    return true;
}

bool UV::setCategorie(Categorie* categorie)
{
    m_categorie = categorie;
    return true;
}

bool UV::setCursus(QMap<unsigned int, Cursus*>* cursus)
{
    m_cursus = cursus;
    return true;
}

bool UV::addCursus(Cursus* cursus)
{
    if (this->getCursus() == 0)
        m_cursus = new QMap<unsigned int, Cursus*>;
    m_cursus->insert(cursus->getId(), cursus);
    return true;
}

bool UV::setId(unsigned int id)
{
    m_id = id;
    return true;
}

Categorie* UV::getCategorie() const
{
    if (m_categorie == NULL || m_categorie == 0)
        return 0;
    return m_categorie;
}

QMap<unsigned int, Cursus*>* UV::getCursus() const
{
    if (m_cursus == NULL || m_cursus == 0)
        return 0;
    return m_cursus;
}
