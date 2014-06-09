#include "simulation.h"

Simulation::Simulation(QObject *parent) :
    QObject(parent)
{
}

bool Simulation::setProfil(Profil* profil)
{
    m_profil = profil;
    return true;
}

bool Simulation::setInscriptions(QMap<unsigned int, Inscription*> inscr)
{
    m_inscriptions = inscr;
    return true;
}

bool Simulation::setCursus(Cursus *cursus)
{
    m_cursus = cursus;
    return true;
}

bool Simulation::addInscription(Inscription* inscription)
{
    m_inscriptions.insert(inscription->getId(), inscription);
    return true;
}
