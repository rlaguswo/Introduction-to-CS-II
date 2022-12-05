/***************************************************************************************************
 * Program: hand.h
 * Author: Hyunjae Kim
 * Date: 07/20/2020
 * Description: This program is a header file of Hand class.
 * *************************************************************************************************/
#ifndef HAND_H
#define HAND_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "card.h"
#include "deck.h"

using namespace std;


class Hand{
private:
    Card* cards;
    int n_cards;

public:
    Hand();//constructor
    ~Hand();//destructor
    Hand(const Hand&);
    Hand& operator=(const Hand&);
  //  Hand (const Hand&); // CC

    //getters
    Card* get_cards();
    int get_n_cards();

    //setters
    void set_cards(Card*);
    void set_n_cards(int);

    
    
    //card remove
    Card remove_card(int);

    //card adding
    void add_card(Card);


    bool verify(int);

    
    
    bool checkbook(int);

};
#endif