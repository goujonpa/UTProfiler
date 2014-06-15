/*!
 * \file main.cpp
 * \brief Main du programme
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Programme qui permet à un étudiant de simuler des inscriptions et lui propose des
 * matières à suivre suivant son cursus, ses matières déjà suivits et ses objetifs en
 * termes de branche/filière/semestre à l'étranger.
 *
 */

#include "mainwindow.h"
#include <QApplication>
#include "profil.h"
#include <iostream>

/*!
 * \brief fonction main
 * Coeur du programme
 * \param argc
 * \param argv
 * \return ouverture
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
