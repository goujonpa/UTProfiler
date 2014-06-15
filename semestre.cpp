/*!
 * \file semestre.cpp
 * \brief Méthodes de la classe Semestre
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe Semestre
 *
 */

#include "semestre.h"

/*!
 * \brief constructeur par défaut Semestre::Semestre
 * \param parent : pointeur vers l'objet parent
 */
Semestre::Semestre(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode Semestre::setSaison
 * \param saison : enum de saison
 * \return true si l'ajout s'est correctement réalisé
 */
bool Semestre::setSaison(Saison saison)
{
    m_saison = saison;
    return true;
}

/*!
 * \brief méthode Semestre::setAnnee
 * \param annee : année du semestre renseigné
 * \return true si l'ajout s'est correctement réalisé
 */
bool Semestre::setAnnee(unsigned int annee)
{
    m_annee = annee;
    return true;
}

/*!
 * \brief méthode Semestre::setId
 * \param id : identificateur du semestre
 * \return true si l'ajout s'est correctement réalisé
 */
bool Semestre::setId(unsigned int id)
{
    m_id = id;
    return true;
}
