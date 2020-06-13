#ifndef PLAYER_H
#define PLAYER_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include <QKeyEvent>
#include <QMouseEvent>
#include "mainwindow.h"
#include <QTimer>
class player:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    player(int,int);
    static int score;
    void mousePressEvent(QMouseEvent *event);
    static qreal y_final;
    void check_and_generate();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mouseRealeaseEvent(QMouseEvent *event);
    void direction(int);
public slots:
    void jump();
    void start_timer();
    void stop_timer();
    void move_left();
    void move_right();
    void fly();

signals:
    void set_left();
    void set_right();
private:
    static const int scene_width=400;
    static const int scene_height=600;
    qreal update_platform;
    qreal dy;
    static qreal a;

    MainWindow *m;
    QTimer *timer;
    int count;
    QTimer *timer_left;
    QTimer *timer_right;
    QTimer *timer_prop;
    bool get_shield;
    qreal y_player;
    int get_coin;
};

#endif // PLAYER_H
