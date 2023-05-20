#ifndef PROTAGONISTA_H
#define PROTAGONISTA_H

#include "personaje.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>
#include <QObject>
#include <QCamera>
class Protagonista: public Personaje
{
    Q_OBJECT
public:
    Protagonista(QString path);
    ~Protagonista();
    void mover(int x, int y);
    void keyPressEvent(QKeyEvent *event) override;
    //bool colisionObstaculos;
    //bool getColisionObstaculos() const;
    int getCordura() const;
    void setCordura(int newCordura);

private:
    int cordura;
    // es posible que pixmap se deje en el padre
    //QPixmap *pixmap;
    //void setColisionObstaculos(bool newColisionObstaculos);

signals:
    void posicionCambiada();
};

#endif // PROTAGONISTA_H
