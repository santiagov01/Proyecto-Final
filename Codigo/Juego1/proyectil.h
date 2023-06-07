#ifndef PROYECTIL_H
#define PROYECTIL_H



#include "auxiliares.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
class Proyectil: public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    double posx,posy, x_destin, y_destin;
    double angle,dt;
    bool dir;
    int tipo_proyectil;

    double vx, vy;
    double distancia_recorrida;

    double direction;

    int ancho, alto, columnas;
    QPixmap *imagen;

public:
    Proyectil(double _px, double _py);
    Proyectil(double _px, double _py, double _xdest, double _ydest);
    Proyectil(double _px, double _py, double _xdest, double _ydest, int _tipo_proyectil);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    //rectangulo que delimita al objeto, posicion y dimensiones
    QRectF boundingRect() const;

    void movimiento_circular();



    double getDistancia_recorrida() const;

    void sprite();

public slots:
  //void movimiento_circular();
 //void movimiento_acelerado();
    void actualizar_sprite();
    void movimiento_helice();
    void movimiento();
    void movimiento_acelerado();
};
#endif // PROYECTIL_H
