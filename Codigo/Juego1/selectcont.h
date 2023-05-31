#ifndef SELECTCONT_H
#define SELECTCONT_H

#include <QPushButton>
#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class SelectCont;
}

class SelectCont : public QMainWindow
{
    Q_OBJECT

public:
    SelectCont(QWidget *parent = nullptr);
    ~SelectCont();

private:
    Ui::SelectCont *ui;
    MainWindow *Mapa;
private slots:
    void goBack();
    void openMapa();

};

#endif // SELECTCONT_H
