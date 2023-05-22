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

using namespace std;
class Personaje : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Personaje(int Ancho, int Alto);
    ~Personaje();

    void mover(int x, int y);
    void sprite();


    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    QPixmap *getPixmap() const;

private:
    unsigned short int posX, posY,columnas,ancho,alto;
    unsigned short int estado, orientacion;
    bool atacando;
    QPixmap *pixmap;
    QTimer *AnimacionTimer;
    map<int, string> Imagenes_personaje;


signals:
    void posicionCambiada();
public slots:
     void actualizar_sprite();

};

#endif // PERSONAJE_H



