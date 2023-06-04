
#include "obstaculos.h"
#include <QPainter>


Obstaculos::Obstaculos(string path, int posX, int posY)
{
    imagen = new QPixmap(QString::fromStdString(path));
    setPos(posX, posY);

    // Crea un rectángulo de colisión escalado a la mitad del tamaño original
    QRectF rect = QRectF(0, 0, imagen->width(), imagen->height());
    QTransform transform;
    transform.scale(1, 1); // Escala en 0.5 en ambas direcciones
    rect = transform.mapRect(rect);
    RectCol = new QGraphicsRectItem(rect.x() + posX, rect.y() + posY, rect.width(), rect.height());
}

QRectF Obstaculos::boundingRect() const
{
    return QRectF(0, 0,imagen->width(),imagen->height());
}


void Obstaculos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
//    painter->setBrush(Qt::gray);
//    painter->setPen(Qt::NoPen);
//    painter->drawRect(boundingRect());
    painter->drawPixmap(0, 0, imagen->width(),imagen->height(), *imagen);
}

QGraphicsRectItem *Obstaculos::getRectCol() const
{
    return RectCol;
}

