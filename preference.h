#ifndef PREFERENCE_H
#define PREFERENCE_H

#include <QObject>
#include "etranger.h"
#include "desiruv.h"
#include "bonusuv.h"
#include <QList>

class Preference : public QObject
{
        Q_OBJECT

    public:

        explicit Preference(QObject *parent = 0);
        Preference(unsigned int id, QList<Etranger*> etranger, QList<DesirUV*> desirs, QList<BonusUV*> bonus): m_id(id), m_etrangers(etranger), m_desirs(desirs), m_bonus(bonus) {}
        unsigned int getId() const {return m_id;}
        QList<Etranger*> getEtranger() const {return m_etrangers;}
        QList<DesirUV*> getDesirs() const {return m_desirs;}
        QList<BonusUV*> getBonus() const {return m_bonus;}
        bool setEtrangers(QList<Etranger*> etranger);
        bool setDesirs(QList<DesirUV*> desirs);
        bool setBonus(QList<BonusUV*> bonus);
        bool addEtranger(Etranger* etranger);
        bool addDesir(DesirUV* desir);
        bool addBonus(BonusUV* bonus);
        bool removeEtranger(Etranger* etranger);
        bool removeDesir(DesirUV* desir);
        bool removeBonus(BonusUV* bonus);

    protected:

        unsigned int m_id;
        QList<Etranger*> m_etrangers;
        QList<DesirUV*> m_desirs;
        QList<BonusUV*> m_bonus;

    signals:

    public slots:

};

#endif // PREFERENCE_H
