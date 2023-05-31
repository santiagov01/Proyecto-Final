#ifndef TERRENO_H
#define TERRENO_H

#include <QPixmap>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include "personaje.h"
#include <QObject>
#include <QFile>
#include "arbol.h"
#include "auxiliares.h"
#include "obstaculos.h"
#include "protagonista.h"
#include <QTimer>
#include <QList>
#include "enemigos.h"
using namespace std;

class Terreno : public QObject
{
    Q_OBJECT
public:
    Terreno(QGraphicsView *view);
    ~Terreno();
    void Crear_fondo(QString path);
    void Mostrar_Terreno();
    void actualizar_vista();
    void leer_archivo(QString ruta_archivo);
    void Cargar_Arboles(string path, string path2);
    void Cargar_Obstaculos(string path1, string path2);

    void EvaluarColision();

    QGraphicsView *getView() const;
    QGraphicsScene *getScene() const;




private:
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

    QTimer *timer_spawn;
    QTimer *timer_cordura;


    int iter;

public slots:
    void disminuir_cordura();
    void aparecerEnemigos();
};

#endif // TERRENO_H
