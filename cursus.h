#ifndef CURSUS_H
#define CURSUS_H

#include <QObject>
#include "branche.h"
#include "filiere.h"

class Cursus : public QObject
{
        Q_OBJECT

    public:

        explicit Cursus(QObject *parent = 0);
        Cursus(unsigned int id, Branche* branche, Filiere* filiere): m_id(id), m_branche(branche), m_filiere(filiere) {}
        unsigned int getId() const {return m_id;}
        Branche* getBranche() const {return m_branche;}
        Filiere* getFiliere() const {return m_filiere;}
        bool setBranche(Branche* branche);
        bool setFiliere(Filiere* filiere);
        bool setId(unsigned int);

    protected:

        unsigned int m_id;
        Branche* m_branche;
        Filiere* m_filiere;

    signals:

    public slots:

};

#endif // CURSUS_H
