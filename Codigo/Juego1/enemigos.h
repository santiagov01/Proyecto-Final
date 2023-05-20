#ifndef ENEMIGOS_H
#define ENEMIGOS_H


#include "personaje.h"
class Enemigos: public Personaje
{
    Q_OBJECT
public:
    Enemigos(QString path, int _posx, int _posy);
    ~Enemigos();
private:
    bool direction;
    double angle;
    double theta;
    bool dir;
public slots:
    void movimiento();
};

#endif // ENEMIGOS_H
