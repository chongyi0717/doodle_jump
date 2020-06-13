#include "monster.h"

Monster::Monster(qreal a,qreal b):PlatForm ()
{
    setPixmap(QPixmap(":/image/monster.png"));
    setScale(1.5);
    setPos(a,b);
}

void Monster::action()
{
    setPos(x(),y()-5);
}
