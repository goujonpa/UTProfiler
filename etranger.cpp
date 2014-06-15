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

bool Etranger::setId(unsigned int id)
{
    m_id = id;
    return true;
}

Semestre* Etranger::getSemestre() const
{
    if (m_semestre == 0 || m_semestre == NULL)
        return 0;
    return m_semestre;
}
