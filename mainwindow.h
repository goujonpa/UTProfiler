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
#include "user.h"
#include "filiere.h"
#include "branche.h"
#include "cursus.h"
#include "dbmanager.h"
#include "xmlmanager.h"


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
        void showUser();
        void stop(QWidget* obj);
        QTableView* getUvView();


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
        QStandardItemModel* stdItMod1;
        DbManager* Db;
        User* user = NULL;
        Branche* branche = NULL;
        Categorie* categorie = NULL;
        Filiere* filiere = NULL;
        Cursus* cursus = NULL;
        UV* uv = NULL;
        Note* note = NULL;
        QSqlQueryModel* sqlModel1;
        QSqlQueryModel* sqlModel2;
        QTableView* tableView1;
        QTableView* tableView2;
        QTableView* selectView1;
        XmlManager* xml;


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

        // ===== Forms =====

        void showNewBranchForm();
        void showNewUserForm();
        void showNewCatForm();
        void showNewFiliereForm();
        void showNewCursusForm();
        void showNewNoteForm();
        void showProfilForm();

        // ===== Validation forms =====

        void valideNewUserForm();
        void valideNewBranchForm();
        void valideNewCatForm();
        void valideNewFiliereForm();
        void valideNewCursusForm();
        void valideNewNoteForm();


        // ===== Dialogs =======

        void dialogAddInscr();


        // ===== Selects =====

        void selectUser();


        void test();
        bool createTables();
        void exportDb();
        void importDb();



};

#endif // MAINWINDOW_H
