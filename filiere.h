#ifndef FILIERE_H
#define FILIERE_H

/*!
  * \file filiere.h
  * \brief Definition d'une filière
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe Filiere
  */

#include <QObject>

/*!
 * \class Filiere
 * \brief The Filiere class
 * Classe qui représente une filière à l'UTC
 */
class Filiere : public QObject
{
        Q_OBJECT

    public:

    /*!
         * \brief Constructeur par défaut de Filiere
         * \param parent : pointeur vers l'objet parent
         */
        explicit Filiere(QObject *parent = 0);
    /*!
         * \brief Constructeur de Filiere
         * \param id : identificateur de la filière
         * \param code : code associé à la filière
         * \param nom : nom de la filière
         */
        Filiere(unsigned int id, QString code, QString nom): m_id(id), m_code(code), m_nom(nom) {}

        /*!
         * \brief méthode getId
         * Récupère l'identificateur de la filière
         * \return id de la filière
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getCode
         * Récupère le code de la filière
         * \return code de la filière
         */
        QString getCode() const {return m_code;}

        /*!
         * \brief méthode getNom
         * Récupère le nom de la filière
         * \return nom de la filière
         */
        QString getNom() const {return m_nom;}

        /*!
         * \brief méthode setCode
         * Modifie le code de la filière
         * \param code : code de la filière
         * \return true si l'ajout s'est déroulé correctement
         */
        bool setCode(QString code);

        /*!
         * \brief méthode setNom
         * Modifie le nom de la filière
         * \param nom : nom de la filière
         * \return true si l'ajout s'est déroulé correctement
         */
        bool setNom(QString nom);
        bool setId(unsigned int id);

    protected:

        /*!
         * \brief m_id : identificateur de la filière
         */
        unsigned int m_id;

        /*!
         * \brief m_code : code de la filière
         */
        QString m_code;

        /*!
         * \brief m_nom : nom de la filière
         */
        QString m_nom;

    signals:

    public slots:

};

#endif // FILIERE_H
