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
