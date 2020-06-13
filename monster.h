#ifndef MONSTER_H
#define MONSTER_H


#include "platform.h"
class Monster:public PlatForm
{
    Q_OBJECT
public:
    Monster(qreal a=0,qreal b=0);
public slots:
    void action();
};

#endif // MONSTER_H
