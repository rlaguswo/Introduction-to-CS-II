/***************************************************************************************************
 * Program: player.cpp
 * Author: Hyunjae Kim
 * Date: 07/20/2020
 * Description: This program is a cpp file of Player class.
 * *************************************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

bool Player::define_cheating(int rank){
    for(int j = 0; hand.get_n_cards();j++){
        if(rank == hand.get_cards()[j].get_rank()){
            return true;
            break;
        }
        else{
            return false;
            break;
        }
    }
}



void Player::removebook(int rank){
    books[n_books] = rank;
    n_books+=1;

    while(this->hand.verify(rank)){
        this->hand.remove_card(rank);
    }
}

int Player::asking_rank(){
    int answer;
    cout << "You are going to give (type rank_number/111:go fish): ";
    cin >> answer;
    return answer;
}
