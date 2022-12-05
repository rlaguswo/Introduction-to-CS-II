/***************************************************************************************************
 * Program: game.cpp
 * Author: Hyunjae Kim
 * Date: 07/20/2020
 * Description: This program is a header file of Game class.
 * *************************************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "game.h"

using namespace std;

//Game constructor
Game::Game(){

    this->gameover = false;
}

//Game destructor
Game::~Game(){}//there's no dynamic array in Game class

//getters
Deck Game::get_deck(){
    return this->d;
}

Player* Game::get_player(){
    return this->player;
}




//setters
void Game::set_deck(Deck deck){
    this->d = deck;
}

string Game::rank_map(int rank)const{
    string ranks[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    
    return ranks[rank];
    }

void Game::game_over(){
    if(player[0].get_n_books() + player[1].get_n_books() > 12){
        gameover = true;
    }
    else{
        gameover = false;
    }
}

void Game::game_screen(){
    cout << endl << endl;
    cout << "___________________________________________________________" << endl;
    cout << "\tcomputer" << endl;

    cout <<"Books: " << player[0].get_n_books();
    cout << endl << "Hand: ";
    int com_cards = player[0].get_hand().get_n_cards();
    for(int i = 0;i < com_cards;i++){
        Card c = player[0].get_hand().get_cards()[i];
        cout << "<" << c.map_rank() << "> ";
    }

    cout << endl << endl << "\tDeck";

    cout << endl << endl << "\tPlayer" << endl;

    cout <<"Books: " << player[1].get_n_books();

    cout << endl << "Hand: ";
    int player_cards = player[1].get_hand().get_n_cards();
    for(int i = 0;i < player_cards;i++){
        Card c = player[1].get_hand().get_cards()[i];
        cout << "<" << c.map_rank() << "> ";
    }
    cout << endl << "     ";

    cout << endl;
    cout << "___________________________________________________________________" << endl;
}

void Game::game_screen2(){
    cout << endl << endl;
    cout << "___________________________________________________________" << endl;
    cout << "\tcomputer" << endl;

    cout <<"Books: " << player[0].get_n_books();
    cout << endl << "Hand: ";
    int com_cards = player[0].get_hand().get_n_cards();
    for(int i = 0;i < com_cards;i++){
        cout << "< > ";
    }

    cout << endl << endl << "\tDeck";

    cout << endl << endl << "\tPlayer" << endl;

    cout <<"Books: " << player[1].get_n_books();
    
    cout << endl << "Hand: ";
    int player_cards = player[1].get_hand().get_n_cards();
    for(int i = 0;i < player_cards;i++){
        Card c = player[1].get_hand().get_cards()[i];
        cout << "<" << c.map_rank() << "> ";
    }
    cout << endl << "     ";
    cout << endl;
    cout << "___________________________________________________________________" << endl;
}


int Game::check_input(){
    int input;
    cout << "Enter the rank of the card you wish to request: ";
    cin >> input;

    return input;
}
int Game::check_quit(){
    int quit;
    cout <<"Enter 1 to play again or 2 to exist: ";
    cin >> quit;
    return quit;
}


int Game::check_choose(){
    if(player[1].get_hand().get_n_cards() < 1 && !gameover){
        cout << "You draw a card ";
        player[1].get_hand().add_card(d.draw_card());
        game_screen();
    }
    Card card;
    int rank_player = -1;
    rank_player = check_input();
    for(int i = 0;i < player[1].get_hand().get_n_cards();i++){
        if(rank_player == player[1].get_hand().get_cards()[i].get_rank()){
            card = player[1].get_hand().get_cards()[i];
        }
    }
    
    int rank = card.get_rank();
    cout << "Player ask for a: " << rank_map(rank) << endl;

    if(player[0].get_hand().get_n_cards() < 1){
        cout << "Computer draw a card ";
        player[1].get_hand().add_card(d.draw_card());
        game_screen();
    }

    return rank;
}

int Game::check_choose2(){
    if(player[1].get_hand().get_n_cards() < 1 && !gameover){
        cout << "You draw a card ";
        player[1].get_hand().add_card(d.draw_card());
        game_screen2();
    }
    Card card;
    int rank_player = -1;
    rank_player = check_input();
    for(int i = 0;i < player[1].get_hand().get_n_cards();i++){
        if(rank_player == player[1].get_hand().get_cards()[i].get_rank()){
            card = player[1].get_hand().get_cards()[i];
        }
    }
    
    int rank = card.get_rank();
    cout << "Player ask for a: " << rank_map(rank) << endl;

    if(player[0].get_hand().get_n_cards() < 1){
        cout << "Computer draw a card ";
        player[1].get_hand().add_card(d.draw_card());
        game_screen2();
    }

    return rank;
}


int Game::check_rand(){
    if(player[0].get_hand().get_n_cards() < 1 && !gameover){
        cout << "Computer draws a card ";
        player[0].get_hand().add_card(d.draw_card());
        game_screen();
    }
    srand(time(NULL));
    //int rank_com = player[0].get_hand().get_n_cards();
    int rank_com = rand()%player[0].get_hand().get_n_cards();
    Card card = player[0].get_hand().get_cards()[rank_com-1];
    int rank = card.get_rank();
    cout << "Computer asks for a: " << card.map_rank() << endl;

    if(player[1].get_hand().get_n_cards() < 1){
        cout << "Computer draws a card. ";
        player[0].get_hand().add_card(d.draw_card());
        game_screen();
    }

    return rank;
}

int Game::check_rand2(){
    if(player[0].get_hand().get_n_cards() < 1 && !gameover){
        cout << "Computer draws a card ";
        player[0].get_hand().add_card(d.draw_card());
        game_screen2();
    }
    srand(time(NULL));
    int rank_com = player[0].get_hand().get_n_cards();
    Card card = player[0].get_hand().get_cards()[rank_com-1];
    int rank = card.get_rank();
    cout << "Computer asks for a: " << card.map_rank() << endl;

    if(player[1].get_hand().get_n_cards() < 1){
        cout << "Computer draws a card. ";
        player[0].get_hand().add_card(d.draw_card());
        game_screen2();
    }

    return rank;
}


void Game::com_to_player(int rank){
    int count = 0;
    while(player[0].get_hand().verify(rank)){
        Card c = player[0].get_hand().remove_card(rank);
        player[1].get_hand().add_card(c);
        count++;
    }
    if(count > 0){
        cout << "Computer gives you" << count << ": " << rank_map(rank) << endl;
    }

    game_screen();

    if(player[1].get_hand().checkbook(rank)){
        cout << "You got a book" << endl;
        player[1].removebook(rank);

        game_screen();
    }
}

void Game::com_to_player2(int rank){
    int count = 0;
    while(player[0].get_hand().verify(rank)){
        Card c = player[0].get_hand().remove_card(rank);
        player[1].get_hand().add_card(c);
        count++;
    }
    if(count > 0){
        cout << "Computer gives you" << count << ": " << rank_map(rank) << endl;
    }

    game_screen2();

    if(player[1].get_hand().checkbook(rank)){
        cout << "You got a book" << endl;
        player[1].removebook(rank);

        game_screen2();
    }
}


void Game::player_to_computer(int rank){
    int count = 0;
    while(player[1].get_hand().verify(rank)){
        Card c = player[1].get_hand().remove_card(rank);
        player[0].get_hand().add_card(c);
        count++;
    }

    if(count > 0){
        cout << "You give Computer " << count << ": " << rank_map(rank) << endl;
    }

    game_screen();

    if(player[0].get_hand().checkbook(rank)){
        cout << "Computer got a book" << endl;
        player[0].removebook(rank);
    }
}


void Game::player_to_computer2(int rank){
    int count = 0;
    while(player[1].get_hand().verify(rank)){
        Card c = player[1].get_hand().remove_card(rank);
        player[0].get_hand().add_card(c);
        count++;
    }

    if(count > 0){
        cout << "You give Computer " << count << ": " << rank_map(rank) << endl;
    }

    game_screen2();

    if(player[0].get_hand().checkbook(rank)){
        cout << "Computer got a book" << endl;
        player[0].removebook(rank);
    }
}

void Game::player_fish(int rank, bool& myturn){
    cout << "Computer Go fish." << endl;
    Card c = d.draw_card();
    int rank_draw = c.get_rank();
    cout << "You draw a: " << c.map_rank() << endl;
    player[1].get_hand().add_card(c);
    if(rank_draw == rank){
        cout << "You fished for what you wanted" << endl;
        if(player[1].get_hand().checkbook(rank)){
            cout << "You got a book" << endl;
            player[1].removebook(rank);
        }
        game_screen();
    }
    else{
        cout << endl;
        if(player[1].get_hand().checkbook(rank_draw)){
            cout << "You got a book" << endl;
            player[1].removebook(rank_draw);
            game_screen();
        }
        cout << "\tCOMPUTER TURN\t" << endl;
        myturn != myturn;
    }
}

void Game::player_fish2(int rank, bool& myturn){
    cout << "Computer Go fish." << endl;
    Card c = d.draw_card();
    int rank_draw = c.get_rank();
    cout << "You draw a: " << c.map_rank() << endl;
    player[1].get_hand().add_card(c);
    if(rank_draw == rank){
        cout << "You fished for what you wanted" << endl;
        if(player[1].get_hand().checkbook(rank)){
            cout << "You got a book" << endl;
            player[1].removebook(rank);
        }
        game_screen2();
    }
    else{
        cout << endl;
        if(player[1].get_hand().checkbook(rank_draw)){
            cout << "You got a book" << endl;
            player[1].removebook(rank_draw);
            game_screen2();
        }
        cout << "\tCOMPUTER TURN\t" << endl;
        myturn != myturn;
    }
}
void Game::com_fish(int rank, bool &comturn){
        cout << "Player go fish" << endl;
        Card c = d.draw_card();
        int rank_draw = c.get_rank();
        cout << "Computer draws a: " << c.map_rank() << endl;
        player[0].get_hand().add_card(c);

        if(rank_draw == rank){
            cout << "Computer fished for what it wanted" << endl;
            if(player[0].get_hand().checkbook(rank)){
                cout << "Computer got a book" << endl;
                player[0].removebook(rank);
            }
        }
        else{
            cout << endl;
            if(player[0].get_hand().checkbook(rank_draw)){
                cout << "Computer got a book" << endl;
                player[0].removebook(rank_draw);
            }
            cout << "\t PLAYER TURN\t" << endl;
            comturn != comturn;
        }
    
}




void Game::player_turn(){
    game_screen();
    bool myturn = true;
    while(myturn && !gameover){
        int rank = check_choose();
        if(player[0].get_hand().verify(rank)){
            com_to_player(rank);
        }
        else{
            player_fish(rank,myturn);
            break;
        }
        game_over();
    }
}

void Game::player_turn2(){
    game_screen2();
    bool myturn = true;
    while(myturn && !gameover){
        int rank = check_choose2();
        if(player[0].get_hand().verify(rank)){
            com_to_player2(rank);
        }
        else{
            player_fish2(rank,myturn);
            break;
        }
        game_over();
    }
}

void Game::com_turn(){
    game_screen();
    bool comturn = true;
    while(comturn && !gameover){
        int rank = check_rand2();
        int go_fish = player[1].asking_rank();
        if(player[1].get_hand().verify(rank)){
            if(go_fish == 111){
                cout << "No Cheating!" << endl;
                player_to_computer(rank);
                
            }
            else{
                player_to_computer(rank);
                }
        }
        else{
            if(go_fish == 111){
                com_fish(rank,comturn);
                break;
            }
        }
        game_over();
    }
}

void Game::com_turn2(){
   game_screen2();
    bool comturn = true;
    while(comturn && !gameover){
        int rank = check_rand2();
        int go_fish = player[1].asking_rank();
        if(player[1].get_hand().verify(rank)){
            if(go_fish == 111){
                cout << "No Cheating!" << endl;
                player_to_computer2(rank);
                
            }
            else{
                player_to_computer2(rank);
                }
        }
        else{
            if(go_fish == 111){
                com_fish(rank,comturn);
                break;
            }
        }
        game_over();
    }
}

void Game::distribute_card(){
    for(int i = 0;i < 7;i++){
        Card c = d.draw_card();
        this->player[0].get_hand().add_card(c);
        Card c1 = d.draw_card();
        this->player[1].get_hand().add_card(c1);
    }

}

void Game::start_game(){
    d.fill_deck();
    d.deck_shuffle();
    distribute_card();
    while(!gameover){
        player_turn();
        com_turn();
    }

    cout << "Game over" << endl;
    game_screen();
    if(player[0].get_n_books() > player[1].get_n_books()){
        cout << "Computer win" << endl;
    }
    else{
        cout << "Player win" << endl;
    }

}

void Game::start_game2(){
    d.fill_deck();
    d.deck_shuffle();
    distribute_card();
    while(!gameover){
        player_turn2();
        com_turn2();
    }

    cout << "Game over" << endl;
    game_screen2();
    if(player[0].get_n_books() > player[1].get_n_books()){
        cout << "Computer win" << endl;
    }
    else{
        cout << "Player win" << endl;
    }

}
