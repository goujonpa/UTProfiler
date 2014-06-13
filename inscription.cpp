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
