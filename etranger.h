#ifndef ETRANGER_H
#define ETRANGER_H

#include <QObject>
#include "semestre.h"

class Etranger : public QObject
{
        Q_OBJECT
    public:
        explicit Etranger(QObject *parent = 0);
    protected:
        int m_id;
        QString m_titre;
        Semestre* m_semestre;


    signals:

    public slots:

};

#endif // ETRANGER_H
