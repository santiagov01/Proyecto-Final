
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include "iniciar.h"
#include <QKeyEvent>
#include "personaje.h"
#include "mision.h"



namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();





private:
    Ui::MainWindow *ui;
    Iniciar *Continentes;
    Mision *prueba;
public slots:
    void goBack();


};

#endif // MAINWINDOW_H
