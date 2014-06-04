#ifndef SEMESTRE_H
#define SEMESTRE_H

#include <QObject>

enum Saison {Automne, Printemps};

class Semestre : public QObject
{
        Q_OBJECT
    public:
        explicit Semestre(QObject *parent = 0);
    protected:
        int m_id;
        Saison m_saison;
        int m_annee;

    signals:

    public slots:

};

#endif // SEMESTRE_H
