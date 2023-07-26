/***************************************************************************************************
 * Program: player.h
 * Author: Hyunjae Kim
 * Date: 07/20/2020
 * Description: This program is a header file of Player class.
 * *************************************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "hand.h"

using namespace std;

class Player{
private:
    Hand hand;
    int* books;
    int n_books;

public:
    Player(); //constructor
   ~Player(); //destructor
    Player (const Player&); // CC
    Player& operator=(const Player&);//AOO
    
    //getters
	Hand& get_hand();
    int* get_books();
    int get_n_books();

    //setters
    void set_books(int*);
    void set_n_books(int);

    bool define_cheating(int);
    void removebook(int); //remove book there is 4 cards 
    int asking_rank(); //computer asks rank
};
#endif
