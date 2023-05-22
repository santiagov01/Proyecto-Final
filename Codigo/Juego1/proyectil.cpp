#include "proyectil.h"
#include "auxiliares.h"
#include <QGraphicsItem>
#include <QTimer>
Proyectil::Proyectil()
{

}

Proyectil::Proyectil(double _px, double _py, double _xdest, double _ydest, QGraphicsItem *parent): QObject()
{
    posx = _px;//debe coincidir con la posicion del jugador
    posy = _py;
    x_destin = _xdest;//posicions del mouse
    y_destin = _ydest;
    QTimer * move_timer = new QTimer();
    connect(move_timer,SIGNAL(timeout()),this,SLOT(movimiento()));
    move_timer->start(50);
}
void Proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::gray);
    painter->setPen(Qt::NoPen);
    painter->drawRect(boundingRect());
}

QRectF Proyectil::boundingRect() const
{
    return QRectF(posx, posy,30,10);
}
void Proyectil::movimiento()
{
    double STEP_SIZE = 5;
    //500 y 200 corresponden a la posicion x,y del jugador principal
    double distancia = calcular_distancia(x(),y(), x_destin,y_destin);
    double angle = calc_angle(x(),y(), x_destin,y_destin);
    double t =rotation();
    //std::cout<<"Rotacion "<<angle<<std::endl;
    //t++;
   // setRotation(-qRadiansToDegrees(angle));
    double dy = STEP_SIZE* sin(qDegreesToRadians(-qRadiansToDegrees(angle)));
    double dx = STEP_SIZE * cos(qDegreesToRadians(-qRadiansToDegrees(angle)));
    setPos(x()+dx, y()+dy);
}
