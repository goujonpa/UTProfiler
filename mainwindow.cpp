/*!
 * \file mainwindow.cpp
 * \brief Méthodes de la classe MainWindow
 * \author Goujon & Cortyl
 * \date 15 juin 2014
 *
 * Définition des méthodes de la classe MainWindow
 *
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*!
      *\brief Initialisation de la fenêtre
      */
    // ===== Init window =====

    ui->setupUi(this); // Init ui
    MainWindow::setWindowState(Qt::WindowMaximized); // plein écran par défaut

    /*!
      *\brief Initialisation de la BDD
      */
    // ===== Init Db =====

    Db = new DbManager;

    /*!
      *\brief Initialisation des Widget
      */
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


    /*!
      *\brief initialisation du XML
      */
    // ===== Init xml =====

    xml = new XmlManager;

    /*!
      *\brief gère la vue principale
      */
    // ===== Main Layout =====

    mainLayout = new QGridLayout;
    zoneCenter->setLayout(mainLayout);

    QLabel* spacer = new QLabel; // -> les boutons sont toujours en haut, et la fenêtre a toujours a peu près la même géométrie
    mainLayout->addWidget(spacer, 0,0,15,6);
    spacer->hide();

    /*!
      *\brief gère la toolbar
      */
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

    /*!
      *\brief Initialisation de l'utilisateur
      */
    // ==== Init user =====

    titre = new QLabel;
    mainLayout->addWidget(titre, 1,0,1,3);

    /*!
      *\brief Initialisation des boutons
      */
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

    /*!
      *\brief Initialisation de QStandardItemModel
      */
    // ===== Init QSIM =====

    stdItMod1 = new QStandardItemModel;
    stdItMod2 = new QStandardItemModel;
    stdItMod3 = new QStandardItemModel;

    /*!
      *\brief Initialisation de LineEdits
      */
    // ===== Init LineEdits =====

    le1 = new QLineEdit;
    le2 = new QLineEdit;

    /*!
      *\brief Initialisation des labelles.
      */
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

    /*!
      *Initialisation du
      */
    // ===== Init Sql MVC =====

    sqlModel1 = new QSqlQueryModel;
    sqlModel2 = new QSqlQueryModel;
    sqlModel3 = new QSqlQueryModel;
    sqlModel4 = new QSqlQueryModel;
    tableView1 = new QTableView;
    tableView2 = new QTableView;
    tableView3 = new QTableView;
    tableView4 = new QTableView;
    utableView = new QTableView;


    /*!
      *\brief Divers
      */
    // ===== Divers =====

    valider = new QPushButton;
    valider->setText("Valider");

    combo1 = new QComboBox;
    dialog1 = new QDialog(this);
    progress1 = new QProgressBar;
    slider1 = new QSlider(Qt::Horizontal);


    /*!
      *\brief Connection
      */
    // ===== Connect =====

    QObject::connect(mainProfilButt, SIGNAL(clicked()), this, SLOT(clear()));
    QObject::connect(mainProfilButt, SIGNAL(clicked()), this, SLOT(showProfilEdit()));

    mainSimuButt->setEnabled(false);
    QObject::connect(mainSimuButt, SIGNAL(clicked()), this, SLOT(clear()));
    QObject::connect(mainSimuButt, SIGNAL(clicked()), this, SLOT(showSimulationEdit()));

    QObject::connect(mainConfigButt, SIGNAL(clicked()), this, SLOT(clear()));
    QObject::connect(mainConfigButt, SIGNAL(clicked()), this, SLOT(showConfigEdit()));
}

/*!
  *\brief Selection d'un objet
  */
// ===== SELECT ITEMS =====================================================



void MainWindow::selectUser()
{
    if (Db->m_user != NULL)
    {
        QMessageBox::information(this, "Chargement de l'utilisateur", "Veuillez patienter pendant l'enregistrement des données courantes et le chargement du nouvel utilisateur. Cela peut prendre quelques instants.");
        Db->update();
    }
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


/*!
  *\brief Afficher un objet
  */
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
    if (Db->m_user->getProfil() != 0)
        profilRep = "Oui";
    if (Db->m_user->getSimulation() != 0)
        simuRep = "Oui";
    stdItMod1->setItem(2,1, new QStandardItem(profilRep));
    stdItMod1->setItem(3,1, new QStandardItem(simuRep));
    utableView->setModel(stdItMod1);
    utableView->horizontalHeader()->setVisible(false);
    utableView->verticalHeader()->setVisible(false);
    mainLayout->addWidget(utableView, 6,0,4,2);
    utableView->show();
    if (Db->m_user != NULL)
        mainSimuButt->setEnabled(true);

}

