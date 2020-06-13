#ifndef HAZARD_H
#define HAZARD_H


#include "platform.h"
class Hazard:public PlatForm
{
    Q_OBJECT
public:
    Hazard(qreal a=0,qreal b=0);
public slots:
    void action();
};

#endif // HAZARD_H
