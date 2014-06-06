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
