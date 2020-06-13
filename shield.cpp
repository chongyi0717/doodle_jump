#include "shield.h"

Shield::Shield(qreal a,qreal b):PlatForm ()
{
    setPixmap(QPixmap(":/image/shield.png"));
    setPos(a,b);
    setScale(0.05);
}

void Shield::action()
{
    setPos(x(),y()-5);
}
