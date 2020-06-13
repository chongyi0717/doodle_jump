#include "platform_prop_springbed.h"

PlatForm_Prop_SpringBed::PlatForm_Prop_SpringBed(qreal a,qreal b):PlatForm ()
{
    setPixmap(QPixmap(":/image/platform_prop2.png"));
    setPos(a,b);
}

void PlatForm_Prop_SpringBed::action()
{
    setPos(x(),y()-5);
}
