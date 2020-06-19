#include "mainwindow.h"
#include "player.h"
#include "platform.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPushButton>
#include <stdlib.h>
#include <QDebug>
#include <time.h>
#include <QTimer>
#include <vector>
#include "platform_basic.h"
#include "platformmoving.h"
#include "platformbroken.h"
#include "platform_prop_springbed.h"
#include "platform_prop_spring.h"
#include "monster.h"
#include "hazard.h"
#include "shield.h"
#include "lose_interface.h"
#include "coin.h"
using namespace std;
vector<PlatForm *> MainWindow::plat={};
QTimer *MainWindow::timer=nullptr;
QGraphicsSimpleTextItem *MainWindow::score_text=nullptr;
QGraphicsPixmapItem *MainWindow::shield_pixmap=nullptr;
QString *MainWindow::score_string=nullptr;
QString *MainWindow::shield_string=nullptr;
QGraphicsSimpleTextItem *MainWindow::coin_text=nullptr;
QString *MainWindow::coin_string=nullptr;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    scene(new QGraphicsScene(0,0,scene_width,scene_height))
{
    srand(time(NULL));
    scene->setBackgroundBrush(QPixmap(":/image/background.png"));
    player *p=new player(scene_width/2-50,scene_height-80);
    scene->addItem(p);

    PlatForm *platform_move1=new PlatFormMoving(rand()%scene_width,rand()%scene_height);
    scene->addItem(platform_move1);
    plat.push_back(platform_move1);

    PlatForm *platform_move2=new PlatFormMoving(rand()%scene_width,rand()%scene_height);
    scene->addItem(platform_move2);
    plat.push_back(platform_move2);
    timer=new QTimer();

    PlatForm *platform_move3=new PlatFormBroken(rand()%scene_width,rand()%scene_height);
    scene->addItem(platform_move3);
    plat.push_back(platform_move3);

    connect(timer,SIGNAL(timeout()),platform_move1,SLOT(action()));
    connect(timer,SIGNAL(timeout()),platform_move2,SLOT(action()));
    timer->start(50);

    generate_platform();
    score_string=new QString();
    score_text=new QGraphicsSimpleTextItem();
    scene->addItem(score_text);


    shield_pixmap=new QGraphicsPixmapItem();
    shield_pixmap->setPos(scene_width-50,0);
    scene->addItem(shield_pixmap);

    QGraphicsSimpleTextItem *coint=new QGraphicsSimpleTextItem("Coin");
    coint->setPos(scene_width-75,50);
    scene->addItem(coint);

    coin_string=new QString();
    coin_text=new QGraphicsSimpleTextItem();
    coin_string->setNum(0);
    coin_text->setText(*coin_string);
    coin_text->setPos(scene_width-25,50);
    scene->addItem(coin_text);

    QGraphicsView *view=new QGraphicsView();
    view->setFixedSize(scene_width,scene_height);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    view->show();
}
MainWindow::~MainWindow()
{

}

void MainWindow::generate_platform()
{
    platform_num=8;

    PlatForm *platform=new PlatForm_Basic(scene_width/2-50,scene_height-10);
    scene->addItem(platform);
    plat.push_back(platform);
    player::y_final=platform->y();
    for(int i=0;i<platform_num;i++)
    {
        platformx=rand()%scene_width;
        platformy=scene_height-i*75;
        PlatForm *platform=new PlatForm_Basic(platformx,platformy);
        scene->addItem(platform);
        plat.push_back(platform);
    }

        PlatForm *prop=new PlatForm_Prop_SpringBed(rand()%scene_width,rand()%scene_height-3*scene_height);
        scene->addItem(prop);
        plat.push_back(prop);

        PlatForm *prop2=new PlatForm_Prop_Spring(rand()%scene_width,rand()%scene_height-scene_height);
        scene->addItem(prop2);
        plat.push_back(prop2);

        PlatForm *monster=new Monster(rand()%scene_width,rand()%scene_height);
        scene->addItem(monster);
        plat.push_back(monster);

        PlatForm *hazard=new Hazard(rand()%scene_width,rand()%scene_height-7*scene_height);
        scene->addItem(hazard);
        plat.push_back(hazard);

        PlatForm *shield=new Shield(rand()%scene_width,rand()%scene_height-2*scene_height);
        scene->addItem(shield);
        plat.push_back(shield);

        PlatForm *coin=new Coin(rand()%scene_width,rand()%scene_height);
        scene->addItem(coin);
        plat.push_back(coin);

}

void MainWindow::terminate()
{
    delete this;
}







