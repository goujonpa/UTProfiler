#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QObject>

class Categorie : public QObject
{
        Q_OBJECT
    public:
        explicit Categorie(QObject *parent = 0);
    protected:
        int m_id;
        QString m_code;
        QString m_nom;

    signals:

    public slots:

};

#endif // CATEGORIE_H
