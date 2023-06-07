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
    double angle;
    int ancho, alto, columnas;
    QPixmap *imagen;
public:
    Proyectil();
    Proyectil(double _px, double _py, double _xdest, double _ydest);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    //rectangulo que delimita al objeto, posicion y dimensiones
    QRectF boundingRect() const;
    void sprite();
public slots:
    void movimiento();
    void actualizar_sprite();
};
#endif // PROYECTIL_H
