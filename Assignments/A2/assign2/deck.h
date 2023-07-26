/***************************************************************************************************
 * Program: deck.h
 * Author: Hyunjae Kim
 * Date: 07/20/2020
 * Description: This program is a header file of Deck class.
 * *************************************************************************************************/
#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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
   // int get_n_cards();

    //setters
    void set_n_cards(int);
    void set_cards(Card*);

    void fill_deck();

    void deck_shuffle();

    Card& draw_card();



};
#endif