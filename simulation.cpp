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

bool Simulation::setInscriptions(QMap<unsigned int, Inscription*>* inscriptions)
{
    m_inscriptions = inscriptions;
    return true;
}

bool Simulation::setCursus(Cursus *cursus)
{
    m_cursus = cursus;
    return true;
}

bool Simulation::addInscription(Inscription* inscription)
{
    m_inscriptions->insert(inscription->getId(), inscription);
    return true;
}

QMap<unsigned int, Inscription*>* Simulation::getInscriptions() const
{
    if (m_inscriptions == NULL || m_inscriptions == 0)
        return 0;
    return m_inscriptions;
}
