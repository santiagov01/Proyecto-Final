#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include "auxiliares.h"
#include "personaje.h"
#include "protagonista.h"
class Enemigos: public Personaje
{
    Q_OBJECT
public:
    Enemigos(string _path, int Ancho, int Alto, int _vida, int _posx, int _posy, Protagonista *player, int _daño);
    ~Enemigos();
    int getVida() const;
    void setVida(int newVida);

    int getDaño() const;


    void botin();

private:
    bool direction;
    double angle;
    double theta;
    bool dir;
    int vida;
    int daño;
    qreal posini;

    Protagonista *pj;
public slots:
    void movimiento();
};

#endif // ENEMIGOS_H
