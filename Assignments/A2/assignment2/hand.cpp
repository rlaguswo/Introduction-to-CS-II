
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
/*Hand::Hand(const Hand& hand){
    cout << "Hand Copy constructor of Hand called" << endl;
    if(this != &hand){
        this->
    }

}*/

//Hand getters
Card* Hand::get_cards(){
    return this->cards;
}

int Hand::get_n_cards(){
    return this->n_cards;
}

//Hand setters
/*void Hand::set_cards(Card* c){
    this->cards = c;
}

void Hand::set_n_cards(int n){
    this->n_cards = n;
}
*/
void Hand::swap(Card& a,Card& b){
    Card tmp = a;
    a = b;
    b = tmp;
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
    cards[n_cards] = new_card;
    this->n_cards++;
     for(int i = 1;i < n_cards;i++){
        for(int j = 0;j < n_cards-1;j++){
            if(cards[j].get_rank() > cards[j+1].get_rank()){
                swap(cards[j],cards[j+1]);
            }
        }
    }
   /* Card* new_tmp = new Card[n_cards+1];

    for(int i = 0;i < this->n_cards;i++){
        new_tmp[i] = this->cards[i];
    }

    new_tmp[this->n_cards] = new_card;

    if(this-> cards != NULL){
        delete [] this->cards;
    }
    this->cards = new_tmp;

    this->n_cards++;*/
}

bool Hand::verify(int rank){
    for(int i = 0;i < this->n_cards;i++){
        if(cards[i].get_rank() == rank){
            return true;
        }

        else{
            return false;
        }
    }
}
//Print card to hand
/*void Hand::print_card_in_hand(){
    Card* c = this->cards;
    for(int i = 0;i < this->n_cards;i++){
        c[i].print_card();
    }
}*/

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
