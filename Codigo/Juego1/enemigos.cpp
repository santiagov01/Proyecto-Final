#include "enemigos.h"
#include "enemigos.h"
#include <QTimer>
#include <qmath.h>
#include "iostream"
#include <QDebug>
#include "auxiliares.h"


Enemigos::Enemigos(string _path, int Ancho, int Alto, int _vida, int _posx, int _posy, Protagonista *player,int _tipo,int _daño):Personaje(_path, Ancho, Alto,_vida)

{
    pj = player;
    posX = _posx;
    posY = _posy;
    tipo = _tipo;
//    pixmap = new QPixmap(path);
    QTimer *timer = new QTimer(this);
    switch (tipo) {
    case 1:
        connect(timer,SIGNAL(timeout()),this,SLOT(movimiento_acercar()));
        break;
    case 2:
        connect(timer,SIGNAL(timeout()),this,SLOT(movimiento_param()));
        break;
    case 3:
        //balas_enemigo = new Proyectil(this->x(),this->y());
        connect(timer,SIGNAL(timeout()),this,SLOT(movimiento_con_proyectil()));
        break;
    case 4:
        connect(timer,SIGNAL(timeout()),this,SLOT(movimiento_ruta()));
        break;
    default:
        break;
    }
    timer->start(100);

    theta = 0;
    angle_pr = 0;
    dir = true;
    direction = true;
    vida=_vida;

    posini = _posx;
    daño=_daño;

    xlim = 0; ylim = 0;
    orientacion = 1;
}

Enemigos::~Enemigos()
{

}



void Enemigos::movimiento_acercar()
{
    double STEP_SIZE = 5;

    double distancia = calcular_distancia(x(),y(), pj->x(),pj->y());
    double angle = calc_angle(x(),y(), pj->x(),pj->y());

    if(distancia > 30){
        double dy = STEP_SIZE* sin(qDegreesToRadians(-qRadiansToDegrees(angle)));
        double dx = STEP_SIZE * cos(qDegreesToRadians(-qRadiansToDegrees(angle)));

        setPos(x()+dx, y()+dy);

        if(dx <0){
            estado = 1;
            this->sprite();
        }else{
            estado = 2;
            this->sprite();
        }
    }

}
void Enemigos::movimiento_ruta(){

    double vel = 10;
    if(orientacion == 1){
        if(x()<=posX){
            dir = true;
        }else if(x()>=xlim){
            dir = false;
        }
        if(dir){
            setPos(x()+vel,y());
        }else if(!dir){
            setPos(x()-vel, y());
        }
    }else{
        if(y()<=posY){
            dir = true;
        }else if(y()>=ylim){
            dir = false;
        }
        if(dir){
            setPos(x(),y()+vel);
        }else if(!dir){
            setPos(x(), y()-vel);
        }
    }


}
void Enemigos::movimiento_param()
{
    double STEP_SIZE = 10;
    if(theta <=0)dir = true;
    else if(theta >=360){
        theta = 0;
        dir = false;
    }
    if(dir){
        theta+=2;
    }else if(!dir){
        theta-=2;
    }
    theta+=2;
    double r = STEP_SIZE*qCos(qDegreesToRadians((5)*theta));
    double dy = (r)* qSin(qDegreesToRadians(theta));
    double dx = (r) * qCos(qDegreesToRadians(theta));
    setPos(x()+ dx, y()+dy);
}

void Enemigos::movimiento_con_proyectil()
{
     double STEP_SIZE = 10;
    if(theta <=0)dir = true;
    else if(theta >=360){
        theta = 0;
        dir = false;
    }
    if(dir){
        theta+=2;
    }else if(!dir){
        theta-=2;
    }
    theta+=2;
    //double r = STEP_SIZE*qCos(qDegreesToRadians((5)*theta));
    double dy = (STEP_SIZE)* qSin(qDegreesToRadians(theta));
    double dx = (STEP_SIZE) * qCos(qDegreesToRadians(theta));
    setPos(x()+ dx, y()+dy);

//    STEP_SIZE = 20;
//    if(angle_pr <=0)dir = true;
//    else if(angle_pr >=360){
//        angle_pr = 0;
//        dir = false;
//    }
//    if(dir){
//        angle+=20;
//    }else if(!dir){
//        angle-=20;
//    }
//    //angle+=2;
//    //double r = STEP_SIZE*qCos(qDegreesToRadians((5)*theta));
//    double dy_pr = (STEP_SIZE)* qSin(qDegreesToRadians(angle));
//    double dx_pr = (STEP_SIZE) * qCos(qDegreesToRadians(angle));
//    //balas_enemigo->setPos(x()+ dx_pr, y()+dy_pr);

}

//void Enemigos::proyectil_circular(QGraphicsScene *scene){
//    if(tipo == 3){
//        scene->addItem(balas_enemigo);
//    }
//}

void Enemigos::setXlim(double newXlim)
{
    xlim = newXlim;
}

void Enemigos::setYlim(double newYlim)
{
    ylim = newYlim;
}

void Enemigos::setOrientacion(int newOrientacion)
{
    orientacion = newOrientacion;
}

int Enemigos::getVida() const
{
    return vida;
}

void Enemigos::setVida(int newVida)
{
    vida = newVida;
}

int Enemigos::getDaño() const
{
    return daño;
}
