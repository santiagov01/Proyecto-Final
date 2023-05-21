
#include "obstaculos.h"
#include <QPainter>


Obstaculos::Obstaculos(string path, int posX, int posY)
{
    imagen=new QPixmap(QString::fromStdString(path));
    setPos(posX,posY);
}

QRectF Obstaculos::boundingRect() const
{
    return QRectF(-10,-10,imagen->size().width(),imagen->size().height());
}

void Obstaculos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(-10, -10, imagen->size().width(),imagen->size().height(), *imagen);
}
