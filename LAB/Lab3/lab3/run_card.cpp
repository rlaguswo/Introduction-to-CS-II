#include <iostream>
#include <string>

#include "card.h"

using namespace std;

int main(){
    Card c1;
    
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 13;j++){
            c1.set_suit(i);
            c1.set_rank(j);
            c1.print_card();
        }
        cout << endl;
    }

return 0;
}