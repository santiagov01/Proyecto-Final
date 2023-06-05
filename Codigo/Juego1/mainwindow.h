
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


#include <QDebug>

#include "pause.h"
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

    Arbol *arbol;//Se pueden eliminar
    Obstaculos *obstaculo;

    list<vector<int>> arboles,obstaculos;
    list<Arbol* > lista_arboles;

    QList<Obstaculos*> lista_obstaculos;
    QList<Enemigos*> lista_enemigos;
    map<int, string> Imagenes_arbol, Imagenes_obstaculo;
    map<int, vector<QString>> datos_tipo_enemigos;

    QTimer *timer_spawn;
    QTimer *timer_cordura;
    QTimer *timer_impacto_proyectil;
    QTimer *timer_impacto_personaje;

    QList<Proyectil*> lista_proyectiles;

    //----------

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
//-----------OLEADA-------------------
    bool iniciar_mision;

    QTimer* timer_eval_pos;
    QTimer* tiempo_oleada;
    bool inicia_oleada1;
    bool inicia_oleada2, inicia_oleada3;
    QGraphicsRectItem* activa_misionoleadas;
    int temp;
    int oleada_actual;
    int tipo_enemigo;
    QGraphicsRectItem* activador_oleada1;
    QGraphicsRectItem* activador_oleada2;
    QGraphicsRectItem* activador_oleada3;
    QGraphicsRectItem* puerta_1;
    QGraphicsRectItem* puerta_2;
    QGraphicsRectItem* puerta_3;

    map<int, QString> tipos_enemigos;
public slots:
    void iniciarOleada();

    void goBack();
    void disminuir_cordura();
    void aparecerEnemigos();
    void impacto_proyectil();
    void impacto_personaje();

};

#endif // MAINWINDOW_H
