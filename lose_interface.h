#ifndef LOSE_INTERFACE_H
#define LOSE_INTERFACE_H

#include <QObject>
#include <QString>
#include <string>
class Lose_Interface:public QObject
{
    Q_OBJECT
public:
    Lose_Interface(int,int);
    QString ReadFile(std::string);
    void WriteFile(std::string,std::string num);
public slots:
    void terminate();
private:
    static const int scene_width=400;
    static const int scene_height=600;
};

#endif // LOSE_INTERFACE_H
