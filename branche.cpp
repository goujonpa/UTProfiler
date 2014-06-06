#include "branche.h"

Branche::Branche(QObject *parent) :
    QObject(parent)
{
}

bool Branche::setCode(QString code)
{
    m_code = code;
    return true;
}

bool Branche::setNom(QString nom)
{
    m_nom = nom;
    return true;
}
