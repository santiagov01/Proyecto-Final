#include "protagonista.h"

Protagonista::Protagonista(QString path)
{
    //pixmap = new QPixmap(":/Pj.png");
    pixmap = new QPixmap(path);
    cordura = 100;
}

Protagonista::~Protagonista()
{
    //delete pixmap;
}

void Protagonista::mover(int x, int y)
{
    posX += x;
    posY += y;
    setPos(posX, posY);
    emit posicionCambiada();
}

void Protagonista::keyPressEvent(QKeyEvent *event)
{
    int speed = 5; // velocidad de movimiento del personaje

    if (event->key() == Qt::Key_A){
        mover(-speed, 0);
        if(!colisionObstaculos){
            mover(-speed, 0);
        }else{
            mover(speed, 0);
        }
    }
    else if (event->key() == Qt::Key_D){
        mover(speed, 0);
        if(!colisionObstaculos){
            mover(speed, 0);
        }else{
            mover(-speed, 0);
        }
    }
    else if (event->key() == Qt::Key_W){
        mover(0, -speed);
        if(!colisionObstaculos){
            mover(0, -speed);
        }else{
            mover(0, speed);
        }
    }

    else if (event->key() == Qt::Key_S){
        mover(0, speed);
        if(!colisionObstaculos){
            mover(0, speed);
        }else{
            mover(0, -speed);
        }
    }
}

int Protagonista::getCordura() const
{
    return cordura;
}

void Protagonista::setCordura(int newCordura)
{
    cordura = newCordura;
}
