#ifndef SELECTCONT_H
#define SELECTCONT_H


#include <QMainWindow>
#include "mainwindow.h"

#include <QVideoWidget>
#include <QMediaPlayer>
#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QLabel>
namespace Ui {
class SelectCont;
}

class SelectCont : public QMainWindow
{
    Q_OBJECT

public:
    SelectCont(QWidget *parent = nullptr);
    ~SelectCont();
    void pantalla_continentes();
    void reiniciar_pantalla();
    void Crear_Cinematica(QString Path);
    void Reproducir();



private:
    Ui::SelectCont *ui;
    MainWindow *Mapa;

    int Continente;
    QWidget *Pantalla_Inicio,*Selector;
    QPixmap *Eilaar_static, *Filnar_mision;
    QPushButton *Boton_Filnar, *Boton_Abadtrah, *Boton_Senifini,*Boton_Bragelante, *Boton_Rikcelare, *Boton_Montino;
    QPushButton *Tehamu, *Janukra;
    QPushButton *Boton_Atras;
    QMediaPlayer *player;
    QVideoWidget  *Cinematica;
private slots:
    void goBack();
    void openMapa();

    void Verificar_Estado();

};

#endif // SELECTCONT_H
