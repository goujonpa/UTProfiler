#ifndef PROFIL_H
#define PROFIL_H

/*!
  * \file profil.h
  * \brief Definition d'un profil
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe Profil
  */

#include <QObject>
#include <QMap>
#include "inscription.h"
#include "cursus.h"
#include "etranger.h"

/*!
 * \class Profil
 * \brief The Profil class
 * La classe qui représente un profil
 */
class Profil : public QObject
{
        Q_OBJECT

    public:
    /*!
         * \brief Constructeur de Profil
         * \param id : identificateur du profil
         * \param insc : conteneur des inscriptions
         * \param actuel : pointeur vers le cursus actuel
         * \param vise : pointeur vers le cursus visé
         * \param etr : conteneur de semestre à l'étranger
         */
        Profil(unsigned int id, QMap<unsigned int, Inscription*> insc, Cursus* actuel, Cursus* vise, QMap<unsigned int, Etranger*> etr): m_id(id), m_inscriptions(insc), m_actuel(actuel), m_vise(vise), m_etranger(etr) {}

    /*!
         * \brief Constructeur par défaut de Profil
         * \param parent : pointeur vers le profil Parent
         */
        explicit Profil(QObject *parent = 0);

        /*!
         * \brief méthode getId
         * Récupère l'identificateur du profil
         * \return la valeur de l'identificateur
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getInscriptions
         * Récupère les inscriptions
         * \return conteneur des inscriptions
         */
        QMap<unsigned int, Inscription*> getInscriptions() const {return m_inscriptions;}

        /*!
         * \brief méthode getActuel
         * Récupère le cursus actuel
         * \return pointeur vers le cursus actuel
         */
        Cursus* getActuel() const {return m_actuel;}

        /*!
         * \brief méthode getVise
         * Récupère le cursus visé
         * \return pointeur vers cursus visé
         */
        Cursus* getVise() const {return m_vise;}

        /*!
         * \brief méthode getEtranger
         * Récupère les semestres réalisés à l'étranger
         * \return conteneur des semestres à l'étranger
         */
        QMap<unsigned int, Etranger*> getEtranger() {return m_etranger;}

        /*!
         * \brief méthode setInscriptions
         * Modifie les inscriptions
         * \param insc : conteneur des inscriptions
         * \return true si l'ajout s'est réalisé correctement
         */
        bool setInscriptions(QMap<unsigned int, Inscription*> insc);

        /*!
         * \brief méthode addInscription
         * Ajoute une inscription
         * \param insc : pointeur vers une inscription
         * \return true si l'ajout s'est réalisé correctement
         */
        bool addInscription(Inscription* insc);

        /*!
         * \brief methode setActuel
         * Modifie le cursus actuel
         * \param actuel : pointeur vers le cursus actuel
         * \return true si l'ajout s'est réalisé correctement
         */
        bool setActuel(Cursus* actuel);

        /*!
         * \brief méthode setVise
         * Modifie le cursus visé
         * \param vise : pointeur vers le cursus visé
         * \return true si l'ajout s'est réalisé correctement
         */
        bool setVise(Cursus* vise);

        /*!
         * \brief méthode setEtranger
         * Modifie le semestre passé à l'étranger
         * \param etr : conteneur de semestre à l'étranger
         * \return true si l'ajout s'est réalisé correctement
         */
        bool setEtranger(QMap<unsigned int, Etranger*> etr);

        /*!
         * \brief méthode addEtranger
         * Ajoute un semestre à l'étranger
         * \param etr : pointeur vers semestre à l'étranger
         * \return true si l'ajout s'est déroulé correctement
         */
        bool addEtranger(Etranger* etr);



    protected:

        /*!
         * \brief m_id : identificateur du profil
         */
        unsigned int m_id;

        /*!
         * \brief m_inscriptions : conteneur des inscriptions
         */
        QMap<unsigned int, Inscription*> m_inscriptions;

        /*!
         * \brief m_actuel : pointeur vers le cursus actuel
         */
        Cursus* m_actuel;

        /*!
         * \brief m_vise : pointeur vers le cursus visé
         */
        Cursus* m_vise;

        /*!
         * \brief m_etranger : conteneur des semestres à l'étranger
         */
        QMap<unsigned int, Etranger*> m_etranger;

    signals:

    public slots:

};

#endif // PROFIL_H
