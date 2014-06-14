#include "bonusuv.h"

BonusUV::BonusUV(QObject *parent) :
    QObject(parent)
{
}

bool BonusUV::setUV(UV *uv)
{
    m_UV = uv;
    return true;
}

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
