


#include "game.h"



using namespace std;

/*void distribute_card(Deck& d,Player& p1,Player& p2){
    for(int i = 0;i < 7;i++){
        Card c = d.draw_card();
        p1.add_card_to_hand(c);
        Card c2 = d.draw_card();
        p2.add_card_to_hand(c2);
    }
}*/
int main(int argc,char** argv){
    int again = 1;
	// string a = argv[1];
	 //if(a == "true"){
    	while(again == 1){
      	  Game game;
        	  game.start_game();
        	  again = game.check_input("Enter 1 to play again or 2 to exist: ", "12");
   	 }
	// }
    return 0;
}
/*
 Deck d1;
    d1.set_n_cards(52);
    d1.fill_deck();
    d1.deck_shuffle();
    d1.print_deck();

    cout << endl;

    Card c[52];
    for(int i = 0;i < 52;++i){
        c[i] = d1.draw_card();
        c[i].print_card();
    }

    cout << endl;

    Player p1, p2;
    p1 = p2; // AOO

    Player p3 = p1; // CC

    Card c1 = d1.draw_card();

    p1.add_card_to_hand(c1);
    p1.print_card_in_hand(c1);
    */