void MainWindow::showProfilInfo()
{
    clear();
    showProfilEdit();
    label1->setText("Informations du Profil :");
    mainLayout->addWidget(label1, 2,3,1,2);
    label1->show();

    stdItMod2->setColumnCount(2);
    stdItMod2->setRowCount(4);
    stdItMod2->setItem(0,0, new QStandardItem("Branche :"));
    stdItMod2->setItem(1,0, new QStandardItem("Filière :"));
    stdItMod2->setItem(2,0, new QStandardItem("Branche désirée :"));
    stdItMod2->setItem(3,0, new QStandardItem("Filière désirée :"));
    stdItMod2->setItem(0,1, new QStandardItem(Db->m_user->getProfil()->getActuel()->getBranche()->getCode()));
    stdItMod2->setItem(1,1, new QStandardItem(Db->m_user->getProfil()->getActuel()->getFiliere()->getCode()));
    stdItMod2->setItem(2,1, new QStandardItem(Db->m_user->getProfil()->getVise()->getBranche()->getCode()));
    stdItMod2->setItem(3,1, new QStandardItem(Db->m_user->getProfil()->getVise()->getFiliere()->getCode()));
    tableView1->setModel(stdItMod2);
    tableView1->horizontalHeader()->setVisible(false);
    tableView1->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView1, 3,3,3,2);
    tableView1->show();

    if (Db->m_user->getProfil()->getInscriptions() != 0)
    {
        label2->setText("Inscriptions :");
        mainLayout->addWidget(label2, 6,3,1,2);
        label2->show();

        stdItMod3->clear();
        stdItMod3->setColumnCount(4);
        stdItMod3->setItem(0,0, new QStandardItem("UV"));
        stdItMod3->setItem(0,1, new QStandardItem("Saison"));
        stdItMod3->setItem(0,2, new QStandardItem("Année"));
        stdItMod3->setItem(0,3, new QStandardItem("Note"));
        QMap<unsigned int, Inscription*>::Iterator it;
        int i = 0;
        for (it = Db->m_user->getProfil()->getInscriptions()->begin(); it != Db->m_user->getProfil()->getInscriptions()->end(); ++it)
        {
            i++;
            stdItMod3->setItem(i,0, new QStandardItem(it.value()->getUV()->getCode()));
            QString saison = "Printemps";
            if (it.value()->getSemestre()->getSaison() == Automne)
                saison = "Automne";
            stdItMod3->setItem(i,1, new QStandardItem(saison));
            stdItMod3->setItem(i,2, new QStandardItem(QString::number(it.value()->getSemestre()->getAnnee())));
            stdItMod3->setItem(i,3, new QStandardItem(it.value()->getNote()->getCode()));
        }
        tableView2->setModel(stdItMod3);
        tableView2->horizontalHeader()->setVisible(false);
        tableView2->verticalHeader()->setVisible(false);
        mainLayout->addWidget(tableView2, 7,3,3,2);
        tableView2->show();
    }

}


/*!
  *\brief Afficher les tableaux
  */
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

    mainLayout->addWidget(Butt3, 3,0,1,1);
    Butt3->setText("Renseigner Profil");
    Butt3->show();
    QObject::connect(Butt3, SIGNAL(clicked()), this, SLOT(showProfilForm()));

    Butt4->setText("Afficher Profil");
    Butt4->show();
    mainLayout->addWidget(Butt4, 3,1,1,1);
    QObject::connect(Butt4, SIGNAL(clicked()), this, SLOT(showProfilInfo()));

    Butt5->setText("Ajouter Inscription");
    Butt5->show();
    mainLayout->addWidget(Butt5, 4,0,1,2);
    QObject::connect(Butt5, SIGNAL(clicked()), this, SLOT(showNewInscriptionForm()));

    mainLayout->addWidget(Butt6, 5,0,1,1);
    Butt6->setText("Ajout Semestre à l'étranger");
    Butt6->show();
    QObject::connect(Butt6, SIGNAL(clicked()), this, SLOT(showNewEtrangerForm()));

    Butt7->setText("Catalogue Semestres à l'étranger");
    Butt7->show();
    mainLayout->addWidget(Butt7, 5,1,1,1);
    QObject::connect(Butt7, SIGNAL(clicked()), this, SLOT(showEtrangerList()));

    if (Db->m_user != NULL)
    {
        showUser();
        if (Db->m_user->getProfil() == 0)
        {
            Butt4->setEnabled(false);
            Butt5->setEnabled(false);
            Butt6->setEnabled(false);
            Butt7->setEnabled(false);
        }
    }
    else
    {
        Butt3->setEnabled(false);
        Butt4->setEnabled(false);
        Butt5->setEnabled(false);
        Butt6->setEnabled(false);
        Butt7->setEnabled(false);
    }
}

