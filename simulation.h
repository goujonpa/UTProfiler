#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include "preference.h"
#include "inscription.h"
#include "cursus.h"

class Simulation : public QObject
{
        Q_OBJECT
    public:
        explicit Simulation(QObject *parent = 0);
    protected:
        int m_id;
        Preference* m_preference;
        Inscription** m_inscriptions;
        Cursus* m_cursus; // cursus visé.

    signals:

    public slots:

};

#endif // SIMULATION_H
