#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include "auxiliares.h"
#include "personaje.h"
#include "protagonista.h"
class Enemigos: public Personaje
{
    Q_OBJECT
public:
    Enemigos(QString path, int _posx, int _posy, Protagonista *pj);
    ~Enemigos();
private:
    bool direction;
    double angle;
    double theta;
    bool dir;

    Protagonista *pj;
public slots:
    void movimiento();
};

#endif // ENEMIGOS_H
