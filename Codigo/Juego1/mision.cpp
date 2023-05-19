#include "mision.h"
#include <QObject>
#include "personaje.h"
#include "auxiliares.h"

Mision::Mision(int codigo, QMainWindow *mainwindow):mainwindow(mainwindow)
{
    view = new QGraphicsView();
    Mapa = new Terreno(view);



    switch(codigo){
    case 1:{
        Mapa->Crear_fondo(":/FilnarMapa1.png");
        Mapa->Cargar_Arboles("ArbolesPrueba.csv");
        Mapa->Mostrar_Terreno();

        mainwindow->setCentralWidget(view);







    }
    }
}

