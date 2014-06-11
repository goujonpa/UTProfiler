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

    //Db->deleteDb();
    //Db->openDb();
    //Db->createTables();


    // ===== Init xml =====

    xml = new XmlManager;

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
    Butt6 = new QPushButton;
    Butt7 = new QPushButton;
    Butt8 = new QPushButton;
    Butt9 = new QPushButton;
    Butt10 = new QPushButton;

    // ===== Init QSIM =====

    stdItMod1 = new QStandardItemModel;

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
    label12 = new QLabel;

    // ===== Init Sql MVC =====

    sqlModel1 = new QSqlQueryModel;
    sqlModel2 = new QSqlQueryModel;
    sqlModel3 = new QSqlQueryModel;
    sqlModel4 = new QSqlQueryModel;
    tableView1 = new QTableView;
    tableView2 = new QTableView;
    tableView3 = new QTableView;
    tableView4 = new QTableView;


    // ===== Divers =====

    valider = new QPushButton;
    valider->setText("Valider");

    combo1 = new QComboBox;

    // ===== Connect =====

    QObject::connect(mainProfilButt, SIGNAL(clicked()), this, SLOT(clear()));
    QObject::connect(mainProfilButt, SIGNAL(clicked()), this, SLOT(showProfilEdit()));

    QObject::connect(mainSimuButt, SIGNAL(clicked()), this, SLOT(clear()));
    QObject::connect(mainSimuButt, SIGNAL(clicked()), this, SLOT(showSimulationEdit()));

    QObject::connect(mainConfigButt, SIGNAL(clicked()), this, SLOT(clear()));
    QObject::connect(mainConfigButt, SIGNAL(clicked()), this, SLOT(showConfigEdit()));
}




// ===== SELECT ITEMS =====================================================



void MainWindow::selectUser()
{
    QItemSelectionModel* selection = tableView1->selectionModel();
    QModelIndex index1 = selection->currentIndex();
    QModelIndex index2 = index1.sibling(index1.row(),0);
    QVariant variant1 = sqlModel1->data(index2);
    user = Db->m_users->find(variant1.toInt()).value();
    Db->m_user = user;
    QMessageBox::information(this, "Utilisateur selectionné", user->getPrenom() + " " + user->getNom());
    clear();
    showProfilEdit();
}



// =====  SHOW ITEMS =====================================================



void MainWindow::showUser()
{
    stdItMod1->setColumnCount(2);
    stdItMod1->setRowCount(4);
    stdItMod1->setItem(0,0, new QStandardItem("Utilisateur Courant"));
    QString name = user->getPrenom() + " " + user->getNom();
    stdItMod1->setItem(0,1, new QStandardItem(name));
    stdItMod1->setItem(1,0, new QStandardItem("Renseignés :"));
    stdItMod1->setItem(2,0, new QStandardItem("Profil"));
    stdItMod1->setItem(3,0, new QStandardItem("Simulation"));
    QString profilRep = "Non";
    QString simuRep = "Non";
    if (user->getProfil() != 0)
        profilRep = "Oui";
    if (user->getSimulation() != 0)
        simuRep = "Oui";
    stdItMod1->setItem(2,1, new QStandardItem(profilRep));
    stdItMod1->setItem(3,1, new QStandardItem(simuRep));
    tableView1->setModel(stdItMod1);
    tableView1->horizontalHeader()->setVisible(false);
    mainLayout->addWidget(tableView1, 6,0,4,2);
    tableView1->show();

}



// ===== SHOW TABS ======================================================



