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
#include <QTimer>
#include <QAbstractScrollArea>
#include "time.h"
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
    void EvaluarColision();

    bool EvaluarColision2();


private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPixmap *Fondo,porcion;
    Personaje *personaje;
    Protagonista *protagonista;
    Enemigos *enemigotest;

    QTimer *timer_aparecer;
    QTimer *timer_cordura;
    QList<Enemigos*> lista_enemigos;
    QList<Obstaculos*> paredes;
    QList<Obstaculos*> recompensas;


    int i_test;
public slots:
    void disminuir_cordura();
    void EvaluarColisionEnemigo();
    void aparecerEnemigos();


};

#endif // TERRENO_H
