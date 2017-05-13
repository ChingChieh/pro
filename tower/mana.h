#ifndef MANA_H
#define MANA_H

#include <QGraphicsTextItem>
#include <QTimer>

class Mana: public QGraphicsTextItem{
public:
    Mana(QGraphicsItem * parent=0);
    void m_decrease();
    int getMana();
public slots:
    void m_increase();
private:
    int mana;
};

#endif // MANA_H
