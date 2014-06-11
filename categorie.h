#ifndef CATEGORIE_H
#define CATEGORIE_H

/*!
  * \file categorie.h
  * \brief Définition d'une catégorie d'UV
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe Categorie
  */

#include <QObject>

/*!
 * \class Categorie
 * \brief The Categorie class
 * Représente les catégorie d'UV à l'UTC
 */
class Categorie : public QObject
{
        Q_OBJECT

    public:

    /*!
         * \brief Constructeur par défaut de Categorie
         * \param parent : pointeur vers l'objet parent
         */
        explicit Categorie(QObject *parent = 0);

    /*!
         * \brief Constructeur de Categorie
         * \param id : identificateur de Categorie
         * \param code : code de la catégorie d'UV
         * \param nom : Nom détaillé de la catégorie
         */
        Categorie(unsigned int id, QString code, QString nom = ""): m_id(id), m_code(code), m_nom(nom) {}

        /*!
         * \brief méthode getId
         * Récupère l'identificateur de la catégorie
         * \return identificateur de la catégorie
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getCode
         * Récupère le code de la catégorie
         * \return code de la catégorie
         */
        QString getCode() const {return m_code;}

        /*!
         * \brief méthode getNom
         * R2cupère le nom détaillé de la catégorie
         * \return nom de la catégorie
         */
        QString getNom() const {return m_nom;}

        /*!
         * \brief méthode setCode
         * Modifie le code de la catégorie
         * \param code : code de l'UV
         * \return true si l'ajout s'est correctement déroulé
         */
        bool setCode(QString code);

        /*!
         * \brief méthode setNom
         * Modifie le nom de la catégorie
         * \param nom : nom de la catégorie
         * \return true si l'ajout s'est correctement déroulé
         */
        bool setNom(QString nom);

        /*!
         * \brief méthode setId
         * Modifie l'identificateur de la catégorie
         * \param id : identificateur
         * \return true si l'ajout s'est correctement déroulé
         */
        bool setId(unsigned int id);

    protected:

        /*!
         * \brief m_id : identificateur de la catégorie
         */
        unsigned int m_id;

        /*!
         * \brief m_code : code de la catégorie
         */
        QString m_code;

        /*!
         * \brief m_nom : nom de la catégorie
         */
        QString m_nom;

    signals:

    public slots:

};

#endif // CATEGORIE_H
