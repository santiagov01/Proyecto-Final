#ifndef MISION_H
#define MISION_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QKeyEvent>
#include "terreno.h"
#include "personaje.h"

class Mision
{

public:
    Mision(int codigo, QMainWindow *mainwindow);
    ~Mision();
    void keyPressEvent(QKeyEvent *event);
private:
    QGraphicsView *view;
    Terreno *Mapa;
    QMainWindow *mainwindow;
    Personaje *personaje;


};

#endif // MISION_H