void MainWindow::showProfilEdit()
{
    titre->setText("Gestion de Profil");

    mainLayout->addWidget(Butt1, 2,0,1,1);
    Butt1->setText("Nouvel utilisateur");
    Butt1->show();
    QObject::connect(Butt1, SIGNAL(clicked()), this, SLOT(showNewUserForm()));

    mainLayout->addWidget(Butt2, 2,1,1,1);
    Butt2->setText("Choisir utilisateur existant");
    Butt2->show();
    QObject::connect(Butt2, SIGNAL(clicked()), this, SLOT(showUserList()));

    mainLayout->addWidget(Butt3, 3,0,1,2);
    Butt3->setText("Renseigner Profil");
    Butt3->show();

    Butt4->setText("Ajouter Inscription");
    Butt4->show();
    mainLayout->addWidget(Butt4, 4,0,1,2);
    QObject::connect(Butt4, SIGNAL(clicked()), this, SLOT(showNewInscriptionForm()));

    if (user != NULL)
    {
        showUser();
        Butt4->setEnabled(true);
    }
    else
        Butt4->setEnabled(false);
}

void MainWindow::showSimulationEdit()
{
    titre->setText("Gestion de la simulation");

    mainLayout->addWidget(Butt1, 2,0,1,1);
    Butt1->setText("Ajout Branche");
    Butt1->show();
    //QObject::connect(Butt1, SIGNAL(clicked()), this, SLOT(showNewBranchForm()));

    mainLayout->addWidget(Butt2, 2,1,1,1);
    Butt2->setText("Catalogue Branches");
    Butt2->show();
    //QObject::connect(Butt2, SIGNAL(clicked()), this, SLOT(showBranchList()));

    mainLayout->addWidget(Butt3, 3,0,1,2);
    Butt3->setText("Load UVs");
    Butt3->show();
    //QObject::connect(Butt3, SIGNAL(clicked()), this, SLOT(test()));

    mainLayout->addWidget(Butt4, 4,0,1,1);
    Butt4->setText("Ajout Categorie");
    Butt4->show();
    //QObject::connect(Butt4, SIGNAL(clicked()), this, SLOT(showNewCatForm()));

    mainLayout->addWidget(Butt5, 4,1,1,1);
    Butt5->setText("Catalogue Categories");
    Butt5->show();
    //QObject::connect(Butt5, SIGNAL(clicked()), this, SLOT(showCatList()));

    mainLayout->addWidget(Butt6, 5,0,1,1);
    Butt6->setText("Ajout Filiere");
    Butt6->show();
    //QObject::connect(Butt6, SIGNAL(clicked()), this, SLOT(showNewFiliereForm()));

    mainLayout->addWidget(Butt7, 5,1,1,1);
    Butt7->setText("Catalogue Filieres");
    Butt7->show();
    //QObject::connect(Butt7, SIGNAL(clicked()), this, SLOT(showFiliereList()));


    mainLayout->addWidget(Butt8, 6,0,1,2);
    Butt8->setText("Catalogue d'UVs");
    Butt8->show();
    //QObject::connect(Butt8, SIGNAL(clicked()), this, SLOT(showUVList()));

    mainLayout->addWidget(Butt9, 7,0,1,1);
    Butt9->setText("Ajout Note");
    Butt9->show();
    //QObject::connect(Butt9, SIGNAL(clicked()), this, SLOT(showNewNoteForm()));

    mainLayout->addWidget(Butt10, 7,1,1,1);
    Butt10->setText("Catalogue Note");
    Butt10->show();
    //QObject::connect(Butt10, SIGNAL(clicked()), this, SLOT(showNoteList()));

}

