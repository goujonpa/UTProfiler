#include "profil.h"

Profil::Profil(QObject *parent) :
    QObject(parent)
{
}


bool Profil::setInscriptions(QMap<unsigned int, Inscription*> insc)
{
    m_inscriptions = insc;
    return true;
}

bool Profil::addInscription(Inscription* insc)
{
    m_inscriptions.insert(insc->getId(), insc);
    return true;
}

bool Profil::setActuel(Cursus* actuel)
{
    m_actuel = actuel;
    return true;
}

bool Profil::setVise(Cursus* vise)
{
    m_vise = vise;
    return true;
}

bool Profil::setEtranger(QMap<unsigned int, Etranger*> etr)
{
    m_etranger = etr;
    return true;
}

bool Profil::addEtranger(Etranger* etr)
{
    m_etranger.insert(etr->getId(), etr);
    return true;
}

bool Profil::setPrefEtrangers(QMap<unsigned int, Etranger*> etrangers)
{
    m_prefEtrangers = etrangers;
    return true;
}

bool Profil::setDesirs(QMap<unsigned int, DesirUV*> desirs)
{
    m_desirs = desirs;
    return true;
}

bool Profil::setBonus(QMap<unsigned int, BonusUV*> bonus)
{
    m_bonus = bonus;
    return true;
}

bool Profil::addPrefEtranger(Etranger* etranger)
{
    m_prefEtrangers.insert(etranger->getId(), etranger);
    return true;
}

bool Profil::addDesir(DesirUV* desir)
{
    m_desirs.insert(desir->getId(), desir);
    return true;
}

bool Profil::addBonus(BonusUV* bonus)
{
    m_bonus.insert(bonus->getId(), bonus);
    return true;
}

bool Profil::removePrefEtranger(Etranger* etranger)
{
    m_prefEtrangers.remove(etranger->getId());
    return true;
}

bool Profil::removeDesir(DesirUV* desir)
{
    m_desirs.remove(desir->getId());
    return true;
}

bool Profil::removeBonus(BonusUV* bonus)
{
    m_bonus.remove(bonus->getId());
    return true;
}

