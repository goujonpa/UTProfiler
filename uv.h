#ifndef UV_H
#define UV_H

/*!
  * \file uv.h
  * \brief Definition d'une UV de base
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe UV
  */


#include <QObject>
#include "categorie.h"
#include "cursus.h"
#include <QMap>

/*!
 * \class UV
 * \brief The UV class
 *
 * La classe UV qui représente une Unité de Valeur à l'UTC
 */

class UV : public QObject
{
        Q_OBJECT

    public:

    /*!
         * \brief Constructeur par défaut d'UV
         * \param parent : pointeur vers l'objet parent
         */
        explicit UV(QObject *parent = 0);

    /*!
         * \brief Constructeur UV
         * Constructeur de la classe UV
         * \param id : identificateur de l'UV
         * \param code : code UV
         * \param credits : nombre de credits
         * \param cat : catégorie de l'UV
         * \param cursus : cursus associé
        */
        UV(unsigned int id, QString code, unsigned int credits, Categorie* cat, QMap<unsigned int, Cursus*> cursus): m_id(id), m_code(code), m_credits(credits), m_categorie(cat), m_cursus(cursus) {}

        /*!
         * \brief méthode getId
         * Récupère la valeur de l'identificateur
         * \return la valeur de l'identificateur
        */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getCode
         * Récupère le code de l'UV
         * \return le code UV
         */
        QString getCode() const {return m_code;}

        /*!
         * \brief méthode getCredits
         * Récupère le nombre de crédits
         * \return le nombre de crédits
         */
        unsigned int getCredits() const {return m_credits;}

        /*!
         * \brief méthode getCategorie
         * Récupère la catégorie de l'UV
         * \return la catégorie
         */
        Categorie* getCategorie() const {return m_categorie;}

        /*!
         * \brief méthode getCursus
         * Récupère le cursus
         * \return le cursus associé
         */
        QMap<unsigned int, Cursus*> getCursus() const {return m_cursus;}

        bool setId(unsigned int id);


        /*!
         * \brief méthode setCode
         * Modifie le code de l'UV
         * \param code : code de l'UV
         * \return true si l'ajout s'est bien réalisé
         */
        bool setCode(QString code);

        /*!
         * \brief méthode setCredits
         * Modifie le nombre de crédits
         * \param credits : numéro de crédits
         * \return true si l'ajout s'est bien réalisé
         */
        bool setCredits(unsigned int credits);

        /*!
         * \brief méthode setCategorie
         * Modifie la catégorie
         * \param cat : catégorie de l'UV
         * \return true si l'ajout s'est bien réalisé
         */
        bool setCategorie(Categorie* cat);

        /*!
         * \brief méthode setCursus
         * Modifie le cursus associé
         * \param cursus : cursus associé
         * \return true si l'ajout s'est bien réalisé
         */
        bool setCursus(QMap<unsigned int, Cursus*> cursus);

        /*!
         * \brief méthode addCursus
         * Ajoute un cursus
         * \param cursus : cursus à ajouter
         * \return true si l'ajout s'est bien réalisé
         */
        bool addCursus(Cursus* cursus);

    protected:

        /*!
         * \brief m_id : identificateur de l'UV
         */
        unsigned int m_id;

        /*!
         * \brief m_code : code de l'UV
         */
        QString m_code;

        /*!
         * \brief m_credits : nombre de crédits de l'UV
         */
        unsigned int m_credits;

        /*!
         * \brief m_categorie : catégorie de l'UV
         */
        Categorie* m_categorie;

        /*!
         * \brief m_cursus : cursus associé à l'UV
         */
        QMap<unsigned int, Cursus*> m_cursus;

        // Comment initialiser ces pointeurs ? Ne vaudrait-il pas mieux donner un "id" à chaque objet ?
        // (Certains objets étant des singletons). Ensuite les managers serviraient a remplir correctement chacun des objets.
        // On ne stockerait que des int dans m_cat et m_cursus

    signals:

    public slots:

};

#endif // UV_H
