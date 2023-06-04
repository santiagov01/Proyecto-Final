#include "terreno.h"
#include "auxiliares.h"
#include <QDebug>

Terreno::Terreno(QGraphicsView *view)
{
    this->view = view;
    scene = new QGraphicsScene();
    view->setScene(scene);
    view->scale(1.5,1.5);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    srand(time(NULL));

//    Personaje *personaje = new Personaje(288,128);
    personaje = new Protagonista("Sprites.csv",43,37,999,100,800,800);
//    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
//    personaje->setFocus();
    view->setRenderHint(QPainter::Antialiasing);

//    this->personaje = personaje;
    personaje->setPos(800,800);
  //   personaje->setZValue(6);

    connect(personaje, &Protagonista::posicionCambiada, this, &Terreno::actualizar_vista);
    connect(personaje, &Protagonista::posicionCambiada, this, &Terreno::EvaluarColision);

    timer_spawn = new QTimer();
    timer_cordura = new QTimer();

    connect(timer_spawn, SIGNAL(timeout()),this, SLOT(aparecerEnemigos()));
    connect(timer_cordura, SIGNAL(timeout()),this, SLOT(disminuir_cordura()));

    timer_cordura->start(1000);
    timer_spawn->start(3600);
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
//        Arbol *arbol = new Arbol(Imagenes_arbol[datos[0]], datos[1], datos[2]);
//        arbol->setZValue(datos[3]+1);
//        lista_arboles.push_back(arbol);
//        scene->addItem(arbol);
          lista_arboles.push_back(new Arbol(Imagenes_arbol[datos[0]], datos[1], datos[2]));
          lista_arboles.back()->setZValue(datos[3]+1);
          scene->addItem(lista_arboles.back());
    }

}

void Terreno::Cargar_Obstaculos(string path1,string path2)
{
    Cargar_datos(path1, &obstaculos);
    Cargar_imagen(path2,&Imagenes_obstaculo);
    for (vector<int> datos : obstaculos) {
//        Obstaculos *obstaculo = new Obstaculos(Imagenes_obstaculo[datos[0]], datos[1], datos[2]);
//        obstaculo->setZValue(6);
//        lista_obstaculos.push_back(obstaculo);
        lista_obstaculos.push_back(new Obstaculos(Imagenes_obstaculo[datos[0]], datos[1], datos[2]));
        lista_obstaculos.back()->setZValue(6);
        scene->addItem( lista_obstaculos.back());
    }

}

void Terreno::EvaluarColision()
{
    QList<Obstaculos*>::Iterator it;

    for(it = lista_obstaculos.begin();it!=lista_obstaculos.end();++it){

        if((*it)->collidesWithItem(personaje)){
            personaje->setColisionObstaculos(true);
            std::cout<<"COLISION"<< iter<<std::endl;
            iter++;

            return;
        }
    }
     personaje->setColisionObstaculos(false);
//    QList<Enemigos*>::Iterator it3;
//    for(it3 = lista_enemigos.begin();it3!=lista_enemigos.end();++it3){
//        if((*it3)->collidesWithItem(protagonista)){
//            protagonista->setColisionObstaculos(true);


//            std::cout<<"COLISION CON ENEMIGOS"<<std::endl;
//            //i_test++;
//            return;
//        }
//    }
//    protagonista->setColisionObstaculos(false);
//    return;
}

void Terreno::aparecerEnemigos()
//Spawn enemigos dependiente de la cordura del personaje
//Faltan hacer validaciones y verificar cuándo es válida este tipo de spawn
{

    int limite_inferior = 60; //ancho del enemigo para que no genere una colision inmediata :v
    int limite_superior = 100;
    int porcentaje = 100 - personaje->getCordura();
    int dado = rand()%(101);
//    std::cout << "PROBABILIDAD: " << porcentaje << std::endl;
//    std::cout << "DADO: " << dado << std::endl;
//    std::cout <<"CORDURA: "<< protagonista->getCordura() << std::endl;
    if(!(dado < porcentaje) || lista_enemigos.size() > 10){
        std::cout << "No aparece enemigo" << std::endl;

        return;
    }
    //std::cout << "Aparece enemigo "<< std::endl;
    int dir_posx;
    int dir_posy;
    //numeros random para poner a la izquierda o derecha
    dir_posx = rand()%2;
    dir_posy = rand()%2;

    //posicion aleatoria cerca al enemigo (depende de limites)
    int e_posx = rand()%(limite_superior+1 - limite_inferior) + limite_inferior;
    int e_posy = rand()%(limite_superior+1 - limite_inferior) +  limite_inferior;
    if(dir_posx==0)e_posx= -e_posx + personaje->x();//posicion x enemigo a la izquierda
    else e_posx = e_posx + personaje->x();
    if(dir_posy==0)e_posy = -e_posy + personaje->y();//posicion y enemigo a la derecha
    else e_posy+= personaje->y();
    //string _path,int Ancho, int Alto, int _vida, int _posx, int _posy, Protagonista *player
    //lista_enemigos.push_back(new Enemigos(":/Quimera.png",e_posx,e_posy,personaje));
    lista_enemigos.push_back(new Enemigos("Sprites.csv",43,37,100,e_posx,e_posy,personaje,10));
//    if(e_posx > Fondo->width())e_posx = Fondo->width()-lista_enemigos.back()->pixmap->width()/2;
//    else if(e_posx < 0)e_posx = lista_enemigos.back()->pixmap->width()/2;
//    if(e_posy > Fondo->height())e_posy = Fondo->height()-lista_enemigos.back()->pixmap->height()/2;
//    else if(e_posy<0)e_posy = lista_enemigos.back()->pixmap->height()/2;
    qreal x = e_posx;
    qreal y = e_posy;
    lista_enemigos.back()->setPos(x,y);


    QGraphicsRectItem* e=new QGraphicsRectItem(-30,-10,60,20);
    scene->addItem(e);
    e->setPos(x,y);
    std::cout<<"NEW ENEMY"<<std::endl;

    scene->addItem(lista_enemigos.back());
}

void Terreno::disminuir_cordura()
//Modificar la cordura del personaje cada 1 minuto
//Aumenta la probabilidad de que aparezca un enemigo
{
    int cordura = personaje->getCordura();
    if(cordura > 0){
        personaje->setCordura(cordura-1);
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




