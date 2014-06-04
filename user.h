#ifndef USER_H
#define USER_H

#include <QObject>

class User : public QObject
{
        Q_OBJECT
    public:
        explicit User(QObject *parent = 0);
    protected:
        int m_id;
        QString m_nom;
        QString m_prenom;
        Simulation* m_simulation;
        Profil* m_profil;
        Preference* m_preference;

    signals:

    public slots:

};

#endif // USER_H
