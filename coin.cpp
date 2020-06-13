#include "coin.h"

Coin::Coin(qreal a,qreal b):PlatForm ()
{
    setPixmap(QPixmap(":/image/coin_real.png"));
    setScale(0.05);
    setPos(a,b);
}

void Coin::action()
{
    setPos(x(),y()-5);
}
