
#include "iniciar.h"
#include "mision.h"

Iniciar::Iniciar( QMainWindow* mainwindow): mainwindow(mainwindow)
{
    Pantalla_Inicio= new QWidget();

    QPixmap Eilaar_static(":/Eilaar_static.png");
    QLabel *Imagen_Eilaar=new QLabel(Pantalla_Inicio);
    Imagen_Eilaar->setPixmap(Eilaar_static);
    Imagen_Eilaar->setGeometry(0, 0, Eilaar_static.width(), Eilaar_static.height());

    QPushButton *Boton_Senifini = new QPushButton("Senifini",Pantalla_Inicio);
    Boton_Senifini->setGeometry(0, 0, 100, 50);
    QPushButton *Boton_Filnar = new QPushButton("Filnar", Pantalla_Inicio);
    Boton_Filnar->setGeometry(100, 0, 100, 50);
    QPushButton *Boton_Abadtrah = new QPushButton("Abadtrah", Pantalla_Inicio);
    Boton_Abadtrah->setGeometry(0, 50, 100, 50);
    QPushButton *Boton_Bragelante = new QPushButton("Bragelante", Pantalla_Inicio);
    Boton_Bragelante->setGeometry(100, 50, 100, 50);
    QPushButton *Boton_Montino = new QPushButton("Montino", Pantalla_Inicio);
    Boton_Montino->setGeometry(0, 100, 100, 50);
    QPushButton *Boton_Rikcelare = new QPushButton("Rikcelare", Pantalla_Inicio);
    Boton_Rikcelare->setGeometry(100, 100, 100, 50);

    mainwindow->setCentralWidget(Pantalla_Inicio);


    connect(Boton_Senifini, &QPushButton::clicked, Pantalla_Inicio, [=]() {
        Crear_Cinematica("C:/Users/tarmi/Videos/Captures/Senifini.mp4");
        Reproducir();
        Continente=0;

    });
    connect(Boton_Filnar, &QPushButton::clicked, Pantalla_Inicio, [=]() {
        Crear_Cinematica("C:/Users/tarmi/Videos/Captures/Filnar.mp4");
        Reproducir();
        Continente=1;

    });
    connect(Boton_Abadtrah, &QPushButton::clicked, Pantalla_Inicio, [=]() {
        Crear_Cinematica("C:/Users/tarmi/Videos/Captures/Abadtrah.mp4"); Reproducir();});
    connect(Boton_Bragelante, &QPushButton::clicked, Pantalla_Inicio, [=]() {
        Crear_Cinematica("C:/Users/tarmi/Videos/Captures/Bragelante.mp4"); Reproducir();});
    connect(Boton_Montino, &QPushButton::clicked, Pantalla_Inicio, [=]() {
        Crear_Cinematica("C:/Users/tarmi/Videos/Captures/Montino.mp4"); Reproducir();});
    connect(Boton_Rikcelare, &QPushButton::clicked, Pantalla_Inicio, [=]() {
        Crear_Cinematica("C:/Users/tarmi/Videos/Captures/Rikcelare.mp4"); Reproducir();});


}

void Iniciar::Crear_Cinematica(QString Path)
{
    player = new QMediaPlayer();
    Cinematica = new QVideoWidget();
    player->setSource(QUrl::fromLocalFile(Path));
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &Iniciar::Verificar_Estado);


}

void Iniciar::Reproducir()
{
    player->setVideoOutput(Cinematica);
    mainwindow->setCentralWidget(Cinematica);
    player->play();
}


void Iniciar::Verificar_Estado()
{
    if (player->mediaStatus() == QMediaPlayer::EndOfMedia)
    {
        Selector= new QWidget();
        switch(Continente){
        case 1:{


            QPixmap Filnar_mision(":/Filnar completo 1.png");
            QLabel *Imagen_Filnar=new QLabel(Selector);
            Imagen_Filnar->setPixmap(Filnar_mision);
            Imagen_Filnar->setGeometry(0, 0, Filnar_mision.width(), Filnar_mision.height());

            QPushButton *Janukra = new QPushButton("Janukra",Selector);
            Janukra->setGeometry(780,305, 100, 50);
            QPushButton *Tehamu = new QPushButton("Tehamu", Selector);
            Tehamu->setGeometry(1070,305, 100, 50);
            mainwindow->setCentralWidget(Selector);

            connect(Janukra, &QPushButton::clicked, mainwindow, [=]() {
                Janukra_Quest=new Mision(1,mainwindow);

            });
        }


        }
    }
}











QWidget *Iniciar::getPantalla_Inicio() const
{
    return Pantalla_Inicio;
}

QPushButton *Iniciar::getBoton_Filnar() const
{
    return Boton_Filnar;
}

Iniciar::~Iniciar()
{
    delete player;
    delete Cinematica;
    delete Pantalla_Inicio;
    delete Boton_Senifini;
    delete Boton_Filnar;
    delete Boton_Abadtrah;
    delete Boton_Bragelante;
    delete Boton_Montino;
    delete Boton_Rikcelare;
}

