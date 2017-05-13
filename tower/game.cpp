#include "Game.h"
#include <QGraphicsScene>
#include "Bullet.h"
#include "Warriors.h"
#include <QBrush>
#include <QImage>
#include <stdlib.h>

Game::Game(QWidget * parent): QGraphicsView(){
    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1000,600);
    setBackgroundBrush(QBrush(QImage(":/image/grass.jpg")));
    // set the scene
    setScene(scene);

    // create a tower
    t = new Tower();
    t->setPos(0,250);

    t2 = new Bad_tower();
    t2->setPos(900,250);

    // add the tower to scene
    scene->addItem(t);
    scene->addItem(t2);

    mmm = new Mana();

    deck = new Deck();
    setFixedSize(1000,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void Game::mousePressEvent(QMouseEvent *event){
    //create a bullet
    Bullet * bullet = new Bullet();
    bullet->setPos(event->pos());
    bullet->setRotation(0);
    scene->addItem(bullet);

}

void Game::keyPressEvent(QKeyEvent *event1){
    //create a warrior
    if(event1->key() == Qt::Key_Space){
    Warriors * warrior = new Warriors();

    int i = rand();
    i %= 4;
    if(i >= 2)
    {
        warrior->setPos(60,300);
    }
    if(i < 2)
    {
        warrior->setPos(60,200);
    }
    scene->addItem(warrior);
    }
}

