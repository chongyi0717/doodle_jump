#include "platformmoving.h"
#include <QGraphicsRectItem>
#include <QBrush>
PlatFormMoving::PlatFormMoving(qreal a,qreal b):PlatForm (),count(1)
{
    setPixmap(QPixmap(":/image/plat_moving.png"));
    setPos(a,b);
}

bool PlatFormMoving::over()
{
    if(x()<=0 || x()>=400)
        return true;
    else
        return false;
}

void PlatFormMoving::action()
{
    if(over())
        count*=-1;
    setPos(x()+(10*count),y());
}

