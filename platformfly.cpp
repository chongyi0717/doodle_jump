#include "platformfly.h"
PlatFormFly::PlatFormFly(qreal a,qreal b):PlatForm ()
{
    setPixmap(QPixmap(":/image/platform.png"));
    setPixmap(QPixmap(":/image/fly.png"));    setPos(a,b);
}
