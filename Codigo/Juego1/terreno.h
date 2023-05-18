#ifndef TERRENO_H
#define TERRENO_H

#include <QPixmap>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include "enemigos.h"
#include "personaje.h"
#include <QObject>
#include "iostream"
#include "obstaculos.h"
#include "protagonista.h"
class Terreno : public QObject
{
    Q_OBJECT
public:
    Terreno(QGraphicsView *view);
    ~Terreno();
    void Crear_fondo(QString path);
    void Mostrar_Terreno();
    void actualizar_vista();
    QGraphicsView *getView() const;
    QGraphicsScene *getScene() const;
    bool EvaluarColision();

    bool EvaluarColision2();
    void crearEnemigos();

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPixmap *Fondo,porcion;
    Personaje *personaje;
    Protagonista *protagonista;
    Enemigos *enemigotest;

    QList<Enemigos*> lista_enemigos;
    QList<Obstaculos*> paredes;
    QList<Obstaculos*> recompensas;
    int i_test;
public slots:

    void EvaluarColisionEnemigo();


};

#endif // TERRENO_H
