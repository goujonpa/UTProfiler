#ifndef CURSUS_H
#define CURSUS_H

/*!
  * \file cursus.h
  * \brief Définition d'un cursus
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe Cursus
  */

#include <QObject>
#include "branche.h"
#include "filiere.h"

/*!
 * \class Cursus
 * \brief The Cursus class
 * Classe qui représente un cursus à l'UTC
 */
class Cursus : public QObject
{
        Q_OBJECT

    public:

    /*!
         * \brief Constructeur par défaut de Cursus
         * \param parent : pointeur vers l'objet parent
         */
        explicit Cursus(QObject *parent = 0);

    /*!
         * \brief Constructeur de Cursus
         * \param id : identificateur de cursus
         * \param branche : pointeur vers la branche associée au cursus
         * \param filiere : pointeur vers la filière associée au cursus
         */
    Cursus(unsigned int id, Branche* branche, Filiere* filiere): m_id(id), m_branche(branche), m_filiere(filiere) {}

        /*!
         * \brief méthode getId
         * Récupère l'identificateur du cursus
         * \return identificateur du cursus
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getBranche
         * Récupère le pointeur vers la branche associée
         * \return true si l'ajout s'est correctement déroulé
         */
        Branche* getBranche() const {return m_branche;}

        /*!
         * \brief méthode getFiliere
         * Récupère le pointeur vers la filière associée
         * \return true si l'ajout s'est correctement déroulé
         */
        Filiere* getFiliere() const {return m_filiere;}

        /*!
         * \brief méthode setBranche
         * Modifie la branche associée au cursus
         * \param branche : pointeur vers branche
         * \return true si l'ajout s'est correctement déroulé
         */
        bool setBranche(Branche* branche);

        /*!
         * \brief méthode setFiliere
         * Modifie la filière associée au cursus
         * \param filiere : pointeur vers filière
         * \return true si l'ajout s'est correctement déroulé
         */
        bool setFiliere(Filiere* filiere);

        /*!
         * \brief méthode setId
         * Permet de modifier manuellement l'identificateur
         * \return true si l'ajout s'est correctement déroulé
         */
        bool setId(unsigned int);

    protected:

        /*!
         * \brief m_id : identificateur du cursus
         */
        unsigned int m_id;

        /*!
         * \brief m_branche : pointeur vers branche
         */
        Branche* m_branche;

        /*!
         * \brief m_filiere : pointeur vers filière
         */
        Filiere* m_filiere;

    signals:

    public slots:

};

#endif // CURSUS_H
