#include "protagonista.h"
#include <string>
#include <QTimer>
#include <QGraphicsScene>
//Verificar escritura correcta de los métodos de una clase heredada
Protagonista::Protagonista(string _path,int Ancho, int Alto,int _vida,int _cordura, int _x, int _y):Personaje(_path, Ancho, Alto,_vida)
{
    //pixmap = new QPixmap(":/Pj.png");

    cordura = _cordura;
    this->posX = _x;
    this->posY = _y;
    vida_actual=_vida;
    vida_maxm=_vida;
    barraCorduraItem=new QGraphicsRectItem();

}

Protagonista::~Protagonista()
{
    delete pixmap;
}




void Protagonista::mover(int x, int y)
{

    setPos(posX+x, posY+y);
    posX += x;
    posY += y;

    emit posicionCambiada();
}


int Protagonista::getCordura() const
{
    return cordura;
}

void Protagonista::setCordura(int newCordura)
{
    cordura = newCordura;
}



void Protagonista::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Dibuja el sprite del personaje
    painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,0,ancho,alto);
}

void Protagonista::BarraCordura(QGraphicsScene *scene) {
    // Crea un objeto QGraphicsRectItem para la barra de vida
    // Configura la posición y dimensiones de la barra de vida
    barraCorduraItem->setRect(-cordura/4, 0, cordura, 5); // Ajusta el ancho del rectángulo

    // Configura el color de la barra de vida
    QBrush brush(Qt::blue);
    barraCorduraItem->setBrush(brush);

    // Establece la propiedad zValue a un valor alto para que la barra de vida se dibuje por encima del personaje
    barraCorduraItem->setZValue(10);
    barraCorduraItem->setEnabled(false);

    // Agrega la barra de vida a la escena
    scene->addItem(barraCorduraItem);
}

void Protagonista::actualizarPosicionBarraCordura() {
    // Actualiza la posición de la barra de vida en función de la posición actual del personaje
    barraCorduraItem->setPos(posX - cordura/4, posY -37);
}


void Protagonista::actualizarBarraCordura() {
    // Calcula el ancho de la barra de vida en función de la vida actual

// Actualiza el rectángulo de la barra de vida con el nuevo ancho
    barraCorduraItem->setRect(-cordura/4, 0, cordura, 5);
    update();
}
void Protagonista::tomar_pocion(int tipo)
{
    if(tipo==0) actualizarBarraVida(-20);
    else cordura+=20;
}
