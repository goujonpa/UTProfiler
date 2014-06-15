#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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


namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
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
