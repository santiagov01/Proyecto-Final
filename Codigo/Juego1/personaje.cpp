#include "personaje.h"

Personaje::Personaje(string _path,int Ancho, int Alto,int _vida)
{

    posX = 800;
    posY = 800;
    vida_max = _vida;
    columnas=0;
    estado=1;
    orientacion=0;


    path = _path;
    Cargar_imagen(path,&Imagenes_personaje);
    //path = "Sprites.csv"
    pixmap=new QPixmap();
    sprite();

    ancho=Ancho;
    alto=Alto;

    AnimacionTimer=new QTimer();
    AnimacionTimer->start(140);
    connect(AnimacionTimer,&QTimer::timeout,this,&Personaje::actualizar_sprite);
}

Personaje::~Personaje()
{
    delete pixmap;
}

void Personaje::sprite()
{
    pixmap->load(QString::fromStdString(Imagenes_personaje[estado]));

}
void Personaje::actualizar_sprite(){
    columnas+=ancho;
    if (columnas>=pixmap->size().width()) columnas=0;
    this->update(-ancho/2,-alto/2,ancho,alto);
}


QRectF Personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}



void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,0,ancho,alto);
}

void Personaje::setColisionObstaculos(bool newColisionObstaculos)
{
    colisionObstaculos = newColisionObstaculos;
}




//void Personaje::keyPressEvent(QKeyEvent *event)
//{
//    int speed = 5; // velocidad de movimiento del personaje

//    if (event->key() == Qt::Key_A){
//        mover(-speed, 0);
//        estado=3;
//        sprite();
//        orientacion=0;

//    }

//    else if (event->key() == Qt::Key_D){
//        mover(speed, 0);
//        estado=2;
//        sprite();
//        orientacion=1;

//    }
//    else if (event->key() == Qt::Key_W)
//        mover(0, -speed);
//    else if (event->key() == Qt::Key_S)
//        mover(0, speed);
//}

//void Personaje::keyReleaseEvent(QKeyEvent *event)
//{
//    if (event->key() == Qt::Key_A || event->key() == Qt::Key_D ||
//        event->key() == Qt::Key_W || event->key() == Qt::Key_S)
//    {
//        estado = 1;
//        sprite();
//    }
//}

//void Personaje::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    if (event->button() == Qt::LeftButton)
//    {
//        if(orientacion==1){
//            estado = 4;
//            sprite();
//        }
//        else{
//            estado=5;
//            sprite();
//        }

//    }
//}

