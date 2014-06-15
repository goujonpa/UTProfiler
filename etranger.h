#ifndef ETRANGER_H
#define ETRANGER_H

#include <QObject>
#include "semestre.h"

class Etranger : public QObject // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Ajouter les crédits prévus, par catégorie !!!!!!!!!!!!!!!!!
{
        Q_OBJECT

    public:

        explicit Etranger(QObject *parent = 0);
        Etranger(unsigned int id, QString titre, Semestre* semestre): m_id(id), m_titre(titre), m_semestre(semestre) {}
        unsigned int getId() const {return m_id;}
        QString getTitre() const {return m_titre;}
        Semestre* getSemestre() const;
        bool setTitre(QString titre);
        bool setSemestre(Semestre* semestre);
        bool setId(unsigned int id);


    protected:

        unsigned int m_id;
        QString m_titre;
        Semestre* m_semestre;


    signals:

    public slots:

};

#endif // ETRANGER_H
