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
class Etranger : public QObject // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Ajouter les crédits prévus, par catégorie !!!!!!!!!!!!!!!!!
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
         * \brief getTitre
         * \return
         */
        QString getTitre() const {return m_titre;}
        Semestre* getSemestre() const {return m_semestre;}
        bool setTitre(QString titre);
        bool setSemestre(Semestre* semestre);

    protected:

        unsigned int m_id;
        QString m_titre;
        Semestre* m_semestre;


    signals:

    public slots:

};

#endif // ETRANGER_H
