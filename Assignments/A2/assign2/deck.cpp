/***************************************************************************************************
 * Program: deck.cpp
 * Author: Hyunjae Kim
 * Date: 07/20/2020
 * Description: This program is a cpp file of Deck class.
 * *************************************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "deck.h"

//Deck constructor
Deck::Deck(){
   // cout << "default constructor being called" << endl;
    this->cards[52];
    this->n_cards = 52;
}

//Deck destructor
Deck::~Deck(){}

//Deck getters
Card* Deck::get_cards(){
    return this->cards;
}

//Deck setter

 void Deck::fill_deck(){
        int x = 0;
        for(int i = 0;i < 4;i++){
             for(int j = 0;j < 13;j++){
                cards[x].set_suit(i);
                cards[x].set_rank(j);    
                x++;
            }         
        }

    }
//Shuffle deck
 void Deck::deck_shuffle(){
        srand(time(NULL));
       
        Card tmp;
        for(int i = 0;i < this->n_cards;i++){
            int x = rand()%52;
            int y = rand()%52;
            tmp = cards[x];
            cards[x] = cards[y];
            cards[y] = tmp;
        }
    }

//Draw card
Card& Deck::draw_card(){
    return cards[--n_cards];
}


