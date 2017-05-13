#include "Bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h> // qSin, qCos, qTan
#include "Game.h"
#include "Warriors.h"
#include "Bad_warriors.h"
#include "bad_tower.h"
#include <QList>
#include <typeinfo>

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){
    // set graphics
    setPixmap(QPixmap(":image/bullet.png"));


    // connect a timer to move()
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);
}




void Bullet::move(){
    int STEP_SIZE = 30;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    // get a list of all the items currently colliding with this bullet
        QList<QGraphicsItem *> colliding_items = collidingItems();


        // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Bad_warriors)){


                // remove them from the scene (still on the heap)

                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);

                // delete them from the heap to save memory
                delete colliding_items[i];
                delete this;

                // return (all code below refers to a non existint bullet)
                return;
            }
        }
    setPos(x() + dx, y() + dy);

}
