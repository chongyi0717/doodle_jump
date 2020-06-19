#include "player.h"
#include<QPixmap>
#include <bullet.h>
#include <QDebug>
#include <QList>
#include <QTimer>
#include "platform.h"
#include "mainwindow.h"
#include "platform_basic.h"
#include "platformmoving.h"
#include "platformbroken.h"
#include "prop_springbed.h"
#include "platform_prop_springbed.h"
#include "platform_prop_spring.h"
#include "monster.h"
#include "hazard.h"
#include "shield.h"
#include <QString>
#include "lose_interface.h"
#include "coin.h"
qreal player::a=500;
int player::score=0;
qreal player::y_final=0;
using namespace std;
player::player(int width,int height):update_platform(0),get_shield(false),y_player(600),get_coin(0)
{
    QPixmap pix;
    pix.load(":/image/player.png");

    setPixmap(pix);

    setPos(width,height);
    setScale(0.9);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(jump()));
    start_timer();
    timer_left=new QTimer();
    timer_right=new QTimer();
    connect(timer_left,SIGNAL(timeout()),this,SLOT(move_left()));
    connect(timer_right,SIGNAL(timeout()),this,SLOT(move_right()));
    timer_prop=new QTimer();
    connect(timer_prop,SIGNAL(timeout()),this,SLOT(fly()));

}

void player::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_A)
    {
        if(timer->isActive())
        timer_left->start(12);
        direction(1);
    }
    else if(event->key()==Qt::Key_D)
    {
        if(timer->isActive())
        timer_right->start(12);
        direction(2);
    }
    else if(event->key()==Qt::Key_Space)
    {
        bullet *b=new bullet(x()+35,y()-35);
        scene()->addItem(b);
    }
    else if(event->key()==Qt::Key_Escape)
    {
        count++;
        if(count%2==1)
        {
            timer->stop();
            timer_left->stop();
            timer_right->stop();
            MainWindow::timer->stop();
        }
        else if(count%2==0)
        {
            timer->start();
            MainWindow::timer->start();
        }
    }
    if(int(x())>=scene_width-40)
    {
        setPos(0-40,y());
    }
    else if(int(x())<=0-40)
    {
        setPos(scene_width-40,y());
    }
}

void player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A)
    {
        timer_left->stop();
    }
    else if(event->key()==Qt::Key_D)
    {
        timer_right->stop();
    }
}

void player::mouseRealeaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
        this->setFocus();
}

void player::direction(int num)
{
    if(num==1)
    {
        setTransform(QTransform());
    }
    else if(num==2)
    {
        setTransform((QTransform(-1,0,0,1,boundingRect().width(),0)));
    }
}

void player::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
        this->clearFocus();
}

void player::check_and_generate()
{
    if(y()<=scene_height/2)
    {
        int platform_num,platformx,platformy;
        platform_num=rand()%20+5;
        for(int i=0;i<platform_num;i++)
        {
            platformx=rand()%scene_width;
            platformy=(rand()%scene_height)-scene_height-10;
            PlatForm *platform=new PlatForm_Basic(platformx,platformy);
            scene()->addItem(platform);
            MainWindow::plat.push_back(platform);
        }
    }
}



