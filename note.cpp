#include "note.h"

Note::Note(QObject *parent) :
    QObject(parent)
{
}

bool Note::setCode(QString code)
{
    m_code = code;
    return true;
}

bool Note::setId(unsigned int id)
{
    m_id = id;
    return true;
}
