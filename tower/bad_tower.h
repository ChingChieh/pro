#ifndef BAD_TOWER_H
#define BAD_TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QObject>

class Bad_tower: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bad_tower(QGraphicsItem * parent=0);
    void B_damage();
    int B_get_tower_HP();

public slots:
    void B_shoot();
    void call_warriors();
private:
    QGraphicsPolygonItem * attack_area;
    int B_tower_HP = 50;
};

#endif // BAD_TOWER_H
