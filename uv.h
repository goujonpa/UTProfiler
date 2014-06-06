#ifndef UV_H
#define UV_H

#include <QObject>
#include "categorie.h"
#include "cursus.h"
#include "QVector"

class UV : public QObject
{
        Q_OBJECT

    public:

        explicit UV(QObject *parent = 0);
        UV(unsigned int id, QString code, unsigned int credits, Categorie* cat, QVector<Cursus*> cursus): m_id(id), m_code(code), m_credits(credits), m_categorie(cat), m_cursus(cursus) {}
        unsigned int getId() const {return m_id;}
        QString getCode() const {return m_code;}
        unsigned int getCredits() const {return m_credits;}
        Categorie* getCategorie() const {return m_categorie;}
        QVector<Cursus*> getCursus() const {return m_cursus;}
        bool setCode(QString code);
        bool setCredits(unsigned int credits);
        bool setCategorie(Categorie* cat);
        bool setCursus(QVector<Cursus*> cursus);
        bool addCursus(Cursus* cursus);

    protected:

        unsigned int m_id;
        QString m_code;
        unsigned int m_credits;
        Categorie* m_categorie;
        QVector<Cursus*> m_cursus;

        // Comment initialiser ces pointeurs ? Ne vaudrait-il pas mieux donner un "id" à chaque objet ?
        // (Certains objets étant des singletons). Ensuite les managers serviraient a remplir correctement chacun des objets.
        // On ne stockerait que des int dans m_cat et m_cursus

    signals:

    public slots:

};

#endif // UV_H
