#include "desiruv.h"

DesirUV::DesirUV(QObject *parent) :
    QObject(parent)
{
}

bool DesirUV::setUV(UV *uv)
{
    m_UV = uv;
    return true;
}

bool DesirUV::setSemestre(Semestre *semestre)
{
    m_semestre = semestre;
    return true;
}
