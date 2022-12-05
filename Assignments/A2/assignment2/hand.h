#ifndef HAND_H
#define HAND_H



#include "deck.h"

using namespace std;


class Hand{
private:
    Card* cards;
    int n_cards;

public:
    Hand();//constructor
    ~Hand();//destructor
  //  Hand (const Hand&); // CC

    //getters
    Card* get_cards();
    int get_n_cards();

    //setters
    void set_cards(Card*);
    void set_n_cards(int);

    /*void ask_ranks(){
        string ask;

        for(int i = 0;i < this->n_cards;i++){
            if(ask == cards[i].map_rank()){
                --this->n_cards;
            }
            
            else{
                this->n_cards += 1;
            }
        }
    }*/ // in the game class
    
    //card remove
    Card remove_card(int);

    //card adding
    void add_card(Card);

    void swap(Card&,Card&);

    bool verify(int);


    
    bool checkbook(int);

};
#endif