#ifndef TERRENO_H
#define TERRENO_H

#include <QPixmap>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>

class Terreno
{
public:
    Terreno(QGraphicsView *view);
    void Crear_fondo(QString path);
    void Mostrar_Terreno();
    QGraphicsView *getView() const;

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPixmap *Fondo;
};

#endif // TERRENO_H
