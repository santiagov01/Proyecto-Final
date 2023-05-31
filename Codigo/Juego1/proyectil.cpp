#include "proyectil.h"
#include "auxiliares.h"
#include <QGraphicsItem>
#include <QTimer>
#include <qmath.h>
Proyectil::Proyectil()
{

}

Proyectil::Proyectil(double _px, double _py, double _xdest, double _ydest)
{

    posx = _px;//debe coincidir con la posicion del jugador
    posy = _py;
    x_destin = _xdest;//posicions del mouse
    y_destin = _ydest;
    angle = calc_angle(posx,posy, x_destin,y_destin);//angulo entre origen y destino, se calcula una vez
    QTimer * move_timer = new QTimer();
    connect(move_timer,SIGNAL(timeout()),this,SLOT(movimiento()));
    move_timer->start(4);
}
void Proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)

{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(Qt::gray);
    painter->setPen(Qt::NoPen);
    painter->drawRect(boundingRect());
}

QRectF Proyectil::boundingRect() const
{
    return QRectF(-15,-5,30,10);
}
void Proyectil::movimiento()
{
    double STEP_SIZE = 5; //-> se puede pasar como variable.

    //rotar el elemento
    setRotation(-qRadiansToDegrees(angle));
    //cambiar signo por el resultado que entrega
    double dy = STEP_SIZE* qSin(qDegreesToRadians(-qRadiansToDegrees(angle)));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(-qRadiansToDegrees(angle)));
    setPos(x()+dx, y()+dy);
}
