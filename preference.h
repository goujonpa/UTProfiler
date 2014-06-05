#ifndef PREFERENCE_H
#define PREFERENCE_H

#include <QObject>
#include "etranger.h"
#include "desiruv.h"
#include "bonusuv.h"

class Preference : public QObject
{
        Q_OBJECT
    public:
        explicit Preference(QObject *parent = 0);
    protected:
        int m_id;
        Etranger** m_etrangers;
        DesirUV** m_desirs;
        BonusUV** m_bonus;

    signals:

    public slots:

};

#endif // PREFERENCE_H
