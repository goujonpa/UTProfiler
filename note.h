#ifndef NOTE_H
#define NOTE_H

#include <QObject>

class Note : public QObject
{
        Q_OBJECT
    public:
        explicit Note(QObject *parent = 0);
    protected:
        int m_id;
        QString m_code;


    signals:

    public slots:

};

#endif // NOTE_H
