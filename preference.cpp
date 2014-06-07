#include "preference.h"

Preference::Preference(QObject *parent) :
    QObject(parent)
{
}

bool Preference::setEtrangers(QMap<unsigned int, Etranger*> etrangers)
{
    m_etrangers = etrangers;
    return true;
}

bool Preference::setDesirs(QMap<unsigned int, DesirUV*> desirs)
{
    m_desirs = desirs;
    return true;
}

bool Preference::setBonus(QMap<unsigned int, BonusUV*> bonus)
{
    m_bonus = bonus;
    return true;
}

bool Preference::addEtranger(Etranger* etranger)
{
    m_etrangers.insert(etranger->getId(), etranger);
    return true;
}

bool Preference::addDesir(DesirUV* desir)
{
    m_desirs.insert(desir->getId(), desir);
    return true;
}

bool Preference::addBonus(BonusUV* bonus)
{
    m_bonus.insert(bonus->getId(), bonus);
    return true;
}

bool Preference::removeEtranger(Etranger* etranger)
{
    m_etrangers.remove(etranger->getId());
    return true;
}

bool Preference::removeDesir(DesirUV* desir)
{
    m_desirs.remove(desir->getId());
    return true;
}

bool Preference::removeBonus(BonusUV* bonus)
{
    m_bonus.remove(bonus->getId());
    return true;
}