void MainWindow::showConfigEdit()
{
    titre->setText("Gestion de la configuration");

    mainLayout->addWidget(Butt1, 2,0,1,1);
    Butt1->setText("Ajout Branche");
    Butt1->show();
    QObject::connect(Butt1, SIGNAL(clicked()), this, SLOT(showNewBranchForm()));

    mainLayout->addWidget(Butt2, 2,1,1,1);
    Butt2->setText("Catalogue Branches");
    Butt2->show();
    QObject::connect(Butt2, SIGNAL(clicked()), this, SLOT(showBranchList()));

    mainLayout->addWidget(Butt3, 3,0,1,2);
    Butt3->setText("Load UVs");
    Butt3->show();
    QObject::connect(Butt3, SIGNAL(clicked()), this, SLOT(test()));

    mainLayout->addWidget(Butt4, 4,0,1,1);
    Butt4->setText("Ajout Categorie");
    Butt4->show();
    QObject::connect(Butt4, SIGNAL(clicked()), this, SLOT(showNewCatForm()));

    mainLayout->addWidget(Butt5, 4,1,1,1);
    Butt5->setText("Catalogue Categories");
    Butt5->show();
    QObject::connect(Butt5, SIGNAL(clicked()), this, SLOT(showCatList()));

    mainLayout->addWidget(Butt6, 5,0,1,1);
    Butt6->setText("Ajout Filiere");
    Butt6->show();
    QObject::connect(Butt6, SIGNAL(clicked()), this, SLOT(showNewFiliereForm()));

    mainLayout->addWidget(Butt7, 5,1,1,1);
    Butt7->setText("Catalogue Filieres");
    Butt7->show();
    QObject::connect(Butt7, SIGNAL(clicked()), this, SLOT(showFiliereList()));


    mainLayout->addWidget(Butt8, 6,0,1,2);
    Butt8->setText("Catalogue d'UVs");
    Butt8->show();
    QObject::connect(Butt8, SIGNAL(clicked()), this, SLOT(showUVList()));

    mainLayout->addWidget(Butt9, 7,0,1,1);
    Butt9->setText("Ajout Note");
    Butt9->show();
    QObject::connect(Butt9, SIGNAL(clicked()), this, SLOT(showNewNoteForm()));

    mainLayout->addWidget(Butt10, 7,1,1,1);
    Butt10->setText("Catalogue Note");
    Butt10->show();
    QObject::connect(Butt10, SIGNAL(clicked()), this, SLOT(showNoteList()));

}



// ===== SHOW FORMS =======================================================



void MainWindow::showNewBranchForm()
{
    clear();
    label10->setText("Code :");
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
    showConfigEdit();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valideNewBranchForm()));
}

void MainWindow::showNewNoteForm()
{
    clear();
    label10->setText("Code :");
    mainLayout->addWidget(label10, 2,3,1,1);
    label10->show();
    mainLayout->addWidget(le1, 2,4,1,2);
    le1->show();
    mainLayout->addWidget(valider, 3,4,1,2);
    valider->show();
    showConfigEdit();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valideNewNoteForm()));
}

void MainWindow::showNewFiliereForm()
{
    clear();
    label10->setText("Code :");
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
    showConfigEdit();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valideNewFiliereForm()));
}

void MainWindow::showNewCatForm()
{
    clear();
    label10->setText("Code :");
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
    showConfigEdit();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valideNewCatForm()));
}

void MainWindow::showNewCursusForm()
{
    clear();
    label10->setText("Nom du Cursus :");
    mainLayout->addWidget(label10, 2,3,1,1);
    label10->show();
    mainLayout->addWidget(le1, 2,4,1,2);
    le1->show();

    label11->setText("Choix de la Branche :");
    mainLayout->addWidget(label11, 3,3,1,1);
    label11->show();

    sqlModel1 = Db->getBranchList();
    tableView1->setModel(sqlModel1);
    tableView1->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView1,4,3,4,2);
    tableView1->show();

    label12->setText("Choix de la Filiere :");
    mainLayout->addWidget(label12, 8,3,1,1);
    label12->show();

    sqlModel2 = Db->getFiliereList();
    tableView2->setModel(sqlModel2);
    tableView2->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView2,9,3,2,2);
    tableView2->show();


    valider->setText("Valider choix");
    mainLayout->addWidget(valider,12,3,1,1);
    valider->show();

    showConfigEdit();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valideNewUserForm()));
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

