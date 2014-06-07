#include "user.h"

User::User(QObject *parent) :
    QObject(parent)
{
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

bool User::setPreference(Preference* pref)
{
    m_preference = pref;
    return true;
}

