#ifndef SEMESTRE_H
#define SEMESTRE_H

#include <QObject>

enum Saison {Automne, Printemps};

class Semestre : public QObject
{
        Q_OBJECT

    public:

        explicit Semestre(QObject *parent = 0);
        Semestre(unsigned int id, Saison saison, unsigned int annee): m_id(id), m_saison(saison), m_annee(annee) {}
        unsigned int getId() const {return m_id;}
        Saison getSaison() const {return m_saison;}
        unsigned int getAnnee() const {return m_annee;}
        bool setSaison(Saison saison);
        bool setAnnee(unsigned int annee);

    protected:

        unsigned int m_id;
        Saison m_saison;
        unsigned int m_annee;

    signals:

    public slots:

};

#endif // SEMESTRE_H
