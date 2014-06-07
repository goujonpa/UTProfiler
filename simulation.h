#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include <QMap>
#include "preference.h"
#include "inscription.h"
#include "cursus.h"

class Simulation : public QObject
{
        Q_OBJECT

    public:

        explicit Simulation(QObject *parent = 0);
        Simulation(unsigned int id, Preference* pref, QMap<unsigned int, Inscription*> inscription, Cursus* cursus): m_id(id), m_preference(pref), m_inscriptions(inscription), m_cursus(cursus) {}
        unsigned int getId() const {return m_id;}
        Preference* getPreference() const {return m_preference;}
        QMap<unsigned int, Inscription*> getInscriptions() const {return m_inscriptions;}
        Cursus* getCursus() const {return m_cursus;}
        bool setPreference(Preference* pref);
        bool setInscriptions(QMap<unsigned int, Inscription*> inscr);
        bool setCursus(Cursus* cursus);
        bool addInscription(Inscription* inscription);


    protected:

        unsigned int m_id;
        Preference* m_preference;
        QMap<unsigned int, Inscription*> m_inscriptions;
        Cursus* m_cursus; // cursus visé.

    signals:

    public slots:

};

#endif // SIMULATION_H