void MainWindow::showNewInscriptionForm()
{
    label10->setText("Ajout d'Inscriptions :");
    mainLayout->addWidget(label10, 2,3,1,1);
    label10->show();

    getUvView();
    mainLayout->addWidget(tableView1, 3,3,2,3);
    tableView1->show();

    combo1->addItem("Printemps");
    combo1->addItem("Automne");
    mainLayout->addWidget(combo1, 6,3,1,3);
    combo1->show();

    label1->setText("Année :");
    mainLayout->addWidget(label1, 7,3,1,1);
    label1->show();

    mainLayout->addWidget(le1, 7,4,1,2);
    le1->show();

    label2->setText("Note :");
    mainLayout->addWidget(label2, 8,3,1,1);
    label2->show();

    getNoteView();
    mainLayout->addWidget(tableView2, 9,3,1,3);
    tableView2->show();

    label3->setText("Branche comptabilisée :");
    mainLayout->addWidget(label3, 10,3,1,3);
    label3->show();

    getBrancheView();
    mainLayout->addWidget(tableView3, 11,3,1,3);
    tableView3->show();

    label4->setText("Filiere comptabilisée :");
    mainLayout->addWidget(label4, 12,3,1,3);
    label4->show();

    getFiliereView();
    mainLayout->addWidget(tableView4, 13,3,1,3);
    tableView4->show();


    valider->setText("Valider");
    mainLayout->addWidget(valider, 14,3,2,3);
    valider->show();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(dialogAddInscr()));
}

// ===== Dialog ==========================================================

void MainWindow::dialogAddInscr()
{

    QItemSelectionModel* selection = tableView1->selectionModel();
    QModelIndex index1 = selection->currentIndex();
    QModelIndex index2 = index1.sibling(index1.row(),0);
    QVariant variant1 = sqlModel1->data(index2);
    unsigned int id = variant1.toInt();
    uv = Db->m_uvs->find(id).value();

    QMessageBox::information(this, "UV", uv->getCode());


    selection = tableView2->selectionModel();
    index1 = selection->currentIndex();
    index2 = index1.sibling(index1.row(),0);
    variant1 = sqlModel2->data(index2);
    id = variant1.toInt();
    note = Db->m_notes->find(id).value();

    QMessageBox::information(this, "Note", note->getCode());

    selection = tableView3->selectionModel();
    index1 = selection->currentIndex();
    index2 = index1.sibling(index1.row(),0);
    variant1 = sqlModel3->data(index2);
    id = variant1.toInt();
    branche = Db->m_branches->find(id).value();

    QMessageBox::information(this, "Branche", branche->getCode());


    selection = tableView4->selectionModel();
    index1 = selection->currentIndex();
    index2 = index1.sibling(index1.row(),0);
    variant1 = sqlModel4->data(index2);
    id = variant1.toInt();
    filiere = Db->m_filieres->find(id).value();


    QMessageBox::information(this, "Filiere", filiere->getCode());


    Saison saison = Printemps;
    if (combo1->currentText() == "Automne")
    {
        saison = Automne;
        QMessageBox::information(this, "Saison", "Automne");
    }

    semestre = new Semestre(0, saison, le1->text().toInt());

    QMap<unsigned int, Semestre*>::iterator it;

    for (it = Db->m_semestres->begin(); it != Db->m_semestres->end(); ++it)
    {
        if ((it.value()->getSaison() == semestre->getSaison()) && (it.value()->getAnnee() == semestre->getAnnee()))
            semestre = it.value();
    }

    if (semestre->getId() == 0)
    {
        id = Db->insertItem(semestre);
        semestre->setId(id);
        Db->m_semestres->insert(semestre->getId(), semestre);
    }

    QString mess = QString::number(semestre->getAnnee());
    QMessageBox::information(this, "Semestre", mess);


    cursus = new Cursus(0, branche, filiere);

    QMap<unsigned int, Cursus*>::iterator it2;

    for (it2 = Db->m_cursuss->begin(); it2 != Db->m_cursuss->end(); ++it2)
    {
        if ((it2.value()->getBranche() == branche) && (it2.value()->getFiliere() == filiere))
            cursus = it2.value();
    }

    if (cursus->getId() == 0)
    {
        id = Db->insertItem(cursus);
        cursus->setId(id);
        Db->m_cursuss->insert(cursus->getId(), cursus);
    }

    QString mess2 = QString::number(cursus->getId());
    QMessageBox::information(this, "IdCursus", mess2);


    inscription = new Inscription(0, uv, semestre, note, cursus, uv->getCategorie());
    id = Db->insertItem(inscription);
    inscription->setId(id);
    Db->m_inscriptions->insert(inscription->getId(), inscription);
    Db->m_userInscriptions->insert(inscription->getId(), inscription);



    QMessageBox::information(this, "Inscription", inscription->getUV()->getCode());


    clear();
    showProfilEdit();


}


