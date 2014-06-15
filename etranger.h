#ifndef ETRANGER_H
#define ETRANGER_H

/*!
  * \file etranger.h
  * \brief Definition d'un semestre à l'étranger
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe Etranger
  */


#include <QObject>
#include "semestre.h"

/*!
 * \class Etranger
 * \brief The Etranger class
 * Classe qui représente un semestre passé à l'étranger
 */
class Etranger : public QObject
{
        Q_OBJECT

    public:

    /*!
         * \brief Constructeur par défaut d'Etranger
         * \param parent : pointeur vers l'objet parent
         */
        explicit Etranger(QObject *parent = 0);

    /*!
         * \brief Constructeur d'Etranger
         * \param id : identificateur d'etranger
         * \param titre : titre donné au semestre etranger
         * \param semestre : pointeur vers un semestre
         */
        Etranger(unsigned int id, QString titre, Semestre* semestre): m_id(id), m_titre(titre), m_semestre(semestre) {}

        /*!
         * \brief méthode getId
         * Récupère l'identificateur d'etranger
         * \return id etranger
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getTitre
         * Récupère l'intitulé du semestre
         * \return intitulé du semestre
         */
        QString getTitre() const {return m_titre;}

        /*!
         * \brief méthode getSemestre
         * Récupère le semestre
         * \return pointeur vers semestre
         */
        Semestre* getSemestre() const;


        /*!
         * \brief méthode setTitre
         * Modifie l'intitulé du semestre
         * \param titre : intitulé du semestre
         * \return true si l'ajout s'est correctement déroulé
         */
        bool setTitre(QString titre);

        /*!
         * \brief méthode setSemestre
         * Modifie le semestre
         * \param semestre : pointeur vers semestre
         * \return true si l'ajout s'est correctement déroulé
         */
        bool setSemestre(Semestre* semestre);
        bool setId(unsigned int id);


    protected:

        /*!
         * \brief m_id : identificateur de semestre à l'étranger
         */
        unsigned int m_id;

        /*!
         * \brief m_titre : nom du semestre à l'étranger
         */
        QString m_titre;

        /*!
         * \brief m_semestre : pointeur vers le semestre
         */
        Semestre* m_semestre;


    signals:

    public slots:

};

#endif // ETRANGER_H
