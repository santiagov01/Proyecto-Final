#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include "auxiliares.h"
#include "personaje.h"
#include "protagonista.h"
#include "proyectil.h"
#include <QGraphicsScene>
class Enemigos: public Personaje
{
    Q_OBJECT
public:
    Enemigos(string _path, int Ancho, int Alto, int _vida, int _posx, int _posy, Protagonista *player, int _tipo, int _daño);
    //Enemigos(string _path, int Ancho, int Alto, int _vida, int _posx, int _posy, Protagonista *player, int _tipo, int _daño, QGraphicsScene *scene);

    ~Enemigos();
    int getVida() const;
    void setVida(int newVida);

    int getDaño() const;

    void proyectil_circular(QGraphicsScene *scene);

    void setXlim(double newXlim);

    void setYlim(double newYlim);

    void setOrientacion(int newOrientacion);

private:
    bool direction;
    double angle, angle_pr;
    double theta;
    bool dir;
    int vida;
    int daño;
    int tipo;

    int orientacion;

    double xlim, ylim;
    //a

    //Proyectil* balas_enemigo;//se podría convertir en una lista
    qreal posini;

    Protagonista *pj;
public slots:
    void movimiento_acercar();
    void movimiento_param();
    void movimiento_con_proyectil();
    void movimiento_ruta();
};

#endif // ENEMIGOS_H
