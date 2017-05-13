#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QObject>



class Tower: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem * parent=0);
    void damage();
    int get_tower_HP();

public slots:
    void shoot();
private:
    QGraphicsPolygonItem * attack_area;
    int tower_HP = 50;
};

#endif // TOWER_H
