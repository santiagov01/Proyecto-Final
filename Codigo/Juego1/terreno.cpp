#include "terreno.h"

Terreno::Terreno(QGraphicsView *view)
{
    this->view = view;
    scene = new QGraphicsScene();
    view->setScene(scene);

    Personaje *personaje = new Personaje();
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();


    this->personaje = personaje;
    personaje->setPos(0,0);
}

Terreno::~Terreno()
{

}

void Terreno::Crear_fondo(QString path)
{
    Fondo = new QPixmap(path);
}

void Terreno::Mostrar_Terreno()
{
    QRectF rect(0, 0, 1366, 750);
    QPixmap camara(*Fondo);
    QPixmap porcion = camara.copy(rect.x(), rect.y(), rect.width(), rect.height());
    scene->clear();
    scene->addPixmap(porcion);
    scene->addItem(personaje);


}

QGraphicsView *Terreno::getView() const
{
    return view;
}

QGraphicsScene *Terreno::getScene() const
{
    return scene;
}

