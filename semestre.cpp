#include "semestre.h"

Semestre::Semestre(QObject *parent) :
    QObject(parent)
{
}

bool Semestre::setSaison(Saison saison)
{
    m_saison = saison;
    return true;
}

bool Semestre::setAnnee(unsigned int annee)
{
    m_annee = annee;
    return true;
}

bool Semestre::setId(unsigned int id)
{
    m_id = id;
    return true;
}
