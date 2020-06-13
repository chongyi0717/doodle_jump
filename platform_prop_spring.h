#ifndef PLATFORM_PROP_SPRING_H
#define PLATFORM_PROP_SPRING_H

#include "platform.h"
class PlatForm_Prop_Spring:public PlatForm
{
    Q_OBJECT
public:
    PlatForm_Prop_Spring(qreal a=0,qreal b=0);
public slots:
    void action();
};

#endif // PLATFORM_PROP_SPRING_H
