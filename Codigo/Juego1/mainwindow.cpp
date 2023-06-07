
#include "mainwindow.h"

#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent, int _mision)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //Continentes=new Iniciar(this);
    mision= _mision;
    juego_iniciado = false;
    mision_completada =  false;
    //--------Conexión para regresar a la anterior ventana--------------------
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::goBack);
    timer->start(150000);
    //prueba=new Mision(1,this);

    //---------------------------------------------------------
    view = ui->graphicsView;
    scene = new QGraphicsScene();

    view->setScene(scene);
    view->scale(1.5,1.5);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    srand(time(NULL));
    //Crear_fondo(":/FilnarMapa1.png");
    //---------------------------------------------------------------------
    //PASAR COMO PARAMETRO EL MAPA Y LOS CSV
    scene->setBackgroundBrush(QBrush(QImage(":/FilnarMapa1.png")));
    //Cargar_Arboles("ArbolesPrueba2.csv","PathArboles.csv");
    Cargar_Arboles(":/ArbolesBosque.csv",":/PathArboles.csv");
    Cargar_Obstaculos(":/Obstaculos.csv",":/PathObstaculos.csv");
    Cargar_datos_enemigo(":/tipo_Enemigos.csv", &datos_tipo_enemigos);
    Cargar_paredes(":/Paredes.csv");


    setCentralWidget(view);
    view->setRenderHint(QPainter::Antialiasing);
    scene->clearFocus();

    personaje = new Protagonista(":/Sprites.csv",45,40,200,100,800,800);
    personaje->setZValue(0);
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    personaje->BarraVida(scene);
    personaje->BarraCordura(scene);


    personaje->setPos(800,800);
    Mostrar_Terreno();

    view->centerOn(personaje->pos());
    //-----------------------------------
    misionCompletedIcon = new Obstaculos(":/Obstaculos/7.png",44,64);
    misionCompletedIcon->setPos(680,480);
    scene->addItem(misionCompletedIcon);
    misionCompletedIcon->setZValue(6);
    //----------------------OLEADAS-------------------------------------------------------
    OleadasConstruct();
    //----------LABERINTO--------------
    LaberintoConstruct();

    //--------------------------------------------------------------------------------
    connect(personaje, &Protagonista::posicionCambiada, this, &MainWindow::actualizar_vista);
    connect(personaje, &Protagonista::posicionCambiada, this, &MainWindow::EvaluarColision);

    timer_spawn = new QTimer();
    timer_cordura = new QTimer();
    timer_impacto_proyectil= new QTimer();
    timer_impacto_personaje=new QTimer();
    timer_recoger_recompensa=new QTimer();

    connect(timer_spawn, SIGNAL(timeout()),this, SLOT(aparecerEnemigos()));
    connect(timer_cordura, SIGNAL(timeout()),this, SLOT(disminuir_cordura()));
    connect(timer_impacto_proyectil, SIGNAL(timeout()),this, SLOT(impacto_proyectil()));
    connect(timer_impacto_personaje,SIGNAL(timeout()),this,SLOT(impacto_personaje()));
    connect(timer_recoger_recompensa, SIGNAL(timeout()),this,SLOT(recoger_botin()));

//    timer_cordura->start(1000);
//    timer_spawn->start(1500);

