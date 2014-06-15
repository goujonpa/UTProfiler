#ifndef MANAGER_H
#define MANAGER_H

/*!
  * \file manager.h
  * \brief Definition d'un manager
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe Manager
  */

#include <QObject>

/*!
 * \class Manager
 * \brief The Manager class
 * La classe qui représente un manager
 */
class Manager : public QObject
{
        Q_OBJECT

    public:
    /*!
         * \brief Constructeur par défaut de Manager
         * \param parent : pointeur vers l'objet parent
         */
        explicit Manager(QObject *parent = 0);


    protected:



    signals:

    public slots:

};




#endif // MANAGER_H
