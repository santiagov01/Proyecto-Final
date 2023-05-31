#include "selectcont.h"
#include "ui_selectcont.h"

SelectCont::SelectCont(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectCont)
{
    ui->setupUi(this);
    QPushButton *previousButton = new QPushButton("Anterior", this);
    connect(previousButton, &QPushButton::clicked, this, &SelectCont::goBack);

    QPushButton *nextButton = new QPushButton("Ventana C", this);
    nextButton->setGeometry(100,100,200,40);
    connect(nextButton, &QPushButton::clicked, this, &::SelectCont::openMapa);
    Mapa = new MainWindow(this);
}

SelectCont::~SelectCont()
{
    delete ui;
}
void SelectCont::openMapa()
{
   // SelectCont *SelectCont= new SelectCont(this);
  // SelectCont->setAttribute(Qt::WA_DeleteOnClose, true); // Establece la propiedad
    Mapa->show();
    hide();
}
void SelectCont::goBack(){
    parentWidget()->show();
    hide();
}
