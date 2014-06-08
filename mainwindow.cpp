#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // ===== Init window =====

    ui->setupUi(this); // Init ui
    MainWindow::setWindowState(Qt::WindowMaximized); // plein écran par défaut

    // ===== Init Db =====

    Db = new DbManager;

    // ===== Main Widget =====

    zoneCenter = new QWidget;
    setCentralWidget(zoneCenter);


    // ===== Actions & Menus =====
/*
    QAction *actionProfil = ui->menuProfil->addAction("Profil");
    QAction *actionSimulation = ui->menuSimulation->addAction("Simulation");
    QAction *actionConfig = ui->menuUTProfiler->addAction("Configuration");
*/

    // ===== Main Layout =====

    mainLayout = new QGridLayout;
    zoneCenter->setLayout(mainLayout);

    QLabel* spacer = new QLabel; // -> les boutons sont toujours en haut, et la fenêtre a toujours a peu près la même géométrie
    mainLayout->addWidget(spacer, 0,0,15,6);
    spacer->hide();


    // ===== Main toolbar =====

    mainProfilButt = new QPushButton;
    mainProfilButt->setText("Profil");

    mainSimuButt = new QPushButton;
    mainSimuButt->setText("Simulation");

    mainConfigButt = new QPushButton;
    mainConfigButt->setText("Configuration");

    mainLayout->addWidget(mainProfilButt,0,0,1,2);
    mainLayout->addWidget(mainSimuButt,0,2,1,2);
    mainLayout->addWidget(mainConfigButt,0,4,1,2);

    // ========================================================


    titre = new QLabel;
    mainLayout->addWidget(titre, 1,0,1,3);


    // ===== Init buttons =====

    Butt1 = new QPushButton;
    Butt2 = new QPushButton;
    Butt3 = new QPushButton;


    // ===== Init LineEdits =====

    le1 = new QLineEdit;
    le2 = new QLineEdit;

    // ===== Init Labels =====

    label1 = new QLabel;
    label2 = new QLabel;

    // ===== Divers =====

    valider = new QPushButton;
    valider->setText("Valider");



    // ===== Connect =====

    QObject::connect(mainProfilButt, SIGNAL(clicked()), this, SLOT(showProfilEdit()));


    /*
    QObject::connect(mainSimuButt, SIGNAL(clicked()), this, SLOT(showProfilEdit()));
    QObject::connect(mainSimuButt, SIGNAL(clicked()), this, SLOT(hideProfilEdit()));
    QObject::connect(mainSimuButt, SIGNAL(clicked()), this, SLOT(hideProfilEdit()));
    */

    QObject::connect(mainConfigButt, SIGNAL(clicked()), this, SLOT(showConfigEdit()));



}

void MainWindow::showProfilEdit()
{
    hideConfigEdit();
    titre->setText("Gestion de Profil");

    mainLayout->addWidget(Butt1, 2,0,1,2);
    Butt1->setText("Nouvel utilisateur");
    Butt1->show();
    QObject::connect(Butt1, SIGNAL(clicked()), this, SLOT(showNewUserForm()));

    mainLayout->addWidget(Butt2, 3,0,1,2);
    Butt2->setText("Choisir utilisateur existant");
    Butt2->show();
    QObject::connect(Butt2, SIGNAL(clicked()), this, SLOT(hideNewUserForm()));

}

void MainWindow::hideProfilEdit()
{
    titre->setText("");

    hideNewUserForm();

    Butt1->hide();
    mainLayout->removeWidget(Butt1);

    Butt2->hide();
    mainLayout->removeWidget(Butt2);
}

void MainWindow::showNewUserForm()
{
    label1->setText("Prenom :");
    mainLayout->addWidget(label1, 2,2,1,2);
    label2->setText("Nom :");
    mainLayout->addWidget(label2, 3,2,1,2);
    mainLayout->addWidget(le1, 2,4,1,2);
    mainLayout->addWidget(le2, 3,4,1,2);
    mainLayout->addWidget(valider, 4,4,1,2);
    label1->show();
    label2->show();
    le1->show();
    le2->show();
    valider->show();
}

void MainWindow::hideNewUserForm()
{
    label1->hide();
    label2->hide();
    le1->hide();
    le2->hide();
    valider->hide();
    mainLayout->removeWidget(label1);
    mainLayout->removeWidget(label2);
    mainLayout->removeWidget(le1);
    mainLayout->removeWidget(le2);
    mainLayout->removeWidget(valider);
}

void MainWindow::showConfigEdit()
{
    hideProfilEdit();
    titre->setText("Gestion de la configuration");

    mainLayout->addWidget(Butt1, 2,0,1,2);
    Butt1->setText("Open DB");
    Butt1->show();
    QObject::connect(Butt1, SIGNAL(clicked()), Db, SLOT(opendb()));

    mainLayout->addWidget(Butt2, 3,0,1,2);
    Butt2->setText("Delete DB");
    Butt2->show();
    QObject::connect(Butt2, SIGNAL(clicked()), Db, SLOT(deletedb()));

    mainLayout->addWidget(Butt3, 4,0,1,2);
    Butt3->setText("Create tables");
    Butt3->show();
    QObject::connect(Butt3, SIGNAL(clicked()), Db, SLOT(createTables()));


}

void MainWindow::hideConfigEdit()
{
    titre->setText("");

    Butt1->hide();
    mainLayout->removeWidget(Butt1);

    Butt2->hide();
    mainLayout->removeWidget(Butt2);

    Butt3->hide();
    mainLayout->removeWidget(Butt3);
}

void MainWindow::showMessage(QString message)
{
    QMessageBox::information(this, "Message", message);
}


MainWindow::~MainWindow()
{
    delete ui;
}
