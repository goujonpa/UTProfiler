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
#include "user.h"
#include "dbmanager.h"


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
        QLabel* label3;
        QLabel* label4;
        QLabel* label5;
        QLabel* label6;
        QLabel* label7;
        QLabel* label8;
        QLabel* label9;
        QLabel* label10;
        QLabel* label11;
        DbManager* Db;
        User* user = NULL;
        QSqlQueryModel* sqlModel1;
        QTableView* tableView1;


    public slots:

        void clear();

        void showProfilEdit();
        void showNewUserForm();
        void showConfigEdit();
        void showUserList();

        void selectUser();

        void valideNewUserForm();

        void test();
        bool openDb();
        bool deleteDb();
        bool createTables();



};

#endif // MAINWINDOW_H
