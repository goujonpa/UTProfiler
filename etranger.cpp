#include "etranger.h"

Etranger::Etranger(QObject *parent) :
    QObject(parent)
{
}

bool Etranger::setTitre(QString titre)
{
    m_titre = titre;
    return true;
}

bool Etranger::setSemestre(Semestre* semestre)
{
    m_semestre = semestre;
    return true;
}
