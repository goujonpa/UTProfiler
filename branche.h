#ifndef BRANCHE_H
#define BRANCHE_H

/*!
  * \file branche.h
  * \brief Définition d'une branche à l'UTC
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe Branche
  */

#include <QObject>

/*!
 * \class Branche
 * \brief The Branche class
 * Représente une branche à l'UTC, spécialisation ingénieur
 */
class Branche : public QObject
{
        Q_OBJECT

    public:

    /*!
         * \brief constructeur par défaut de Branche
         * \param parent : pointeur vers l'objet parent
         */
        explicit Branche(QObject *parent = 0);


    /*!
         * \brief méthode Branche
         * \param id : identificateur de la branche
         * \param code : code de la branche
         * \param nom : nom de la branche
         */
        Branche(unsigned int id, QString code, QString nom): m_id(id), m_code(code), m_nom(nom) {}

        /*!
         * \brief méthode getId
         * Récupère l'identificateur de la branche
         * \return id de la branche
         */

        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getCode
         * Récupère le code de la branche
         * \return code de l'UV
         */
        QString getCode() const {return m_code;}

        /*!
         * \brief méthode getNom
         * Récupère le nom de la branche
         * \return nom de la branche
         */
        QString getNom() const {return m_nom;}

        /*!
         * \brief méthode setCode
         * Modifie le code de la branche
         * \param code : code de la branche
         * \return true si l'ajout s'est correctement réalisé
         */
        bool setCode(QString code);

        /*!
         * \brief méthode setNom
         * Modifie le nom de la branche
         * \param nom : nom de la branche
         * \return true si l'ajout s'est correctement déroulé
         */
        bool setNom(QString nom);

        /*!
         * \brief méthode setId
         * Modifie l'identificateur de la branche
         * \param id : identificateur de la branche
         * \return true si l'ajout s'est correctement réalisé
         */
        bool setId(unsigned int id);


    protected:

        /*!
         * \brief m_id : identificateur de la branche
         */
        int m_id;

        /*!
         * \brief m_code : code de la branche
         */
        QString m_code;

        /*!
         * \brief m_nom : nom de la branche
         */
        QString m_nom;

    signals:

    public slots:

};

#endif // BRANCHE_H
