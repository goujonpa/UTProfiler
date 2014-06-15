/*!
 * \file cursus.cpp
 * \brief Méthodes de la classe DesirUV
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe DesirUV
 *
 */

#include "desiruv.h"

/*!
 * \brief constructeur par défaut DesirUV::DesirUV
 * \param parent : pointeur vers l'objet parent
 */
DesirUV::DesirUV(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode DesirUV::setUV
 * \param uv : pointeur vers l'UV à ajouter
 * \return true si l'ajout s'est bien déroulé
 */
bool DesirUV::setUV(UV *uv)
{
    m_UV = uv;
    return true;
}

/*!
 * \brief méthode DesirUV::setSemestre
 * \param semestre : pointeur vers le semestre à ajouter
 * \return true si l'ajout s'est déroulé
 */
bool DesirUV::setSemestre(Semestre *semestre)
{
    m_semestre = semestre;
    return true;
}
