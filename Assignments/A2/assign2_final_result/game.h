/***************************************************************************************************
 * Program: game.h
 * Author: Hyunjae Kim
 * Date: 07/20/2020
 * Description: This program is a header file of Game class.
 * *************************************************************************************************/
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


#include "player.h"

using namespace std;

class Game{
private:
    Deck d;
    Player player[2];
    bool gameover;
public:
    Game(); // constructor
    ~Game(); //destructor
    
    //getters
    Deck get_deck();
    Player* get_player();

    //setters
    void set_deck(Deck);
  
    //map int rank to card rankd
    string rank_map(int rank)const;
  
    //check game is over
    void game_over();
  
    //debug mode game screen
    void game_screen();
  
    //normal mode game screen
    void game_screen2();
  
    //check user input
    int check_input();
  
    //check the player is going to quit
    int check_quit();
  
    //debug mode, check the player's hand
    int check_choose();
  
    //normal mode
    int check_choose2();
  
    //debug mode, check the computer's hand
    int check_rand();
  
    //normal mode
    int check_rand2();
  
    //debug mode
    void com_to_player(int);
  
    //normal mode
    void com_to_player2(int);
  
    //debug mode
    void player_to_computer(int);
  
    //normal mode
    void player_to_computer2(int);
  
    //debug mode
    void player_fish(int,bool&);
  
    //normal mode
    void player_fish2(int,bool&);
  
    //computer answers go fish
    void com_fish(int,bool&);
  
    //debug mode
    void player_turn();
  
    //Normal maode
    void player_turn2();
  
    //debug mode
    void com_turn();
  
    //Normal mode
    void com_turn2();
  
    //give 7 cards to each player
    void distribute_card();
  
    //debug mode
    void start_game();
  
    //Normal mode
    void start_game2();
};
#endif
