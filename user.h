#ifndef USER_H
#define USER_H

#include <QObject>
#include "simulation.h"
#include "profil.h"
#include "preference.h"

class User : public QObject
{
        Q_OBJECT

    public:

        explicit User(QObject *parent = 0);
        User(unsigned int id, QString nom, QString prenom, Simulation* simu, Profil* profil, Preference* pref): m_id(id), m_nom(nom), m_prenom(prenom), m_simulation(simu), m_profil(profil), m_preference(pref) {}
        unsigned int getId() const {return m_id;}
        QString getNom() const {return m_nom;}
        QString getPrenom() const {return m_prenom;}
        Simulation* getSimulation() const {return m_simulation;}
        Profil* getProfil() const {return m_profil;}
        Preference* getPreference() const {return m_preference;}
        bool setNom(QString nom);
        bool setPrenom(QString prenom);
        bool setSimulation(Simulation* simulation);
        bool setProfil(Profil* profil);
        bool setPreference(Preference* pref);

    protected:

        unsigned int m_id;
        QString m_nom;
        QString m_prenom;
        Simulation* m_simulation;
        Profil* m_profil;
        Preference* m_preference;

    signals:

    public slots:

};

#endif // USER_H
