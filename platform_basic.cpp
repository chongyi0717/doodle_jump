#include "platform_basic.h"

PlatForm_Basic::PlatForm_Basic(qreal a,qreal b):PlatForm()
{
    setPixmap(QPixmap(":/image/platform.png"));
    setPos(a,b);
}

void PlatForm_Basic::action()
{

}

