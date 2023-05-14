#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>
#include <QObject>
#include <QCamera>
class Personaje : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Personaje();
    ~Personaje();

    void mover(int x, int y);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void keyPressEvent(QKeyEvent *event) override;
    QPixmap *getPixmap() const;

    bool getColisionObstaculos() const;

    void setColisionObstaculos(bool newColisionObstaculos);

private:
    int posX, posY, radio;
    bool colisionObstaculos;
    QPixmap *pixmap;
signals:
    void posicionCambiada();

};

#endif // PERSONAJE_H



