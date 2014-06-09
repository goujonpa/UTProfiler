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

    // ===== Init Db =====

    //deleteDb();
    openDb();
    createTables();

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

    // =================================================

    // ==== Init user =====

    titre = new QLabel;
    mainLayout->addWidget(titre, 1,0,1,3);


    // ===== Init buttons =====

    Butt1 = new QPushButton;
    Butt2 = new QPushButton;
    Butt3 = new QPushButton;
    Butt4 = new QPushButton;
    Butt5 = new QPushButton;


    // ===== Init LineEdits =====

    le1 = new QLineEdit;
    le2 = new QLineEdit;

    // ===== Init Labels =====

    label1 = new QLabel;
    label2 = new QLabel;
    label3 = new QLabel;
    label4 = new QLabel;
    label5 = new QLabel;
    label6 = new QLabel;
    label7 = new QLabel;
    label8 = new QLabel;
    label9 = new QLabel;
    label10 = new QLabel;
    label11 = new QLabel;

    // ===== Init Sql MVC =====

    sqlModel1 = new QSqlQueryModel;
    tableView1 = new QTableView;

    // ===== Divers =====

    valider = new QPushButton;
    valider->setText("Valider");

    // ===== Connect =====

    QObject::connect(mainProfilButt, SIGNAL(clicked()), this, SLOT(clear()));
    QObject::connect(mainProfilButt, SIGNAL(clicked()), this, SLOT(showProfilEdit()));

    //QObject::connect(mainSimuButt, SIGNAL(clicked()), this, SLOT(showProfilEdit()));

    QObject::connect(mainConfigButt, SIGNAL(clicked()), this, SLOT(clear()));
    QObject::connect(mainConfigButt, SIGNAL(clicked()), this, SLOT(showConfigEdit()));
}

void MainWindow::showProfilEdit()
{
    titre->setText("Gestion de Profil");

    mainLayout->addWidget(Butt1, 2,0,1,2);
    Butt1->setText("Nouvel utilisateur");
    Butt1->show();
    QObject::connect(Butt1, SIGNAL(clicked()), this, SLOT(showProfilEdit()));
    QObject::connect(Butt1, SIGNAL(clicked()), this, SLOT(showNewUserForm()));

    mainLayout->addWidget(Butt2, 3,0,1,2);
    Butt2->setText("Choisir utilisateur existant");
    Butt2->show();
    QObject::connect(Butt2, SIGNAL(clicked()), this, SLOT(showProfilEdit()));
    QObject::connect(Butt2, SIGNAL(clicked()), this, SLOT(showUserList()));

    if (user != NULL)
        showUser();
}

void MainWindow::showNewUserForm()
{
    clear();
    label10->setText("Prenom :");
    mainLayout->addWidget(label10, 2,3,1,1);
    label11->setText("Nom :");
    mainLayout->addWidget(label11, 3,3,1,1);
    mainLayout->addWidget(le1, 2,4,1,2);
    mainLayout->addWidget(le2, 3,4,1,2);
    mainLayout->addWidget(valider, 4,4,1,2);
    label10->show();
    label11->show();
    le1->show();
    le2->show();
    valider->show();
    showProfilEdit();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valideNewUserForm()));
}

void MainWindow::valideNewUserForm()
{
    user = new User(0, le2->text(), le1->text(), 0, 0);
    int idUser = Db->insertItem(user);
    user->setId(idUser);
    if (idUser > 0)
        affiche("Nouvel Utilisateur créé.");
    if (idUser == -1)
        affiche("Erreur : echec, too bad, my bad.");
    clear();
    showProfilEdit();
}

void MainWindow::showUserList()
{
    clear();
    showProfilEdit();
    sqlModel1 = Db->getUserList();
    label11->setText("Liste des utilisateurs :");
    mainLayout->addWidget(label11, 2,2,1,1);
    label11->show();
    tableView1->setModel(sqlModel1);
    tableView1->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView1,3,2,5,3);
    tableView1->show();
    valider->setText("Valider choix");
    mainLayout->addWidget(valider,9,2,1,1);
    valider->show();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(selectUser()));
}