//    timer_impacto_proyectil->start(1);
//    timer_impacto_personaje->start(1000);
    causa_aparicion = "cordura";

    tipo_enemigo = 1;
    tipo_proyectil =1;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::OleadasConstruct(){


    tiempo_oleada = new QTimer(); //se inicializa al emepezar la oleada.
    temp = 30;

    inicia_oleada1 = false;
    inicia_oleada2 = false;
    inicia_oleada3 = false;
    iniciar_mision= false;

//    activa_misionoleadas = new QGraphicsRectItem(-30,10,60,20);
//    activa_misionoleadas->setBrush(Qt::green);
    activa_misionoleadas = new Obstaculos(":/Obstaculos/7.png",44,64);
    activa_misionoleadas->setPos(640,2480);
    activa_misionoleadas->setZValue(6);
    scene->addItem(activa_misionoleadas);

//    activador_oleada1 = new QGraphicsRectItem(-30,10,60,20);
//    activador_oleada1->setBrush(Qt::green);
    activador_oleada1 = new Obstaculos(":/Obstaculos/7.png",44,64);
    scene->addItem(activador_oleada1);
    activador_oleada1->setPos(1800,3000);
    activador_oleada1->setZValue(6);


//    activador_oleada2 = new QGraphicsRectItem(-30,10,60,20);
//    activador_oleada2->setBrush(Qt::green);
    activador_oleada2 = new Obstaculos(":/Obstaculos/7.png",44,64);
    scene->addItem(activador_oleada2);
    activador_oleada2->setPos(180,4060);
    activador_oleada2->setZValue(6);

//    activador_oleada3 = new QGraphicsRectItem(-30,10,60,20);
//    activador_oleada3->setBrush(Qt::green);
    activador_oleada3 = new Obstaculos(":/Obstaculos/7.png",44,64);
    scene->addItem(activador_oleada3);
    activador_oleada3->setPos(1700,3920);
    activador_oleada3->setZValue(6);

    puerta_1 = new Obstaculos(":/Obstaculos/7.png",44,64);
    lista_obstaculos.push_back(puerta_1);
    //puerta_1->setBrush(Qt::green);

    puerta_2 = new Obstaculos(":/Obstaculos/7.png",44,64);
    //puerta_2->setBrush(Qt::green);
    puerta_3 = new Obstaculos(":/Obstaculos/7.png",44,64);

    connect(tiempo_oleada, SIGNAL(timeout()),this, SLOT(iniciarOleada()));


}

void MainWindow::LaberintoConstruct()
{
    tiempo_laberinto = new QTimer();
    laberinto_completado = false;
    iniciar_laberinto = false;
    activa_lab = new Obstaculos(":/Obstaculos/7.png",44,64);
    scene->addItem(activa_lab);
    activa_lab->setPos(2940,620);
    activa_lab->setZValue(6);

    puerta_entrada = new Obstaculos(":/Obstaculos/7.png",44,64);
    puerta_salida = new Obstaculos(":/Obstaculos/7.png",44,64);
    scene->addItem(puerta_salida);
    puerta_salida->setPos(4100,1040);
    puerta_salida->setZValue(6);


    //activa_lab = new Obstaculos(":/Obstaculos/7.png",44,64);

    termina_lab = new Obstaculos(":/Obstaculos/7.png",44,64);
    aparecerEnemigos_Laberinto(3480,100,3480,280,2);
    aparecerEnemigos_Laberinto(3760,860,3980,860,1);
    connect(tiempo_laberinto, SIGNAL(timeout()),this, SLOT(iniciarLaberinto()));


    //-----------AUDIO--------
    player_audio = new QMediaPlayer(this);
    audio = new QAudioOutput();
    player_audio->setSource(QUrl::fromLocalFile("qrc:/soundtrack.mp3"));
    audio->setVolume(0.5);
    player_audio->setAudioOutput(audio);

    player_audio->play();
}

void MainWindow::setMision(int newMision)
{
    mision = newMision;
}
void MainWindow::goBack(){
    parentWidget()->show();
    close();
}
//void MainWindow::Crear_fondo(QString path)
//{
//    Fondo = new QPixmap(path);
//}

void MainWindow::Mostrar_Terreno()
{
    scene->setSceneRect(0,0,4803,4163);
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
        lista_obstaculos.push_back(new Obstaculos(datos[0], datos[1], datos[2],Imagenes_arbol[datos[0]]));
        lista_obstaculos.back()->setZValue(datos[3]);
        scene->addItem(lista_obstaculos.back());
    }

}

