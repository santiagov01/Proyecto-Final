#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>
#include <QObject>
#include <QMovie>
#include <QString>
#include <QLabel>
#include <QTimer>
#include "auxiliares.h"
#include <QGraphicsSceneMouseEvent>
#include <string>
#include <QGraphicsScene>
using namespace std;
class Personaje : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Personaje(string _path,int Ancho, int Alto,int _vida);
    ~Personaje();

    //void mover(int x, int y);
    void sprite();
    string path;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

//    void keyPressEvent(QKeyEvent *event) override;
//    void keyReleaseEvent(QKeyEvent *event) override;
//    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    unsigned short int posX, posY,columnas,ancho,alto;
    unsigned short int estado, orientacion;
    int vida_maxm, vida_actual, vida;
    bool atacando;
    bool colisionObstaculos;
    QPixmap *pixmap;
    QTimer *AnimacionTimer;
    map<int, string> Imagenes_personaje;

    QGraphicsRectItem *barraVidaItem;


    void setColisionObstaculos(bool newColisionObstaculos);
    void BarraVida(QGraphicsScene *scene);
    void actualizarPosicionBarraVida();
    void actualizarBarraVida(int daño);

    void setVida_actual(int newVida_actual);

public slots:
     void actualizar_sprite();

};

#endif // PERSONAJE_H



