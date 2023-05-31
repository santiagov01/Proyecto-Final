
#include "mainwindow.h"

#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Continentes=new Iniciar(this);

    //--------Conexión para regresar a la anterior ventana--------------------
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::goBack);
    timer->start(200000);
    //prueba=new Mision(1,this);

    //---------------------------------------------------------
    view = ui->graphicsView;
    scene = new QGraphicsScene();

    view->setScene(scene);
    //view->scale(1.5,1.5);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    srand(time(NULL));


    //Crear_fondo(":/FilnarMapa1.png");
    //---------------------------------------------------------------------
    //PASAR COMO PARAMETRO EL MAPA Y LOS CSV
    scene->setBackgroundBrush(QBrush(QImage(":/FilnarMapa1.png")));
    Cargar_Arboles("ArbolesPrueba2.csv","PathArboles.csv");
    Cargar_Obstaculos("Obstaculos.csv","PathObstaculos.csv");


    setCentralWidget(view);
    view->setRenderHint(QPainter::Antialiasing);
    scene->clearFocus();

    personaje = new Protagonista("Sprites.csv",45,45,999,100,800,800);
    personaje->setZValue(1);
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();

    Mostrar_Terreno();
    personaje->setPos(800,800);


    //--------------------------------------------------------------------------------
    connect(personaje, &Protagonista::posicionCambiada, this, &MainWindow::actualizar_vista);
    connect(personaje, &Protagonista::posicionCambiada, this, &MainWindow::EvaluarColision);

    timer_spawn = new QTimer();
    timer_cordura = new QTimer();

    connect(timer_spawn, SIGNAL(timeout()),this, SLOT(aparecerEnemigos()));
    connect(timer_cordura, SIGNAL(timeout()),this, SLOT(disminuir_cordura()));

    timer_cordura->start(1000);
    timer_spawn->start(3600);


    //-----------------------------------------------------------------------------

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goBack(){
    parentWidget()->show();
    hide();
}
//void MainWindow::Crear_fondo(QString path)
//{
//    Fondo = new QPixmap(path);
//}

void MainWindow::Mostrar_Terreno()
{
    scene->setSceneRect(0,0,4800,4160);
    //scene->addPixmap(*Fondo);
    scene->addItem(personaje);
}

void MainWindow::actualizar_vista()
{
    view->centerOn(personaje->pos());
}
void MainWindow::Cargar_Arboles(string path1, string path2)
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

void MainWindow::Cargar_Obstaculos(string path1,string path2)
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


void MainWindow::EvaluarColision()
{
    QList<Obstaculos*>::Iterator it;

    for(it = lista_obstaculos.begin();it!=lista_obstaculos.end();++it){

        if((*it)->collidesWithItem(personaje)){
            personaje->setColisionObstaculos(true);


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


void MainWindow::aparecerEnemigos()
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
    lista_enemigos.push_back(new Enemigos("Sprites.csv",45,45,100,e_posx,e_posy,personaje));
//    if(e_posx > Fondo->width())e_posx = Fondo->width()-lista_enemigos.back()->pixmap->width()/2;
//    else if(e_posx < 0)e_posx = lista_enemigos.back()->pixmap->width()/2;
//    if(e_posy > Fondo->height())e_posy = Fondo->height()-lista_enemigos.back()->pixmap->height()/2;
//    else if(e_posy<0)e_posy = lista_enemigos.back()->pixmap->height()/2;
    qreal x = e_posx;
    qreal y = e_posy;
    lista_enemigos.back()->setPos(x,y);

    scene->addItem(lista_enemigos.back());
}

void MainWindow::disminuir_cordura()
//Modificar la cordura del personaje cada 1 minuto
//Aumenta la probabilidad de que aparezca un enemigo
{
    int cordura = personaje->getCordura();
    if(cordura > 0){
        personaje->setCordura(cordura-1);
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int speed = 10; // velocidad de movimiento del personaje

    if (event->key() == Qt::Key_A){
        personaje->mover(-speed, 0);
        if(personaje->colisionObstaculos==false){
            personaje->mover(-speed, 0);
            personaje->estado=3;
            personaje->sprite();
            personaje->orientacion=0;
        }else{
            personaje->mover(speed, 0);
            personaje->estado=2;
            personaje->sprite();
            personaje->orientacion=1;
        }


    }

    else if (event->key() == Qt::Key_D){
        personaje->mover(speed, 0);
        if(personaje->colisionObstaculos==false){
            personaje->mover(speed, 0);
            personaje->estado=2;
            personaje->sprite();
            personaje->orientacion=1;
        }else{
            personaje->mover(-speed, 0);
            personaje->estado=3;
            personaje->sprite();
            personaje->orientacion=0;
        }


    }
    else if (event->key() == Qt::Key_W){
        personaje->mover(0, -speed);
        if(personaje->colisionObstaculos==false){
            personaje->mover(0, -speed);
        }else{
            personaje->mover(0, speed);
        }
    }
    else if (event->key() == Qt::Key_S){
        personaje->mover(0, speed);
        if(personaje->colisionObstaculos==false){
            personaje->mover(0, speed);
        }else{
            personaje->mover(0, -speed);
        }
    }

    else if (event->key() == Qt::Key_Q){
        personaje->mover(-speed, speed);
        if(personaje->colisionObstaculos==false){
            personaje->mover(0, speed);
        }else{
            personaje->mover(0, -speed);
        }
    }




}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A || event->key() == Qt::Key_D ||
        event->key() == Qt::Key_W || event->key() == Qt::Key_S)
    {
        personaje->estado = 1;
        personaje->sprite();
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {

        QPointF scenePos = view->mapToScene(event->pos());

        // Obtener coordenadas x,y
        qreal xx = scenePos.x();
        qreal yy = scenePos.y();

        lista_proyectiles.push_back(new Proyectil(personaje->x(),personaje->y(),xx,yy));

        lista_proyectiles.back()->setPos(personaje->x(),personaje->y());
        scene->addItem(lista_proyectiles.back());



//        for (auto it = lista_proyectiles.begin(); it != lista_proyectiles.end();) { // notar que no incrementamos it
//            bool colision = false;
//            for (auto it2 = lista_enemigos.begin(); it2 != lista_enemigos.end(); ++it2) {
//                if ((*it)->collidesWithItem(*it2)) {
//                    colision = true;
//                    (*it2)->setVida((*it2)->getVida() - 10);
//                    if ((*it2)->getVida() <= 0) {
//                        lista_enemigos.erase(it2); // eliminar enemigo de la lista
//                        scene->removeItem(*it2);
//                    }
//                    break;
//                }
//            }
//            if (colision) {
//                it = lista_proyectiles.erase(it); // eliminar proyectil de la lista y actualizar iterador
//            } else {
//                ++it; // avanzar iterador
//            }
        }
    for (auto it = lista_proyectiles.begin(); it != lista_proyectiles.end();) { // notar que no incrementamos it
        bool colision = false;
        for (auto it2 = lista_enemigos.begin(); it2 != lista_enemigos.end(); ++it2) {
            if ((*it)->collidesWithItem(*it2,Qt::IntersectsItemBoundingRect)) {
                colision = true;
                (*it2)->setVida((*it2)->getVida() - 20);
                if ((*it2)->getVida() <=0) {
                    scene->removeItem(*it2);
                    it2 = lista_enemigos.erase(it2);
                   // eliminar enemigo de la lista y actualizar iterador
                    break; // salir del bucle si se eliminó al enemigo
                }
                break;
            }
        }
        if (colision) {
            scene->removeItem(*it);
            it = lista_proyectiles.erase(it);

        } else {
            ++it;
        }
    }
}
