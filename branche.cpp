/*!
 * \file branche.cpp
 * \brief Méthodes de la classe Branche
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe Branche
 *
 */

#include "branche.h"

/*!
 * \brief Constructeur par défaut Branche::Branche
 * \param parent : pointeur vers l'objet parent
 */
Branche::Branche(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode Branche::setCode
 * \param code : code de la branche
 * \return true si l'ajout s'est correctement déroulé
 */
bool Branche::setCode(QString code)
{
    m_code = code;
    return true;
}

/*!
 * \brief méthode Branche::setNom
 * \param nom : nom détaillé de la branche
 * \return true si l'ajout s'est correctement déroulé
 */
bool Branche::setNom(QString nom)
{
    m_nom = nom;
    return true;
}

/*!
 * \brief méthode Branche::setId
 * \param id : identificateur de la branche
 * \return true si l'ajout s'est correctement déroulé
 */
bool Branche::setId(unsigned int id)
{
    m_id = id;
    return true;
}

