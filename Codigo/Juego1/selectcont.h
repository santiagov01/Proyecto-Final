#ifndef SELECTCONT_H
#define SELECTCONT_H


#include <QMainWindow>
#include "mainwindow.h"
#include "cinematica.h"
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




private:
    Ui::SelectCont *ui;
    MainWindow *Mapa;
    QPushButton *Boton_Filnar, *Boton_Abadtrah, *Boton_Senifini,*Boton_Bragelante, *Boton_Rikcelare, *Boton_Montino;
    
    QWidget *Pantalla_Inicio;
    Cinematica* filnar;
private slots:
    void goBack();
    //void openMapa();



};

#endif // SELECTCONT_H
