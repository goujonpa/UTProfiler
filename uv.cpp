/*!
 * \file uv.cpp
 * \brief Méthodes de la classe UV
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe UV
 *
 */

#include "uv.h"

/*!
 * \brief constructeur par défaut UV::UV
 * \param parent : pointeur vers l'objet parent
 */
UV::UV(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode UV::setCode
 * \param code : code de l'UV
 * \return true si l'ajout s'est correctement réalisé
 */
bool UV::setCode(QString code)
{
    m_code = code;
    return true;
}

/*!
 * \brief méthode UV::setCredits
 * \param credits : nombre de crédit associés à l'UV
 * \return true si l'ajout s'est correctement réalisé
 */
bool UV::setCredits(unsigned int credits)
{
    m_credits = credits;
    return true;
}

/*!
 * \brief méthode UV::setCategorie
 * \param categorie : pointeur vers la catégoire associé à l'UV
 * \return true si l'ajout s'est correctement réalisé
 */
bool UV::setCategorie(Categorie* categorie)
{
    m_categorie = categorie;
    return true;
}

/*!
 * \brief méthode UV::setCursus
 * \param cursus : pointeur vers le conteneur des cursus associés à l'UV
 * \return true si l'ajout s'est correctement réalisé
 */
bool UV::setCursus(QMap<unsigned int, Cursus*>* cursus)
{
    m_cursus = cursus;
    return true;
}

/*!
 * \brief méthode UV::addCursus
 * \param cursus : pointeur vers le cursus à ajouter
 * \return true si l'ajout s'est correctement réalisé
 */
bool UV::addCursus(Cursus* cursus)
{
    if (this->getCursus() == 0)
        m_cursus = new QMap<unsigned int, Cursus*>;
    m_cursus->insert(cursus->getId(), cursus);
    return true;
}

/*!
 * \brief méthode UV::setId
 * \param id : identificateur de l'UV
 * \return true si l'ajout s'est correctement réalisé
 */
bool UV::setId(unsigned int id)
{
    m_id = id;
    return true;
}

/*!
 * \brief méthode UV::getCategorie
 * \return un pointeur vers la catégorie de l'UV
 */
Categorie* UV::getCategorie() const
{
    if (m_categorie == NULL || m_categorie == 0)
        return 0;
    return m_categorie;
}

/*!
 * \brief méthode UV::getCursus
 * \return un pointeur vers le conteneur des cursus associés à l'UV
 */
QMap<unsigned int, Cursus*>* UV::getCursus() const
{
    if (m_cursus == NULL || m_cursus == 0)
        return 0;
    return m_cursus;
}
