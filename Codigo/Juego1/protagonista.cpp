#include "protagonista.h"
#include <string>
#include <QTimer>
#include <QGraphicsScene>
//Verificar escritura correcta de los métodos de una clase heredada
Protagonista::Protagonista(string _path,int Ancho, int Alto,int _vida,int _cordura, int _x, int _y):Personaje(_path, Ancho, Alto,_vida)
{
    //pixmap = new QPixmap(":/Pj.png");

    cordura = _cordura;
    this->posX = _x;
    this->posY = _y;
    vida_actual=_vida;
    vida_maxm=_vida;


}

Protagonista::~Protagonista()
{
    delete pixmap;
}




void Protagonista::mover(int x, int y)
{

    setPos(posX+x, posY+y);
    posX += x;
    posY += y;

    emit posicionCambiada();
}


int Protagonista::getCordura() const
{
    return cordura;
}

void Protagonista::setCordura(int newCordura)
{
    cordura = newCordura;
}



void Protagonista::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Dibuja el sprite del personaje
    painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,0,ancho,alto);
}

