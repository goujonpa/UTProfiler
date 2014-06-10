#ifndef BRANCHE_H
#define BRANCHE_H

#include <QObject>

class Branche : public QObject
{
        Q_OBJECT

    public:

        explicit Branche(QObject *parent = 0);
        Branche(unsigned int id = 0, QString code = "", QString nom = ""): m_id(id), m_code(code), m_nom(nom) {}
        unsigned int getId() const {return m_id;}
        QString getCode() const {return m_code;}
        QString getNom() const {return m_nom;}
        bool setCode(QString code);
        bool setNom(QString nom);
        bool setId(unsigned int id);


    protected:

        int m_id;
        QString m_code;
        QString m_nom;

    signals:

    public slots:

};

#endif // BRANCHE_H
