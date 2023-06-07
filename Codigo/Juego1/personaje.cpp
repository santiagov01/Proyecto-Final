#include "personaje.h"

Personaje::Personaje(string _path,int Ancho, int Alto,int _vida)
{

    posX = 800;
    posY = 800;

    vida_maxm = _vida;
    vida_actual=_vida;
    barraVidaItem = new QGraphicsRectItem();

    columnas=0;
    estado=1;
    orientacion=0;


    path = _path;
    Cargar_imagen(path,&Imagenes_personaje);
    //path = "Sprites.csv"
    pixmap=new QPixmap();
    sprite();

    ancho=Ancho;
    alto=Alto;

    AnimacionTimer=new QTimer();
    AnimacionTimer->start(140);
    connect(AnimacionTimer,&QTimer::timeout,this,&Personaje::actualizar_sprite);

    vida = ((float)vida_actual / (float)vida_maxm) * 100.0;
}

Personaje::~Personaje()
{
    delete pixmap;
}

void Personaje::sprite()
{
    pixmap->load(QString::fromStdString(Imagenes_personaje[estado]));

}
void Personaje::actualizar_sprite(){
    columnas+=ancho;
    if (columnas>=pixmap->size().width()) columnas=0;
    this->update(-ancho/2,-alto/2,ancho,alto);
}


QRectF Personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}



void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(-ancho/2,-alto/2, *pixmap,columnas,0,ancho,alto);


}

void Personaje::setVida_actual(int newVida_actual)
{
    vida_actual = newVida_actual;
}

void Personaje::setColisionObstaculos(bool newColisionObstaculos)
{
    colisionObstaculos = newColisionObstaculos;
}

void Personaje::BarraVida(QGraphicsScene *scene) {
    // Crea un objeto QGraphicsRectItem para la barra de vida

    // Configura la posición y dimensiones de la barra de vida
    barraVidaItem->setRect(-vida/4, 0, vida, 5); // Ajusta el ancho del rectángulo

    // Configura el color de la barra de vida
    QBrush brush(Qt::red);
    barraVidaItem->setBrush(brush);

    // Establece la propiedad zValue a un valor alto para que la barra de vida se dibuje por encima del personaje
    barraVidaItem->setZValue(10);
    barraVidaItem->setEnabled(false);

    // Agrega la barra de vida a la escena
    scene->addItem(barraVidaItem);
}

void Personaje::actualizarPosicionBarraVida() {
    // Actualiza la posición de la barra de vida en función de la posición actual del personaje
    barraVidaItem->setPos(posX - vida/4, posY - 45);
}


void Personaje::actualizarBarraVida(int daño) {
    // Calcula el ancho de la barra de vida en función de la vida actual
    vida_actual=vida_actual-daño;
    vida = ((float)vida_actual / (float)vida_maxm) * 100.0;

    // Actualiza el rectángulo de la barra de vida con el nuevo ancho
    barraVidaItem->setRect(-vida/4, 0, vida, 5);
    update();
}

