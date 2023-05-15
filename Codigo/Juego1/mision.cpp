#include "mision.h"
#include <QObject>
#include "personaje.h"

Mision::Mision(int codigo, QMainWindow *mainwindow):mainwindow(mainwindow)
{
    view = new QGraphicsView();
    Mapa = new Terreno(view);



    switch(codigo){
    case 1:{
        Mapa->Crear_fondo(":/FilnarFondo.png");
        Mapa->Mostrar_Terreno();
        mainwindow->setCentralWidget(view);
        mainwindow->focusWidget();
        }
    }
}

