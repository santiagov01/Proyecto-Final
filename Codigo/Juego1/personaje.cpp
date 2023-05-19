#include "personaje.h"

Personaje::Personaje()
{
    posX = 0;
    posY = 0;

    pixmap = new QPixmap(":/Pj.png");
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

QRectF Personaje::boundingRect() const
{
    return QRectF(posX, posY, pixmap->width(), pixmap->height());
}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(boundingRect(), *pixmap, pixmap->rect());
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
    }

    else if (event->key() == Qt::Key_D)
        mover(speed, 0);
    else if (event->key() == Qt::Key_W)
        mover(0, -speed);
    else if (event->key() == Qt::Key_S)
        mover(0, speed);
}
