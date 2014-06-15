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

bool DesirUV::setId(unsigned int id)
{
    m_id = id;
    return true;
}

UV* DesirUV::getUV() const
{
    if (m_UV == 0 || m_UV == NULL)
        return 0;
    return m_UV;
}

Semestre* DesirUV::getSemestre() const
{
    if (m_semestre == 0 || m_semestre == NULL)
        return 0;
    return m_semestre;
}
