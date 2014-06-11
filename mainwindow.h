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
#include <QSqlQueryModel>
#include <QTableView>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QVariant>
#include <QStandardItemModel>
#include "user.h"
#include "filiere.h"
#include "branche.h"
#include "cursus.h"
#include "dbmanager.h"
#include "xmlmanager.h"

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
        void showUser();
        void stop(QWidget* obj);



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
        QPushButton* Butt6;
        QPushButton* Butt7;
        QPushButton* Butt8;
        QPushButton* Butt9;
        QPushButton* mainProfilButt;
        QPushButton* mainSimuButt;
        QPushButton* mainConfigButt;
        QLineEdit* le1;
        QLineEdit* le2;
        QPushButton* valider;
        QLabel* label1;
        QLabel* label2;
        QLabel* label3;
        QLabel* label4;
        QLabel* label5;
        QLabel* label6;
        QLabel* label7;
        QLabel* label8;
        QLabel* label9;
        QLabel* label10;
        QLabel* label11;
        QLabel* label12;
        QStandardItemModel* stdItMod1;
        DbManager* Db;
        User* user = NULL;
        Branche* branche = NULL;
        Categorie* categorie = NULL;
        Filiere* filiere = NULL;
        Cursus* cursus = NULL;
        UV* uv = NULL;
        QSqlQueryModel* sqlModel1;
        QSqlQueryModel* sqlModel2;
        QTableView* tableView1;
        QTableView* tableView2;
        XmlManager* xml;


    public slots:

        void clear();

        void showProfilEdit();
        void showNewUserForm();
        void showConfigEdit();
        void showUserList();
        void showNewBranchForm();
        void showBranchList();
        void showNewCatForm();
        void showCatList();
        void showNewFiliereForm();
        void showFiliereList();
        void showNewCursusForm();
        void showUVList();

        void selectUser();

        void valideNewUserForm();
        void valideNewBranchForm();
        void valideNewCatForm();
        void valideNewFiliereForm();
        void valideNewCursusForm();

        void test();
        bool openDb();
        bool deleteDb();
        bool createTables();



};

#endif // MAINWINDOW_H
