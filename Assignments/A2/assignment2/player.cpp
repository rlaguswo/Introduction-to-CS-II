

#include "player.h"

using namespace std;

//Player constructor
Player::Player(){
   // cout << "Player constructor called" << endl;
    this->n_books = 0;
    this->books = new int[13];
}

//Player destructor
Player::~Player(){
    //cout << "Player destructor called" << endl;
    if(this->books != NULL){
        delete[] this->books;
        this->books = NULL;
    }
}
/*
//Player copy constructor
Player::Player(const Player& old_obj){
    //cout << "Copy constructor of Player called" << endl;
    this->n_books = old_obj.n_books;

    this->books = new int[this->n_books];
    for(int i = 0;i < this->n_books;++i)
        this->books[i] = old_obj.books[i];
}

//Player Assignment Operator Overload
Player& Player::operator=(const Player& old_obj){
   // cout << "Assignment operator overload of Player called" << endl;
    if(this != &old_obj){
        this->n_books = old_obj.n_books;

        if(this->books != NULL)
            delete [] this->books;
        
        this->books = new int[this->n_books];
        for(int i = 0;i < this->n_books;++i){
            this->books[i] = old_obj.books[i];
        }
    }

    return *this;
}
*/
//Player getters
Hand& Player::get_hand(){
	return this->hand;
}
int* Player::get_books(){
    return this->books;
}

int Player::get_n_books(){
    return this->n_books;
}

//Player setters
void Player::set_books(int* book_arr){
    this->books = book_arr;
}

void Player::set_n_books(int num_books){
    this->n_books = num_books;
}

Card Player::random(){
    srand(time(NULL));
    int random = rand()%hand.get_n_cards();
    Card card = this->hand.get_cards()[random];
    return card;
}

void Player::removebook(int rank){
    books[n_books] = rank;
    n_books++;

    while(this->hand.verify(rank)){
        this->hand.remove_card(rank);
    }
}

//Add card to hand
void Player::add_card_to_hand(Card new_card){
    this->hand.add_card(new_card);
}

//Remove card from hand
void Player::remove_from_hand(int rank){
    this->hand.remove_card(rank);
}

//varify rank
bool Player::varify(int rank){
    Card* card = this->hand.get_cards();
    for(int i = 0;i < this->hand.get_n_cards();i++){
        if(card[i].get_rank() != rank){
            return false;
        }

        else{
            return true;
        }
    }
}

//Check books
void Player::check_n_books(){
    int num_cards = 1, i;
    Card* c = this->hand.get_cards();
    for(i = 0;i < this->hand.get_n_cards();i++){
        if(c[i].get_rank() == c[i+1].get_rank()){
            num_cards++;
        }
    }

    if(num_cards == 4){
        this->n_books++;
    }
    

}
