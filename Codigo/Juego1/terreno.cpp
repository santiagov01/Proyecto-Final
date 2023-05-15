#include "terreno.h"

Terreno::Terreno(QGraphicsView *view)
{
    this->view = view;
    scene = new QGraphicsScene();
    view->setScene(scene);

    //Personaje *personaje = new Personaje();
    //personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    //personaje->setFocus();

    this->personaje = new Personaje();
    personaje->setPos(10,10);
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();

    paredes.push_back(new Obstaculos(200,200,660,20));


    connect(personaje, &Personaje::posicionCambiada, this, &Terreno::actualizar_vista);
    connect(personaje, &Personaje::posicionCambiada, this, &Terreno::EvaluarColision);
    connect(personaje, &Personaje::posicionCambiada, this, &Terreno::EvaluarColision2);



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


    /*personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    personaje->focusItem();*/
    personaje->setActive(true);
    personaje->setSelected(true);

    scene->addItem(paredes.back());
    paredes.push_back(new Obstaculos(-20,-20,660,20));
    scene->addItem(paredes.back());
    paredes.push_back(new Obstaculos(-20,-20,20,430));
    scene->addItem(paredes.back());
    paredes.push_back(new Obstaculos(0,Fondo->height(),660,20));
    scene->addItem(paredes.back());

    recompensas.push_back(new Obstaculos(400,400,20,20));
    scene->addItem(recompensas.back());


}

void Terreno::actualizar_vista()
{
    view->centerOn(personaje);
}
bool Terreno::EvaluarColision()
{
    QList<Obstaculos*>::Iterator it;
    for(it = paredes.begin();it!=paredes.end();++it){
        if((*it)->collidesWithItem(personaje)){
            personaje->setColisionObstaculos(true);
            return true;
        }
    }
    personaje->setColisionObstaculos(false);
    return false;
}

bool Terreno::EvaluarColision2()
{
    QList<Obstaculos*>::Iterator it2;
    for(it2 = recompensas.begin();it2!=recompensas.end();++it2){
        if((*it2)->collidesWithItem(personaje)){
            scene->removeItem(*it2);
            recompensas.erase(it2);
            return true;
        }
    }
    return false;
}
QGraphicsView *Terreno::getView() const
{
    return view;
}

QGraphicsScene *Terreno::getScene() const
{
    return scene;
}

