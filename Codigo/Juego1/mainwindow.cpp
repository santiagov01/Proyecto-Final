#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Continentes = new Iniciar(this);
    //MainWindow().showFullScreen();
    Mision1 = new Mision(1, this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


