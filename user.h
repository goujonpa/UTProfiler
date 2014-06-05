#ifndef USER_H
#define USER_H

#include <QObject>
#include "simulation.h"
#include "profil.h"
#include "preference.h"

class User : public QObject
{
        Q_OBJECT
    public:
        explicit User(QObject *parent = 0);
    protected:
        int m_id;
        QString m_nom;
        QString m_prenom;
        Simulation* m_simulation;
        Profil* m_profil;
        Preference* m_preference;

    signals:

    public slots:

};

#endif // USER_H
