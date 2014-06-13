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
#include "desiruv.h"
#include "bonusuv.h"


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
        Profil(unsigned int id, QMap<unsigned int, Inscription*>* inscriptions, Cursus* actuel, Cursus* vise, QMap<unsigned int, Etranger*>* etrangers, QMap<unsigned int, Etranger*>* prefEtrangers, QMap<unsigned int, DesirUV*>* desirs, QMap<unsigned int, BonusUV*>* bonus): m_id(id), m_inscriptions(inscriptions), m_actuel(actuel), m_vise(vise), m_etrangers(etrangers), m_prefEtrangers(prefEtrangers), m_desirs(desirs), m_bonus(bonus) {}

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
        QMap<unsigned int, Inscription*>* getInscriptions() const {return m_inscriptions;}

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
        QMap<unsigned int, Etranger*>* getEtrangers() {return m_etrangers;}

        /*!
         * \brief méthode setInscriptions
         * Modifie les inscriptions
         * \param insc : conteneur des inscriptions
         * \return true si l'ajout s'est réalisé correctement
         */
        bool setInscriptions(QMap<unsigned int, Inscription*>* inscriptions);

        /*!
         * \brief méthode addInscription
         * Ajoute une inscription
         * \param insc : pointeur vers une inscription
         * \return true si l'ajout s'est réalisé correctement
         */
        bool addInscription(Inscription* inscription);

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
        bool setEtrangers(QMap<unsigned int, Etranger*>* etrangers);

        /*!
         * \brief méthode addEtranger
         * Ajoute un semestre à l'étranger
         * \param etr : pointeur vers semestre à l'étranger
         * \return true si l'ajout s'est déroulé correctement
         */
        bool addEtranger(Etranger* etranger);

        /*!
         * \brief méthode setId
         * \param id : identificateur de profil
         * \return true si l'ajout s'est correctement déroulé
         */
        bool setId(unsigned int id);

        /*!
         * \brief méthode getPrefEtranger
         * Récupère les préférences de départ à l'étranger
         * \return conteneur de semestre à l'étranger
         */
        QMap<unsigned int, Etranger*>* getPrefEtranger() const {return m_prefEtrangers;}


        /*!
         * \brief méthode getDesirs
         * Récupère les UVs les plus désirées
         * \return : conteneur d'UV désirées
         */
        QMap<unsigned int, DesirUV*>* getDesirs() const {return m_desirs;}

        /*!
         * \brief méthode getBonus
         * Récupère les préférences envers des UVs
         * \return conteneur d'avis sur des UVs
         */
        QMap<unsigned int, BonusUV*>* getBonus() const {return m_bonus;}

        /*!
         * \brief méthode setPrefEtrangers
         * Modifie les préférences de semestre à l'étranger
         * \param etranger : pointeur vers conteneur de semestre à l'étranger
         * \return true si la modification s'est correctement réalisée
         */
        bool setPrefEtrangers(QMap<unsigned int, Etranger*>* etranger);

        /*!
         * \brief méthode setDesirs
         * Modifie les désirs de faire des UVs en particulier
         * \param desirs : pointeur vers conteneur de désirs d'UVs
         * \return true si la modification s'est correctement réalisée
         */
        bool setDesirs(QMap<unsigned int, DesirUV*>* desirs);


        /*!
         * \brief méthode setBonus
         * Modifie les avis données à des UVs
         * \param bonus : pointeur vers conteneur de BonusUV
         * \return true si la modification s'est correctement réalisée
         */
        bool setBonus(QMap<unsigned int, BonusUV*>* bonus);

        /*!
         * \brief méthode addPrefEtranger
         * Ajoute un souhait de départ à l'étranger
         * \param etranger : pointeur vers un semestre à l'étranger
         * \return true si la modification s'est correctement réalisée
         */

        bool addPrefEtranger(Etranger* etranger);

        /*!
         * \brief méthode addDesir
         * Ajoute un désir de faire une UV
         * \param desir : pointeur vers un désir d'UV
         * \return true si la modification s'est correctement réalisée
         */
        bool addDesir(DesirUV* desir);

        /*!
         * \brief méthode addBonus
         * Ajoute une préférence à une UV
         * \param bonus : pointeur vers un BonusUV
         * \return true si la modification s'est correctement réalisée
         */
        bool addBonus(BonusUV* bonus);

        /*!
         * \brief méthode removePrefEtranger
         * Retire un souhait de semestre à l'étranger
         * \param etranger : pointeur vers un semestre à l'étranger
         * \return true si la modification s'est correctement réalisée
         */
        bool removePrefEtranger(Etranger* etranger);

        /*!
         * \brief méthode removeDesir
         * Retire un désir de faire une UV
         * \param desir : pointeur vers un désir d'UV
         * \return true si la modification s'est correctement réalisée
         */
        bool removeDesir(DesirUV* desir);

        /*!
         * \brief méthode removeBonus
         * Retire une préférence donnée à une UV
         * \param bonus : pointeur vers BonusUV
         * \return true si la modification s'est correctement réalisée
         */
        bool removeBonus(BonusUV* bonus);



    protected:

        /*!
         * \brief m_id : identificateur du profil
         */
        unsigned int m_id;

        /*!
         * \brief m_inscriptions : conteneur des inscriptions
         */
        QMap<unsigned int, Inscription*>* m_inscriptions;

        /*!
         * \brief m_actuel : pointeur vers le cursus actuel
         */
        Cursus* m_actuel;

        /*!
         * \brief m_vise : pointeur vers le cursus visé
         */
        Cursus* m_vise;

        /*!
         * \brief m_etranger : pointeur vers conteneur des semestres à l'étranger
         */
        QMap<unsigned int, Etranger*>* m_etrangers;

        /*!
         * \brief m_prefEtrangers : pointeur vers conteneur de semestre à l'étranger
         */
        QMap<unsigned int, Etranger*>* m_prefEtrangers;

        /*!
         * \brief m_desirs : pointeur conteneur de désirs d'UV
         */
        QMap<unsigned int, DesirUV*>* m_desirs;

        /*!
         * \brief m_bonus : pointeur conteneur d'UV à favoriser
         */
        QMap<unsigned int, BonusUV*>* m_bonus;


    signals:

    public slots:

};

#endif // PROFIL_H