void MainWindow::showSimulationEdit()
{
    titre->setText("Gestion de la simulation");

    mainLayout->addWidget(Butt1, 2,0,1,1);
    Butt1->setText("Ajout Bonus UV");
    Butt1->show();
    QObject::connect(Butt1, SIGNAL(clicked()), this, SLOT(showNewBonusForm()));

    mainLayout->addWidget(Butt2, 2,1,1,1);
    Butt2->setText("Catalogue Bonus UV");
    Butt2->show();
    QObject::connect(Butt2, SIGNAL(clicked()), this, SLOT(showBonusList()));

    mainLayout->addWidget(Butt3, 3,0,1,1);
    Butt3->setText("Ajout Désir par Semestre");
    Butt3->show();
    QObject::connect(Butt3, SIGNAL(clicked()), this, SLOT(showNewDesirForm()));

    mainLayout->addWidget(Butt4, 3,1,1,1);
    Butt4->setText("Catalogue Désirs par Semestre");
    Butt4->show();
    QObject::connect(Butt4, SIGNAL(clicked()), this, SLOT(showDesirsList()));

    mainLayout->addWidget(Butt5, 4,0,1,1);
    Butt5->setText("Ajout Semestre à l'étranger");
    Butt5->show();
    QObject::connect(Butt5, SIGNAL(clicked()), this, SLOT(showNewPrefEtrangerForm()));

    mainLayout->addWidget(Butt6, 4,1,1,1);
    Butt6->setText("Catalogue Semestres à l'étranger");
    Butt6->show();
    QObject::connect(Butt6, SIGNAL(clicked()), this, SLOT(showPrefEtrangersList()));

    mainLayout->addWidget(Butt7, 6,0,1,2);
    Butt7->setText("Lancer la Simulation");
    Butt7->show();
    //QObject::connect(Butt7, SIGNAL(clicked()), this, SLOT(showFiliereList()));

    if (Db->m_user->getProfil()->getBonus() == 0)
        Butt2->setEnabled(false);
    if (Db->m_user->getProfil()->getDesirs() == 0)
        Butt4->setEnabled(false);
    if (Db->m_user->getProfil()->getPrefEtrangers() == 0)
        Butt6->setEnabled(false);
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

    mainLayout->addWidget(Butt3, 7,0,1,2);
    Butt3->setText("Test");
    Butt3->show();
    QObject::connect(Butt3, SIGNAL(clicked()), this, SLOT(test()));

    mainLayout->addWidget(Butt4, 3,0,1,1);
    Butt4->setText("Ajout Categorie");
    Butt4->show();
    QObject::connect(Butt4, SIGNAL(clicked()), this, SLOT(showNewCatForm()));

    mainLayout->addWidget(Butt5, 3,1,1,1);
    Butt5->setText("Catalogue Categories");
    Butt5->show();
    QObject::connect(Butt5, SIGNAL(clicked()), this, SLOT(showCatList()));

    mainLayout->addWidget(Butt6, 4,0,1,1);
    Butt6->setText("Ajout Filiere");
    Butt6->show();
    QObject::connect(Butt6, SIGNAL(clicked()), this, SLOT(showNewFiliereForm()));

    mainLayout->addWidget(Butt7, 4,1,1,1);
    Butt7->setText("Catalogue Filieres");
    Butt7->show();
    QObject::connect(Butt7, SIGNAL(clicked()), this, SLOT(showFiliereList()));

    mainLayout->addWidget(Butt8, 6,0,1,2);
    Butt8->setText("Catalogue d'UVs");
    Butt8->show();
    QObject::connect(Butt8, SIGNAL(clicked()), this, SLOT(showUVList()));

    mainLayout->addWidget(Butt9, 5,0,1,1);
    Butt9->setText("Ajout Note");
    Butt9->show();
    QObject::connect(Butt9, SIGNAL(clicked()), this, SLOT(showNewNoteForm()));

    mainLayout->addWidget(Butt10, 5,1,1,1);
    Butt10->setText("Catalogue Notes");
    Butt10->show();
    QObject::connect(Butt10, SIGNAL(clicked()), this, SLOT(showNoteList()));

}


