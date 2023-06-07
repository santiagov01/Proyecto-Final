
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QPixmap>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QObject>
#include <QFile>
#include "arbol.h"
#include "auxiliares.h"
#include "obstaculos.h"
#include "protagonista.h"
#include <QTimer>
#include <QList>
#include "enemigos.h"

#include <QMainWindow>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QKeyEvent>
#include <QMouseEvent>
#include "proyectil.h"

#include "botin.h"


#include <QDebug>

//CONTINENTE
namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //-------------------------

    void Crear_fondo(QString path);
    void Mostrar_Terreno();
    void actualizar_vista();
    void leer_archivo(QString ruta_archivo);
    void Cargar_Arboles(string path, string path2);
    void Cargar_Obstaculos(string path1, string path2);
    void Cargar_paredes(string path1);

    void EvaluarColision();
    //-----------------
private:
    Ui::MainWindow *ui;
//    Iniciar *Continentes;
//    Mision *prueba;
    //------------
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPixmap *Fondo,porcion;
    //Personaje *personaje;
    Protagonista* personaje;


    Obstaculos *obstaculo;
    Botin *Recompensa;

    list<vector<int>> arboles,obstaculos,paredes;
    list<Botin*> lista_botin;
    QList<Obstaculos*> lista_obstaculos;
    QList<Enemigos*> lista_enemigos;
    map<int, string> Imagenes_arbol, Imagenes_obstaculo;

    QTimer *timer_spawn;
    QTimer *timer_cordura;
    QTimer *timer_impacto_proyectil;
    QTimer *timer_impacto_personaje;
    QTimer *timer_recoger_recompensa;

    QList<Proyectil*> lista_proyectiles;


    //----------

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
public slots:
    void goBack();
    void disminuir_cordura();
    void aparecerEnemigos();
    void impacto_proyectil();
    void impacto_personaje();
    void recoger_botin();

};

#endif // MAINWINDOW_H
