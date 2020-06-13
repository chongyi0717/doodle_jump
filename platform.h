#ifndef PLATFORM_H
#define PLATFORM_H

#include <QObject>
#include <QGraphicsPixmapItem>
class PlatForm : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PlatForm(){}

signals:

public slots:
    virtual void action()=0;



};

#endif // PLATFORM_H
