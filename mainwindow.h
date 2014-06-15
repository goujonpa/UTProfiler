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
#include <QCheckBox>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QVariant>
#include <QStandardItemModel>
#include <QComboBox>
#include <QDialog>
#include <semestre.h>
#include <QProgressBar>
#include "user.h"
#include "filiere.h"
#include "branche.h"
#include "cursus.h"
#include "dbmanager.h"
#include "note.h"
#include "uv.h"
#include "categorie.h"
#include"semestre.h"
#include "inscription.h"
#include "xmlmanager.h"
#include <QSlider>

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
        void stop(QWidget* obj);
        QTableView* getUvView();
        QTableView* getNoteView();
        QTableView* getBrancheView();
        QTableView* getFiliereView();
        QTableView* getBrancheView2();
        QTableView* getFiliereView2();


    private:
        Ui::MainWindow *ui;
        QWidget* zoneCenter;
        QGridLayout* mainLayout;
        QGridLayout* layout1;
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
        QPushButton* Butt10;
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
        QComboBox* combo1;
        QStandardItemModel* stdItMod1;
        QStandardItemModel* stdItMod2;
        QStandardItemModel* stdItMod3;
        DbManager* Db;
        User* user = NULL;
        Branche* branche = NULL;
        Categorie* categorie = NULL;
        Filiere* filiere = NULL;
        Cursus* cursus = NULL;
        Cursus* cursus2 = NULL;
        UV* uv = NULL;
        Note* note = NULL;
        Semestre* semestre = NULL;
        Inscription* inscription = NULL;
        Profil* profil = NULL;
        QSqlQueryModel* sqlModel1;
        QSqlQueryModel* sqlModel2;
        QSqlQueryModel* sqlModel3;
        QSqlQueryModel* sqlModel4;
        QTableView* tableView1;
        QTableView* tableView2;
        QTableView* tableView3;
        QTableView* tableView4;
        QTableView* utableView;
        QDialog* dialog1;
        QProgressBar* progress1;
        XmlManager* xml;
        QSlider* slider1;


        // ===== Ajout Cursus Form =====

        // ===== Branches ===========

        QCheckBox* c1;
        QCheckBox* c2;
        QCheckBox* c3;
        QCheckBox* c4;
        QCheckBox* c5;
        QCheckBox* c6;
        QCheckBox* c7;
        QCheckBox* c8;

        // ===== Filieres ============

        QCheckBox* c9;
        QCheckBox* c10;
        QCheckBox* c11;
        QCheckBox* c12;
        QCheckBox* c13;
        QCheckBox* c14;
        QCheckBox* c15;
        QCheckBox* c16;
        QCheckBox* c17;
        QCheckBox* c18;
        QCheckBox* c19;
        QCheckBox* c20;
        QCheckBox* c21;
        QCheckBox* c22;
        QCheckBox* c23;
        QCheckBox* c24;
        QCheckBox* c25;
        QCheckBox* c26;
        QCheckBox* c27;
        QCheckBox* c28;
        QCheckBox* c29;
        QCheckBox* c30;
        QCheckBox* c31;
        QCheckBox* c32;
        QCheckBox* c33;
        QCheckBox* c34;

        QLabel* l1;
        QLabel* l2;
        QLabel* l3;
        QLabel* l4;
        QLabel* l5;
        QLabel* l6;
        QLabel* l7;
        QLabel* l8;

        QLabel* l9;
        QLabel* l10;
        QLabel* l11;
        QLabel* l12;
        QLabel* l13;
        QLabel* l14;
        QLabel* l15;
        QLabel* l16;
        QLabel* l17;
        QLabel* l18;
        QLabel* l19;
        QLabel* l20;
        QLabel* l21;
        QLabel* l22;
        QLabel* l23;
        QLabel* l24;
        QLabel* l25;
        QLabel* l26;
        QLabel* l27;
        QLabel* l28;
        QLabel* l29;
        QLabel* l30;
        QLabel* l31;
        QLabel* l32;
        QLabel* l33;
        QLabel* l34;

        QMap<unsigned int, UV*>::Iterator it10;




    public slots:



        void clear();

        // ===== Tabs =====

        void showProfilEdit();
        void showConfigEdit();
        void showSimulationEdit();


        // ===== Lists =====

        void showUserList();
        void showBranchList();
        void showCatList();
        void showFiliereList();
        void showUVList();
        void showNoteList();
        void showBonusList();
        void showDesirsList();
        void showEtrangerList();
        void showPrefEtrangersList();

        // ===== Forms =====

        void showNewBranchForm();
        void showNewUserForm();
        void showNewCatForm();
        void showNewFiliereForm();
        void showNewCursusForm();
        void showNewNoteForm();
        void showNewInscriptionForm();
        void showProfilForm();
        void showNewBonusForm();
        void showNewDesirForm();
        void showNewEtrangerForm();
        void showNewPrefEtrangerForm();
        void showAjoutCursusUVForm();


        // ===== Validation forms =====

        void valideNewUserForm();
        void valideNewBranchForm();
        void valideNewCatForm();
        void valideNewFiliereForm();
        void valideNewCursusForm();
        void valideNewNoteForm();
        void valideNewInscriptionForm();
        void valideProfilForm();
        void valideNewBonusForm();
        void valideNewDesirForm();
        void valideNewEtrangerForm();
        void valideNewPrefEtrangerForm();
        void valideAjoutCursusUVForm();

        // ===== show items =====

        void showProfilInfo();
        void showUser();

        // ===== Selects =====

        void selectUser();

        // ===== Divers =====

        void test();
        void exportDb();
        void importDb();
        void sliderBonus(int);



};

#endif // MAINWINDOW_H
