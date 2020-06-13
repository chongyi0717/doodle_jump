#ifndef COIN_H
#define COIN_H


#include "platform.h"
class Coin:public PlatForm
{
    Q_OBJECT
public:
    Coin(qreal a=0,qreal b=0);
public slots:
    void action();
};

#endif // COIN_H
