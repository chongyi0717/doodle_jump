#include "platformbroken.h"
#include <QGraphicsScene>
PlatFormBroken::PlatFormBroken(qreal a,qreal b):PlatForm ()
{
    setPixmap(QPixmap(":/image/platform_broken.png"));
    setPos(a,b);
    setScale(0.75);
}

void PlatFormBroken::action()
{
    scene()->removeItem(this);
    delete this;
}
