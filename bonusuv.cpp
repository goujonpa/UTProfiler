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