void MainWindow::selectUser()
{
    QItemSelectionModel* selection = tableView1->selectionModel();
    QModelIndex index1 = selection->currentIndex();
    QModelIndex index2 = index1.sibling(index1.row(),0);
    QVariant variant1 = sqlModel1->data(index2);
    user = new User;
    user = Db->getItem(user, variant1.toInt());
    QMessageBox::information(this, "Utilisateur selectionné", user->getPrenom() + " " + user->getNom());
    clear();
    showProfilEdit();
}

void MainWindow::showUser() //OK
{
    label3->setText("Utilisateur courant :");
    QString name = user->getPrenom() + " " + user->getNom();
    label4->setText(name);
    label1->setText("Profil");
    label2->setText("Simulation");
    label5->setText("Renseignés :");
    label7->setText("Non");
    if (user->getProfil() != 0)
        label7->setText("Oui");
    label9->setText("Non");
    if (user->getSimulation() != 0)
        label9->setText("Oui");
    mainLayout->addWidget(label3, 7,0,1,1);
    mainLayout->addWidget(label4, 7,1,1,1);
    mainLayout->addWidget(label5, 8,0,1,1);
    mainLayout->addWidget(label1, 9,0,1,1);
    mainLayout->addWidget(label7, 9,1,1,1);
    mainLayout->addWidget(label2, 10,0,1,1);
    mainLayout->addWidget(label9, 10,1,1,1);
    label1->show();
    label2->show();
    label3->show();
    label4->show();
    label5->show();
    label7->show();
    label9->show();
}

void MainWindow::clear()
{
    titre->setText("");

    stop(Butt1);
    stop(Butt2);
    stop(Butt3);
    stop(Butt4);
    stop(Butt5);

    stop(label1);
    stop(label2);
    stop(label3);
    stop(label4);
    stop(label5);
    stop(label6);
    stop(label7);
    stop(label8);
    stop(label9);
    stop(label10);
    stop(label11);

    stop(le1);
    stop(le2);

    stop(tableView1);

    stop(valider);
}

void MainWindow::stop(QWidget* obj)
{
    obj->hide();
    mainLayout->removeWidget(obj);
    obj->disconnect();
}

void MainWindow::showConfigEdit()
{
    titre->setText("Gestion de la configuration");

    /*
    mainLayout->addWidget(Butt1, 2,0,1,2);
    Butt1->setText("Open DB");
    Butt1->show();
    QObject::connect(Butt1, SIGNAL(clicked()), this, SLOT(opendb()));

    mainLayout->addWidget(Butt2, 3,0,1,2);
    Butt2->setText("Delete DB");
    Butt2->show();
    QObject::connect(Butt2, SIGNAL(clicked()), this, SLOT(deletedb()));

    mainLayout->addWidget(Butt3, 4,0,1,2);
    Butt3->setText("Create tables");
    Butt3->show();
    QObject::connect(Butt3, SIGNAL(clicked()), this, SLOT(createTables()));

    mainLayout->addWidget(Butt4, 5,0,1,2);
    Butt4->setText("Insert UV");
    Butt4->show();
    QObject::connect(Butt4, SIGNAL(clicked()), this, SLOT(insertuv()));

    mainLayout->addWidget(Butt5, 6,0,1,2);
    Butt5->setText("TEST");
    Butt5->show();
    QObject::connect(Butt5, SIGNAL(clicked()), this, SLOT(test()));
    */
}

void MainWindow::affiche(QString message)
{
    QMessageBox::information(this, "Information", message);
}

void MainWindow::test()
{
    //QString code = Db->getUV(1);
    //affiche(code);
}

bool MainWindow::openDb()
{
   //bool ret =
           Db->openDB();
   //if (ret)
       //affiche("Db ouverte");
    return true;
}

bool MainWindow::deleteDb()
{
    bool ret = Db->deleteDB();
    if (ret)
        affiche("Db supprimée");
    return true;
}

bool MainWindow::createTables()
{
    bool ret = Db->createTables();
    if (ret)
        affiche("Tables crées");
    return true;
}

MainWindow::~MainWindow()
{
    delete ui;
}
