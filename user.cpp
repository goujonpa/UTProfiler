#include "user.h"

User::User(QObject *parent) :
    QObject(parent)
{
}

bool User::setId(unsigned int id)
{
    m_id = id;
    return true;
}

bool User::setNom(QString nom)
{
    m_nom = nom;
    return true;
}

bool User::setPrenom(QString prenom)
{
    m_prenom = prenom;
    return true;
}

bool User::setSimulation(Simulation* simulation)
{
    m_simulation = simulation;
    return true;
}

bool User::setProfil(Profil* profil)
{
    m_profil = profil;
    return true;
}

Profil* User::getProfil() const
{
    if (m_profil == NULL)
        return NULL;
    if (m_profil == 0)
        return NULL;
    return m_profil;
}


