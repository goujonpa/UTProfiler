#include "filiere.h"

Filiere::Filiere(QObject *parent) :
    QObject(parent)
{
}

bool Filiere::setCode(QString code)
{
    m_code = code;
    return true;
}

bool Filiere::setNom(QString nom)
{
    m_nom = nom;
    return true;
}

bool Filiere::setId(unsigned int id)
{
    m_id = id;
    return true;
}
