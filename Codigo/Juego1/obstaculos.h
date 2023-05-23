
#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include <QString>
#include <QGraphicsItem>
#include <QPixmap>
#include <QFile>
#include <sstream>
using namespace std;
class Obstaculos: public QGraphicsItem
{
public:
    Obstaculos(string path, int posX, int posY);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QPixmap *imagen;
    int Tipo;
};
#endif // OBSTACULOS_H
