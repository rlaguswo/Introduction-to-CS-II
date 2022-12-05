#ifndef PLAYER_H
#define PLAYER_H



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
    //Player (const Player&); // CC
    //Player& operator=(const Player&);//AOO
    
    //getters
	Hand& get_hand();
    int* get_books();
    int get_n_books();

    //setters
    void set_books(int*);
    void set_n_books(int);

    Card random();
    void removebook(int);
    void add_card_to_hand(Card);
    void remove_from_hand(int);
    void check_n_books();
    bool varify(int);
};
#endif
