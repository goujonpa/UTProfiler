#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QObject>

class Categorie : public QObject
{
        Q_OBJECT

    public:

        explicit Categorie(QObject *parent = 0);
        Categorie(unsigned int id, QString code, QString nom = ""): m_id(id), m_code(code), m_nom(nom) {}
        unsigned int getId() const {return m_id;}
        QString getCode() const {return m_code;}
        QString getNom() const {return m_nom;}
        bool setCode(QString code);
        bool setNom(QString nom);
        bool setId(unsigned int id);

    protected:

        unsigned int m_id;
        QString m_code;
        QString m_nom;

    signals:

    public slots:

};

#endif // CATEGORIE_H
