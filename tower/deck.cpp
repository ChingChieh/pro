#include "Deck.h"


Deck::Deck(){
    // initialize the score to 0
    deck = 1;

}

void Deck::increase(){
    if(deck == 1) deck = 2;
    else if(deck == 2) deck = 1;
}

int Deck::getDeck(){
    return deck;
}
