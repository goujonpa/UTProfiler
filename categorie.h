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
        std::string m_code;

    signals:

    public slots:

};

#endif // CATEGORIE_H
