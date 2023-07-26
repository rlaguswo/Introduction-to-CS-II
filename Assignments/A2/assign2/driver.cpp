/***************************************************************************************************
 * Program: driver.cpp
 * Author: Hyunjae Kim
 * Date: 07/20/2020
 * Description: This program is a cpp file of the main function.
 * *************************************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "game.h"

using namespace std;

int main(int argc,char** argv){
    int again = 1,attempt = 1;
    string a = argv[1];
    if(a == "true"){
        

       while(again == 1 ){
            Game game;
            game.start_game();
            again = game.check_quit();
         }


    }
    if(a == "false"){
        while(again == 1){
            Game game;
            game.start_game2();
            again = game.check_quit();
         }
    }
    return 0;
}