void MainWindow::Cargar_Obstaculos(string path1,string path2)
{
    Cargar_datos(path1, &obstaculos);
    Cargar_imagen(path2,&Imagenes_obstaculo);
    for (vector<int> datos : obstaculos) {
        lista_obstaculos.push_back(new Obstaculos(Imagenes_obstaculo[datos[0]], datos[1], datos[2]));
        lista_obstaculos.back()->setZValue(datos[3]);
        scene->addItem( lista_obstaculos.back());
    }

}
void MainWindow::Cargar_paredes(string path1)
{

    Leer_paredes(path1,&paredes);
    for(vector<int>datos:paredes){

        lista_obstaculos.push_back(new Obstaculos(datos[0],datos[1],datos[2],datos[3]));
        scene->addItem(lista_obstaculos.back());
    }
}
void MainWindow::EvaluarColision()
{
    //QList<Obstaculos*>::Iterator it;

//    for(it = lista_obstaculos.begin();it!=lista_obstaculos.end();++it){
//        if((*it)->collidesWithItem(personaje)){
//            personaje->setColisionObstaculos(true);
//            return;
//        }
//    }
//     personaje->setColisionObstaculos(false);

     //---------------OLEADAS----------------------------------

     if(activa_misionoleadas->collidesWithItem(personaje) && !iniciar_mision &&mision==1){
         iniciar_mision = true;
         timer_spawn->stop();
         QMessageBox::about(this,"Aviso", "Busca la sangre del cadaver, allí empezarás tu oleada. Revisa que aparezcan enemigos");
     }
     if(activador_oleada1->collidesWithItem(personaje) && !inicia_oleada1 && iniciar_mision){
        inicia_oleada1 = true;
        puerta_1->setPos(1640,2740);
        scene->addItem(puerta_1);
        lista_obstaculos.push_back(puerta_1);
         //disconnect(timer_spawn, SIGNAL(timeout()),this, SLOT(aparecerEnemigos()));
          //no aparecen el tipo de enemigos de antes :D

        causa_aparicion = "oleada";
        tiempo_oleada->start(1000);
        timer_spawn->start(1000);

        oleada_actual = 1;
        tipo_enemigo = 1;
     }
     if(activador_oleada2->collidesWithItem(personaje) && !inicia_oleada2 && iniciar_mision && inicia_oleada1){
        inicia_oleada2 = true;
        puerta_1->setPos(440,3740);
        puerta_1->show();
        tiempo_oleada->start(1000);
        timer_spawn->start(1000);
        causa_aparicion = "oleada";
        oleada_actual = 2;
        tipo_enemigo = 2;
     }
     if(activador_oleada3->collidesWithItem(personaje) && inicia_oleada2 && iniciar_mision && !inicia_oleada3){
        inicia_oleada3 = true;
        puerta_1->setPos(940,3720);
        puerta_1->show();
        tiempo_oleada->start(1000);
        timer_spawn->start(1000);
        causa_aparicion = "oleada";
        oleada_actual = 3;
        tipo_enemigo = 3;
     }

     //----------------LABERINTO--------------------

    if(activa_lab->collidesWithItem(personaje) && mision == 2 && !iniciar_laberinto){
        iniciar_laberinto = true;
        //timer_spawn->stop();
        tiempo_laberinto->start(1000);
        scene->addItem(puerta_entrada);
        lista_obstaculos.push_back(puerta_entrada);
        puerta_entrada->setPos(2960,680);
        puerta_entrada->setZValue(6);
        QMessageBox::about(this,"Aviso", "¿eres capaz de superar el laberinto?");

    }
    if(puerta_salida->collidesWithItem(personaje) && iniciar_laberinto){
        laberinto_completado = true;
    }
    if(mision_completada || laberinto_completado){
        if(misionCompletedIcon->collidesWithItem(personaje)){
            QMessageBox::about(this,"Aviso", "Recuperaste tu alma");
            goBack();
        }
    }
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
    if(causa_aparicion == "cordura"){//se elige hacer comparación con string para mayor legibilidad
        int porcentaje = 100 - personaje->getCordura();
        int dado = rand()%(101);
        if(!(dado < porcentaje) || lista_enemigos.size() > 10){
            std::cout << "No aparece enemigo" << std::endl;
            return;
        }
    }
    //numeros random para poner a la izquierda o derecha
    int dir_posx = rand()%2;
    int dir_posy = rand()%2;

    //posicion aleatoria cerca al enemigo (depende de limites)
    int e_posx = rand()%(limite_superior+1 - limite_inferior) + limite_inferior;
    int e_posy = rand()%(limite_superior+1 - limite_inferior) +  limite_inferior;
    if(dir_posx==0)e_posx= -e_posx + personaje->x();//posicion x enemigo a la izquierda
    else e_posx = e_posx + personaje->x();
    if(dir_posy==0)e_posy = -e_posy + personaje->y();//posicion y enemigo a la derecha
    else e_posy+= personaje->y();

    //---------Extraer parametros-----------------
    string path_e = datos_tipo_enemigos[tipo_enemigo][0].toStdString();
    int w = (datos_tipo_enemigos[tipo_enemigo][1]).toInt();
    int h = (datos_tipo_enemigos[tipo_enemigo][2]).toInt();
    int vida_max = (datos_tipo_enemigos[tipo_enemigo][3]).toInt();
    int damage = (datos_tipo_enemigos[tipo_enemigo][4]).toInt();
    //------------añadir a lista----------
    lista_enemigos.push_back(new Enemigos(path_e,w,h,vida_max,e_posx,e_posy,personaje,tipo_enemigo,damage));
    //lista_enemigos.back()->proyectil_circular(scene);

    switch (tipo_enemigo) {
    case 1:
        std::cout << "ENEMIGO SEGUIDOR" << std::endl;
        break;

    case 2:
        std::cout << "ENEMIGO 2" << std::endl;
        break;

    case 3:
        std::cout << "ENEMIGO 3" << std::endl;
        break;
    default:
        break;
    }
    //    if(e_posx > Fondo->width())e_posx = Fondo->width()-lista_enemigos.back()->pixmap->width()/2;
//    else if(e_posx < 0)e_posx = lista_enemigos.back()->pixmap->width()/2;
//    if(e_posy > Fondo->height())e_posy = Fondo->height()-lista_enemigos.back()->pixmap->height()/2;
//    else if(e_posy<0)e_posy = lista_enemigos.back()->pixmap->height()/2;
    //-------añadir a escena--------
    qreal x = e_posx;
    qreal y = e_posy;
    lista_enemigos.back()->setPos(x,y);

    scene->addItem(lista_enemigos.back());
}

