#ifndef NOTE_H
#define NOTE_H

#include <QObject>

class Note : public QObject
{
        Q_OBJECT

    public:

        explicit Note(QObject *parent = 0);
        Note(unsigned int id, QString code): m_id(id), m_code(code) {}
        unsigned int getID() const {return m_id;}
        QString getCode() const {return m_code;}
        bool setCode(QString code);

    protected:

        unsigned int m_id;
        QString m_code;


    signals:

    public slots:

};

#endif // NOTE_H
