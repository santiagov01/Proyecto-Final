#include "terreno.h"

#include "QDebug"
#include "QScrollArea"
Terreno::Terreno(QGraphicsView *view)
{
    this->view = view;
    scene = new QGraphicsScene();
    view->setScene(scene);

    //Personaje *personaje = new Personaje();
    //personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    //personaje->setFocus();

    /*
    this->personaje = new Personaje();
    personaje->setPos(10,10);
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();

    paredes.push_back(new Obstaculos(200,200,660,20));


    connect(personaje, &Personaje::posicionCambiada, this, &Terreno::actualizar_vista);
    connect(personaje, &Personaje::posicionCambiada, this, &Terreno::EvaluarColision);
    connect(personaje, &Personaje::posicionCambiada, this, &Terreno::EvaluarColision2);
*/
    this->protagonista = new Protagonista(":/Pj.png");
    protagonista->setPos(10,10);
    protagonista->setFlag(QGraphicsItem::ItemIsFocusable);
    protagonista->setFocus();

    paredes.push_back(new Obstaculos(200,200,660,20));

    lista_enemigos.push_back(new Enemigos(":/enemytest.png",200,200));


    this->enemigotest = new Enemigos(":/enemytest.png",100,100);


    connect(protagonista, &Protagonista::posicionCambiada, this, &Terreno::actualizar_vista);
    connect(protagonista, &Protagonista::posicionCambiada, this, &Terreno::EvaluarColision2);

    connect(protagonista, &Protagonista::posicionCambiada, this, &Terreno::EvaluarColision);

    connect(protagonista, &Protagonista::posicionCambiada, this, &Terreno::EvaluarColisionEnemigo);
   // connect(protagonista, SIGNAL(protagonista->posicionCambiada()), this, SLOT(EvaluarColisionEnemigo()));
    i_test =0;
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
    scene->addItem(enemigotest);
    scene->addItem(protagonista);




    /*personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    personaje->focusItem();*/
    //personaje->setActive(true);
    //personaje->setSelected(true);

    scene->addItem(paredes.back());
    paredes.push_back(new Obstaculos(-20,-20,660,20));
    scene->addItem(paredes.back());
    paredes.push_back(new Obstaculos(-20,-20,20,430));
    scene->addItem(paredes.back());
    paredes.push_back(new Obstaculos(0,Fondo->height(),660,20));
    scene->addItem(paredes.back());


    recompensas.push_back(new Obstaculos(400,400,20,20));
    scene->addItem(recompensas.back());

    scene->addItem(lista_enemigos.back());
    lista_enemigos.push_back(new Enemigos(":/enemytest.png",200,300));
    scene->addItem(lista_enemigos.back());


}

void Terreno::actualizar_vista()
{
    view->centerOn(protagonista);
}
bool Terreno::EvaluarColision()
{
    QList<Obstaculos*>::Iterator it;

    for(it = paredes.begin();it!=paredes.end();++it){
        if((*it)->collidesWithItem(protagonista) ||enemigotest->collidesWithItem(protagonista) ){
            protagonista->setColisionObstaculos(true);
            std::cout<<"COLISION"<<i_test<<std::endl;
            i_test++;
            return true;
        }
    }
    protagonista->setColisionObstaculos(false);
    return false;
}

void Terreno::EvaluarColisionEnemigo()
{
    QList<Enemigos*>::Iterator it;
    for(it = lista_enemigos.begin();it!=lista_enemigos.end();++it){
        if((*it)->collidesWithItem(protagonista) ||enemigotest->collidesWithItem(protagonista) ){
            protagonista->setColisionObstaculos(true);
            std::cout<<"COLISION ENEMIGOS"<<std::endl;
            //i_test++;
            return;
        }
    }
    protagonista->setColisionObstaculos(false);
    return;
}

bool Terreno::EvaluarColision2()
{
    QList<Obstaculos*>::Iterator it2;
    for(it2 = recompensas.begin();it2!=recompensas.end();++it2){
        if((*it2)->collidesWithItem(protagonista)){
            scene->removeItem(*it2);
            recompensas.erase(it2);
            std::cout<<"ME LO COMO"<<std::endl;
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

