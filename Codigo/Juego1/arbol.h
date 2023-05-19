
#ifndef ARBOL_H
#define ARBOL_H

#include <QString>
#include <QGraphicsItem>
#include <QPixmap>

class Arbol: public QGraphicsItem
{
public:
    Arbol(int Tipo, int posX, int posY);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QPixmap *imagen;
};

#endif // ARBOL_H
