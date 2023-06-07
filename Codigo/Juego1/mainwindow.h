#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QPixmap>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QObject>
#include <QFile>
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
#include <QMessageBox>

#include <QDebug>
#include "botin.h"
#include "pause.h"
//CONTINENTE
namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, int _mision = 1);
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
    void OleadasConstruct();
    void LaberintoConstruct();
    void setMision(int newMision);

private:
    Ui::MainWindow *ui;
//    Iniciar *Continentes;
//    Mision *prueba;
    //------------
    int mision; //1=> oleadas, 2=> laberinto
    bool juego_iniciado;
    bool mision_completada;
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
    map<int, vector<QString>> datos_tipo_enemigos;

    QTimer *timer_spawn;
    QTimer *timer_cordura;
    QTimer *timer_impacto_proyectil;
    QTimer *timer_impacto_personaje;
    QTimer *timer_recoger_recompensa;
    QList<Proyectil*> lista_proyectiles;

    string causa_aparicion;

    Obstaculos* misionCompletedIcon;
    //----------

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
//-----------OLEADA-------------------
    bool iniciar_mision;
    Obstaculos* activa_misionoleadas;
    Obstaculos* activador_oleada1;
    Obstaculos* activador_oleada3;
    Obstaculos* activador_oleada2;

    Obstaculos* puerta_1;
    Obstaculos* puerta_2;
    Obstaculos* puerta_3;
    QTimer* timer_eval_pos;
    QTimer* tiempo_oleada;
    bool inicia_oleada1;
    bool inicia_oleada2, inicia_oleada3;

    int temp;
    int oleada_actual;
    int tipo_enemigo;
//    QGraphicsRectItem* activa_misionoleadas;
//    QGraphicsRectItem* activador_oleada1;
//    QGraphicsRectItem* activador_oleada2;
//    QGraphicsRectItem* activador_oleada3;
//    QGraphicsRectItem* puerta_1;
//    QGraphicsRectItem* puerta_2;
//    QGraphicsRectItem* puerta_3;


//------LABERINTO-----
    bool laberinto_completado;
    bool iniciar_laberinto;
    QTimer* tiempo_laberinto;
    Obstaculos* activa_lab;
    Obstaculos* termina_lab;
    Obstaculos* puerta_entrada;
    Obstaculos* puerta_salida;
    void aparecerEnemigos_Laberinto(double, double, double xlim, double ylim, int direct);

    //------
    int tipo_proyectil;

public slots:
    void iniciarOleada();
    void iniciarLaberinto();

    void goBack();
    void disminuir_cordura();
    void aparecerEnemigos();

    void impacto_proyectil();
    void impacto_personaje();

    void recoger_botin();
};

#endif // MAINWINDOW_H
