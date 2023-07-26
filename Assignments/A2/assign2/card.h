/***************************************************************************************************
 * Program: card.h
 * Author: Hyunjae Kim
 * Date: 07/20/2020
 * Description: This program is a header file of Card class.
 * *************************************************************************************************/


#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Card{
private:
    int rank;
    int suit;

public:
    Card();//defalut constructor

    //getters
    int get_rank() const;
    int get_suit() const;

    //setters
    void set_rank(int);
    void set_suit(int);
    string map_suit()const;
    string map_rank()const;
};

#endif

