#include "Warriors.h"
#include "Bad_warriors.h"
#include <QPixmap>
#include <QTimer>
#include "Game.h"
#include <QGraphicsScene>
#include <QList>
extern Game * game;

Warriors::Warriors(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    if(game -> deck -> getDeck() == 1){
    setPixmap(QPixmap(":/image/warrior1.png"));
    pace = 5;
    attack = 5;
    }

    if(game -> deck -> getDeck() == 2){
    setPixmap(QPixmap(":/image/warrior2.png"));
    pace = 7;
    attack = 3;
    }

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(walk()));
    timer->start(50);

        game -> deck -> increase();
}



void Warriors::walk(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Bad_warriors)){

            setPos(x(),y());
            return;
        }
    }

    setPos(x()+pace,y());

}