/*!
  *\brief Affichage des formulaires
  */
// ===== SHOW FORMS =======================================================

void MainWindow::showNewBonusForm()
{
    clear();
    label1->setText("Choix de l'UV :");
    mainLayout->addWidget(label1, 2,3,1,1);
    label1->show();

    getUvView();
    mainLayout->addWidget(tableView1, 3,3,5,3);
    tableView1->show();

    label2->setText("Bonus :");
    mainLayout->addWidget(label2, 8,3,1,1);
    label2->show();

    slider1->setRange(-2, 2);
    mainLayout->addWidget(slider1, 9,3,1,3);
    slider1->show();

    label3->setText("Pas de bonus");
    mainLayout->addWidget(label3, 10,4,1,2);
    label3->show();

    label4->setText("Signification du Bonus :");
    mainLayout->addWidget(label4, 10,3,1,1);
    label4->show();

    QObject::connect(slider1, SIGNAL(valueChanged(int)), this, SLOT(sliderBonus(int)));

    mainLayout->addWidget(valider, 11,3,1,3);
    valider->show();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valideNewBonusForm()));

    showSimulationEdit();
}

void MainWindow::showProfilForm()
{
    clear();
    label1->setText("Choix UV :");
    mainLayout->addWidget(label1, 2,3,1,1);
    label1->show();

    label2->setText("Branche :");
    mainLayout->addWidget(label2, 3,3,1,1);
    label2->show();

    getBrancheView();
    mainLayout->addWidget(tableView3, 4,3,2,3);
    tableView3->show();

    label3->setText("Filiere :");
    mainLayout->addWidget(label3, 6,3,1,1);
    label3->show();

    getFiliereView();
    mainLayout->addWidget(tableView4, 7,3,2,3);
    tableView4->show();

    label4->setText("Cursus visé");
    mainLayout->addWidget(label4, 9,3,1,1);
    label4->show();

    label5->setText("Branche :");
    mainLayout->addWidget(label5, 10,3,1,1);
    label5->show();

    getBrancheView2();
    mainLayout->addWidget(tableView1, 11,3,2,3);
    tableView1->show();

    label6->setText("Filiere :");
    mainLayout->addWidget(label6, 13,3,1,1);
    label6->show();

    getFiliereView2();
    mainLayout->addWidget(tableView2, 14,3,2,3);
    tableView2->show();

    mainLayout->addWidget(valider, 16,3,1,1);
    valider->show();

    showProfilEdit();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valideProfilForm()));
}


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

void MainWindow::showNewDesirForm()
{
    clear();
    label10->setText("Ajout de désir par semestre :");
    mainLayout->addWidget(label10, 2,3,1,1);
    label10->show();

    getUvView();
    mainLayout->addWidget(tableView1, 3,3,3,3);
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

    mainLayout->addWidget(valider, 8,3,1,3);
    valider->show();

    showSimulationEdit();

    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valideNewDesirForm()));
}


void MainWindow::showNewInscriptionForm()
{
    clear();
    label10->setText("Ajout d'Inscriptions :");
    mainLayout->addWidget(label10, 2,3,1,1);
    label10->show();

    getUvView();
    mainLayout->addWidget(tableView1, 3,3,3,3);
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

    showProfilEdit();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valideNewInscriptionForm()));
}

void MainWindow::showNewEtrangerForm()
{
    clear();
    label10->setText("Ajout de semestres à l'étranger :");
    mainLayout->addWidget(label10, 2,3,1,1);
    label10->show();

    label11->setText("Titre :");
    mainLayout->addWidget(label11, 3,3,1,1);
    label11->show();

    mainLayout->addWidget(le2, 3,4,1,2);
    le2->show();


    combo1->addItem("Printemps");
    combo1->addItem("Automne");
    mainLayout->addWidget(combo1, 4,3,1,3);
    combo1->show();

    label1->setText("Année :");
    mainLayout->addWidget(label1, 5,3,1,1);
    label1->show();

    mainLayout->addWidget(le1, 5,4,1,2);
    le1->show();

    valider->setText("Valider");
    mainLayout->addWidget(valider, 6,3,1,3);
    valider->show();

    showProfilEdit();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valideNewEtrangerForm()));
}

