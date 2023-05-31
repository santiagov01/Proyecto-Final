#ifndef PROYECTIL_H
#define PROYECTIL_H



#include "auxiliares.h"
#include <QGraphicsItem>
#include <QPainter>
class Proyectil: public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    double posx,posy, x_destin, y_destin;
    double angle;

public:
    Proyectil();
    Proyectil(double _px, double _py, double _xdest, double _ydest);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    //rectangulo que delimita al objeto, posicion y dimensiones
    QRectF boundingRect() const;
public slots:
    void movimiento();
};
#endif // PROYECTIL_H
