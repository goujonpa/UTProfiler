/*!
 * \file categorie.cpp
 * \brief Méthodes de la classe Categorie
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe Categorie
 *
 */

#include "categorie.h"

Categorie::Categorie(QObject *parent) :
    QObject(parent)
{
}


bool Categorie::setCode(QString code)
{
    m_code = code;
    return true;
}

bool Categorie::setNom(QString nom)
{
    m_nom = nom;
    return true;
}

bool Categorie::setId(unsigned int id)
{
    m_id = id;
    return true;
}
