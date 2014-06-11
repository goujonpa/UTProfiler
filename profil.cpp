#include "profil.h"

Profil::Profil(QObject *parent) :
    QObject(parent)
{
}


bool Profil::setInscriptions(QMap<unsigned int, Inscription*>* inscriptions)
{
    m_inscriptions = inscriptions;
    return true;
}

bool Profil::addInscription(Inscription* inscription)
{
    m_inscriptions->insert(inscription->getId(), inscription);
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

bool Profil::setEtrangers(QMap<unsigned int, Etranger*>* etrangers)
{
    m_etrangers = etrangers;
    return true;
}

bool Profil::addEtranger(Etranger* etranger)
{
    m_etrangers->insert(etranger->getId(), etranger);
    return true;
}

bool Profil::setPrefEtrangers(QMap<unsigned int, Etranger*>* etrangers)
{
    m_prefEtrangers = etrangers;
    return true;
}

bool Profil::setDesirs(QMap<unsigned int, DesirUV*>* desirs)
{
    m_desirs = desirs;
    return true;
}

bool Profil::setBonus(QMap<unsigned int, BonusUV*>* bonus)
{
    m_bonus = bonus;
    return true;
}

bool Profil::addPrefEtranger(Etranger* etranger)
{
    m_prefEtrangers->insert(etranger->getId(), etranger);
    return true;
}

bool Profil::addDesir(DesirUV* desir)
{
    m_desirs->insert(desir->getId(), desir);
    return true;
}

bool Profil::addBonus(BonusUV* bonus)
{
    m_bonus->insert(bonus->getId(), bonus);
    return true;
}

bool Profil::removePrefEtranger(Etranger* etranger)
{
    m_prefEtrangers->remove(etranger->getId());
    return true;
}

bool Profil::removeDesir(DesirUV* desir)
{
    m_desirs->remove(desir->getId());
    return true;
}

bool Profil::removeBonus(BonusUV* bonus)
{
    m_bonus->remove(bonus->getId());
    return true;
}

bool Profil::setId(unsigned int id)
{
    m_id = id;
    return true;
}
