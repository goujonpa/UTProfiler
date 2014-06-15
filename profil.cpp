/*!
 * \file profil.cpp
 * \brief Méthodes de la classe Profil
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe Profil
 *
 */

#include "profil.h"

/*!
 * \brief constructeur par défaut de Profil::Profil
 * \param parent : pointeur vers l'objet parent
 */
Profil::Profil(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode Profil::setInscriptions
 * \param inscriptions : pointeur vers le conteneur des inscriptions
 * \return true si l'ajout s'est correctement réalisé
 */
bool Profil::setInscriptions(QMap<unsigned int, Inscription*>* inscriptions)
{
    m_inscriptions = inscriptions;
    return true;
}

/*!
 * \brief méthode Profil::addInscription
 * \param inscription : pointeur vers l'inscription à ajouter
 * \return true si l'ajout s'est correctement réalisé
 */
bool Profil::addInscription(Inscription* inscription)
{
    m_inscriptions->insert(inscription->getId(), inscription);
    return true;
}

/*!
 * \brief méthode Profil::setActuel
 * \param actuel : pointeur vers le cursus actuel
 * \return true si l'ajout s'est correctement réalisé
 */
bool Profil::setActuel(Cursus* actuel)
{
    m_actuel = actuel;
    return true;
}

/*!
 * \brief méthode Profil::setVise
 * \param vise : pointeur vers le cursus visé
 * \return true si l'ajout s'est correctement réalisé
 */
bool Profil::setVise(Cursus* vise)
{
    m_vise = vise;
    return true;
}

/*!
 * \brief méthode Profil::setEtrangers
 * \param etrangers : pointeur vers le conteneur des semestre à l'étranger
 * \return true si l'ajout s'est correctement réalisé
 */
bool Profil::setEtrangers(QMap<unsigned int, Etranger*>* etrangers)
{
    m_etrangers = etrangers;
    return true;
}

/*!
 * \brief méthide Profil::addEtranger
 * \param etranger : pointeur vers le semestre à l'étranger à rajouter
 * \return true si l'ajout s'est correctement réalisé
 */
bool Profil::addEtranger(Etranger* etranger)
{
    m_etrangers->insert(etranger->getId(), etranger);
    return true;
}

/*!
 * \brief méthode Profil::setPrefEtrangers
 * \param etrangers : pointeur vers le conteneur des semestres passées à l'étranger
 * \return true si l'ajout s'est correctement réalisé
 */
bool Profil::setPrefEtrangers(QMap<unsigned int, Etranger*>* etrangers)
{
    m_prefEtrangers = etrangers;
    return true;
}

/*!
 * \brief méthode Profil::setDesirs
 * \param desirs : pointeur vers le conteneur des DésirUV
 * \return true si l'ajout s'est correctement réalisé
 */
bool Profil::setDesirs(QMap<unsigned int, DesirUV*>* desirs)
{
    m_desirs = desirs;
    return true;
}

/*!
 * \brief méthode Profil::setBonus
 * \param bonus : pointeur vers le conteneur des BonusUV
 * \return true si l'ajout s'est correctement réalisé
 */
bool Profil::setBonus(QMap<unsigned int, BonusUV*>* bonus)
{
    m_bonus = bonus;
    return true;
}

/*!
 * \brief méthode Profil::addPrefEtranger
 * \param etranger : pointeur vers un semestre à l'étranger à ajouter
 * \return true si l'ajout s'est correctement réalisé
 */
bool Profil::addPrefEtranger(Etranger* etranger)
{
    m_prefEtrangers->insert(etranger->getId(), etranger);
    return true;
}

/*!
 * \brief méthode Profil::addDesir
 * \param desir : pointeur vers un DesirUV à ajouter
 * \return true si l'ajout s'est correctement réalisé
 */
bool Profil::addDesir(DesirUV* desir)
{
    m_desirs->insert(desir->getId(), desir);
    return true;
}

/*!
 * \brief méthide Profil::addBonus
 * \param bonus : pointeur vers le bonus à ajouter
 * \return true si l'ajout s'est correctement réalisé
 */
bool Profil::addBonus(BonusUV* bonus)
{
    m_bonus->insert(bonus->getId(), bonus);
    return true;
}

/*!
 * \brief méthode Profil::removePrefEtranger
 * \param etranger : pointeur vers le semestre à l'étranger à retirer
 * \return true si le retrait s'est correctement réalisé
 */
bool Profil::removePrefEtranger(Etranger* etranger)
{
    m_prefEtrangers->remove(etranger->getId());
    return true;
}

/*!
 * \brief méthode Profil::removeDesir
 * \param desir : pointeur vers le DesirUV à retirer
 * \return true si le retrait s'est correctement réalisé
 */
bool Profil::removeDesir(DesirUV* desir)
{
    m_desirs->remove(desir->getId());
    return true;
}

/*!
 * \brief méthode Profil::removeBonus
 * \param bonus : pointeur vers BonusUV à retirer
 * \return true si le retrait s'est correctement réalisé
 */
bool Profil::removeBonus(BonusUV* bonus)
{
    m_bonus->remove(bonus->getId());
    return true;
}

/*!
 * \brief méthode Profil::setId
 * \param id : identificateur du profil
 * \return true si l'ajout s'est correctement réalisé
 */
bool Profil::setId(unsigned int id)
{
    m_id = id;
    return true;
}

/*!
 * \brief méthode Profil::getInscriptions
 * \return pointeur vers le conteneur des inscriptions
 */
QMap<unsigned int, Inscription*>* Profil::getInscriptions() const
{
    if (m_inscriptions == NULL || m_inscriptions == 0)
        return 0;
    return m_inscriptions;
}

/*!
 * \brief méthode Profil::getActuel
 * \return le pointeur vers le cursus actuel
 */
Cursus* Profil::getActuel() const
{
    if (m_actuel == NULL || m_actuel == 0)
        return 0;
    return m_actuel;
}

/*!
 * \brief méthode Profil::getVise
 * \return le pointeur vers le cursus visé
 */
Cursus* Profil::getVise() const
{
    if (m_vise == NULL || m_vise == 0)
        return 0;
    return m_vise;
}

/*!
 * \brief méthode Profil::getEtrangers
 * \return pointeur vers le conteneur de semestre à l'étranger
 */
QMap<unsigned int, Etranger*>* Profil::getEtrangers() const
{
    if (m_etrangers == NULL || m_etrangers == 0)
        return 0;
    return m_etrangers;
}

/*!
 * \brief méthode Profil::getPrefEtrangers
 * \return pointeur vers le conteneur de préférences à l'étranger
 */
QMap<unsigned int, Etranger*>* Profil::getPrefEtrangers() const
{
    if (m_prefEtrangers == NULL || m_prefEtrangers == 0)
        return 0;
    return m_prefEtrangers;
}

/*!
 * \brief méthode Profil::getDesirs
 * \return pointeur vers le conteneur de DesirUV
 */
QMap<unsigned int, DesirUV*>* Profil::getDesirs() const
{
    if (m_desirs == NULL || m_desirs == 0)
        return 0;
    return m_desirs;
}

/*!
 * \brief méthode Profil::getBonus
 * \return pointeur vers le conteneur des BonusUV
 */
QMap<unsigned int, BonusUV*>* Profil::getBonus() const
{
    if (m_bonus == NULL || m_bonus == 0)
        return 0;
    return m_bonus;
}

