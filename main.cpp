#include "mainwindow.h"
#include <QApplication>
#include "player.h"
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QGraphicsView>
#include <QPushButton>
#include <QObject>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w;


    return a.exec();
}
