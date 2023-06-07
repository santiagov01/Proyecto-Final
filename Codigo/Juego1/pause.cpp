#include "pause.h"
#include "ui_pause.h"

Pause::Pause(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pause)
{
    ui->setupUi(this);
}

Pause::~Pause()
{
    delete ui;
}

void Pause::on_pushButton_clicked()
{
    //salir
    qApp->quit();
}


void Pause::on_pushButton_2_clicked()
{
    //continuar

    close();

}

