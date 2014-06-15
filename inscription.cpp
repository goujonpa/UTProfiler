/*!
 * \file inscription.cpp
 * \brief Méthodes de la classe Inscription
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe Inscription
 *
 */

#include "inscription.h"

/*!
 * \brief constructeur par défaut d'Inscription::Inscription
 * \param parent : pointeur vers l'objet parent
 */
Inscription::Inscription(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode Inscription::setUV
 * \param uv : pointeur vers l'UV à ajouter à l'inscription
 * \return true si l'ajout s'est correctement réalisé
 */
bool Inscription::setUV(UV* uv)
{
    m_uv = uv;
    return true;
}

/*!
 * \brief méthode Inscription::setSemestre
 * \param semestre : pointeur vers l'UV à ajouter à l'inscription
 * \return true si l'ajout s'est correctement réalisé
 */
bool Inscription::setSemestre(Semestre* semestre)
{
    m_semestre = semestre;
    return true;
}

/*!
 * \brief méthode Inscription::setNote
 * \param note : pointeur vers la note
 * \return true si l'ajout s'est correctement réalisé
 */
bool Inscription::setNote(Note* note)
{
    m_note = note;
    return true;
}

/*!
 * \brief méthode Inscription::setCursus
 * \param cursus : pointeur vers le cursus correspondant à l'inscription
 * \return true si l'ajout s'est correctement réalisé
 */
bool Inscription::setCursus(Cursus* cursus)
{
    m_cursus = cursus;
    return true;
}

/*!
 * \brief méthode Inscription::setCategorie
 * \param categorie : pointeur vers la catégorie
 * \return true si l'ajout s'est correctement réalisé
 */
bool Inscription::setCategorie(Categorie* categorie)
{
    m_categorie = categorie;
    return true;
}

/*!
 * \brief méthode Inscription::setId
 * \param id : identificateur de l'inscription
 * \return true si l'ajout s'est correctement réalisé
 */
bool Inscription::setId(unsigned int id)
{
    m_id = id;
    return true;
}

UV* Inscription::getUV() const
{
    if (m_uv == 0 || m_uv == NULL)
        return 0;
    return m_uv;
}

Semestre* Inscription::getSemestre() const
{
    if (m_semestre == 0 || m_semestre == NULL)
        return 0;
    return m_semestre;
}

Note* Inscription::getNote() const
{
    if (m_note == 0 || m_note == NULL)
        return 0;
    return m_note;
}

Cursus* Inscription::getCursus() const
{
    if (m_cursus == 0 || m_cursus == NULL)
        return 0;
    return m_cursus;
}

Categorie*  Inscription::getCategorie() const
{
    if (m_categorie == 0 || m_categorie == NULL)
        return 0;
    return m_categorie;
}
