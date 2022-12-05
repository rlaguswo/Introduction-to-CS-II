

#include "card.h"

using namespace std;

//Card constructor
Card::Card(){
   // cout << "default constructor being called" << endl;
    this->rank = 0;
    this->suit = 0;
}

//getters
int Card::get_rank() const{
    return this->rank;
}

int Card::get_suit() const{
    return this->suit;
}

//setters
void Card::set_rank(int r){
    this->rank = r;
}

void Card::set_suit(int s){
    this->suit = s;
}





