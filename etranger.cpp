/*!
 * \file etranger.cpp
 * \brief Méthodes de la classe Etranger
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe Etranger
 *
 */

#include "etranger.h"

/*!
 * \brief constructeur par défaut Etranger::Etranger
 * \param parent : pointeur vers l'objet parent
 */
Etranger::Etranger(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode Etranger::setTitre
 * \param titre : titre du semestre à l'étranger
 * \return true si l'ajout s'est bien déroulé
 */
bool Etranger::setTitre(QString titre)
{
    m_titre = titre;
    return true;
}

/*!
 * \brief méthode Etranger::setSemestre
 * \param semestre : pointeur vers le semestre passé à l'étranger
 * \return true si l'ajout s'est bien déroulé
 */
bool Etranger::setSemestre(Semestre* semestre)
{
    m_semestre = semestre;
    return true;
}

bool Etranger::setId(unsigned int id)
{
    m_id = id;
    return true;
}

Semestre* Etranger::getSemestre() const
{
    if (m_semestre == 0 || m_semestre == NULL)
        return 0;
    return m_semestre;
}
