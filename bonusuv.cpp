/*!
 * \file bonusuv.cpp
 * \brief Méthodes de la classe BonusUV
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe BonusUV
 *
 */

#include "bonusuv.h"

/*!
 * \brief Constructeur par défaut BonusUV::BonusUV
 * \param parent : pointeur vers l'objet parent
 */
BonusUV::BonusUV(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode BonusUV::setUV
 * \param uv: pointeur vers UV
 * \return true si l'ajout s'est correctement déroulé
 */
bool BonusUV::setUV(UV *uv)
{
    m_UV = uv;
    return true;
}

/*!
 * \brief méthode BonusUV::setBonus
 * \param bonus : valeur indiquant la priorité de volonté de faire l'UV
 * \return true si l'ajout s'est correctement déroulé
 */
bool BonusUV::setBonus(int bonus)
{
    m_bonus = bonus;
    return true;
}

bool BonusUV::setId(unsigned int id)
{
    m_id = id;
    return true;
}

UV* BonusUV::getUV() const
{
    if (m_UV == 0 || m_UV == NULL)
        return 0;
    return m_UV;
}
