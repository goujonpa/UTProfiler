#include "profil.h"

Profil::Profil(QObject *parent) :
    QObject(parent)
{
}


bool Profil::setInscriptions(QMap<unsigned int, Inscription*> insc)
{
    m_inscriptions = insc;
    return true;
}

bool Profil::addInscription(Inscription* insc)
{
    m_inscriptions.insert(insc->getId(), insc);
    return true;
}

bool Profil::setActuel(Cursus* actuel)
{
    m_actuel = actuel;
    return true;
}

bool Profil::setVise(Cursus* vise)
{
    m_vise = vise;
    return true;
}

bool Profil::setEtranger(QMap<unsigned int, Etranger*> etr)
{
    m_etranger = etr;
    return true;
}

bool Profil::addEtranger(Etranger* etr)
{
    m_etranger.insert(etr->getId(), etr);
    return true;
}
