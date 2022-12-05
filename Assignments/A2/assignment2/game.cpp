
#include <string>
#include "game.h"

using namespace std;

//Game constructor
Game::Game(){

    this->gameover = false;
}

//Game destructor
Game::~Game(){}//there's no dynamic array in Game class

//getters
/*Deck Game::get_deck(){
    return this->d;
}

Player* Game::get_player(){
    return this->player;
}*/




//setters
/*void Game::set_deck(Deck deck){
    this->d = deck;
}*/

string Game::map_rank(int rank){
    string ranks[13] = {"2","3","4","5","6","7","8","9","10","J","K","Q","A"};
    return ranks[rank];
}

void Game::game_over(){
    if(player[0].get_n_books() + player[1].get_n_books() > 12){
        this->gameover = true;
    }
    this->gameover = false;
}

void Game::game_screen(){
    cout << endl;
    cout << "___________________________________________________________" << endl;
    cout << "\tcomputer" << endl;

    cout <<"Books: ";
    for(int i = 0;i < player[0].get_n_books();i++){
        cout << "<" << map_rank(player[0].get_hand().get_cards()[i].get_rank()) << ">";
    }
    cout << "Hand: ";
    int com_cards = player[0].get_hand().get_n_cards();
    for(int i = 0;i < com_cards;i++){
        cout << "<" << map_rank(player[0].get_hand().get_cards()[i].get_rank()) << ">";
    }

    cout << endl;
    cout << endl;
    cout << "\t(DECK)";
    cout << endl;
    cout << endl;
    cout << "\tPlayer" << endl;

    cout <<"Books";
    for(int i = 0;i < player[1].get_n_books();i++){
        cout << "<" << map_rank(player[1].get_books()[i]) << ">";
    }
    cout << endl;
    cout << "Hand: ";
    int player_cards = player[1].get_hand().get_n_cards();
    for(int i = 0;i < player_cards;i++){
        cout << "<" << map_rank(player[1].get_hand().get_cards()[i].get_rank()) << ">";
    }
    cout << endl;
    cout << "   ";
    for(int i = 0;i < player_cards;i++){
        if(map_rank(player[1].get_hand().get_cards()[i].get_rank()) == "10"){
            cout << "  " << i << " ";
        }
        else{
            if(i > 9){
                cout << " " << i << " ";
            }
            else{
                cout << "  " << i << " ";
            }
        }
    }
    cout << endl;
    cout << "___________________________________________________________________" << endl;
}

int Game::check_input(string question, string valid){
    string var_str;
    size_t found;

    do{
        cout << question << endl;
        cin >> var_str;
        found = var_str.find_first_not_of(valid);
    }while(found != string::npos && var_str.length() < 3);

    return stoi(var_str);
}

int Game::check_choose(){
    if(player[1].get_hand().get_n_cards() < 1){
        cout << "You draw a card ";
        player[1].get_hand().add_card(d.draw_card());
        game_screen();
    }
    int index = -1;
    index = check_input("Enter the index of the card you wish to request: ", "0123456789");
    int rank = player[1].get_hand().get_cards()[index].get_rank();
    cout << "You ask for a: " << map_rank(rank) << endl;

    if(player[0].get_hand().get_n_cards() < 1){
        cout << "You draw a card ";
        player[1].get_hand().add_card(d.draw_card());
        game_screen();
    }

    return rank;
}

int Game::check_rank(){
    if(player[0].get_hand().get_n_cards() < 1){
        cout << "Computer draws a card ";
        player[0].get_hand().add_card(d.draw_card());
        game_screen();
    }
    srand(time(NULL));
    int rank_com = rand() % player[0].get_hand().get_n_cards();
    int rank = player[0].get_hand().get_cards()[rank_com].get_rank();
    cout << "Computer asks for a: " << map_rank(rank) << endl;

    if(player[1].get_hand().get_n_cards() < 1){
        cout << "Computer draws a card. ";
        player[0].get_hand().add_card(d.draw_card());
        game_screen();
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
        cout << "Computer give you" << count << ": " << map_rank(rank) << endl;
    }

    game_screen();

    if(player[1].get_hand().checkbook(rank)){
        cout << "You got a book" << endl;
        player[1].removebook(rank);

        game_screen();
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
        cout << "You give Computer " << count << ": " << map_rank(rank) << endl;
    }

    game_screen();

    if(player[0].get_hand().checkbook(rank)){
        cout << "Computer got a book" << endl;
        player[0].removebook(rank);
    }
}

void Game::player_fish(int rank, bool& myturn){
    cout << "Go fish." << endl;
    Card c = d.draw_card();
    int rank_draw = c.get_rank();
    cout << "You draw a: " << map_rank(rank_draw) << endl;
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
        cout << "\tcomputer's turn\t" << endl;
        myturn != myturn;
    }
}

void Game::com_fish(int rank, bool &comturn){
    cout << "Go fish" << endl;
    Card c = d.draw_card();
    int rank_draw = c.get_rank();
    cout << "Computer draws a: " << map_rank(rank_draw) << endl;
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
        cout << "\t your turn\t" << endl;
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
        }
        game_over();
    }
}

void Game::com_turn(){
    game_screen();
    bool comturn = true;
    while(comturn && !gameover){
        int rank = check_choose();
        if(player[1].get_hand().verify(rank)){
            player_to_computer(rank);
        }
        else{
            com_fish(rank,comturn);
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
    if(player[0].get_n_books() > player[1].get_n_books()){
        cout << "Computer win" << endl;
    }
    else{
        cout << "Player win" << endl;
    }

}
