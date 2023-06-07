#include "botin.h"

Botin::Botin(int _posX, int _posY)
{
    posX = _posX;
    posY = _posY;
    srand(time(nullptr));
    tipo = rand() % 2;


    if(tipo==0){
        imagen=new QPixmap(":/Pocion/Salud.png");
    }
    else imagen=new QPixmap(":/Pocion/Cordura.png");

}

QRectF Botin::boundingRect() const
{
    return QRectF(posX, posY, imagen->width(),imagen->height()); // ajustar el tamaño del rectángulo de colisión
}

void Botin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);


    painter->drawPixmap(posX, posY, imagen->width(),imagen->height(),*imagen); // dibujar el objeto como un círculo

}
int Botin::getTipo() const
{
    return tipo;
}

