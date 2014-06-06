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
        DesirUV(unsigned int id, UV* uv, Semestre* semestre): m_id(id), m_UV(uv), m_semestre(semestre) {}
        unsigned int getId() const {return m_id;}
        UV* getUV() const {return m_UV;}
        Semestre* getSemestre() const {return m_semestre;}
        bool setUV(UV* uv);
        bool setSemestre(Semestre* semestre);

    protected:

        unsigned int m_id;
        UV* m_UV;
        Semestre* m_semestre;

    signals:

    public slots:

};

#endif // DESIRUV_H
