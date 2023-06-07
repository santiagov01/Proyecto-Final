#ifndef CINEMATICA_H
#define CINEMATICA_H

#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QLabel>

#include "mainwindow.h"

namespace Ui {
class Cinematica;
}

class Cinematica : public QMainWindow
{
    Q_OBJECT

public:
    Cinematica(QWidget *parent = nullptr, QString _path = "qrc:/Videos/Filnar.mp4", int _Continente =1);
    ~Cinematica();
    void Crear_Cinematica(QString Path);
    void Reproducir();

private:
    Ui::Cinematica *ui;
    int Continente;
    QWidget *Selector;
    QPixmap *Eilaar_static, *Filnar_mision;
    MainWindow* Mapa;
    QPushButton *Tehamu, *Janukra;
    QPushButton *Boton_Atras;
    QMediaPlayer *player;
    QVideoWidget  *Animacion;
    QString path;
private slots:
    void goBackMneu();
    void openMapa();

    void Verificar_Estado();
};

#endif // CINEMATICA_H
