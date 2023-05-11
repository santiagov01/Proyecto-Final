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

    connect(personaje, &Personaje::posicionCambiada, this, &Terreno::actualizar_vista);


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
    QRectF rect(0, 0, 1920, 1080);
    QPixmap vista(*Fondo);
    QPixmap porcion = vista.copy(rect.x(), rect.y(), rect.width(), rect.height());
    scene->clear();
    scene->addPixmap(porcion);
    scene->addItem(personaje);
}

void Terreno::actualizar_vista()
{
    view->centerOn(personaje);
}

QGraphicsView *Terreno::getView() const
{
    return view;
}

QGraphicsScene *Terreno::getScene() const
{
    return scene;
}

