#ifndef BONUSUV_H
#define BONUSUV_H

#include <QObject>
#include "uv.h"

class BonusUV : public QObject
{
    Q_OBJECT
public:
    explicit BonusUV(QObject *parent = 0);
protected:
    int m_id;
    UV* m_UV;
    int m_bonus;

signals:

public slots:

};

#endif // BONUSUV_H
