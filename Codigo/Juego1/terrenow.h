#ifndef TerrenoWW_H
#define TerrenoWW_H

#include <QPixmap>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include "enemigos.h"
#include "personaje.h"
#include <QObject>

#include "obstaculos.h"
#include "protagonista.h"
#include <QTimer>
#include <QAbstractScrollArea>
#include "qmainwindow.h"
#include "time.h"

#include "proyectil.h"
class TerrenoW : public QMainWindow {
    Q_OBJECT
public:
    TerrenoW(QWidget *parent = nullptr);
    ~TerrenoW();
    void Crear_fondo(QString path);
    void Mostrar_TerrenoW();
    void actualizar_vista();
    QGraphicsView *getView() const;
    QGraphicsScene *getScene() const;
    void EvaluarColision();

    bool EvaluarColision2();
    //void mousePressEvent(QMouseEvent *event) ;

private:
    QMainWindow *mainwindow;

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

    QList<Proyectil*> proyectiles_pj;

    int i_test;
public slots:
    void disminuir_cordura();
    void EvaluarColisionEnemigo();
    void aparecerEnemigos();
};

#endif // TerrenoWW_H
