#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <cstring>
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
};

#endif

