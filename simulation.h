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
        Simulation(unsigned int id, QMap<unsigned int, Inscription*>* inscriptions, Semestre* semestre): m_id(id), m_inscriptions(inscriptions), m_semestre(semestre) {}

        /*!
         * \brief méthode getId
         * Récupère l'identificateur de simulation
         * \return la valeur de l'identificateur
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getInscriptions
         * Récupère le conteneur des inscriptions
         * \return conteneur des inscriptions
         */
        QMap<unsigned int, Inscription*>* getInscriptions() const;

        /*!
         * \brief méthode setInscriptions
         * Modifie le conteneur des inscriptions
         * \param inscr : conteneur des incriptions
         * \return true si l'ajout s'est bien réalisé
         */
        bool setInscriptions(QMap<unsigned int, Inscription*>* inscriptions);


        /*!
         * \brief méthode addInscription
         * Ajoute une inscription
         * \param inscription : pointeur vers une inscription
         * \return true si l'ajout s'est bien réalisé
         */
        bool addInscription(Inscription* inscription);

        bool setId(unsigned int id);

        bool setSemestre(Semestre* semestre);

        Semestre* getSemestre() const;


    protected:

        /*!
         * \brief m_id : identificateur de la simulation
         */
        unsigned int m_id;

        /*!
         * \brief m_inscriptions : conteneur des inscriptions
         */
        QMap<unsigned int, Inscription*>* m_inscriptions;

        Semestre* m_semestre;

    signals:

    public slots:

};

#endif // SIMULATION_H
