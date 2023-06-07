#include "proyectil.h"
#include "auxiliares.h"
#include <QGraphicsItem>
#include <QTimer>
#include <qmath.h>


Proyectil::Proyectil(double _px, double _py)
{
    posx = _px;
    posy = _py;

    angle = 0;
    dir = true;
    setPos(posx, posy);
    dt = 0.1;

    distancia_recorrida = 0;
    columnas=0;
    ancho=20;
    alto=20;

    imagen=new QPixmap();
    sprite();

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
    move_timer->start(20);
    dt = 0.1;

    distancia_recorrida = 0;
    columnas=0;
    ancho=20;
    alto=20;

    imagen=new QPixmap();
    sprite();
}
Proyectil::Proyectil(double _px, double _py, double _xdest, double _ydest, int _tipo_proyectil)
{

    tipo_proyectil = _tipo_proyectil;
    posx = _px;//debe coincidir con la posicion del jugador
    posy = _py;
    x_destin = _xdest;//posicions del mouse
    y_destin = _ydest;
    angle = calc_angle(posx,posy, x_destin,y_destin);//angulo entre origen y destino, se calcula una vez
    QTimer * move_timer = new QTimer();
    switch (tipo_proyectil) {
    case 1:
        connect(move_timer,SIGNAL(timeout()),this,SLOT(movimiento()));
        break;
    case 2:
        connect(move_timer,SIGNAL(timeout()),this,SLOT(movimiento_acelerado()));
        break;
    case 3:
        connect(move_timer,SIGNAL(timeout()),this,SLOT(movimiento_helice()));
        vx = 0;
        vy=0;
        break;
    default:
        break;
    }
    direction = calc_angle(posx,posy,x_destin,y_destin);
    move_timer->start(20);
    dt = 0.1;

    distancia_recorrida = 0;

    columnas=0;
    ancho=20;
    alto=20;

    imagen=new QPixmap();
    sprite();
}
void Proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)

{
    Q_UNUSED(option);
    Q_UNUSED(widget);

//    painter->setBrush(Qt::gray);
//    painter->setPen(Qt::NoPen);
//    painter->drawRect(boundingRect());
    painter->drawPixmap(-ancho/2,-alto/2, *imagen,columnas,0,ancho,alto);
}

QRectF Proyectil::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}
void Proyectil::movimiento()
{

    double STEP_SIZE = 15; //-> se puede pasar como variable.

    //rotar el elemento
    setRotation(-qRadiansToDegrees(angle));
    //cambiar signo por el resultado que entrega
    double dy = STEP_SIZE* qSin(qDegreesToRadians(-qRadiansToDegrees(angle)));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(-qRadiansToDegrees(angle)));
    setPos(x()+dx, y()+dy);

    distancia_recorrida = calcular_distancia(x(),y(),posx,posy);
}
void Proyectil::movimiento_acelerado(){
    double STEP_SIZE = 1.2;

    //rotar el elemento
    setRotation(-qRadiansToDegrees(angle));
    double dy = STEP_SIZE* qSin(qDegreesToRadians(-qRadiansToDegrees(angle)))*pow(dt,2);
    double dx = STEP_SIZE * qCos(qDegreesToRadians(-qRadiansToDegrees(angle)))*pow(dt,2);
    setPos(x()+dx, y()+dy);
    dt+=0.16;
}
void Proyectil::movimiento_helice(){
    double STEP_SIZE = 10;
    if(angle <=0)dir = true;
    else if(angle >=360){
        angle = 0;
        dir = false;
    }
    if(dir){
        angle+=2;
    }else if(!dir){
        angle-=2;
    }
    angle+=2;
    double xx = vx*qCos(qDegreesToRadians(direction));
    double yy = vy*qSin(qDegreesToRadians(direction));

    //double r = STEP_SIZE*qCos(qDegreesToRadians((5)*theta));
    double dy = (STEP_SIZE)* qSin(qDegreesToRadians(angle));
    double dx = (STEP_SIZE) * qCos(qDegreesToRadians(angle));
    setPos(x()+ dx +xx, y()+dy + yy);
}
void Proyectil::movimiento_circular(){
    double STEP_SIZE = 10;
    if(angle <=0)dir = true;
    else if(angle >=360){
        angle = 0;
        dir = false;
    }
    if(dir){
        angle+=2;
    }else if(!dir){
        angle-=2;
    }
    angle+=2;
    //double r = STEP_SIZE*qCos(qDegreesToRadians((5)*theta));
    double dy = (STEP_SIZE)* qSin(qDegreesToRadians(angle));
    double dx = (STEP_SIZE) * qCos(qDegreesToRadians(angle));
    setPos(x()+ dx, y()+dy);
}
void Proyectil::sprite()
{
    imagen->load(QString::fromStdString(":/Sprites PJ/Proyectil.png"));

}
void Proyectil::actualizar_sprite(){
    columnas+=ancho;
    if (columnas>=imagen->size().width()) columnas=0;
    this->update(-ancho/2,-alto/2,ancho,alto);
}
double Proyectil::getDistancia_recorrida() const
{
    return distancia_recorrida;
}
