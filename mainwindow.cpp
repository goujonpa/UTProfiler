#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Init ui
    MainWindow::setWindowState(Qt::WindowMaximized); // plein écran par défaut

    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);

    QAction *actionProfil = ui->menuProfil->addAction("Profil");
    QAction *actionSimulation = ui->menuSimulation->addAction("Simulation");
    QAction *actionConfig = ui->menuUTProfiler->addAction("Configuration");

    QToolBar *barreOutil = addToolBar("Profil");



}

MainWindow::~MainWindow()
{
    delete ui;
}
