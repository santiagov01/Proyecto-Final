#include "enemigos.h"
#include <QTimer>
#include <qmath.h>
#include "iostream"
#include <QDebug>
Enemigos::Enemigos(QString path, int _posx, int _posy)

{
    posX = _posx;
    posY = _posy;
    pixmap = new QPixmap(path);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movimiento()));
    timer->start(33);
    direction = true;
    theta = 0;
    dir = true;
}

Enemigos::~Enemigos()
{

}

void Enemigos::movimiento()
{

        /*
    qreal newposx = x()+10;
    if(x()>0 && direction){
        setPos(x()+10,y());
    }else if(x()>500){
        setPos(x()-10,y());
        direction = false;
    }
    */
    double STEP_SIZE = 2;
    if(theta <=0) dir = true;
    else if(theta >=360) dir = false;

    if(dir){
        theta+=5;
    }else if(!dir){
        theta-=5;
    }
    double dy = STEP_SIZE* qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
    std::cout<<posX<<std::endl;
    setPos(x()+dx, y()+dy);
}
