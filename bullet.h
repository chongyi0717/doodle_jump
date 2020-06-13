#ifndef BULLET_H
#define BULLET_H

#include<QGraphicsPixmapItem>
class bullet:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet();
    bullet(double,double);
public slots:
    void move();
private:
    static const int scene_width=400;
    static const int scene_height=600;
};

#endif // BULLET_H
