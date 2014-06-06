#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QObject>
#include "uv.h"
#include "semestre.h"
#include "note.h"
#include "cursus.h"
#include "categorie.h"

class Inscription : public QObject
{
        Q_OBJECT

    public:

        explicit Inscription(QObject *parent = 0);
        Inscription(unsigned int id, UV* uv, Semestre* semestre, Note* note, Cursus* cursus, Categorie* categorie): m_id(id), m_uv(uv), m_semestre(semestre), m_note(note), m_cursus(cursus), m_categorie(categorie) {}
        unsigned int getId() const {return m_id;}
        UV* getUV() const {return m_uv;}
        Semestre* getSemestre() const {return m_semestre;}
        Note* getNote() const {return m_note;}
        Cursus* getCursus() const {return m_cursus;}
        Categorie* getCategorie() const {return m_categorie;}
        bool setUV(UV* uv);
        bool setSemestre(Semestre* semestre);
        bool setNote(Note* note);
        bool setCursus(Cursus* cursus);
        bool setCategorie(Categorie* categorie);

    protected:

        unsigned int m_id;
        UV* m_uv;
        Semestre* m_semestre;
        Note* m_note;
        Cursus* m_cursus;
        Categorie* m_categorie;



    signals:

    public slots:

};

#endif // INSCRIPTION_H