void player::jump()
{
    dy+=0.2;
    a+=dy;

    QList<QGraphicsItem *>colliding_items= collidingItems();

    for(int i=0;i<colliding_items.size();++i)
    {

        if(typeid(*(colliding_items[i]))==typeid(PlatForm_Basic) ||typeid(*(colliding_items[i]))==typeid(PlatFormMoving))
        {
            if(x()+50>colliding_items[i]->x()&& (x() + 20 < colliding_items[i]->x() + 68) &&
                    (y() + 70 > colliding_items[i]->y())&& (y() + 70 < colliding_items[i]->y() + 14)&&dy>0)
            {
                dy=-12;

            }
        }

        else if(typeid(*(colliding_items[i]))==typeid(PlatForm_Prop_Spring))
        {
            if(x()+50>colliding_items[i]->x()&& (x() + 20 < colliding_items[i]->x() + 68) &&
                    (y() + 70 > colliding_items[i]->y())&& (y() + 70 < colliding_items[i]->y() + 14)&&dy>0)
            {
                dy=-12;

            }
        }
        else if(typeid(*(colliding_items[i]))==typeid(PlatForm_Prop_SpringBed))
        {
            if(x()+50>colliding_items[i]->x()&& (x() + 20 < colliding_items[i]->x() + 68) &&
                    (y() + 70 > colliding_items[i]->y())&& (y() + 70 < colliding_items[i]->y() + 14)&&dy>0)
            {

                dy=-18;

            }
        }
        else if(typeid(*(colliding_items[i]))==typeid(PlatFormBroken))
        {
            if(x()+50>colliding_items[i]->x()&& (x() + 20 < colliding_items[i]->x() + 68) &&
                    (y() + 70 > colliding_items[i]->y())&& (y() + 70 < colliding_items[i]->y() + 14)&&dy>0)

            colliding_items[i]->setPos(rand()%scene_width,rand()%scene_height-scene_height);
        }
        else if(typeid(*(colliding_items[i]))==typeid(Monster) || typeid(*(colliding_items[i]))==typeid(Hazard))
        {
            if(!get_shield)
            {
                Lose_Interface *interface=new Lose_Interface(score,get_coin);
                setPos(-100,-100);
                timer->stop();
                timer_left->stop();
                timer_right->stop();
                MainWindow::timer->stop();
            }
            else if(get_shield){
                colliding_items[i]->setPos(rand()%scene_width,rand()%scene_height-5*scene_height);
                get_shield=false;
            }
        }
        else if(typeid(*(colliding_items[i]))==typeid(Shield))
        {
            colliding_items[i]->setPos(rand()%scene_width,rand()%scene_height-3*scene_height);
            get_shield=true;
        }
        else if(typeid(*(colliding_items[i]))==typeid(Coin))
        {
            colliding_items[i]->setPos(rand()%scene_width,rand()%scene_height-2*scene_height);
            get_coin++;
        }
    }
    if(y()<scene_height/2)
    {
        a=scene_height/2+(dy<0?dy:0.2);

    for(int i=0;i<MainWindow::plat.size();i++)
    {
        MainWindow::plat.at(i)->setY(dy<=0?MainWindow::plat.at(i)->y()-dy:(MainWindow::plat.at(i)->y()));
        //MainWindow::plat.at(i)->setY(MainWindow::plat.at(i)->y()-dy);
        if(MainWindow::plat.at(i)->y()>scene_height)
        {
           if(typeid(*(MainWindow::plat.at(i)))==typeid(PlatFormBroken) ||
                   typeid(*(MainWindow::plat.at(i)))==typeid(PlatForm_Prop_SpringBed) ||
                   typeid(*(MainWindow::plat.at(i)))==typeid(PlatForm_Prop_Spring)||
                   typeid(*(MainWindow::plat.at(i)))==typeid(PlatFormMoving))
           {
                MainWindow::plat.at(i)->setPos(rand()%scene_width,rand()%scene_height-2*scene_height);
                continue;
           }
           else if(typeid(*(MainWindow::plat.at(i)))==typeid(PlatForm_Basic))
           {
                 MainWindow::plat.at(i)->setPos(rand()%scene_width,0);
                 continue;
           }
           else if(typeid(*(MainWindow::plat.at(i)))==typeid(Monster) )
           {
                 MainWindow::plat.at(i)->setPos(rand()%scene_width,rand()%scene_height-6*scene_height);
                 continue;
           }
           else if(typeid(*(MainWindow::plat.at(i)))==typeid(Hazard) )
           {
                 MainWindow::plat.at(i)->setPos(rand()%scene_width,rand()%scene_height-7*scene_height);
                 continue;
           }
           else if(typeid(*(MainWindow::plat.at(i)))==typeid(Coin) )
           {
                 MainWindow::plat.at(i)->setPos(rand()%scene_width,rand()%scene_height-scene_height);
                 continue;
           }
        }
    }
    }
    update_platform=0;

    if(y_final<MainWindow::plat.at(5)->y() && MainWindow::plat.at(5)->y()>=0 && MainWindow::plat.at(5)->y()<=scene_height )
    {
        update_platform=MainWindow::plat.at(5)->y()-y_final;
        y_final=MainWindow::plat.at(5)->y();
    }
    else if(MainWindow::plat.at(5)->y()==0)
        y_final=0;
    score+=update_platform;
    MainWindow::score_string->setNum(score);
    MainWindow::score_text->setText(*MainWindow::score_string);
    MainWindow::coin_string->setNum(get_coin);
    MainWindow::coin_text->setText(*MainWindow::coin_string);
    if(get_shield)
    {

        MainWindow::shield_pixmap->setPixmap(QPixmap(":/image/shield.png"));
        MainWindow::shield_pixmap->setScale(0.05);
    }
    else {
        MainWindow::shield_pixmap->setPixmap(QPixmap(""));
    }
    if(y()>scene_height)
    {
        Lose_Interface *interface=new Lose_Interface(score,get_coin);
        scene()->removeItem(this);
        delete this;
    }
    setY(a);

}

void player::start_timer()
{
    timer->start(15);
}

void player::stop_timer()
{
    timer->stop();
}

void player::move_left()
{
    setPos(x()-5,y());
}

void player::move_right()
{
    setPos(x()+5,y());
}

void player::fly()
{
    setPos(x(),y()-5);
}







