#include "terreno.h"
#include "auxiliares.h"
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
    personaje->setZValue(1);

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

    scene->setSceneRect(0,0,Fondo->width(),Fondo->height());
    scene->addPixmap(*Fondo);
    scene->addItem(personaje);
}

void Terreno::actualizar_vista()
{
    view->centerOn(personaje);
}

void Terreno::Cargar_Arboles(string path)
{
    Cargar_datos(path, &arboles);
    for (vector<int> datos : arboles) {
        Arbol *arbol = new Arbol(datos[0], datos[1], datos[2]);
        arbol->setZValue(2);
        lista_arboles.push_back(arbol);
        scene->addItem(arbol);
    }

}


QGraphicsView *Terreno::getView() const
{
    return view;
}

QGraphicsScene *Terreno::getScene() const
{
    return scene;
}




