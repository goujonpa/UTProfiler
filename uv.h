#ifndef UV_H
#define UV_H

#include <QObject>

class UV : public QObject
{
        Q_OBJECT
    public:
        explicit UV(QObject *parent = 0);
    protected:
        int m_id;
        QString m_code;
        int m_credits;
        Categorie* m_categorie;
        Cursus** m_cursus;

        // Comment initialiser ces pointeurs ? Ne vaudrait-il pas mieux donner un "id" à chaque objet ?
        // (Certains objets étant des singletons). Ensuite les managers serviraient a remplir correctement chacun des objets.
        // On ne stockerait que des int dans m_cat et m_cursus

    signals:

    public slots:

};

#endif // UV_H
