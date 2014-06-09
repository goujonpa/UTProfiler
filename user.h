#ifndef USER_H
#define USER_H

/*!
  * \file user.h
  * \brief Definition d'un utilisateur
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe user
  */

#include <QObject>
#include "simulation.h"
#include "profil.h"

/*!
 * \class User
 * \brief The User class
 *
 * La classe qui représente un utilisateur
 */
class User : public QObject
{
        Q_OBJECT

    public:

    /*!
         * \brief Constructeur par défaut de User
         * \param parent : pointeur vers l'objet parent
         */
        explicit User(QObject *parent = 0);

    /*!
         * \brief Constructeur User
         * \param id : identificateur du user
         * \param nom : nom du user
         * \param prenom : prenom du user
         * \param simu : pointeur vers objet Simulation
         * \param profil : pointeur vers objet Profil
         * \param pref : pointeur vers objet Preference
         */
        User(unsigned int id, QString nom, QString prenom, Simulation* simu, Profil* profil): m_id(id), m_nom(nom), m_prenom(prenom), m_simulation(simu), m_profil(profil) {}

        /*!
         * \brief méthode getId
         * Récupère l'identificateur du user
         * \return la valeur de l'identificateur
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getNom
         * Récupère le nom du user
         * \return le nom de l'utilisateur
         */
        QString getNom() const {return m_nom;}

        /*!
         * \brief méthode getPrenom
         * Récupère le prenom du user
         * \return le prenom de l'utilisateur
         */
        QString getPrenom() const {return m_prenom;}

        /*!
         * \brief méthode getSimulation
         * Récupère le pointeur de la simulation
         * \return pointeur vers simulation
         */
        Simulation* getSimulation() const {return m_simulation;}

        /*!
         * \brief méthode getProfil
         * Récupère le pointeur du profil
         * \return pointeur vers profil
         */
        Profil* getProfil() const {return m_profil;}

        /*!
         * \brief méthode getPreference
         * Récupère le pointeur des préférences
         * \return pointeur vers Preference
         */

        bool setId(unsigned int id);
        /*!
         * \brief méthode setNom
         * Modifie le nom de user
         * \param nom : nom de user
         * \return true si l'ajout s'est bien réalisé
         */
        bool setNom(QString nom);

        /*!
         * \brief méthode setPrenom
         * Modifie le prenom de user
         * \param prenom : prenom de user
         * \return true si l'ajout s'est bien réalisé
         */
        bool setPrenom(QString prenom);

        /*!
         * \brief méthode setSimulation
         * Modifie la simulation
         * \param simulation : pointeur vers simulation
         * \return true si l'ajout s'est bien réalisé
         */
        bool setSimulation(Simulation* simulation);

        /*!
         * \brief méthode setProfil
         * Modifie le profil
         * \param profil : pointeur vers profil
         * \return true si l'ajout s'est bien réalisé
         */
        bool setProfil(Profil* profil);

        /*!
         * \brief méthode  setPreference
         * Modifie la préférence
         * \param pref : pointeur vers preference
         * \return true si l'ajout s'est bien réalisé
         */

    protected:

        /*!
         * \brief m_id : identificateur de user
         */
        unsigned int m_id;

        /*!
         * \brief m_nom : nom de user
         */
        QString m_nom;

        /*!
         * \brief m_prenom : prenom de user
         */
        QString m_prenom;

        /*!
         * \brief m_simulation : simulation de user
         */
        Simulation* m_simulation;

        /*!
         * \brief m_profil : profil de user
         */
        Profil* m_profil;

        /*!
         * \brief m_preference : preference de user
         */

    signals:

    public slots:

};

#endif // USER_H
