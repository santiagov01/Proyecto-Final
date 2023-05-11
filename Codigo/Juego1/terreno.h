#ifndef TERRENO_H
#define TERRENO_H

#include <QPixmap>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include "personaje.h"
#include <QObject>
#include "camara.h"
class Terreno : public QObject
{
    Q_OBJECT
public:
    Terreno(QGraphicsView *view);
    ~Terreno();
    void Crear_fondo(QString path);
    void Mostrar_Terreno();
    void actualizar_vista();
    QGraphicsView *getView() const;
    QGraphicsScene *getScene() const;

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPixmap *Fondo,porcion;
    Personaje *personaje;

};

#endif // TERRENO_H