void MainWindow::showNewPrefEtrangerForm()
{
    clear();
    label10->setText("Ajout de semestres à l'étranger :");
    mainLayout->addWidget(label10, 2,3,1,1);
    label10->show();

    label11->setText("Titre :");
    mainLayout->addWidget(label11, 3,3,1,1);
    label11->show();

    mainLayout->addWidget(le2, 3,4,1,2);
    le2->show();


    combo1->addItem("Printemps");
    combo1->addItem("Automne");
    mainLayout->addWidget(combo1, 4,3,1,3);
    combo1->show();

    label1->setText("Année :");
    mainLayout->addWidget(label1, 5,3,1,1);
    label1->show();

    mainLayout->addWidget(le1, 5,4,1,2);
    le1->show();

    valider->setText("Valider");
    mainLayout->addWidget(valider, 6,3,1,3);
    valider->show();

    showSimulationEdit();
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(valideNewPrefEtrangerForm()));
}




/*!
  *\brief Formulaires Valident
  */
// ===== VALIDE FORMS ==========================================================


void MainWindow::valideNewEtrangerForm()
{
    unsigned int id;

    Saison saison = Printemps;
    if (combo1->currentText() == "Automne")
        saison = Automne;

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

    QString titre = le2->text();

    Etranger* etranger = new Etranger(0, titre, semestre);
    id = Db->insertItem(etranger);
    etranger->setId(id);
    Db->m_user->getProfil()->addEtranger(etranger);
    Db->m_etrangers->insert(etranger->getId(), etranger);

    clear();
    showProfilEdit();
}

void MainWindow::valideNewPrefEtrangerForm()
{
    unsigned int id;

    Saison saison = Printemps;
    if (combo1->currentText() == "Automne")
        saison = Automne;

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

    QString titre = le2->text();

    Etranger* etranger = new Etranger(0, titre, semestre);
    id = Db->insertItem(etranger);
    etranger->setId(id);
    Db->m_user->getProfil()->addPrefEtranger(etranger);
    Db->m_etrangers->insert(etranger->getId(), etranger);

    clear();
    showSimulationEdit();
}

void MainWindow::valideProfilForm()
{

    QItemSelectionModel* selection = tableView3->selectionModel();
    QModelIndex index1 = selection->currentIndex();
    QModelIndex index2 = index1.sibling(index1.row(),0);
    QVariant variant1 = sqlModel3->data(index2);
    unsigned int id = variant1.toInt();
    branche = Db->m_branches->find(id).value();

    selection = tableView4->selectionModel();
    index1 = selection->currentIndex();
    index2 = index1.sibling(index1.row(),0);
    variant1 = sqlModel4->data(index2);
    id = variant1.toInt();
    filiere = Db->m_filieres->find(id).value();

    cursus = new Cursus(0, branche, filiere);

    QMap<unsigned int, Cursus*>::iterator it;

    for (it = Db->m_cursus->begin(); it != Db->m_cursus->end(); ++it)
    {
        if ((it.value()->getBranche() == branche) && (it.value()->getFiliere() == filiere))
            cursus = it.value();
    }

    if (cursus->getId() == 0)
    {
        id = Db->insertItem(cursus);
        cursus->setId(id);
        Db->m_cursus->insert(cursus->getId(), cursus);
    }

    selection = tableView1->selectionModel();
    index1 = selection->currentIndex();
    index2 = index1.sibling(index1.row(),0);
    variant1 = sqlModel1->data(index2);
    id = variant1.toInt();
    branche = Db->m_branches->find(id).value();

    selection = tableView2->selectionModel();
    index1 = selection->currentIndex();
    index2 = index1.sibling(index1.row(),0);
    variant1 = sqlModel2->data(index2);
    id = variant1.toInt();
    filiere = Db->m_filieres->find(id).value();


    cursus2 = new Cursus(0, branche, filiere);
    QMap<unsigned int, Cursus*>::iterator it2;

    for (it2 = Db->m_cursus->begin(); it2 != Db->m_cursus->end(); ++it2)
    {
        if ((it2.value()->getBranche() == branche) && (it2.value()->getFiliere() == filiere))
            cursus2 = it2.value();
    }

    if (cursus2->getId() == 0)
    {
        id = Db->insertItem(cursus2);
        cursus2->setId(id);
        Db->m_cursus->insert(cursus2->getId(), cursus2);
    }

    if (Db->m_user->getProfil() == 0)
    {
        profil = new Profil(0, 0, cursus, cursus2, 0, 0, 0, 0);
        id = Db->insertItem(profil);
        profil->setId(id);
        Db->m_profils->insert(profil->getId(), profil);
        Db->m_user->setProfil(profil);
    }
    else
    {
        Db->m_user->getProfil()->setActuel(cursus);
        Db->m_user->getProfil()->setVise(cursus2);
    }

    clear();
    showProfilEdit();
}

