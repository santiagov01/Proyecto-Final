#include "obstaculos.h"

#include <QGraphicsItem>
Obstaculos::Obstaculos()
{

}

Obstaculos::Obstaculos(int x, int y, int w, int h)
{
    this->posx = x;
    this->posy = y;
    this->w = w;
    this->h = h;
}

void Obstaculos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::gray);
    painter->setPen(Qt::NoPen);
    painter->drawRect(boundingRect());
}

QRectF Obstaculos::boundingRect() const
{
    return QRectF(posx, posy, w,h);
}
