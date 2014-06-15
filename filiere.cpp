/*!
 * \file filiere.cpp
 * \brief Méthodes de la classe Filiere
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe Filiere
 *
 */

#include "filiere.h"

/*!
 * \brief constructeur par défaut Filiere::Filiere
 * \param parent : pointeur vers l'objet parent
 */
Filiere::Filiere(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode Filiere::setCode
 * \param code : code de l'UV
 * \return true l'ajout s'est correctement déroulé
 */
bool Filiere::setCode(QString code)
{
    m_code = code;
    return true;
}

/*!
 * \brief méthode Filiere::setNom
 * \param nom : nom de l'UV
 * \return true si l'ajout s'est correctement déroulé
 */
bool Filiere::setNom(QString nom)
{
    m_nom = nom;
    return true;
}

/*!
 * \brief méthode Filiere::setId
 * \param id : identificateur de l'UV
 * \return true si l'ajout s'est correctement déroulé
 */
bool Filiere::setId(unsigned int id)
{
    m_id = id;
    return true;
}
