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

void Terreno::Cargar_Arboles(string path1, string path2)
{
    Cargar_datos(path1, &arboles);
    Cargar_imagen(path2,&Imagenes_arbol);
    for (vector<int> datos : arboles) {
        Arbol *arbol = new Arbol(Imagenes_arbol[datos[0]], datos[1], datos[2]);
        arbol->setZValue(datos[3]+1);
        lista_arboles.push_back(arbol);
        scene->addItem(arbol);
    }

}

void Terreno::Cargar_Obstaculos(string path1,string path2)
{
    Cargar_datos(path1, &obstaculos);
    Cargar_imagen(path2,&Imagenes_obstaculo);
    for (vector<int> datos : obstaculos) {
        Obstaculos *obstaculo = new Obstaculos(Imagenes_obstaculo[datos[0]], datos[1], datos[2]);
        obstaculo->setZValue(6);
        lista_obstaculos.push_back(obstaculo);
        scene->addItem(obstaculo);
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




