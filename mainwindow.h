#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*!
  * \file mainwindow.h
  * \brief Definition de la fenêtre principale
  * \author Goujon & Cortyl
  * \date 15 juin 2014
  * \details Classe MainWindow
  */

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include "user.h"
#include "dbmanager.h"

/*!
 * \namespace Ui
 */
namespace Ui
{
    class MainWindow;
}

/*!
 * \class MainWindow
 * \brief The MainWindow class
 * La classe qui représente la fenêtre principale
 */
class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
    /*!
         * \brief Constructeur par défaut de MainWindow
         * \param parent : pointeur vers la MainWindow parent
         */
        explicit MainWindow(QWidget *parent = 0);
    /*!
         *\brief Destructeur de MainWindow
         */
        ~MainWindow();

        /*!
         * \brief méthode affiche
         * Affiche un message
         * \param message : message affiché
         */
        void affiche(QString message);


    private:
        Ui::MainWindow *ui;
        QWidget* zoneCenter;
        QGridLayout* mainLayout;
        QLabel* titre;
        QPushButton* Butt1;
        QPushButton* Butt2;
        QPushButton* Butt3;
        QPushButton* Butt4;
        QPushButton* Butt5;
        QPushButton* mainProfilButt;
        QPushButton* mainSimuButt;
        QPushButton* mainConfigButt;
        QLineEdit* le1;
        QLineEdit* le2;
        QPushButton* valider;
        QLabel* label1;
        QLabel* label2;
        DbManager* Db;


    public slots:
        void showProfilEdit();
        void hideProfilEdit();
        void showNewUserForm();
        void hideNewUserForm();
        void showConfigEdit();
        void hideConfigEdit();
        void showMessage(QString message);
        void test();

};

#endif // MAINWINDOW_H
