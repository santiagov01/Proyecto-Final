#include "personaje.h"

Personaje::Personaje(int Ancho, int Alto)
{
    posX = 800;
    posY = 800;

    columnas=0;
    estado=1;
    orientacion=0;

    ancho=Ancho;
    alto=Alto;

    Cargar_imagen("Sprites.csv",&Imagenes_personaje);

    pixmap=new QPixmap();
    sprite();

    AnimacionTimer=new QTimer();
    AnimacionTimer->start(125);
    connect(AnimacionTimer,&QTimer::timeout,this,&Personaje::actualizar_sprite);
}

Personaje::~Personaje()
{
    delete pixmap;
}


void Personaje::mover(int x, int y)
{
    posX += x;
    posY += y;
    setPos(posX, posY);
    emit posicionCambiada();
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



QPixmap *Personaje::getPixmap() const
{
    return pixmap;
}




void Personaje::keyPressEvent(QKeyEvent *event)
{
    int speed = 5; // velocidad de movimiento del personaje

    if (event->key() == Qt::Key_A){
        mover(-speed, 0);
        estado=3;
        sprite();
        orientacion=0;

    }

    else if (event->key() == Qt::Key_D){
        mover(speed, 0);
        estado=2;
        sprite();
        orientacion=1;

    }
    else if (event->key() == Qt::Key_W)
        mover(0, -speed);
    else if (event->key() == Qt::Key_S)
        mover(0, speed);
}

void Personaje::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A || event->key() == Qt::Key_D ||
        event->key() == Qt::Key_W || event->key() == Qt::Key_S)
    {
        estado = 1;
        sprite();
    }
}

void Personaje::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if(orientacion==1){
            estado = 4;
            sprite();
        }
        else{
            estado=5;
            sprite();
        }

    }
}

