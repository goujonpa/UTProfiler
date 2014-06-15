#ifndef INSCRIPTION_H
#define INSCRIPTION_H

/*!
  * \file inscription.h
  * \brief Definition d'une inscription
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe Inscription
  */

#include <QObject>
#include "uv.h"
#include "semestre.h"
#include "note.h"
#include "cursus.h"
#include "categorie.h"

/*!
 * \class Incription
 * \brief The Inscription class
 * La classe qui représente une inscription
 */
class Inscription : public QObject
{
        Q_OBJECT

    public:
    /*!
         * \brief Constructeur par défaut d'Inscription
         * \param parent : pointeur vers l'objet parent
         */
        explicit Inscription(QObject *parent = 0);

    /*!
         * \brief Constructeur d'Inscription
         * \param id : identificateur de l'inscription
         * \param uv : pointeur vers un objet UV
         * \param semestre : pointeur vers un objet Semestre
         * \param note : pointeur vers un objet Note
         * \param cursus : pointeur vers une objet Cursus
         * \param categorie : pointeur vers un objet Categorie
         */
        Inscription(unsigned int id, UV* uv, Semestre* semestre, Note* note, Cursus* cursus, Categorie* categorie): m_id(id), m_uv(uv), m_semestre(semestre), m_note(note), m_cursus(cursus), m_categorie(categorie) {}

        /*!
         * \brief méthode getId
         * Récupère l'identificateur de l'inscription
         * \return identificateur de l'inscription
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getUV
         * Récupère l'UV
         * \return pointeur vers UV
         */
        UV* getUV() const;

        /*!
         * \brief méthode getSemestre
         * Récupère le semestre
         * \return pointeur vers Semestre
         */
        Semestre* getSemestre() const;

        /*!
         * \brief méthode getNote
         * Récupère la note
         * \return pointeur vers Note
         */
        Note* getNote() const;

        /*!
         * \brief méthode getCursus
         * Récupère le cursus
         * \return pointeur vers Cursus
         */
        Cursus* getCursus() const;

        /*!
         * \brief méthode getCategorie
         * Récupère la catégorie
         * \return pointeur vers Categorie
         */
        Categorie* getCategorie() const;

        /*!
         * \brief méthode setUV
         * Modifie l'UV de l'inscription
         * \param uv : pointeur vers UV
         * \return true si l'ajout s'est correctement réalisé
         */
        bool setUV(UV* uv);

        /*!
         * \brief méthode setSemestre
         * Modifie le semestre de l'inscription
         * \param semestre : pointeur vers Semestre
         * \return true si l'ajout s'est correctement réalisé
         */
        bool setSemestre(Semestre* semestre);

        /*!
         * \brief méthode setNote
         * Modifie la note de l'inscription
         * \param note : pointeur vers Note
         * \return true si l'ajout s'est correctement réalisé
         */
        bool setNote(Note* note);

        /*!
         * \brief méthode setCursus
         * Modifie le cursus associé à l'inscription
         * \param cursus : pointeur vers Cursus
         * \return true si l'ajout s'est correctement réalisé
         */
        bool setCursus(Cursus* cursus);

        /*!
         * \brief méthode setCategorie
         * Modifie la catégorie associée à l'inscription
         * \param categorie : pointeur vers Categorie
         * \return true si l'ajout s'est correcement réalisé
         */
        bool setCategorie(Categorie* categorie);

        /*!
         * \brief méthode setId
         * Modifie l'identificateur d'une inscription
         * \param id: indentificateur d'inscription
         * \return true si l'ajout s'est correctement réalisé
         */
        bool setId(unsigned int id);

    protected:

        /*!
         * \brief m_id : identificateur de l'inscription
         */
        unsigned int m_id;

        /*!
         * \brief m_uv : pointeur vers l'UV de l'inscription
         */
        UV* m_uv;

        /*!
         * \brief m_semestre : pointeur vers le semestre de l'inscription
         */
        Semestre* m_semestre;

        /*!
         * \brief m_note : pointeur vers la note de l'inscription
         */
        Note* m_note;

        /*!
         * \brief m_cursus : pointeur vers le cursus de l'inscription
         */
        Cursus* m_cursus;

        /*!
         * \brief m_categorie : pointeur vers la catégorie de l'inscription
         */
        Categorie* m_categorie;



    signals:

    public slots:

};

#endif // INSCRIPTION_H
