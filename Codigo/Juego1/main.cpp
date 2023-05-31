
#include "mainwindow.h"
#include "menu.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    Menu w;
    w.show();
    return a.exec();
}
