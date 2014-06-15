/*!
 * \file note.cpp
 * \brief Méthodes de la classe Note
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe Note
 *
 */

#include "note.h"

/*!
 * \brief constructeur par défaut Note::Note
 * \param parent : pointeur vers l'objet parent
 */
Note::Note(QObject *parent) :
    QObject(parent)
{
}

/*!
 * \brief méthode Note::setCode
 * \param code : code de l'uv
 * \return true si l'ajout s'est bien réalisé
 */
bool Note::setCode(QString code)
{
    m_code = code;
    return true;
}

/*!
 * \brief méthode Note::setId
 * \param id : identificateur de la note
 * \return :true si l'ajout s'est bien réalisé
 */
bool Note::setId(unsigned int id)
{
    m_id = id;
    return true;
}
