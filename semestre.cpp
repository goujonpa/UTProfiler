#include "semestre.h"

Semestre::Semestre(QObject *parent) :
    QObject(parent)
{
}

bool setSaison(Saison saison)
{
    m_saison = saison;
    return true;
}

bool setAnnee(unsigned int annee)
{
    m_annee = annee;
    return true;
}
