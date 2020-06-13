#include "lose_interface.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <fstream>
using namespace std;
Lose_Interface::Lose_Interface(int score,int coin)
{

    QString highest_score=ReadFile("highest_score.txt");
    int high_score=highest_score.toInt();
    if(score>high_score)
        high_score=score;
    highest_score=QString::number(high_score);
    WriteFile("highest_score.txt",string((const char*)highest_score.toLocal8Bit()));

    QLabel *label=new QLabel();
    label->setGeometry(50,0,100,50);
    label->setText("GAME OVER");


    QLabel *label1=new QLabel();
    label1->setGeometry(00,50,100,50);
    label1->setText("Score:");

    QLabel *label2=new QLabel();
    label2->setNum(score);
    label2->setGeometry(100,50,100,50);


    QLabel *label3=new QLabel("Highest Score:");
    label3->setGeometry(0,100,100,50);



    QLabel *lb_high=new QLabel();
    lb_high->setGeometry(100,100,100,50);
    lb_high->setText(highest_score);

    QLabel *label4=new QLabel("Coin:");
    label4->setGeometry(0,150,100,50);

    QLabel *lb_coin=new QLabel();
    lb_coin->setGeometry(100,150,100,50);
    lb_coin->setNum(coin);
    /*
    QPushButton *btn=new QPushButton("Restart");
    btn->setGeometry(0,100,100,50);
    */
    QPushButton *btn2=new QPushButton("Quit");
    btn2->setGeometry(0,200,100,50);
    connect(btn2,SIGNAL(clicked()),this,SLOT(terminate()));



    QGraphicsScene *scene=new QGraphicsScene(0,0,scene_width/2,scene_height/2);
    //scene->addWidget(btn);
    scene->addWidget(label);
    scene->addWidget(label1);
    scene->addWidget(label2);
    scene->addWidget(btn2);
    scene->addWidget(label3);
    scene->addWidget(lb_high);
    scene->addWidget(label4);
    scene->addWidget(lb_coin);

    QGraphicsView *view=new QGraphicsView();
    view->setFixedSize(scene_width/2,scene_height/2);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    view->show();
}

QString Lose_Interface::ReadFile(string FileName)
{
    ifstream inFile(FileName,ios::in);

    if(!inFile)
        qDebug()<<"Failed Reading";
    string buffer;
    getline(inFile,buffer);
    return QString(QString::fromLocal8Bit(buffer.c_str()));

}


void Lose_Interface::WriteFile(string FileName,string num)
{
    ofstream outfile(FileName,ios::out);
    if(!outfile)
        qDebug()<<"Failed Writing";
    outfile<<num;
}
void Lose_Interface::terminate()
{
    exit(0);
}


