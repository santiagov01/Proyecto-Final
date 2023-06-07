
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
Obstaculos::Obstaculos(int tipo, int posX, int posY,string path)
{
    imagen=new QPixmap(QString::fromStdString(path));
    setPos(posX,posY);

    RectCol=new QGraphicsRectItem();
    RectCol->setZValue(10);
    switch (tipo){

    default:{
        RectCol->setRect(-5, 64, 5, 10);
        RectCol->setPos(posX+32,posY);
        break;
    }
    case 7:{
        RectCol->setRect(-5, 110, 20, 10);
        RectCol->setPos(posX+70,posY+20);
        break;
    }
    case 10:{
        RectCol->setRect(-5, 110, 20, 10);
        RectCol->setPos(posX+120,posY+50);
        break;
    }
    case 11:{
        RectCol->setRect(-5, 110, 10,25);
        RectCol->setPos(posX+75,posY+80);
        break;
    }

    }

}

Obstaculos::Obstaculos(int Inicialx, int Inicialy, int Finalx, int Finaly)
{
    imagen=new QPixmap("0,0");
    RectCol=new QGraphicsRectItem(Inicialx,Inicialy,Finalx-Inicialx,Finaly-Inicialy);

    setPos(Inicialx,Inicialy);
    RectCol->setZValue(10);
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

