#include "profil.h"

Profil::Profil(QObject *parent) :
    QObject(parent)
{
}


bool Profil::setInscriptions(QVector<Inscription*> insc)
{
    m_inscriptions = insc;
    return true;
}

bool Profil::addInscription(Inscription* insc)
{
    m_inscriptions.push_back(insc);
    return true;
}

bool setActuel(Cursus* actuel)
{

}

bool setVise(Cursus* vise)
{

}

bool setEtranger(QVector<Etranger*> etr);
{

}

bool addEtranger(Etranger* etr)
{

}
