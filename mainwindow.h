#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "platform.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>
#include "platform_basic.h"
#include <QString>
#include <QGraphicsSimpleTextItem>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    //virtual void mousePressEvent(QMouseEvent *event);
    ~MainWindow();
    void generate_platform();
    QGraphicsScene *scene;
    static std::vector<PlatForm*> plat;
    static QGraphicsSimpleTextItem *score_text;
    static QString *score_string;
    static QTimer *timer;
    static QString *shield_string;
    static QGraphicsPixmapItem *shield_pixmap;
    static QGraphicsSimpleTextItem *coin_text;
    static QString *coin_string;
public slots:
    void terminate();

private:
    static const int scene_width=400;
    static const int scene_height=600;

    qreal platformx;
    qreal platformy;

    int platform_num;
    bool check_bounce(qreal y);


    qreal dy;
    qreal a;
};

#endif // MAINWINDOW_H