// ===== VALIDE FORMS ==========================================================



void MainWindow::valideNewNoteForm()
{
    note = new Note(0, le1->text());
    int id = Db->insertItem(note);
    note->setId(id);
    if (id > 0)
        affiche("Nouvelle note créée.");
    if (id == -1)
        affiche("Erreur : echec, too bad, my bad.");
    clear();
    showConfigEdit();
}

void MainWindow::valideNewCursusForm()
{
    QItemSelectionModel* selection = tableView1->selectionModel();
    QModelIndex index1 = selection->currentIndex();
    QModelIndex index2 = index1.sibling(index1.row(),0);
    QVariant variant1 = sqlModel1->data(index2);
    branche = new Branche(0, "", "");
    branche = Db->getItem(branche, variant1.toInt());

    QItemSelectionModel* selection2 = tableView2->selectionModel();
    QModelIndex index3 = selection2->currentIndex();
    QModelIndex index4 = index3.sibling(index3.row(),0);
    QVariant variant2 = sqlModel1->data(index4);
    filiere = new Filiere(0, "", "");
    filiere = Db->getItem(filiere, variant2.toInt());

    cursus = new Cursus(0, branche, filiere);
    int id = Db->insertItem(cursus);
    cursus->setId(id);

    QString message = branche->getCode() + " => " + filiere->getCode();

    if (id > 0)
        QMessageBox::information(this, "Cursus inséré", message);
    else
        affiche("Erreur ZBleh");

    clear();
    showConfigEdit();

}

void MainWindow::valideNewBranchForm()
{
    branche = new Branche(0, le1->text(), le2->text());
    int id = Db->insertItem(branche);
    branche->setId(id);
    if (id > 0)
        affiche("Nouvelle branche créée.");
    if (id == -1)
        affiche("Erreur : echec, too bad, my bad.");
    clear();
    showConfigEdit();
}

void MainWindow::valideNewFiliereForm()
{
    filiere = new Filiere(0, le1->text(), le2->text());
    int id = Db->insertItem(filiere);
    filiere->setId(id);
    if (id > 0)
        affiche("Nouvelle filière créée.");
    if (id == -1)
        affiche("Erreur : echec, too bad, my bad.");
    clear();
    showConfigEdit();
}

void MainWindow::valideNewCatForm()
{
    categorie = new Categorie(0, le1->text(), le2->text());
    int id = Db->insertItem(categorie);
    categorie->setId(id);
    if (id > 0)
        affiche("Nouvelle catégorie créée.");
    if (id == -1)
        affiche("Erreur : echec, too bad, my bad.");
    clear();
    showConfigEdit();
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



// ===== SHOW LISTS =======================================================



void MainWindow::showBranchList()
{
    clear();
    showConfigEdit();
    sqlModel1 = Db->getBranchList();
    label11->setText("Liste des Branches :");
    mainLayout->addWidget(label11, 2,3,1,1);
    label11->show();
    tableView1->setModel(sqlModel1);
    tableView1->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView1,3,3,5,2);
    tableView1->show();
}

