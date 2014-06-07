#ifndef PREFERENCE_H
#define PREFERENCE_H

#include <QObject>
#include "etranger.h"
#include "desiruv.h"
#include "bonusuv.h"
#include <QMap>

class Preference : public QObject
{
        Q_OBJECT

    public:

        explicit Preference(QObject *parent = 0);
        Preference(unsigned int id, QMap<unsigned int, Etranger*> etranger, QMap<unsigned int, DesirUV*> desirs, QMap<unsigned int, BonusUV*> bonus): m_id(id), m_etrangers(etranger), m_desirs(desirs), m_bonus(bonus) {}
        unsigned int getId() const {return m_id;}
        QMap<unsigned int, Etranger*> getEtranger() const {return m_etrangers;}
        QMap<unsigned int, DesirUV*> getDesirs() const {return m_desirs;}
        QMap<unsigned int, BonusUV*> getBonus() const {return m_bonus;}
        bool setEtrangers(QMap<unsigned int, Etranger*> etranger);
        bool setDesirs(QMap<unsigned int, DesirUV*> desirs);
        bool setBonus(QMap<unsigned int, BonusUV*> bonus);
        bool addEtranger(Etranger* etranger);
        bool addDesir(DesirUV* desir);
        bool addBonus(BonusUV* bonus);
        bool removeEtranger(Etranger* etranger);
        bool removeDesir(DesirUV* desir);
        bool removeBonus(BonusUV* bonus);

    protected:

        unsigned int m_id;
        QMap<unsigned int, Etranger*> m_etrangers;
        QMap<unsigned int, DesirUV*> m_desirs;
        QMap<unsigned int, BonusUV*> m_bonus;

    signals:

    public slots:

};

#endif // PREFERENCE_H
