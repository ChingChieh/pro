#include "Bad_tower.h"
#include "Bad_warriors.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include "Bullet.h"
#include <QPointF>
#include <QLineF>
#include "Game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QImage>
#include <stdlib.h>
extern Game * game;

Bad_tower::Bad_tower(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // set the graphics
    setPixmap(QPixmap(":/image/r_tower.png"));

    // create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
               << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // scale points
    int SCALE_FACTOR = 75;
    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }

    // create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);

    // move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF tower_center(x()+44,y()+44);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    //control to shoot
    QTimer * B_shoot_timer = new QTimer(this);
    connect(B_shoot_timer,SIGNAL(timeout()),this,SLOT(B_shoot()));
    B_shoot_timer->start(2000);

    //creat bad warriors
    QTimer * B_timer = new QTimer(this);
    connect(B_timer,SIGNAL(timeout()),this,SLOT(call_warriors()));
    B_timer->start(1500);
}

void Bad_tower::B_damage(){
    B_tower_HP--;
}

int Bad_tower::B_get_tower_HP(){
    return B_tower_HP;
}

void Bad_tower::B_shoot(){
    Bullet * bullet = new Bullet();
    bullet->setPos(750,220);
    bullet->setRotation(180);
    game -> scene->addItem(bullet);
}

void Bad_tower::call_warriors(){
    int i = rand();
    Bad_warriors * bad_warrior = new Bad_warriors();
    i %= 4;
    if(i >= 2)
    {
        bad_warrior->setPos(750,300);
    }
    if(i < 2)
    {
        bad_warrior->setPos(750,200);
    }

    game -> scene->addItem(bad_warrior);
}
