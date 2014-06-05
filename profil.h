#ifndef PROFIL_H
#define PROFIL_H

#include <QObject>
#include "inscription.h"
#include "cursus.h"
#include "etranger.h"

class Profil : public QObject // sera singleton
{
        Q_OBJECT
    public:
        explicit Profil(QObject *parent = 0);
    protected:
        int m_id;
        Inscription** m_inscriptions;
        Cursus* m_actuel;
        Cursus* m_vise;
        Etranger** m_etranger;

    signals:

    public slots:

};

#endif // PROFIL_H
