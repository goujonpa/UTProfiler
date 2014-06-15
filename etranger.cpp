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
