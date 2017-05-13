#ifndef WARRIORS_H
#define WARRIORS_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <typeinfo>
class Warriors: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
   Warriors(QGraphicsItem * parent = 0);

   int attack;
   int pace;

public slots:
   void walk();


};


#endif // WARRIORS_H
