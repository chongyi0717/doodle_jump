#ifndef PLATFORMMOVING_H
#define PLATFORMMOVING_H


#include "platform.h"
class PlatFormMoving :public PlatForm
{
    Q_OBJECT
public:
    PlatFormMoving(qreal a=0,qreal b=0);

signals:

public slots:
    void action();

private:
    int count;
    bool over();
};

#endif // PLATFORMMOVING_H

