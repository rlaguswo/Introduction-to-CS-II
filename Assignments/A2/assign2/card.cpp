/***************************************************************************************************
 * Program: card.cpp
 * Author: Hyunjae Kim
 * Date: 07/20/2020
 * Description: This program is cpp file of Card class.
 * *************************************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "card.h"

using namespace std;

//Card constructor
Card::Card(){
   // cout << "default constructor being called" << endl;
    this->rank = 0;
    this->suit = 0;
}

//getters
/************************************************************************
 * Function: get_rank()
 * Description: This function is a accessor of the card rank
 * **********************************************************************/
int Card::get_rank() const{
    return this->rank;
}

/************************************************************************
 * Function: get_suit()
 * Description: This function is a accessor of the card suit
 * **********************************************************************/
int Card::get_suit() const{
    return this->suit;
}

//setters
/************************************************************************
 * Function: set_rank()
 * Description: This function is a mutator of the card rank
 * **********************************************************************/
void Card::set_rank(int r){
    this->rank = r;
}

/************************************************************************
 * Function: set_suit()
 * Description: This function is a mutator of the card suit
 * **********************************************************************/
void Card::set_suit(int s){
    this->suit = s;
}

/************************************************************************
 * Function: map_suit()
 * Description: This function converts this->suit to one of the D,C,S,H
 * **********************************************************************/
string Card::map_suit()const{
    string suits[4] = {"D","C","S","H"};
    return suits[this->suit];
}

/************************************************************************
 * Function: map_rank()
 * Description: This function converts this->suit to one of the card ranks
 * **********************************************************************/
string Card::map_rank()const{
    string ranks[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    return ranks[this->rank];
}




