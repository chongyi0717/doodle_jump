#ifndef PROP_SPRINGBED_H
#define PROP_SPRINGBED_H
#include <QObject>
#include <QGraphicsPixmapItem>
class Prop_SpringBed:public QObject,public QGraphicsPixmapItem
{

public:
    Prop_SpringBed(double a=0,double b=0);

};

#endif // PROP_SPRINGBED_H
