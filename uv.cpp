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

bool UV::setCategorie(Categorie* cat)
{
    m_categorie = cat;
    return true;
}

bool UV::setCursus(QVector<Cursus*> cursus)
{
    m_cursus = cursus;
    return true;
}

bool UV::addCursus(Cursus* cursus)
{
    m_cursus.push_back(cursus);
    return true;
}
