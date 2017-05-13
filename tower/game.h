#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QWidget>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Deck.h"
#include "Tower.h"
#include "Bad_tower.h"
#include "Mana.h"
class Game: public QGraphicsView{
public:
    // member functions
    Game(QWidget * parent=0);

    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event1);
    // member attributes
    QGraphicsScene * scene;
    Deck * deck;
    Tower * t;
    Bad_tower * t2;
    Mana * mmm;
};

#endif // GAME_H
