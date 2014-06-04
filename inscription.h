#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QObject>

class Inscription : public QObject
{
        Q_OBJECT
    public:
        explicit Inscription(QObject *parent = 0);
    protected:
        int m_id;
        UV* m_uv;
        Semestre* m_semestre;
        Note* m_note;
        Cursus* m_cursus;
        Categorie* m_categorie;



    signals:

    public slots:

};

#endif // INSCRIPTION_H
