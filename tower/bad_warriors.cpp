#include <Bad_warriors.h>
#include <Warriors.h>
#include <QPixmap>
#include <QTimer>
#include "Game.h"
#include <QGraphicsScene>
#include "Tower.h"
#include <typeinfo>
#include <QList>
extern Game * game;

Bad_warriors::Bad_warriors(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    if(game -> deck -> getDeck() == 1){
    setPixmap(QPixmap(":/image/warrior3.png"));
    B_pace = 5;
    B_attack = 5;
    }

    if(game -> deck -> getDeck() == 2){
    setPixmap(QPixmap(":/image/warrior4.png"));
    B_pace = 7;
    B_attack = 3;
    }

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(B_walk()));
    timer->start(50);

        game -> deck -> increase();
}

void Bad_warriors::B_walk(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Warriors)){

            setPos(x(),y());
            return;
        }
    }
    setPos(x()-B_pace,y());

}
