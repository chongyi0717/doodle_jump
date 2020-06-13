#ifndef SHIELD_H
#define SHIELD_H


#include "platform.h"
class Shield:public PlatForm
{
    Q_OBJECT
public:
    Shield(qreal a=0,qreal b=0);
public slots:
    void action();
};

#endif // SHIELD_H
