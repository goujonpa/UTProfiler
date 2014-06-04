#ifndef BRANCHE_H
#define BRANCHE_H

#include <QObject>

class Branche : public QObject
{
        Q_OBJECT
    public:
        explicit Branche(QObject *parent = 0);
    protected:
        int m_id;
        QString m_code;
        QString m_nom;

    signals:

    public slots:

};

#endif // BRANCHE_H
