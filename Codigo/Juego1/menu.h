#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();
    MainWindow *windowB;
    //TestElementos* ventana3;

private:
    Ui::Menu *ui;
private slots:
    void openWindowB();
};

#endif // MENU_H
