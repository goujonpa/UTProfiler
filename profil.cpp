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
    if (this->getInscriptions() == 0)
        m_inscriptions = new QMap<unsigned int, Inscription*>;
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
    if (this->getEtrangers() == 0)
        m_etrangers = new QMap<unsigned int, Etranger*>;
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
    if (this->getPrefEtrangers() == 0)
        m_prefEtrangers = new QMap<unsigned int, Etranger*>;
    m_prefEtrangers->insert(etranger->getId(), etranger);
    return true;
}

bool Profil::addDesir(DesirUV* desir)
{
    if (this->getDesirs() == 0)
        m_desirs = new QMap<unsigned int, DesirUV*>;
    m_desirs->insert(desir->getId(), desir);
    return true;
}

bool Profil::addBonus(BonusUV* bonus)
{
    if (this->getBonus() == 0)
        m_bonus = new QMap<unsigned int, BonusUV*>;
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

QMap<unsigned int, Inscription*>* Profil::getInscriptions() const
{
    if (m_inscriptions == NULL || m_inscriptions == 0)
        return 0;
    return m_inscriptions;
}

Cursus* Profil::getActuel() const
{
    if (m_actuel == NULL || m_actuel == 0)
        return 0;
    return m_actuel;
}

Cursus* Profil::getVise() const
{
    if (m_vise == NULL || m_vise == 0)
        return 0;
    return m_vise;
}

QMap<unsigned int, Etranger*>* Profil::getEtrangers() const
{
    if (m_etrangers == NULL || m_etrangers == 0)
        return 0;
    return m_etrangers;
}

QMap<unsigned int, Etranger*>* Profil::getPrefEtrangers() const
{
    if (m_prefEtrangers == NULL || m_prefEtrangers == 0)
        return 0;
    return m_prefEtrangers;
}

QMap<unsigned int, DesirUV*>* Profil::getDesirs() const
{
    if (m_desirs == NULL || m_desirs == 0)
        return 0;
    return m_desirs;
}

QMap<unsigned int, BonusUV*>* Profil::getBonus() const
{
    if (m_bonus == NULL || m_bonus == 0)
        return 0;
    return m_bonus;
}

