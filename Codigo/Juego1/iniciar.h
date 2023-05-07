
#ifndef INICIAR_H
#define INICIAR_H

#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>


class Iniciar : public QObject
{
    Q_OBJECT
public:
    Iniciar(QMainWindow *mainwindow);
    void Crear_Cinematica(QString Path);
    void Reproducir();
    QWidget *getPantalla_Inicio() const;
    QPushButton *getBoton_Filnar() const;
    ~Iniciar();

private:
    int Continente;
    QWidget *Pantalla_Inicio,*Selector;
    QPixmap *Eilaar_static, *Filnar_mision;
    QPushButton *Boton_Filnar, *Boton_Abadtrah, *Boton_Senifini,*Boton_Bragelante, *Boton_Rikcelare, *Boton_Montino;
    QPushButton *Tehamu, *Janukra;
    QMediaPlayer *player;
    QVideoWidget  *Cinematica;
    QMainWindow* mainwindow;
private slots:
    void Verificar_Estado();


};

#endif // INICIAR_H
