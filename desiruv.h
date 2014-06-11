#ifndef DESIRUV_H
#define DESIRUV_H

/*!
  * \file desiruv.h
  * \brief Choix d'UV ; permet à l'utilisateur d'exprimer un voeu d'UV
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe DesirUV
  */

#include <QObject>
#include "semestre.h"
#include "uv.h"

/*!
 * \class DesirUV
 * \brief The DesirUV class
 * Choix d'UV ; permet à l'utilisateur d'exprimer un voeu d'UV
 */
class DesirUV : public QObject
{
        Q_OBJECT

    public:

    /*!
         * \brief Constructeur par défaut de DesirUV
         * \param parent : pointeur vers l'objet parent
         */
        explicit DesirUV(QObject *parent = 0);
    /*!
         * \brief Constructeur DesirUV
         * \param id : identificateur d'une desir d'uv
         * \param uv : pointeur vers une UV
         * \param semestre : pointeur vers un semestre
         */
        DesirUV(unsigned int id, UV* uv, Semestre* semestre): m_id(id), m_UV(uv), m_semestre(semestre) {}

        /*!
         * \brief méthode getId
         * Récupère l'identificateur de desirUV
         * \return identificateur de desirUV
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getUV
         * Récupère l'UV désirée
         * \return pointeur vers UV
         */
        UV* getUV() const {return m_UV;}

        /*!
         * \brief méthode getSemestre
         * Récupère le semestre durant lequel un utilisateur souhaite faire l'UV
         * \return pointeur vers semestre
         */
        Semestre* getSemestre() const {return m_semestre;}

        /*!
         * \brief méthode setUV
         * Modifie l'UV désirée
         * \param uv : pointeur vers UV
         * \return true si l'ajout s'est correctement réalisé
         */
        bool setUV(UV* uv);

        /*!
         * \brief méthode setSemestre
         * Modifie le semestre durant lequel l'utilisateur souhaite faire l'UV
         * \param semestre : pointeur vers semestre
         * \return true si l'ajout s'est correctement réalisé
         */
        bool setSemestre(Semestre* semestre);

    protected:

        /*!
         * \brief m_id : indentificateur de desirUV
         */
        unsigned int m_id;

        /*!
         * \brief m_UV : pointeur vers l'UV désirée
         */
        UV* m_UV;

        /*!
         * \brief m_semestre : pointeur vers le semestre durant lequel l'utilisateur souhaite faire l'UV
         */
        Semestre* m_semestre;

    signals:

    public slots:

};

#endif // DESIRUV_H
