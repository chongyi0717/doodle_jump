#include "hazard.h"

Hazard::Hazard(qreal a,qreal b):PlatForm ()
{
    setPixmap(QPixmap(":/image/Hazard.png"));
    setScale(1.5);
    setPos(a,b);
}

void Hazard::action()
{
    setPos(x(),y()-5);
}
