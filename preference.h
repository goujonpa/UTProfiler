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

    protected:

        unsigned int m_id;
        QVector<Etranger*> m_etrangers;
        QList<DesirUV*> m_desirs;
        QList<BonusUV*> m_bonus;

    signals:

    public slots:

};

#endif // PREFERENCE_H
