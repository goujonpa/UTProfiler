/*!
 * \file cursus.cpp
 * \brief Méthodes de la classe Cursus
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe Categorie
 *
 */

#include "cursus.h"

/*!
 * \brief Constructeur par défaut Cursus::Cursus
 * \param parent : pointeur vers l'objet parent
 */
Cursus::Cursus(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode Cursus::setBranche
 * \param branche : pointeur vers la branche correspondante au cursus
 * \return true si l'ajout s'est correctement déroulé
 */
bool Cursus::setBranche(Branche* branche)
{
    m_branche = branche;
    return true;
}

/*!
 * \brief méthode Cursus::setFiliere
 * \param filiere : pointeur vers la filière correspondante au cursus
 * \return true si l'ajout s'est correctement déroulé
 */
bool Cursus::setFiliere(Filiere* filiere)
{
    m_filiere = filiere;
    return true;
}

/*!
 * \brief méthode Cursus::setId
 * \param id : indentificateur du cursus
 * \return true si l'ajout s'est correctement déroulé
 */
bool Cursus::setId(unsigned int id)
{
    m_id = id;
    return true;
}
