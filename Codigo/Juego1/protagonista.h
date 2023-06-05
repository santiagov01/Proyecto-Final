#ifndef PROTAGONISTA_H
#define PROTAGONISTA_H


#include "personaje.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>
#include <QObject>
#include <QCamera>
#include <QList>
#include <string>
class Protagonista: public Personaje
{
    Q_OBJECT
public:
    Protagonista(string _path, int Ancho, int Alto, int _vida, int cordura, int _x, int _y);
    ~Protagonista();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;



//    void keyPressEvent(QKeyEvent *event) override;
//    void keyReleaseEvent(QKeyEvent *event) override;
    //bool colisionObstaculos;
    //bool getColisionObstaculos() const;

//    void keyPressEvent(QKeyEvent *event) override;
//    void keyReleaseEvent(QKeyEvent *event) override;
    //void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    int getCordura() const;
    void setCordura(int newCordura);
    void mover(int x, int y);
    bool moverIx;
    bool moverDx;
    bool moverUy;
    bool moverDy;
    int arma;

private:
    int cordura;

    // es posible que pixmap se deje en el padre
    //QPixmap *pixmap;
    //void setColisionObstaculos(bool newColisionObstaculos);
public slots:
    //void mover();
    //void mover(int x, int y);
signals:
    void posicionCambiada();

};


#endif // PROTAGONISTA_H
