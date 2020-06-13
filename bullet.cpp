#include "bullet.h"
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "monster.h"
#include "hazard.h"
#include "player.h"
bullet::bullet()
{

}

bullet::bullet(double x,double y)
{
    setPixmap(QPixmap(":/image/bullet.png"));
    setScale(0.15);
    setPos(x-7,y);
    QTimer *time=new QTimer();
    connect(time,SIGNAL(timeout()),this,SLOT(move()));
    time->start(10);
}

void bullet::move()
{
    setPos(x(),y()-10);
    if(y() < -600)
    {
        scene()->removeItem(this);
        delete this;
    }
    QList<QGraphicsItem *>colliding_items= collidingItems();
    for(int i=0;i<colliding_items.size();i++)
    {
        if(typeid(*(colliding_items[i]))==typeid(Monster))
        {
            scene()->removeItem(this);
            delete this;
            colliding_items[i]->setPos(rand()%scene_width,rand()%scene_height-10*scene_height);
            player::score+=100;
        }
    }
}
