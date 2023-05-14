#ifndef TERRENO_H
#define TERRENO_H

#include <QPixmap>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include "personaje.h"
#include <QObject>

#include "obstaculos.h"
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
    bool EvaluarColision();
    bool EvaluarColision2();

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPixmap *Fondo,porcion;
    Personaje *personaje;

    QList<Obstaculos*> paredes;
    QList<Obstaculos*> recompensas;

};

#endif // TERRENO_H
