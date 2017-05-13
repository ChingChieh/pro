#ifndef DECK_H
#define DECK_H
#include <QGraphicsItem>
class Deck{
public:
    Deck();
    void increase();
    int getDeck();
private:
    int deck;
};

#endif // DECK_H
