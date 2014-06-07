#include "preference.h"

Preference::Preference(QObject *parent) :
    QObject(parent)
{
}

bool Preference::setEtrangers(QList<Etranger*> etrangers)
{
    m_etrangers = etrangers;
    return true;
}

bool Preference::setDesirs(QList<DesirUV*> desirs)
{
    m_desirs = desirs;
    return true;
}

bool Preference::setBonus(QList<BonusUV*> bonus)
{
    m_bonus = bonus;
    return true;
}

bool Preference::addEtranger(Etranger* etranger)
{
    m_etrangers.push_back(etranger);
    return true;
}

bool Preference::addDesir(DesirUV* desir)
{
    m_desirs.push_back(desir);
    return true;
}

bool Preference::addBonus(BonusUV* bonus)
{
    m_bonus.push_back(bonus);
    return true;
}

bool Preference::removeEtranger(Etranger* etranger)
{
    m_etrangers.removeOne(etranger);
    return true;
}

bool Preference::removeDesir(DesirUV* desir)
{
    m_desirs.removeOne(desir);
    return true;
}

bool Preference::removeBonus(BonusUV* bonus)
{
    m_bonus.removeOne(bonus);
    return true;
}
