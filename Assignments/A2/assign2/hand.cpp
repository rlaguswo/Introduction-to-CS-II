/***************************************************************************************************
 * Program: hand.cpp
 * Author: Hyunjae Kim
 * Date: 07/20/2020
 * Description: This program is a header file of  Hand class.
 * *************************************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "hand.h"

//Hand constructor
Hand::Hand(){
    this->n_cards = 0;
    this->cards = new Card[52];
}

//Hand destructor
Hand::~Hand(){
    if(this->cards != NULL){
        delete [] this->cards;
        this->cards = NULL;
    }
}

//Hand Copy Constructor
Hand::Hand(const Hand& hand){
    this->n_cards = hand.n_cards;

    this->cards = new Card [this->n_cards];
    for(int i = 0;i < this->n_cards;i++){
        this->cards[i] = hand.cards[i];
    }
}

Hand& Hand::operator=(const Hand& old_hand){
    if(this != &old_hand){
        this->n_cards = old_hand.n_cards;

        if(this->cards != NULL)
            delete [] this->cards;
        this->cards = new Card[this->n_cards];
        for(int i = 0;i < this->n_cards;i++){
            this->cards[i] = old_hand.cards[i];
        }
        return *this;
    }
}


//Hand getters
Card* Hand::get_cards(){
    return this->cards;
}

int Hand::get_n_cards(){
    return this->n_cards;
}

//Hand setters
void Hand::set_cards(Card* c){
    this->cards = c;
}

void Hand::set_n_cards(int n){
    this->n_cards = n;
}




//Hand card remove
Card Hand::remove_card(int rank){
    int old_card = -1;
    Card remove_card;
    for(int i = 0;i < this->n_cards;++i){
        if(this->cards[i].get_rank() == rank){
            old_card = i;
            break;
        }
    }

    remove_card = cards[old_card];
    for(int i = old_card;i < this->n_cards-1;i++){
        this->cards[i] = this->cards[i+1];
    }

    this->n_cards--;
    return remove_card;

}

//Add card to Hand
void Hand::add_card(Card new_card){
   Card* new_tmp = new Card[n_cards+1];

    for(int i = 0;i < this->n_cards;i++){
        new_tmp[i] = this->cards[i];
    }

    new_tmp[this->n_cards] = new_card;

    if(this-> cards != NULL){
        delete [] this->cards;
    }
    this->cards = new_tmp;

    this->n_cards++;
}

bool Hand::verify(int rank){
    for(int i = 0;i < this->n_cards;i++){
        if(cards[i].get_rank() == rank){
            return true;
        }
    }
    return false;
}

bool Hand::checkbook(int rank){
    int same_rank = 0;
    for(int i = 0;i < this->n_cards;i++){
        if(cards[i].get_rank() == rank){
            same_rank++;
        }
    }
    if(same_rank > 3){
        return true;
    }
    return false;
}
