/*!
 * \file categorie.cpp
 * \brief Méthodes de la classe Categorie
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe Categorie
 *
 */

#include "categorie.h"

/*!
 * \brief Constructeur par défaut Categorie::Categorie
 * \param parent : pointeur vers l'objet parents
 */
Categorie::Categorie(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode Categorie::setCode
 * \param code : code de la catégorie
 * \return true si l'ajout s'est correctement réalisé
 */
bool Categorie::setCode(QString code)
{
    m_code = code;
    return true;
}

/*!
 * \brief méthode Categorie::setNom
 * \param nom : nom de la catégorie
 * \return true si l'ajout s'est correctement réalisé
 */
bool Categorie::setNom(QString nom)
{
    m_nom = nom;
    return true;
}

/*!
 * \brief méthode Categorie::setId
 * \param id : identificateur de la catégorie
 * \return true si l'ajout s'est correctement réalisé
 */
bool Categorie::setId(unsigned int id)
{
    m_id = id;
    return true;
}
