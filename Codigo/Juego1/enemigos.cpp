#include "enemigos.h"
#include "enemigos.h"
#include <QTimer>
#include <qmath.h>
#include "iostream"
#include <QDebug>
#include "auxiliares.h"


Enemigos::Enemigos(string _path, int Ancho, int Alto, int _vida, int _posx, int _posy, Protagonista *player,int _daño):Personaje(_path, Ancho, Alto,_vida)

{
    pj = player;
    posX = _posx;
    posY = _posy;
//    pixmap = new QPixmap(path);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movimiento()));
    timer->start(100);
    direction = true;
    theta = 0;
    dir = true;
    vida=_vida;

    posini = _posx;
    daño=_daño;
}

Enemigos::~Enemigos()
{

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

void Enemigos::movimiento()
{

    /*
    qreal newposx = x()+10;

    if(x()>=posini && direction){
        setPos(x()+10,y());
        estado = 1;
        this->sprite();
    }else if(x()>posini+100){
        setPos(x()-10,y());
        estado = 2;
        this->sprite();
        direction = false;
    }
    */

    /*
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
    */


    //Existen dos opciones para obtener la posición del jugador
    //1. Pasar por parámetro el objeto jugador y obtener su posición
    //2. Invocar movimiento() en terreno, así se adquiere la posición de inmediato.


    double STEP_SIZE = 5;
    //500 y 200 corresponden a la posicion x,y del jugador principal
    double distancia = calcular_distancia(x(),y(), pj->x(),pj->y());
    double angle = calc_angle(x(),y(), pj->x(),pj->y());
    //double t =rotation();
    //std::cout<<"Rotacion "<<angle<<std::endl;
    //t++;
   // setRotation(-qRadiansToDegrees(angle));
    if(distancia > 30){
        //if(qDegreesToRadians(t)!=angle)setRotation(-qRadiansToDegrees(angle));

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
        //std::cout<<angle<<std::endl;

    }

}
