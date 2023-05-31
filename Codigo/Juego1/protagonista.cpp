#include "protagonista.h"
#include <string>
#include <QTimer>
//Verificar escritura correcta de los métodos de una clase heredada
Protagonista::Protagonista(string _path,int Ancho, int Alto,int _vida,int _cordura, int _x, int _y):Personaje(_path, Ancho, Alto,_vida)
{
    //pixmap = new QPixmap(":/Pj.png");

    cordura = _cordura;
    this->posX = _x;
    this->posY = _y;
    this->arma= 0;


//    QTimer *timer = new QTimer();
//    connect(timer, SIGNAL(timeout()),this, SLOT(mover()));
//    timer->start(33);
//    moverIx=false;
//    moverDx=false;
//    moverUy=false;
//    moverDy=false;
}

Protagonista::~Protagonista()
{
    //delete pixmap;
}


/* PARA ESTE MOVIMIENTO ES NECESARIO DESCOMENTAR mover() de public slots. EN EL .h
//También descomentar las lineas 11-17 del constructor
void Protagonista::mover()
{
    if(moverIx)
    {
        setPos(x()-2,y());
    }
    if(moverDx)
    {
        setPos(x()+2,y());
    }
    if(moverUy)
    {
        setPos(x(),y()-2);
    }
    if(moverDy)
    {
        setPos(x(),y()+2);
    }
    emit posicionCambiada();
}
void Protagonista::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx=true;
        if(colisionObstaculos){
            moverIx = false;
            setPos(x()+2,y());
        }
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx=true;
        if(colisionObstaculos){
            moverDx = false;
            setPos(x()-2,y());
        }
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy=true;
        if(colisionObstaculos){
            moverUy = false;
            setPos(x(),y()+2);
        }
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDy=true;
        if(colisionObstaculos){
            moverDy = false;
            setPos(x(),y()-2);
        }
    }
}
void Protagonista::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx=false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDy=false;
    }

}
*/


//void Protagonista::mover(int x, int y)
//{
//    posX += x;
//    posY += y;
//    setPos(posX, posY);
//    emit posicionCambiada();
//}

//void Protagonista::keyPressEvent(QKeyEvent *event)
//{
//    int speed = 5; // velocidad de movimiento del personaje

//    if (event->key() == Qt::Key_A){
//        mover(-speed, 0);
//        if(!colisionObstaculos){
//            mover(-speed, 0);
//        }else{
//            mover(speed+2, 0);
//        }
//    }
//    else if (event->key() == Qt::Key_D){
//        mover(speed, 0);
//        if(!colisionObstaculos){
//            mover(speed, 0);
//        }else{
//            mover(-speed-2, 0);
//        }
//    }
//    else if (event->key() == Qt::Key_W){
//        mover(0, -speed);
//        if(!colisionObstaculos){
//            mover(0, -speed);
//        }else{
//            mover(0, speed+2);
//        }
//    }

//    else if (event->key() == Qt::Key_S){
//        mover(0, speed);
//        if(!colisionObstaculos){
//            mover(0, speed);
//        }else{
//            mover(0, -speed-2);
//        }
//    }
//}

//void Protagonista::keyReleaseEvent(QKeyEvent *event)
//{
//    if (event->key() == Qt::Key_A){
//        mover(0, 0);
//    }else if (event->key() == Qt::Key_D){
//        mover(0, 0);
//    }else if (event->key() == Qt::Key_W){
//        mover(0, 0);
//    }else if (event->key() == Qt::Key_S){
//        mover(0, 0);
//    }

//}

void Protagonista::mover(int x, int y)
{
    posX += x;
    posY += y;
    setPos(posX, posY);
    emit posicionCambiada();
}
//void Protagonista::keyPressEvent(QKeyEvent *event)
//{
//    int speed = 10; // velocidad de movimiento del personaje

//    if (event->key() == Qt::Key_A){
//        this->mover(-speed, 0);
//        if(!colisionObstaculos){
//            this->mover(-speed, 0);
//            estado=3;
//            this->sprite();
//            orientacion=0;
//        }else{
//            this->mover(speed, 0);
//            estado=2;
//            this->sprite();
//            orientacion=1;
//        }


//    }

//    else if (event->key() == Qt::Key_D){
//        this->mover(speed, 0);
//        if(!colisionObstaculos){
//            this->mover(speed, 0);
//            estado=2;
//            this->sprite();
//            orientacion=1;
//        }else{
//            this->mover(-speed, 0);
//            estado=3;
//            this->sprite();
//            orientacion=0;
//        }


//    }
//    else if (event->key() == Qt::Key_W){
//        //mover(0, -speed);
//        if(!colisionObstaculos){
//            mover(0, -speed);
//        }else{
//            mover(0, speed);
//        }
//    }
//    else if (event->key() == Qt::Key_S){
//        //this->mover(0, speed);
//        if(!colisionObstaculos){
//            this->mover(0, speed);
//        }else{
//            this->mover(0, -speed);
//        }
//    }


//}

//void Protagonista::keyReleaseEvent(QKeyEvent *event)
//{
//    if (event->key() == Qt::Key_A || event->key() == Qt::Key_D ||
//        event->key() == Qt::Key_W || event->key() == Qt::Key_S)
//    {
//        estado = 1;
//        this->sprite();
//    }
//}

//void Protagonista::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    if (event->button() == Qt::LeftButton)
//    {
//        if(orientacion==1){
//            estado = 4;
//            this->sprite();
//        }
//        else{
//            estado=5;
//            this->sprite();
//        }

//    }
//}

int Protagonista::getCordura() const
{
    return cordura;
}

void Protagonista::setCordura(int newCordura)
{
    cordura = newCordura;
}
