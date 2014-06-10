#include "cursus.h"

Cursus::Cursus(QObject *parent) :
    QObject(parent)
{
}


bool Cursus::setBranche(Branche* branche)
{
    m_branche = branche;
    return true;
}

bool Cursus::setFiliere(Filiere* filiere)
{
    m_filiere = filiere;
    return true;
}

bool Cursus::setId(unsigned int id)
{
    m_id = id;
    return true;
}
