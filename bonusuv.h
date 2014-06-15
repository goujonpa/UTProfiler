#ifndef BONUSUV_H
#define BONUSUV_H

/*!
  * \file bonusuv.h
  * \brief Définition d'une préférence pour une UV
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe BonusUV
  */

#include <QObject>
#include "uv.h"

/*!
 * \brief The BonusUV class
 * Classe qui permet d'exprimer une préférence pour une UV
 */
class BonusUV : public QObject
{
        Q_OBJECT

    public:

    /*!
         * \brief Constructeur par défaut de BonusUV
         * \param parent : pointeur vers objet parent
         */
        explicit BonusUV(QObject *parent = 0);

    /*!
         * \brief Constructeur BonusUV
         * \param id : identificateur d'avis sur une UV
         * \param uv : pointeur vers l'UV "noté"
         * \param bonus : note donnée
         */
        BonusUV(unsigned int id, UV* uv, int bonus): m_id(id), m_UV(uv), m_bonus(bonus) {}

        /*!
         * \brief méthode getId
         * Récupère l'identifcateur de l'avis
         * \return id de l'avis
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getUV
         * Récupère l'UV notée
         * \return pointeur vers UV
         */
        UV* getUV() const;

        /*!
         * \brief méthode getBonus
         * Récupère la note donnée
         * \return note donnée à l'UV
         */
        int getBonus() const {return m_bonus;}

        /*!
         * \brief méthode setUV
         * Modifie l'UV notée
         * \param uv : pointeur vers l'UV
         * \return true si la modification s'est correctement déroulé
         */
        bool setUV(UV* uv);

        /*!
         * \brief méthode setBonus
         * Modifie la note donnée à l'UV
         * \param bonus : note donnée à l'UV
         * \return true si l'ajout s'est bien déroulé
         */
        bool setBonus(int bonus);
        bool setId(unsigned int id);

    protected:

        /*!
         * \brief m_id : identificateur de la préférence
         */
        unsigned int m_id;

        /*!
         * \brief m_UV : pointeur vers l'UV noté
         */
        UV* m_UV;

        /*!
         * \brief m_bonus : note donnée
         */
        int m_bonus;

    signals:

    public slots:

};

#endif // BONUSUV_H
