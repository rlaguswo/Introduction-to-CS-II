#include <iostream>
#include <string>

#include "card.h"

using namespace std;

Card::Card(){
    cout << "default constructor being called" << endl;
    this->rank = 0;
    this->suit = 0;
}

int Card::get_rank() const{
    return this->rank;
}

int Card::get_suit() const{
    return this->suit;
}

void Card::set_rank(int r){
    this->rank = r;
}

void Card::set_suit(int s){
    this->suit = s;
}

string Card::map_suit(){
    if(this->suit == 0)
        return "clubs";
    
    else if(this->suit == 1)
        return "diamonds";
    
    else if(this->suit == 2)
        return "hearts";
    
    else if(this->suit == 3)
        return "spades";
}

string Card::map_rank(){
    if(this->rank == 0)
        return "2";
    
    if(this->rank == 1)
        return "3";

    if(this->rank == 2)
        return "4";

    if(this->rank == 3)
        return "5";
    
    if(this->rank == 4)
        return "6";
    
    if(this->rank == 5)
        return "7";

    if(this->rank == 6)
        return "8";
    
    if(this->rank == 7)
        return "9";

    if(this->rank == 8)
        return "10";

    if(this->rank == 9)
        return "J";

    if(this->rank == 10)
        return "K";
    if(this->rank == 11)
        return "Q";
    if(this->rank == 12)
        return "A";
}

void Card::print_card(){
    cout << map_suit() << " " << map_rank() << endl;
}