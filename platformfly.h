#ifndef PLATFORMFLY_H
#define PLATFORMFLY_H


#include<QObject>
#include "platform.h"
class PlatFormFly :public PlatForm
{
    Q_OBJECT
public:
    PlatFormFly(qreal a=0,qreal b=0);

signals:

public slots:
    void action();

private:

};

#endif // PLATFORMFLY_H