void MainWindow::showFiliereList()
{
    clear();
    showConfigEdit();
    sqlModel1 = Db->getFiliereList();
    label11->setText("Liste des Filieres :");
    mainLayout->addWidget(label11, 2,3,1,1);
    label11->show();
    tableView1->setModel(sqlModel1);
    tableView1->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView1,3,3,5,2);
    tableView1->show();
}

void MainWindow::showCatList()
{
    clear();
    showConfigEdit();
    sqlModel1 = Db->getCatList();
    label11->setText("Liste des Categories d'UV :");
    mainLayout->addWidget(label11, 2,3,1,1);
    label11->show();
    tableView1->setModel(sqlModel1);
    tableView1->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView1,3,3,5,2);
    tableView1->show();
}

void MainWindow::showNoteList()
{
    clear();
    showConfigEdit();
    sqlModel1 = Db->getNoteList();
    label11->setText("Liste des Notes :");
    mainLayout->addWidget(label11, 2,3,1,1);
    label11->show();
    tableView1->setModel(sqlModel1);
    tableView1->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView1,3,3,5,2);
    tableView1->show();
}

void MainWindow::showUVList()
{
    clear();
    showConfigEdit();
    sqlModel1 = Db->getUVList();
    label11->setText("Catalogue d'UVs :");
    mainLayout->addWidget(label11, 2,3,1,1);
    label11->show();
    tableView1->setModel(sqlModel1);
    tableView1->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView1,3,2,15,4);
    tableView1->show();
}

void MainWindow::showUserList()
{
    clear();
    showProfilEdit();
    sqlModel1 = Db->getUserList();
    label11->setText("Liste des utilisateurs :");
    mainLayout->addWidget(label11, 2,3,1,1);
    label11->show();
    tableView1->setModel(sqlModel1);
    tableView1->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView1,3,3,5,2);
    tableView1->show();
    valider->setText("Valider choix");
    mainLayout->addWidget(valider,9,3,1,1);
    valider->show();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(selectUser()));
}



// ===== GET VIEWS =======================================================



QTableView* MainWindow::getUvView()
{
    sqlModel1 = Db->getUVList();
    tableView1->setModel(sqlModel1);
    tableView1->verticalHeader()->setVisible(false);
    return tableView1;
}

QTableView* MainWindow::getNoteView()
{
    sqlModel2 = Db->getNoteList();
    tableView2->setModel(sqlModel2);
    tableView2->verticalHeader()->setVisible(false);
    return tableView2;
}

QTableView* MainWindow::getBrancheView()
{
    sqlModel3 = Db->getBranchList();
    tableView3->setModel(sqlModel3);
    tableView3->verticalHeader()->setVisible(false);
    return tableView3;
}

QTableView* MainWindow::getFiliereView()
{
    sqlModel4 = Db->getFiliereList();
    tableView4->setModel(sqlModel4);
    tableView4->verticalHeader()->setVisible(false);
    return tableView4;
}



// ===== DIVERS ========================================================



void MainWindow::affiche(QString message)
{
    QMessageBox::information(this, "Information", message);
}

void MainWindow::test()
{

    QString filename("uvs.xml");
    xml->load(filename, uv, Db);

}


void MainWindow::exportDb()
{

}

void MainWindow::importDb()
{

}

void MainWindow::stop(QWidget* obj)
{
    obj->hide();
    mainLayout->removeWidget(obj);
    obj->disconnect();
}

void MainWindow::clear()
{
    titre->setText("");

    stop(Butt1);
    stop(Butt2);
    stop(Butt3);
    stop(Butt4);
    stop(Butt5);
    stop(Butt6);
    stop(Butt7);
    stop(Butt8);
    stop(Butt9);
    stop(Butt10);

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
    stop(label12);

    stop(le1);
    stop(le2);

    stop(tableView1);
    stop(tableView2);
    stop(tableView3);
    stop(tableView4);

    stop(combo1);

    stop(valider);
}

MainWindow::~MainWindow()
{
    delete ui;
}
