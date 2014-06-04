#ifndef CURSUS_H
#define CURSUS_H

#include <QObject>
#include "branche.h"
#include "filiere.h"

class Cursus : public QObject
{
        Q_OBJECT
    public:
        explicit Cursus(QObject *parent = 0);
    protected:
        int m_id;
        Branche* m_branche;
        Filiere* m_filiere;

    signals:

    public slots:

};

#endif // CURSUS_H
