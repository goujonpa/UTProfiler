#ifndef SEMESTRE_H
#define SEMESTRE_H

/*!
  * \file semestre.h
  * \brief Definition d'un semestre
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe semestre
  */

#include <QObject>

/*!
 * \enum Saison
 * \brief Deux saisons qui divise une année universitaire semestriellement
 */
enum Saison {Automne, Printemps};

/*!
 * \class Semestre
 * \brief The Semestre class
 * La classe qui représente une simulation
 */
class Semestre : public QObject
{
        Q_OBJECT

    public:

    /*!
         * \brief Constructeur par défaut de Semestre
         * \param parent : pointeur vers l'objet parent
         */
        explicit Semestre(QObject *parent = 0);

    /*!
         * \brief Constructeur Semestre
         * \param id : identificateur de semestre
         * \param saison : saison du semestre (de l'énumération)
         * \param annee : année du semestre
         */
        Semestre(unsigned int id, Saison saison, unsigned int annee): m_id(id), m_saison(saison), m_annee(annee) {}

        /*!
         * \brief méthode getId
         * Récupère l'identificateur du semestre
         * \return la valeur de l'identificateur
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getSaison
         * Récupère la saison du semestre
         * \return  la saison du semestre
         */
        Saison getSaison() const {return m_saison;}

        /*!
         * \brief méthode getAnnee
         * Récupère l'année du semestre
         * \return l'année du semestre
         */
        unsigned int getAnnee() const {return m_annee;}

        /*!
         * \brief méthode setSaison
         * Modifie la saison
         * \param saison : saison de l'enumération
         * \return true si l'ajout s'est déroulé correctement
         */
        bool setSaison(Saison saison);

        /*!
         * \brief méthode setAnnee
         * Modifie l'année
         * \param annee : année du semestre
         * \return true si l'ajout s'est déroulé correctement
         */
        bool setAnnee(unsigned int annee);

        bool setId(unsigned int id);

    protected:

        /*!
         * \brief m_id : identificateur de semestre
         */
        unsigned int m_id;

        /*!
         * \brief m_saison : saison du semestre
         */
        Saison m_saison;

        /*!
         * \brief m_annee : année du semestre
         */
        unsigned int m_annee;

    signals:

    public slots:

};

#endif // SEMESTRE_H