void MainWindow::valideNewDesirForm()
{

    QItemSelectionModel* selection = tableView1->selectionModel();
    QModelIndex index1 = selection->currentIndex();
    QModelIndex index2 = index1.sibling(index1.row(),0);
    QVariant variant1 = sqlModel1->data(index2);
    unsigned int id = variant1.toInt();
    uv = Db->m_uvs->find(id).value();

    Saison saison = Printemps;
    if (combo1->currentText() == "Automne")
        saison = Automne;

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

    DesirUV* desir = new DesirUV(0, uv, semestre);
    id = Db->insertItem(desir);
    desir->setId(id);
    Db->m_user->getProfil()->addDesir(desir);
    Db->m_desirs->insert(desir->getId(), desir);

    clear();
    showSimulationEdit();
}

void MainWindow::valideNewInscriptionForm()
{

    QItemSelectionModel* selection = tableView1->selectionModel();
    QModelIndex index1 = selection->currentIndex();
    QModelIndex index2 = index1.sibling(index1.row(),0);
    QVariant variant1 = sqlModel1->data(index2);
    unsigned int id = variant1.toInt();
    uv = Db->m_uvs->find(id).value();

    selection = tableView2->selectionModel();
    index1 = selection->currentIndex();
    index2 = index1.sibling(index1.row(),0);
    variant1 = sqlModel2->data(index2);
    id = variant1.toInt();
    note = Db->m_notes->find(id).value();

    selection = tableView3->selectionModel();
    index1 = selection->currentIndex();
    index2 = index1.sibling(index1.row(),0);
    variant1 = sqlModel3->data(index2);
    id = variant1.toInt();
    branche = Db->m_branches->find(id).value();

    selection = tableView4->selectionModel();
    index1 = selection->currentIndex();
    index2 = index1.sibling(index1.row(),0);
    variant1 = sqlModel4->data(index2);
    id = variant1.toInt();
    filiere = Db->m_filieres->find(id).value();

    Saison saison = Printemps;
    if (combo1->currentText() == "Automne")
        saison = Automne;

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

    cursus = new Cursus(0, branche, filiere);

    QMap<unsigned int, Cursus*>::iterator it2;

    for (it2 = Db->m_cursus->begin(); it2 != Db->m_cursus->end(); ++it2)
    {
        if ((it2.value()->getBranche() == branche) && (it2.value()->getFiliere() == filiere))
            cursus = it2.value();
    }

    if (cursus->getId() == 0)
    {
        id = Db->insertItem(cursus);
        cursus->setId(id);
        Db->m_cursus->insert(cursus->getId(), cursus);
    }


    inscription = new Inscription(0, uv, semestre, note, cursus, uv->getCategorie());
    id = Db->insertItem(inscription);
    inscription->setId(id);
    Db->m_inscriptions->insert(inscription->getId(), inscription);
    Db->m_user->getProfil()->addInscription(inscription);


    clear();
    showProfilEdit();
}


void MainWindow::valideNewBonusForm()
{
    QItemSelectionModel* selection = tableView1->selectionModel();
    QModelIndex index1 = selection->currentIndex();
    QModelIndex index2 = index1.sibling(index1.row(),0);
    QVariant variant1 = sqlModel1->data(index2);
    unsigned int id = variant1.toInt();
    uv = Db->m_uvs->find(id).value();

    unsigned int valeur = slider1->value();

    BonusUV* bonus = new BonusUV(0, uv, valeur);
    id = Db->insertItem(bonus);
    bonus->setId(id);

    Db->m_user->getProfil()->addBonus(bonus);
    Db->m_bonus->insert(bonus->getId(), bonus);

    clear();
    showSimulationEdit();
}

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
    branche = Db->m_branches->find(variant1.toInt()).value();

    selection = tableView2->selectionModel();
    index1 = selection->currentIndex();
    index2 = index1.sibling(index1.row(),0);
    variant1 = sqlModel1->data(index2);
    filiere = Db->m_filieres->find(variant1.toInt()).value();

    cursus = new Cursus(0, branche, filiere);
    int id = Db->insertItem(cursus);
    cursus->setId(id);

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
    {
        affiche("Nouvel Utilisateur créé.");
        Db->m_user = user;
    }
    if (idUser == -1)
        affiche("Erreur : echec, too bad, my bad.");
    clear();
    showProfilEdit();
}


/*!
  *\brief Affichage des listes
  */
// ===== SHOW LISTS =======================================================

