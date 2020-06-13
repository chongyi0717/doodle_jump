#ifndef PLATFORM_PROP_SPRINGBED_H
#define PLATFORM_PROP_SPRINGBED_H

#include "platform.h"

class PlatForm_Prop_SpringBed:public PlatForm
{
    Q_OBJECT
public:
    PlatForm_Prop_SpringBed(qreal a=0,qreal b=0);
public slots:
    void action();
};

#endif // PLATFORM_PROP_SPRINGBED_H
