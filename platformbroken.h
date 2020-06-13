#ifndef PLATFORMBROKEN_H
#define PLATFORMBROKEN_H

#include "platform.h"
class PlatFormBroken:public PlatForm
{
    Q_OBJECT
public:
    PlatFormBroken(qreal a=0,qreal b=0);

public slots:
    void action();
};

#endif // PLATFORMBROKEN_H