void MainWindow::showBonusList()
{
    clear();
    label2->setText("Vos bonus :");
    mainLayout->addWidget(label2, 2,3,1,2);
    label2->show();

    stdItMod3->clear();
    stdItMod3->setColumnCount(2);
    stdItMod3->setItem(0,0, new QStandardItem("UV"));
    stdItMod3->setItem(0,1, new QStandardItem("Bonus"));
    QMap<unsigned int, BonusUV*>::Iterator it;
    int i = 0;
    for (it = Db->m_user->getProfil()->getBonus()->begin(); it != Db->m_user->getProfil()->getBonus()->end(); ++it)
    {
        i++;
        stdItMod3->setItem(i,0, new QStandardItem(it.value()->getUV()->getCode()));
        QString bonus;
        switch (it.value()->getBonus())
        {
            case 0:
                bonus = "Pas de bonus";
                break;
            case 1:
                bonus = "UV désirée";
                break;
            case 2:
                bonus = "UV exigée";
                break;
            case -1:
                bonus = "UV non désirée";
                break;
            case -2:
                bonus = "UV rejetée";
                break;
        }
        stdItMod3->setItem(i,1, new QStandardItem(bonus));
    }
    tableView2->setModel(stdItMod3);
    tableView2->horizontalHeader()->setVisible(false);
    tableView2->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView2, 3,3,3,2);
    tableView2->show();
    showSimulationEdit();
}


void MainWindow::showDesirsList()
{
    clear();
    label2->setText("Vos désirs :");
    mainLayout->addWidget(label2, 2,3,1,2);
    label2->show();

    stdItMod3->clear();
    stdItMod3->setColumnCount(3);
    stdItMod3->setItem(0,0, new QStandardItem("UV"));
    stdItMod3->setItem(0,1, new QStandardItem("Saison"));
    stdItMod3->setItem(0,2, new QStandardItem("Année"));
    QMap<unsigned int, DesirUV*>::Iterator it;
    int i = 0;
    for (it = Db->m_user->getProfil()->getDesirs()->begin(); it != Db->m_user->getProfil()->getDesirs()->end(); ++it)
    {
        i++;
        stdItMod3->setItem(i,0, new QStandardItem(it.value()->getUV()->getCode()));
        QString saison = "Printemps";
        if (it.value()->getSemestre()->getSaison() == Automne)
            saison = "Automne";
        stdItMod3->setItem(i,1, new QStandardItem(saison));
        stdItMod3->setItem(i,2, new QStandardItem(QString::number(it.value()->getSemestre()->getAnnee())));
    }
    tableView2->setModel(stdItMod3);
    tableView2->horizontalHeader()->setVisible(false);
    tableView2->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView2, 3,3,3,2);
    tableView2->show();
    showSimulationEdit();

}

void MainWindow::showEtrangerList()
{
    clear();
    label2->setText("Vos semestres à l'étranger :");
    mainLayout->addWidget(label2, 2,3,1,2);
    label2->show();

    stdItMod3->clear();
    stdItMod3->setColumnCount(3);
    stdItMod3->setItem(0,0, new QStandardItem("Titre"));
    stdItMod3->setItem(0,1, new QStandardItem("Saison"));
    stdItMod3->setItem(0,2, new QStandardItem("Année"));
    QMap<unsigned int, Etranger*>::Iterator it;
    int i = 0;
    for (it = Db->m_user->getProfil()->getEtrangers()->begin(); it != Db->m_user->getProfil()->getEtrangers()->end(); ++it)
    {
        i++;
        stdItMod3->setItem(i,0, new QStandardItem(it.value()->getTitre()));
        QString saison = "Printemps";
        if (it.value()->getSemestre()->getSaison() == Automne)
            saison = "Automne";
        stdItMod3->setItem(i,1, new QStandardItem(saison));
        stdItMod3->setItem(i,2, new QStandardItem(QString::number(it.value()->getSemestre()->getAnnee())));
    }
    tableView2->setModel(stdItMod3);
    tableView2->horizontalHeader()->setVisible(false);
    tableView2->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView2, 3,3,3,2);
    tableView2->show();
    showProfilEdit();

}


