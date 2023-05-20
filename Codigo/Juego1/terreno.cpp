#include "terreno.h"
#include <QGraphicsScene>
#include "QDebug"
#include "QScrollArea"
Terreno::Terreno(QGraphicsView *view)
{
    this->view = view;
    scene = new QGraphicsScene();
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    srand(time(NULL));
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

    lista_enemigos.push_back(new Enemigos(":/Quimera.png",200,200));
    this->enemigotest = new Enemigos(":/Quimera.png",100,100);

    timer_aparecer = new QTimer();
    timer_cordura = new QTimer();
    connect(protagonista, &Protagonista::posicionCambiada, this, &Terreno::actualizar_vista);
    connect(protagonista, &Protagonista::posicionCambiada, this, &Terreno::EvaluarColision2);
    //connect(protagonista, &Protagonista::posicionCambiada, this, &Terreno::EvaluarColisionEnemigo);
    connect(protagonista, &Protagonista::posicionCambiada, this, &Terreno::EvaluarColision);

    connect(timer_aparecer, SIGNAL(timeout()),this, SLOT(aparecerEnemigos()));
    connect(timer_cordura, SIGNAL(timeout()),this, SLOT(disminuir_cordura()));

    timer_cordura->start(1000);
    timer_aparecer->start(3000);
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
    lista_enemigos.push_back(new Enemigos(":/Quimera.png",200,300));
    scene->addItem(lista_enemigos.back());

}

void Terreno::actualizar_vista()
{
    view->centerOn(protagonista);
}
void Terreno::EvaluarColision()
{
    QList<Obstaculos*>::Iterator it;
    QList<Enemigos*>::Iterator it2;
    it2 = lista_enemigos.begin();
    for(it = paredes.begin();it!=paredes.end();++it){

        if((*it)->collidesWithItem(protagonista) ||enemigotest->collidesWithItem(protagonista) ){
            protagonista->setColisionObstaculos(true);
            std::cout<<"COLISION"<<i_test<<std::endl;
            i_test++;
            return;
        }
    }
    protagonista->setColisionObstaculos(false);
    QList<Enemigos*>::Iterator it3;
    for(it3 = lista_enemigos.begin();it3!=lista_enemigos.end();++it3){
        if((*it3)->collidesWithItem(protagonista) ||enemigotest->collidesWithItem(protagonista) ){
            protagonista->setColisionObstaculos(true);
            std::cout<<"COLISION ENEMIGOS"<<std::endl;
            //i_test++;
            return;
        }
    }
    protagonista->setColisionObstaculos(false);
    return;
}

void Terreno::EvaluarColisionEnemigo()
{
    QList<Enemigos*>::Iterator it3;
    for(it3 = lista_enemigos.begin();it3!=lista_enemigos.end();++it3){
        if((*it3)->collidesWithItem(protagonista) ||enemigotest->collidesWithItem(protagonista) ){
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

void Terreno::disminuir_cordura()
//Modificar la cordura del personaje cada 1 minuto
//Aumenta la probabilidad de que aparezca un enemigo
{
    int cordura = protagonista->getCordura();
    if(cordura > 0){
        protagonista->setCordura(cordura-1);
    }

}

void Terreno::aparecerEnemigos()
{

    int limite_inferior = 30; //ancho del enemigo para que no genere una colision inmediata :v
    int limite_superior = 100;
    int porcentaje = 100 - protagonista->getCordura();
    int dado = rand()%(101);
    std::cout << "PROBABILIDAD: " << porcentaje << std::endl;
    std::cout << "DADO: " << dado << std::endl;
    std::cout <<"CORDURA: "<< protagonista->getCordura() << std::endl;
    if(!(dado < porcentaje)){
        std::cout << "No aparece enemigo" << std::endl;

        return;
    }
    std::cout << "Aparece enemigo "<< std::endl;
    int dir_posx;
    int dir_posy;
    //numeros random para poner a la izquierda o derecha
    dir_posx = rand()%2;
    dir_posy = rand()%2;

    //posicion aleatoria cerca al enemigo (depende de limites)
    int e_posx = rand()%(limite_superior+1 - limite_inferior) + limite_inferior;
    int e_posy = rand()%(limite_superior+1 - limite_inferior) +  limite_inferior;
    if(dir_posx==0)e_posx= -e_posx + protagonista->posX;//posicion x enemigo a la izquierda
    else e_posx = e_posx + protagonista->posX;
    if(dir_posy==0)e_posy = -e_posy + protagonista->posY;//posicion y enemigo a la derecha
    else e_posy+= protagonista->posY;
    /*
    std::cout << protagonista->posX<<std::endl;
    std::cout << protagonista->posY<<std::endl;
    std::cout << "POSFINAL"<<std::endl;
    std::cout << e_posx<<std::endl;
    std::cout << e_posy<<std::endl;
    */
    lista_enemigos.push_back(new Enemigos(":/Quimera.png",e_posx,e_posy));
    qreal x = e_posx;
    qreal y = e_posy;
    lista_enemigos.back()->setPos(x,y);
    std::cout<<"NEW ENEMY"<<std::endl;

    scene->addItem(lista_enemigos.back());

}
QGraphicsView *Terreno::getView() const
{
    return view;
}

QGraphicsScene *Terreno::getScene() const
{
    return scene;
}