void MainWindow::impacto_proyectil()
{

    if(lista_proyectiles.size()!=0){
        for (auto it = lista_proyectiles.begin(); it != lista_proyectiles.end();) { // notar que no incrementamos it
            bool colision = false;
            for (auto it2 = lista_enemigos.begin(); it2 != lista_enemigos.end(); ++it2) {
                if ((*it)->collidesWithItem(*it2,Qt::IntersectsItemBoundingRect)) {
                    colision = true;
                    (*it2)->setVida((*it2)->getVida() - 20);
                    if ((*it2)->getVida() <=0) {
                        int aparicion = rand() % 101;
                        if (aparicion >= 95) {
                            Recompensa=new Botin((*it2)->x(),(*it2)->y());
                            lista_botin.push_back(Recompensa);
                            scene->addItem(Recompensa);
                        }
                        scene->removeItem(*it2);
                        it2 = lista_enemigos.erase(it2);
                        // eliminar enemigo de la lista y actualizar iterador
                        break; // salir del bucle si se eliminó al enemigo
                    }
                    else it2++;
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
//    if(lista_proyectiles.size()!=0){
//        for (auto it = lista_proyectiles.begin(); it != lista_proyectiles.end();++it){
//            if((*it)->getDistancia_recorrida()>=60){
//                scene->removeItem(*it);
//                //it = lista_proyectiles.erase(it);
//                //++it
//                //it =
//            }
//        }
//    }

}
void MainWindow::recoger_botin()
{

    if(lista_botin.size()!=0){

        for(auto it=lista_botin.begin();it!=lista_botin.end();){
            if((*it)->collidesWithItem(personaje)){
                    qDebug("colision");
                    personaje->tomar_pocion((*it)->getTipo());
                    scene->removeItem(*it);
                    it=lista_botin.erase(it);

                    }
            else it++;

                }
        }
}
void MainWindow::impacto_personaje(){

    if(lista_enemigos.size()!=0){
        for(auto it=lista_enemigos.begin();it !=lista_enemigos.end();){
            if((*it)->collidesWithItem(personaje,Qt::IntersectsItemBoundingRect)){
                personaje->actualizarBarraVida((*it)->getDaño());
                    it++;
            }
            else it++;


        };
    }
}

void MainWindow::disminuir_cordura()
//Modificar la cordura del personaje cada 1 minuto
//Aumenta la probabilidad de que aparezca un enemigo
{
    int cordura = personaje->getCordura();
    if(cordura > 0){        
        personaje->setCordura(cordura-1);
    }
    personaje->actualizarBarraCordura();
    if(personaje->vida_actual<=0){
        QMessageBox::about(this,"DEEEAD", "¿Realmente moriste?");
        personaje->vida_actual = 100;

    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    //inicializar timers....
    if(!juego_iniciado){
        timer_cordura->start(1000);
        timer_spawn->start(1500);

        timer_impacto_proyectil->start(1);
        timer_impacto_personaje->start(1000);
        timer_recoger_recompensa->start(1);
        juego_iniciado = true;
        QMessageBox::about(this,"Aviso", "Debes buscar el lugar donde inicia tu mision, cuida tu c0rDUR4");
    }

    //---------
    int speed = 20; // velocidad de movimiento del personaje
    personaje->actualizarPosicionBarraCordura();
    personaje->actualizarPosicionBarraVida();

    if (event->key() == Qt::Key_A){
        personaje->mover(-speed,0);
        personaje->estado=3;
        personaje->sprite();
        for(auto it=lista_obstaculos.begin();it!=lista_obstaculos.end();it++){
            if(personaje->collidesWithItem((*it)->getRectCol())){
                personaje->mover(speed, 0);
            }
        }
    }

    else if (event->key() == Qt::Key_D){
        personaje->mover(speed, 0);
        personaje->estado=2;
        personaje->sprite();
        for(auto it=lista_obstaculos.begin();it!=lista_obstaculos.end();it++){
            if(personaje->collidesWithItem((*it)->getRectCol()))
                    personaje->mover(-speed, 0);
            qDebug("hola");
        }
    }
    else if (event->key() == Qt::Key_W){
        personaje->mover(0, -speed);
        for(auto it=lista_obstaculos.begin();it!=lista_obstaculos.end();it++){
            if(personaje->collidesWithItem((*it)->getRectCol())) {
                    personaje->mover(0, speed);
            }
        }
    }


    else if (event->key() == Qt::Key_S){
        personaje->mover(0, speed);
        for(auto it=lista_obstaculos.begin();it!=lista_obstaculos.end();it++){
            if(personaje->collidesWithItem((*it)->getRectCol())){
                personaje->mover(0, -speed);

            }
        }
    }
    if(event->key() == Qt ::Key_P){
        Pause ventanapausa(this);
        ventanapausa.setModal(true);
        ventanapausa.exec();

    }
    if(event->key() == Qt ::Key_Shift){
        if(tipo_proyectil == 1){
            tipo_proyectil =2;
        }else if(tipo_proyectil ==2){
            tipo_proyectil =3;
        }else if(tipo_proyectil ==3){
            tipo_proyectil =1;
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
//        switch (tipo_proyectil) {
//        case 1:

//            break;
//        default:
//            break;
//        }
        //lista_proyectiles.push_back(new Proyectil(personaje->x(),personaje->y(),xx,yy));
        lista_proyectiles.push_back(new Proyectil(personaje->x(),personaje->y(),xx,yy,tipo_proyectil));

        lista_proyectiles.back()->setPos(personaje->x(),personaje->y());
        scene->addItem(lista_proyectiles.back());

    }
}

void MainWindow::aparecerEnemigos_Laberinto(double X, double Y, double xlim, double ylim, int direct)
    //direct => dirección horizontal o vertical. 1 para horizontal, 2 para vertical
{
    //tipo de enemigo será fijo => (4)

    string path_e = datos_tipo_enemigos[4][0].toStdString();
    int w = (datos_tipo_enemigos[4][1]).toInt();
    int h = (datos_tipo_enemigos[4][2]).toInt();
    int vida_max = (datos_tipo_enemigos[4][3]).toInt();
    int damage = (datos_tipo_enemigos[4][4]).toInt();
    lista_enemigos.push_back(new Enemigos(path_e,w,h,vida_max,X,Y,personaje,4,damage));
    lista_enemigos.back()->setXlim(xlim);//cambio los limites
    lista_enemigos.back()->setYlim(ylim);
    lista_enemigos.back()->setOrientacion(direct);//dice si va horizontal o vertical

    lista_enemigos.back()->setPos(X,Y);
    scene->addItem(lista_enemigos.back());
}

//---------------OLEADAS--------------------------
void MainWindow::iniciarOleada()
{
    //variar los enemigos
    temp--;
    if(temp == 0 ){
        if(oleada_actual == 1){
            QMessageBox::about(this,"Muerte", "Muy bien, busca el otro rastro del cadaver");
        }else if(oleada_actual == 2){
            QMessageBox::about(this,"Orgullo", "Te falta la ultima oleada, dirigite a la otra anomalía de sangre");
        }
        tiempo_oleada->stop();
        puerta_1->hide();
        //aumentar cosas nuestro pj.
        std::cout << " Se acabo el tiempo " << std::endl;
        timer_spawn->stop();
        temp = 30;
        if(oleada_actual == 3){
             //aumentar cosas nuestro pj.
            mision_completada = true;
            QMessageBox::about(this,"Aviso", "Has completado completado las oleadas");
        }
    }
}

void MainWindow::iniciarLaberinto()
{
    if(laberinto_completado){
        //aumentar cosas al pj
        QMessageBox::about(this,"Aviso", "Has completado el laberinto, felicidades");
        tiempo_laberinto->stop();

    }
}
