#ifndef FILIERE_H
#define FILIERE_H

#include <QObject>

class Filiere : public QObject
{
        Q_OBJECT
    public:
        explicit Filiere(QObject *parent = 0);
    protected:
        int m_id;
        QString m_code;
        QString m_nom;

    signals:

    public slots:

};

#endif // FILIERE_H
