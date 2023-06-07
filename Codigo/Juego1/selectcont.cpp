#include "selectcont.h"
#include "ui_selectcont.h"

SelectCont::SelectCont(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectCont)
{
    ui->setupUi(this);
    QPushButton *previousButton = new QPushButton("Anterior", this);
    connect(previousButton, &QPushButton::clicked, this, &SelectCont::goBack);

//    QPushButton *nextButton = new QPushButton("Ventana C", this);
//    nextButton->setGeometry(100,100,200,40);
//    connect(nextButton, &QPushButton::clicked, this, &::SelectCont::openMapa);
//    Mapa = new MainWindow(this,1);
    pantalla_continentes();


}

SelectCont::~SelectCont()
{
    delete ui;
}

void SelectCont::pantalla_continentes()
{
    Pantalla_Inicio= new QWidget();

    QPixmap Eilaar_static(":/Eilaar_static.png");
    QLabel *Imagen_Eilaar=new QLabel(Pantalla_Inicio);
    Imagen_Eilaar->setPixmap(Eilaar_static);
    Imagen_Eilaar->setGeometry(0, 0, Eilaar_static.width(), Eilaar_static.height());

    Boton_Senifini = new QPushButton("Senifini",Pantalla_Inicio);
    Boton_Senifini->setGeometry(0, 0, 100, 50);
    Boton_Filnar = new QPushButton("Filnar", Pantalla_Inicio);
    Boton_Filnar->setGeometry(100, 0, 100, 50);
    Boton_Abadtrah = new QPushButton("Abadtrah", Pantalla_Inicio);
    Boton_Abadtrah->setGeometry(0, 50, 100, 50);
    Boton_Bragelante = new QPushButton("Bragelante", Pantalla_Inicio);
    Boton_Bragelante->setGeometry(100, 50, 100, 50);
    Boton_Montino = new QPushButton("Montino", Pantalla_Inicio);
    Boton_Montino->setGeometry(0, 100, 100, 50);
    Boton_Rikcelare = new QPushButton("Rikcelare", Pantalla_Inicio);
    Boton_Rikcelare->setGeometry(100, 100, 100, 50);

    setCentralWidget(Pantalla_Inicio);


//    connect(Boton_Senifini, &QPushButton::clicked, Pantalla_Inicio, [=]() {
//        filnar = new Cinematica(this, "qrc:/Videos/Filnar.mp4",0);
//        filnar->setAttribute(Qt::WA_DeleteOnClose, true);
//        filnar->showFullScreen();
//        hide();

//    });
    connect(Boton_Filnar, &QPushButton::clicked, Pantalla_Inicio, [=]() {
        filnar = new Cinematica(this, "qrc:/Videos/Filnar.mp4",1);
        filnar->setAttribute(Qt::WA_DeleteOnClose, true);
        filnar->showFullScreen();
        hide();
    });
//    connect(Boton_Abadtrah, &QPushButton::clicked, Pantalla_Inicio, [=]() {
//        filnar = new Cinematica(this, "qrc:/Videos/Filnar.mp4",2);
//        filnar->setAttribute(Qt::WA_DeleteOnClose, true);
//        filnar->showFullScreen();
//        hide();
//    });
//    connect(Boton_Bragelante, &QPushButton::clicked, Pantalla_Inicio, [=]() {

//        filnar = new Cinematica(this, "qrc:/Videos/Bragelante.mp4",3);
//        filnar->setAttribute(Qt::WA_DeleteOnClose, true);
//        filnar->showFullScreen();
//        hide();
//    });
//    connect(Boton_Montino, &QPushButton::clicked, Pantalla_Inicio, [=]() {

//        filnar = new Cinematica(this, "qrc:/Videos/Montino.mp4",4);
//        filnar->setAttribute(Qt::WA_DeleteOnClose, true);
//        filnar->showFullScreen();
//        hide();
//    });
//    connect(Boton_Rikcelare, &QPushButton::clicked, Pantalla_Inicio, [=]() {
//        filnar = new Cinematica(this, "qrc:/Videos/Montino.mp4",5);
//        filnar->setAttribute(Qt::WA_DeleteOnClose, true);
//        filnar->showFullScreen();
//        hide();
//    });


}

void SelectCont::reiniciar_pantalla()
{
    //delete player;
    //delete Cinematica;
    //delete Pantalla_Inicio;
//    delete Boton_Senifini;
//    delete Boton_Filnar;
//    delete Boton_Abadtrah;
//    delete Boton_Bragelante;
//    delete Boton_Montino;
//    delete Boton_Rikcelare;

    pantalla_continentes();
}


//void SelectCont::openMapa()
//{
//   // SelectCont *SelectCont= new SelectCont(this);
//  // SelectCont->setAttribute(Qt::WA_DeleteOnClose, true); // Establece la propiedad
//    Cinematica->show();
//    hide();
//}
void SelectCont::goBack(){
    parentWidget()->show();
    hide();
}
