#ifndef BAD_WARRIORS_H
#define BAD_WARRIORS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bad_warriors: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
   Bad_warriors(QGraphicsItem * parent = 0);

   int B_attack;
   int B_pace;

public slots:
   void B_walk();


};

#endif // BAD_WARRIORS_H
