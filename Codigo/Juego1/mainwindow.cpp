
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Continentes=new Iniciar(this);
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::goBack);
    timer->start(5000);
    prueba=new Mision(1,this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goBack(){
    parentWidget()->show();
    hide();
}

