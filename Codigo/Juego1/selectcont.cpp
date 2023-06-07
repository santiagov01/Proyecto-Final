#include "selectcont.h"
#include "ui_selectcont.h"

SelectCont::SelectCont(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectCont)
{
    ui->setupUi(this);
//    QPushButton *previousButton = new QPushButton("Anterior", this);
//    connect(previousButton, &QPushButton::clicked, this, &SelectCont::goBack);

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


    connect(Boton_Senifini, &QPushButton::clicked, Pantalla_Inicio, [=]() {

        Crear_Cinematica("qrc:/Videos/Senifini.mp4");
        Reproducir();
        Continente=0;

    });
    connect(Boton_Filnar, &QPushButton::clicked, Pantalla_Inicio, [=]() {
        Crear_Cinematica("qrc:/Videos/Filnar.mp4");
        Reproducir();
        Continente=1;

    });
    connect(Boton_Abadtrah, &QPushButton::clicked, Pantalla_Inicio, [=]() {
        Crear_Cinematica("qrc:/Videos/Bragelante.mp4"); Reproducir();});
    connect(Boton_Bragelante, &QPushButton::clicked, Pantalla_Inicio, [=]() {
        Crear_Cinematica("qrc:/Videos/Bragelante.mp4"); Reproducir();});
    connect(Boton_Montino, &QPushButton::clicked, Pantalla_Inicio, [=]() {
        Crear_Cinematica("qrc:/Videos/Montino.mp4"); Reproducir();});
    connect(Boton_Rikcelare, &QPushButton::clicked, Pantalla_Inicio, [=]() {
        Crear_Cinematica("qrc:/Videos/Rikcelare.mp4"); Reproducir();});


}

void SelectCont::reiniciar_pantalla()
{
    delete player;
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
void SelectCont::Crear_Cinematica(QString Path)
{
    player = new QMediaPlayer(this);
    Cinematica = new QVideoWidget(this);
    //QMedia
    player->setSource(QUrl::fromLocalFile(Path));
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &SelectCont::Verificar_Estado);
}

void SelectCont::Reproducir()
{
    player->setVideoOutput(Cinematica);
    setCentralWidget(Cinematica);
    player->play();

}
void SelectCont::Verificar_Estado()
{

    if (player->mediaStatus() == QMediaPlayer::EndOfMedia)

    {
        //delete Cinematica;

        Selector= new QWidget(this);
        switch(Continente){
        case 1:{

            Selector->setEnabled(true);
            QPixmap Filnar_mision(":/Filnar completo 1.png");
            QLabel *Imagen_Filnar=new QLabel(Selector);
            Imagen_Filnar->setPixmap(Filnar_mision);
            Imagen_Filnar->setGeometry(0, 0, Filnar_mision.width(), Filnar_mision.height());

            QPushButton *Janukra = new QPushButton("Janukra",Selector);
            Janukra->setGeometry(780,305, 100, 50);
            QPushButton *Tehamu = new QPushButton("Tehamu", Selector);
            Tehamu->setGeometry(1070,305, 100, 50);
            QPushButton *Boton_Atras= new QPushButton("Atras",Selector);
            Boton_Atras->setGeometry(20,20,100,50);

            setCentralWidget(Selector);



            connect(Janukra, &QPushButton::clicked, this, [=]() {
                Mapa = new MainWindow(this,1);
                Mapa->setAttribute(Qt::WA_DeleteOnClose, true);
                reiniciar_pantalla();
                Mapa->show();

                hide();
            });
            connect(Tehamu, &QPushButton::clicked, this, [=]() {
                Mapa = new MainWindow(this,2);
                Mapa->setAttribute(Qt::WA_DeleteOnClose, true);
                reiniciar_pantalla();
                Mapa->show();

                hide();
            });
            connect(Boton_Atras,&QPushButton::clicked,this,[=](){
//                Selector->setVisible(false);
//                Pantalla_Inicio->setVisible(true);
//                setCentralWidget(Pantalla_Inicio);
                reiniciar_pantalla();
            });
        }
        }



        }
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
