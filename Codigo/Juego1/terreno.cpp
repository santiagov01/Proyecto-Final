#include "terreno.h"

Terreno::Terreno(QGraphicsView *view)
{
    this->view = view;
    scene = new QGraphicsScene();
    view->setScene(scene);
}

void Terreno::Crear_fondo(QString path)
{
    Fondo = new QPixmap(path);
}

void Terreno::Mostrar_Terreno()
{
    scene->addPixmap(*Fondo);
    view->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

QGraphicsView *Terreno::getView() const
{
    return view;
}
