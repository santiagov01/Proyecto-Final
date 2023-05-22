#ifndef OBSTACULOS_H
#define OBSTACULOS_H


#include <QGraphicsItem>
#include <QPainter>
class Obstaculos:public QGraphicsItem
{
    int posx,posy,w,h;

public:
    Obstaculos();
    Obstaculos(int x,int y,int w, int h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    //rectangulo que delimita al objeto, posicion y dimensiones
    QRectF boundingRect() const;

};
#endif // OBSTACULOS_H
