#ifndef PROFIL_H
#define PROFIL_H

#include <QObject>
#include <QMap>
#include "inscription.h"
#include "cursus.h"
#include "etranger.h"
#include "desiruv.h"
#include "bonusuv.h"


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

        QMap<unsigned int, Etranger*> getPrefEtranger() const {return m_prefEtrangers;}
        QMap<unsigned int, DesirUV*> getDesirs() const {return m_desirs;}
        QMap<unsigned int, BonusUV*> getBonus() const {return m_bonus;}
        bool setPrefEtrangers(QMap<unsigned int, Etranger*> etranger);
        bool setDesirs(QMap<unsigned int, DesirUV*> desirs);
        bool setBonus(QMap<unsigned int, BonusUV*> bonus);
        bool addPrefEtranger(Etranger* etranger);
        bool addDesir(DesirUV* desir);
        bool addBonus(BonusUV* bonus);
        bool removePrefEtranger(Etranger* etranger);
        bool removeDesir(DesirUV* desir);
        bool removeBonus(BonusUV* bonus);



    protected:
        unsigned int m_id;
        QMap<unsigned int, Inscription*> m_inscriptions;
        Cursus* m_actuel;
        Cursus* m_vise;
        QMap<unsigned int, Etranger*> m_etranger;
        QMap<unsigned int, Etranger*> m_prefEtrangers;
        QMap<unsigned int, DesirUV*> m_desirs;
        QMap<unsigned int, BonusUV*> m_bonus;

    signals:

    public slots:

};

#endif // PROFIL_H
