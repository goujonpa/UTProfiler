#ifndef PROFIL_H
#define PROFIL_H

#include <QObject>
#include <QMap>
#include "inscription.h"
#include "cursus.h"
#include "etranger.h"

class Profil : public QObject
{
        Q_OBJECT

    public:

        Profil(unsigned int id, QMap<unsigned int, Inscription*> insc, Cursus* actuel, Cursus* vise, QMap<unsigned int, Etranger*> etr): m_id(id), m_inscriptions(insc), m_actuel(actuel), m_vise(vise), m_etranger(etr) {}
        explicit Profil(QObject *parent = 0);
        unsigned int getId() const {return m_id;}
        QMap<unsigned int, Inscription*> getInscriptions() const {return m_inscriptions;}
        Cursus* getActuel() const {return m_actuel;}
        Cursus* getVise() const {return m_vise;}
        QMap<unsigned int, Etranger*> getEtranger() {return m_etranger;}
        bool setInscriptions(QMap<unsigned int, Inscription*> insc);
        bool addInscription(Inscription* insc);
        bool setActuel(Cursus* actuel);
        bool setVise(Cursus* vise);
        bool setEtranger(QMap<unsigned int, Etranger*> etr);
        bool addEtranger(Etranger* etr);



    protected:
        unsigned int m_id;
        QMap<unsigned int, Inscription*> m_inscriptions;
        Cursus* m_actuel;
        Cursus* m_vise;
        QMap<unsigned int, Etranger*> m_etranger;

    signals:

    public slots:

};

#endif // PROFIL_H
