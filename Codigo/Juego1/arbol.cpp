
#include "arbol.h"
#include <QPainter>
Arbol::Arbol(int Tipo, int posX, int posY)
{
    switch(Tipo){
    case 1:{
        imagen=new QPixmap(":/Arboles/Tipo1.png");
        break;
    }
    case 2:{
        imagen=new QPixmap(":/Arboles/Tipo2.png");
    }
    }

    setPos(posX,posY);


}

QRectF Arbol::boundingRect() const
{
    return QRectF(-10,-10,64,96);
}

void Arbol::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(-10, -10, 64, 96, *imagen);
}
