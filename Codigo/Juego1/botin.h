#ifndef BOTIN_H
#define BOTIN_H

#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsObject>
#include <QPixmap>
using namespace std;
class Botin : public QGraphicsObject
{
    Q_OBJECT

public:
    Botin(int _posX, int _posY);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    int getTipo() const;

private:
    int tipo, posX, posY, aparicion;
    QPixmap *imagen;

    QGraphicsEllipseItem *Pocion;
};

#endif // BOTIN_H
