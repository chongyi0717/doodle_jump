#ifndef PLATFORM_BASIC_H
#define PLATFORM_BASIC_H

#include <QObject>
#include "platform.h"
class PlatForm_Basic:public PlatForm
{
    Q_OBJECT
public:
    PlatForm_Basic(qreal a=0,qreal b=0);

public slots:
    void action();
};

#endif // PLATFORM_BASIC_H
