#ifndef MISION_H
#define MISION_H

#include <QMainWindow>
#include <QGraphicsView>
#include "terreno.h"

class Mision
{
public:
    Mision(int codigo, QMainWindow *mainwindow);
private:
    QGraphicsView *view;
    Terreno *Mapa;
    QMainWindow *mainwindow;
};

#endif // MISION_H
