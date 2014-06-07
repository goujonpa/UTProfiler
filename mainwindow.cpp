#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Init ui
    MainWindow::setWindowState(Qt::WindowMaximized); // plein écran par défaut

    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);


    // ===== Actions & Menus =====

    QAction *actionProfil = ui->menuProfil->addAction("Profil");
    QAction *actionSimulation = ui->menuSimulation->addAction("Simulation");
    QAction *actionConfig = ui->menuUTProfiler->addAction("Configuration");




    // ===== Main Layout =====

    QGridLayout *mainlayout = new QGridLayout;
    zoneCentrale->setLayout(mainlayout);

    QPushButton *boutonProfil = new QPushButton;
    boutonProfil->setText("Profil");

    QPushButton *boutonSimulation = new QPushButton;
    boutonSimulation->setText("Simulation");

    QPushButton *boutonConfiguration = new QPushButton;
    boutonConfiguration->setText("Configuration");

    mainlayout->addWidget(boutonProfil,0,0,1,1);
    mainlayout->addWidget(boutonSimulation,0,1,1,1);
    mainlayout->addWidget(boutonConfiguration,0,2,1,1);

    QLabel *affichageProfil = new QLabel;
    affichageProfil->setText("Profil");
    mainlayout->addWidget(affichageProfil, 1,0,10,3);





}

MainWindow::~MainWindow()
{
    delete ui;
}