void MainWindow::showPrefEtrangersList()
{
    clear();
    label2->setText("Semestres à l'étranger désirés :");
    mainLayout->addWidget(label2, 2,3,1,2);
    label2->show();

    stdItMod3->clear();
    stdItMod3->setColumnCount(3);
    stdItMod3->setItem(0,0, new QStandardItem("Titre"));
    stdItMod3->setItem(0,1, new QStandardItem("Saison"));
    stdItMod3->setItem(0,2, new QStandardItem("Année"));
    QMap<unsigned int, Etranger*>::Iterator it;
    int i = 0;
    for (it = Db->m_user->getProfil()->getPrefEtrangers()->begin(); it != Db->m_user->getProfil()->getPrefEtrangers()->end(); ++it)
    {
        i++;
        stdItMod3->setItem(i,0, new QStandardItem(it.value()->getTitre()));
        QString saison = "Printemps";
        if (it.value()->getSemestre()->getSaison() == Automne)
            saison = "Automne";
        stdItMod3->setItem(i,1, new QStandardItem(saison));
        stdItMod3->setItem(i,2, new QStandardItem(QString::number(it.value()->getSemestre()->getAnnee())));
    }
    tableView2->setModel(stdItMod3);
    tableView2->horizontalHeader()->setVisible(false);
    tableView2->verticalHeader()->setVisible(false);
    mainLayout->addWidget(tableView2, 3,3,3,2);
    tableView2->show();
    showSimulationEdit();

}




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


/*!
  *\brief Récupérer des vues
  */
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

QTableView* MainWindow::getBrancheView2()
{
    sqlModel1 = Db->getBranchList();
    tableView1->setModel(sqlModel1);
    tableView1->verticalHeader()->setVisible(false);
    return tableView1;
}

QTableView* MainWindow::getFiliereView2()
{
    sqlModel2 = Db->getFiliereList();
    tableView2->setModel(sqlModel2);
    tableView2->verticalHeader()->setVisible(false);
    return tableView2;
}



/*!
  *\brief Divers
  */
// ===== DIVERS ========================================================



void MainWindow::affiche(QString message)
{
    QMessageBox::information(this, "Information", message);
}

void MainWindow::test()
{
    //QMessageBox::information(this, "profil existe ?", QString::number(Db->m_profils->find(3).value()->getId()));
    for (QMap<unsigned int, Inscription*>::Iterator it = Db->m_inscriptions->begin(); it != Db->m_inscriptions->end(); it++)
    {
        QString message = QString::number(it.value()->getId());

        QMessageBox::information(this, "Id Profil", message);
    }

    //QMessageBox::information(this, "test", Db->m_test);


    //bool ret;
    //QString message;
    //message = Db->m_user->getProfil()->getActuel()->getBranche()->getCode();
    //QMessageBox::information(this, "Branche Actuelle", message);
    //message = Db->m_user->getProfil()->getVise()->getFiliere()->getCode();
    //QMessageBox::information(this, "Filiere visée", message);

    //QSqlError err = Db->lastError();
    //affiche(err.text());
    //QString filename("uvs.xml");
    //xml->load(filename, Db);
    //Db->remove();
    //Db->save();
    //Db->deleteDb();
    //ret = Db->createTables();
    //if (ret)
        //QMessageBox::information(this, "tables", "ok");
    //xml->load(filename, Db);
    //Db->save();

    /*
    QMap<unsigned int, UV*>::Iterator it;
    for (it = Db->m_uvs->begin(); it != Db->m_uvs->end(); ++it)
    {
        if (it.value()->getId() < 15)
        {
            QString message;
            message += it.value()->getCode();
            message += QString::number(it.value()->getCredits());
            message += it.value()->getCategorie()->getCode();
            if (it.value()->getCursus() == 0)
                message += "oui";
            QMessageBox::information(this, "", message);
        }


    }
    */
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
    Butt1->setEnabled(true);
    Butt2->setEnabled(true);
    Butt3->setEnabled(true);
    Butt4->setEnabled(true);
    Butt5->setEnabled(true);
    Butt6->setEnabled(true);
    Butt7->setEnabled(true);
    Butt8->setEnabled(true);
    Butt9->setEnabled(true);
    Butt10->setEnabled(true);

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
    stop(utableView);

    stop(slider1);

    stop(combo1);
    combo1->removeItem(1);
    combo1->removeItem(0);

    stop(valider);
}

MainWindow::~MainWindow()
{
    Db->~DbManager();
    delete ui;
}

void MainWindow::sliderBonus(int val)
{
    if (val ==  0)
    {
        label3->setText("Pas de Bonus");
    }
    if (val == 1)
    {
        label3->setText("J'apprécierais cette UV");
    }
    if (val == 2)
    {
        label3->setText("Je veux absolumment cette UV");
    }
    if (val == -1)
    {
        label3->setText("J'aimerais éviter cette UV");
    }
    if (val == -2)
    {
        label3->setText("Je ne veux pas du tout cette UV");
    }
}
