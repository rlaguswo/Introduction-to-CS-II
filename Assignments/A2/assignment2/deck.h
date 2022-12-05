#ifndef DECK_H
#define DECK_H



#include "card.h"

using namespace std;


class Deck{
private:
    Card cards[52];
    int n_cards;

public:
    Deck();
   ~Deck();

    //getters
    Card* get_cards();
    int get_n_cards();

    //setters
    void set_n_cards(int);
    void set_cards(Card*);

    void fill_deck();

    void deck_shuffle();

    Card& draw_card();



};
#endif