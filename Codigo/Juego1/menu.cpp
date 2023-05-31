#include "menu.h"
#include "ui_menu.h"
#include <QTimer>
#include <QPushButton>
Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);

    QPushButton *nextButton = new QPushButton("Siguiente", this);
    connect(nextButton, &QPushButton::clicked, this, &Menu::openWindowB);
    windowB = new MainWindow(this);

//    QTimer *temp = new QTimer();
//    connect(temp, SIGNAL(timeout()), this, SLOT(openWindowB()));
    //temp->start(1000);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::openWindowB()
{
   // WindowB *windowB= new WindowB(this);
  // windowB->setAttribute(Qt::WA_DeleteOnClose, true); // Establece la propiedad
    windowB->show();
   hide();
}


