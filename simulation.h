#ifndef SIMULATION_H
#define SIMULATION_H

/*!
  * \file simulation.h
  * \brief Definition d'une simulation
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe simulation
  */

#include <QObject>
#include <QMap>
#include "inscription.h"
#include "cursus.h"
#include "profil.h"

/*!
 * \class Simulation
 * \brief The Simulation class
 *
 * La classe qui représente une simulation
 */
class Simulation : public QObject
{
        Q_OBJECT

    public:

    /*!
         * \brief Constructeur par défaut de Simulation
         * \param parent : pointeur vers l'objet parent
         */
        explicit Simulation(QObject *parent = 0);

    /*!
         * \brief Constructeur Simulation
         * \param id : identificateur de simulation
         * \param pref : pointeur vers objet Preference
         * \param inscription : conteneur contenant les pointeurs vers toutes les inscriptions que contient la simulation
         * \param cursus : pointeur vers objet cursus
         */
        Simulation(unsigned int id, Profil* profil, QMap<unsigned int, Inscription*>* inscriptions, Cursus* cursus): m_id(id), m_profil(profil), m_inscriptions(inscriptions), m_cursus(cursus) {}

        /*!
         * \brief méthode getId
         * Récupère l'identificateur de simulation
         * \return la valeur de l'identificateur
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getPreference
         * Récupère le pointeur de la preference
         * \return pointeur vers preference
         */
        Profil* getProfil() const {return m_profil;}

        /*!
         * \brief méthode getInscriptions
         * Récupère le conteneur des inscriptions
         * \return conteneur des inscriptions
         */
        QMap<unsigned int, Inscription*>* getInscriptions() const;

        /*!
         * \brief méthode getCursus
         * \return
         */
        Cursus* getCursus() const {return m_cursus;}

        /*!
         * \brief méthode setPreference
         * Modifie preference
         * \param pref : pointeur vers Preference
         * \return true si l'ajout s'est bien réalisé
         */
        bool setProfil(Profil* profil);

        /*!
         * \brief méthode setInscriptions
         * Modifie le conteneur des inscriptions
         * \param inscr : conteneur des incriptions
         * \return true si l'ajout s'est bien réalisé
         */
        bool setInscriptions(QMap<unsigned int, Inscription*>* inscriptions);

        /*!
         * \brief méthode setCursus
         * Modifie le cursus
         * \param cursus : pointeur vers cursus
         * \return true si l'ajout s'est bien réalisé
         */
        bool setCursus(Cursus* cursus);

        /*!
         * \brief méthode addInscription
         * Ajoute une inscription
         * \param inscription : pointeur vers une inscription
         * \return true si l'ajout s'est bien réalisé
         */
        bool addInscription(Inscription* inscription);


    protected:

        /*!
         * \brief m_id : identificateur de la simulation
         */
        unsigned int m_id;

        /*!
         * \brief m_preference : pointeur vers preference
         */
        Profil* m_profil;

        /*!
         * \brief m_inscriptions : conteneur des inscriptions
         */
        QMap<unsigned int, Inscription*>* m_inscriptions;

        /*!
         * \brief m_cursus : pointeur vers le cursus visé
         */
        Cursus* m_cursus; // cursus visé.

    signals:

    public slots:

};

#endif // SIMULATION_H
