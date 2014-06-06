#ifndef BONUSUV_H
#define BONUSUV_H

#include <QObject>
#include "uv.h"

class BonusUV : public QObject
{
        Q_OBJECT

    public:

        explicit BonusUV(QObject *parent = 0);
        BonusUV(unsigned int id, UV* uv, int bonus): m_id(id), m_UV(uv), m_bonus(bonus) {}
        unsigned int getId() const {return m_id;}
        UV* getUV() const {return m_UV;}
        int getBonus() const {return m_bonus;}
        bool setUV(UV* uv);
        bool setBonus(int bonus);

    protected:

        unsigned int m_id;
        UV* m_UV;
        int m_bonus;

    signals:

    public slots:

};

#endif // BONUSUV_H
