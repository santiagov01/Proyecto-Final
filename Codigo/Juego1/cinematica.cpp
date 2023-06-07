#include "cinematica.h"
#include "ui_cinematica.h"

Cinematica::Cinematica(QWidget *parent, QString _path, int _Continente) :
    QMainWindow(parent),
    ui(new Ui::Cinematica)
{
    ui->setupUi(this);

    path = _path;
    Continente = _Continente;
    player = new QMediaPlayer(this);
    Animacion = new QVideoWidget(this);
    //QMedia
    player->setSource(QUrl::fromLocalFile(path));
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &Cinematica::Verificar_Estado);
    player->setVideoOutput(Animacion);
    setCentralWidget(Animacion);
    player->play();
}



Cinematica::~Cinematica()
{
    delete ui;

}

void Cinematica::goBackMneu()
{
    parentWidget()->show();
    close();
}

void Cinematica::openMapa()
{
    Mapa->show();
    hide();
}

void Cinematica::Verificar_Estado()
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

                Mapa->showFullScreen();

                hide();
            });
            connect(Tehamu, &QPushButton::clicked, this, [=]() {
                Mapa = new MainWindow(this,2);
                Mapa->setAttribute(Qt::WA_DeleteOnClose, true);

                Mapa->showFullScreen();

                hide();
            });
            connect(Boton_Atras,&QPushButton::clicked,this,[=](){
//                Selector->setVisible(false);
//                Pantalla_Inicio->setVisible(true);
//                setCentralWidget(Pantalla_Inicio);
                goBackMneu();
            });
        }
        }



        }
    }
