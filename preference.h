#ifndef PREFERENCE_H
#define PREFERENCE_H

/*!
  * \file preference.h
  * \brief Definition d'une préférence
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe Preference
  */

#include <QObject>
#include "etranger.h"
#include "desiruv.h"
#include "bonusuv.h"
#include <QMap>

/*!
 * \class Preference
 * \brief The Preference class
 * La classe qui représente une préférence
 */
class Preference : public QObject
{
        Q_OBJECT

    public:
    /*!
         * \brief Constructeur par défaut de Preference
         * \param parent : pointeur vers le Preference parent
         */
        explicit Preference(QObject *parent = 0);

    /*!
         * \brief Constructeur de Preference
         * \param id : identificateur de preference
         * \param etranger : conteneur de semestre à l'étranger
         * \param desirs : conteneur de désir UV
         * \param bonus : conteneur d'UV bonus
         */
        Preference(unsigned int id, QMap<unsigned int, Etranger*> etranger, QMap<unsigned int, DesirUV*> desirs, QMap<unsigned int, BonusUV*> bonus): m_id(id), m_etrangers(etranger), m_desirs(desirs), m_bonus(bonus) {}

        /*!
         * \brief méthode getId
         * Récupère l'identificateur de Preference
         * \return valeur de l'identificateur
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getEtranger
         * Récupère les semestre à l'étranger
         * \return conteneur de semestre à l'étranger
         */
        QMap<unsigned int, Etranger*> getEtranger() const {return m_etrangers;}

        /*!
         * \brief méthode getDesirs
         * Récupère les souhaits d'UVs
         * \return conteneur des UVs désirées
         */
        QMap<unsigned int, DesirUV*> getDesirs() const {return m_desirs;}

        /*!
         * \brief méthode getBonus
         * Récupère les UVs bonus
         * \return conteneur d'UVs bonus
         */
        QMap<unsigned int, BonusUV*> getBonus() const {return m_bonus;}

        /*!
         * \brief méthode setEtrangers
         * Modifie les semestres à l'étranger
         * \param etranger : conteneur de semestre à l'étranger
         * \return true si la modification a eu lieu correctement
         */
        bool setEtrangers(QMap<unsigned int, Etranger*> etranger);

        /*!
         * \brief méthode setDesirs
         * Modifie les désirs d'UV a effectuer
         * \param desirs : conteneur des UV souhaitées
         * \return true si la modification a eu lieu correctement
         */
        bool setDesirs(QMap<unsigned int, DesirUV*> desirs);

        /*!
         * \brief méthode setBonus
         * Modifie les UVs nonus
         * \param bonus : conteneur des UVs bonus
         * \return true si la modification a eu lieu correctement
         */
        bool setBonus(QMap<unsigned int, BonusUV*> bonus);

        /*!
         * \brief méthode addEtranger
         * Ajoute un semestre à l'étranger
         * \param etranger : pointeur vers un semestre à l'étranger
         * \return true si l'ajout à bien eu lieu
         */
        bool addEtranger(Etranger* etranger);

        /*!
         * \brief méthode addDesir
         * Ajoute un désir d'UV
         * \param desir : pointeur vers désirs UV
         * \return true si l'ajout a eu lieu correctement
         */
        bool addDesir(DesirUV* desir);

        /*!
         * \brief méthode addBonus
         * ajoute à partir d'un bonus
         * \param bonus : pointeur vers BonusUV
         * \return true si l'ajout a eu lieu correctement
         */
        bool addBonus(BonusUV* bonus);

        /*!
         * \brief méthode removeEtranger
         * Supprime un semestre à l'étranger
         * \param etranger : pointeur vers Etranger
         * \return true si la modification s'est faite correctement
         */
        bool removeEtranger(Etranger* etranger);

        /*!
         * \brief méthode removeDesir
         * Supprime un souhait d'UV
         * \param desir : pointeur vers une DesirUV
         * \return true si la mofication a eu lieu correctment
         */
        bool removeDesir(DesirUV* desir);

        /*!
         * \brief méthode removeBonus
         * Supprime une UV bonus
         * \param bonus : pointeur vers une UVBonus
         * \return
         */
        bool removeBonus(BonusUV* bonus);

    protected:

        /*!
         * \brief m_id : identificateur de la préférence
         */
        unsigned int m_id;

        /*!
         * \brief m_etrangers : conteneur des semestres à l'étranger
         */
        QMap<unsigned int, Etranger*> m_etrangers;

        /*!
         * \brief m_desirs : conteneur des souhaits d'UV
         */
        QMap<unsigned int, DesirUV*> m_desirs;

        /*!
         * \brief m_bonus : conteneur des UV bonus
         */
        QMap<unsigned int, BonusUV*> m_bonus;

    signals:

    public slots:

};

#endif // PREFERENCE_H
