#ifndef GAME_H
#define GAME_H



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
    string map_rank(int);
    void game_over();
    void game_screen();
    int check_input(string,string);
    int check_choose();
    int check_rank();
    void com_to_player(int);
    void player_to_computer(int);
    void player_fish(int,bool&);
    void com_fish(int,bool&);
    void player_turn();
    void com_turn();
    void distribute_card();
    void start_game();
};
#endif
