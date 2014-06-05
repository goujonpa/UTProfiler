#ifndef DESIRUV_H
#define DESIRUV_H

#include <QObject>
#include "semestre.h"
#include "uv.h"

class DesirUV : public QObject
{
        Q_OBJECT
    public:
        explicit DesirUV(QObject *parent = 0);
    protected:
        int m_id;
        UV* m_UV;
        Semestre* m_semestre;

    signals:

    public slots:

};

#endif // DESIRUV_H
