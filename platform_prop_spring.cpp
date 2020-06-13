#include "platform_prop_spring.h"

PlatForm_Prop_Spring::PlatForm_Prop_Spring(qreal a,qreal b):PlatForm ()
{
    setPixmap(QPixmap(":/image/platform_prop1.png"));
    setPos(a,b);
}

void PlatForm_Prop_Spring::action()
{
    setPos(x(),y()-5);
}
