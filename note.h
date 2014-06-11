#ifndef NOTE_H
#define NOTE_H

/*!
  * \file note.h
  * \brief Definition d'une note
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe Note
  */

#include <QObject>

/*!
 * \class Note
 * \brief The Note class
 * La classe qui représente une note
 */
class Note : public QObject
{
        Q_OBJECT

    public:

    /*!
         * \brief Constructeur par défaut de Note
         * \param parent : pointeur vers l'objet Note parent
         */
        explicit Note(QObject *parent = 0);

    /*!
         * \brief Constructeur de Note
         * \param id : identificateur de note
         * \param code : code associé à l'UV
         */
        Note(unsigned int id, QString code): m_id(id), m_code(code) {}

        /*!
         * \brief méthode getId
         * Récupère l'identificateur de la note
         * \return identificateur de la note
         */
        unsigned int getId() const {return m_id;}

        /*!
         * \brief méthode getCode
         * Récupère le code associé à l'UV
         * \return code associé à l'UV
         */
        QString getCode() const {return m_code;}

        /*!
         * \brief méthode setCode
         * Modifie le code
         * \param code : code associé à l'UV
         * \return true si l'ajout s'est correctement déroulé
         */
        bool setCode(QString code);
        bool setId(unsigned int id);

    protected:

        /*!
         * \brief m_id : identificateur de la note
         */
        unsigned int m_id;

        /*!
         * \brief m_code : code de la note
         */
        QString m_code;


    signals:

    public slots:

};

#endif // NOTE_H
