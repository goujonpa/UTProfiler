/*!
 * \file similation.cpp
 * \brief Méthodes de la classe Simulation
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe Simulation
 *
 */

#include "simulation.h"

/*!
 * \brief constructeur par défaut de Simulation::Simulation
 * \param parent : pointeur vers l'objet parent
 */
Simulation::Simulation(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode Simulation::setProfil
 * \param profil : pointeur vers le profil qui demande une simulation
 * \return true si l'ajout s'est correctement réalisé
 */
bool Simulation::setProfil(Profil* profil)
{
    m_profil = profil;
    return true;
}


/*!
 * \brief méthode Simulation::setInscriptions
 * \param inscr : conteneur d'inscription
 * \return true si l'ajout s'est correctement réalisé
 */
bool Simulation::setInscriptions(QMap<unsigned int, Inscription*>* inscriptions)
{
    m_inscriptions = inscriptions;
    return true;
}

/*!
 * \brief méthode Simulation::setCursus
 * \param cursus : pointeur vers le cursus
 * \return true si l'ajout s'est correctement réalisé
 */
bool Simulation::setCursus(Cursus *cursus)
{
    m_cursus = cursus;
    return true;
}

/*!
 * \brief méthode Simulation::addInscription
 * \param inscription : pointeur vers Inscription
 * \return true si l'ajout s'est correctement réalisé
 */
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
