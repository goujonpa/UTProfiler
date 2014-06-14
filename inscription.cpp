#include "inscription.h"

Inscription::Inscription(QObject *parent) :
    QObject(parent)
{
}

bool Inscription::setUV(UV* uv)
{
    m_uv = uv;
    return true;
}

bool Inscription::setSemestre(Semestre* semestre)
{
    m_semestre = semestre;
    return true;
}

bool Inscription::setNote(Note* note)
{
    m_note = note;
    return true;
}

bool Inscription::setCursus(Cursus* cursus)
{
    m_cursus = cursus;
    return true;
}

bool Inscription::setCategorie(Categorie* categorie)
{
    m_categorie = categorie;
    return true;
}

bool Inscription::setId(unsigned int id)
{
    m_id = id;
    return true;
}

UV* Inscription::getUV() const
{
    if (m_uv == 0 || m_uv == NULL)
        return 0;
    return m_uv;
}

Semestre* Inscription::getSemestre() const
{
    if (m_semestre == 0 || m_semestre == NULL)
        return 0;
    return m_semestre;
}

Note* Inscription::getNote() const
{
    if (m_note == 0 || m_note == NULL)
        return 0;
    return m_note;
}

Cursus* Inscription::getCursus() const
{
    if (m_cursus == 0 || m_cursus == NULL)
        return 0;
    return m_cursus;
}

Categorie*  Inscription::getCategorie() const
{
    if (m_categorie == 0 || m_categorie == NULL)
        return 0;
    return m_categorie;
}
