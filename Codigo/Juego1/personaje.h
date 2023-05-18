#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>
#include <QObject>
#include <QCamera>
#include <string.h>
class Personaje : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Personaje();
    ~Personaje();
    QRectF boundingRect() const override;
    QPixmap *getPixmap() const;
    QString path;
    //void mover(int x, int y);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    //void keyPressEvent(QKeyEvent *event) override;


    bool getColisionObstaculos() const;
    void setColisionObstaculos(bool newColisionObstaculos);
    bool colisionObstaculos;
    int posX, posY, radio;
    QPixmap *pixmap;





/*
signals:
    void posicionCambiada();
*/
};

#endif // PERSONAJE_H



