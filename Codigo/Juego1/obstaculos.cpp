
#include "obstaculos.h"
#include <QPainter>


Obstaculos::Obstaculos(string path, int posX, int posY)
{
    //se puede indexar por
    imagen=new QPixmap(QString::fromStdString(path));
    setPos(posX,posY);
}

QRectF Obstaculos::boundingRect() const
{
    return QRectF(-10, -10,imagen->width(),imagen->height());
}

void Obstaculos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
//    painter->setBrush(Qt::gray);
//    painter->setPen(Qt::NoPen);
//    painter->drawRect(boundingRect());
    painter->drawPixmap(-10, -10 , imagen->width(),imagen->height(), *imagen);
}
