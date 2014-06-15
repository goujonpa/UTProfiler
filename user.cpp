/*!
 * \file user.cpp
 * \brief Méthodes de la classe User
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe User
 *
 */

#include "user.h"

/*!
 * \brief constructeur par défaut User::User
 * \param parent : pointeur vers l'objet parent
 */
User::User(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode User::setId
 * \param id : identificateur de l'utilisateur
 * \return true si l'ajout s'est correctement réalisé
 */
bool User::setId(unsigned int id)
{
    m_id = id;
    return true;
}

/*!
 * \brief méthode User::setNom
 * \param nom : nom de l'utilisateur
 * \return true si l'ajout s'est correctement réalisé
 */
bool User::setNom(QString nom)
{
    m_nom = nom;
    return true;
}

/*!
 * \brief méthode User::setPrenom
 * \param prenom : prenom de l'utilisateur
 * \return true si l'ajout s'est correctement réalisé
 */
bool User::setPrenom(QString prenom)
{
    m_prenom = prenom;
    return true;
}

/*!
 * \brief méthode User::setSimulation
 * \param simulation : pointeur vers une simulation
 * \return true si l'ajout s'est correctement réalisé
 */
bool User::setSimulation(Simulation* simulation)
{
    m_simulation = simulation;
    return true;
}

/*!
 * \brief méthode User::setProfil
 * \param profil : pointeur vers le profil de l'utilisateur
 * \return true si l'ajout s'est correctement réalisé
 */
bool User::setProfil(Profil* profil)
{
    m_profil = profil;
    return true;
}

/*!
 * \brief méthode User::getProfil
 * \return le pointeur vers le profil de l'utilisateur
 */
Profil* User::getProfil() const
{
    if (m_profil == NULL || m_profil == 0)
        return 0;
    return m_profil;
}

/*!
 * \brief méthode User::getSimulation
 * \return pointeur vers la simulation de l'utilisateur
 */
Simulation* User::getSimulation() const
{
    if (m_simulation == NULL || m_profil == 0)
        return 0;
    return m_simulation;
}
