
#ifndef ARBOL_H
#define ARBOL_H

#include <QString>
#include <QGraphicsItem>
#include <QPixmap>
using namespace std;
class Arbol: public QGraphicsItem
{
public:
    Arbol(string path, int posX, int posY);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QString path;
    QPixmap *imagen;
    int Tipo;
};

#endif // ARBOL_H
