#include "enemigos.h"

Enemigos::Enemigos(QString path, int _posx, int _posy)

{
    posX = _posx;
    posY = _posy;
    pixmap = new QPixmap(path);
}

Enemigos::~Enemigos()
{

}
