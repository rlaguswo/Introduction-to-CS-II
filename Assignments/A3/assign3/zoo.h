/************************************************************************************************************************
 * Program: zoo.h
 * Author: Hyunjae Kim
 * Date: 08/02/2020
 * Description: This is a header file of the zoo class which has inherited classes from animal class and animal class.
 * *********************************************************************************************************************/
#ifndef ZOO_H
#define ZOO_H

#include "animal.h"
#include "monkey.h"
#include "sea_otter.h"
#include "sloth.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Zoo{
private:
    //animal vector
    vector <Animal*> animals; 
    
    //food cost
    int base_food_cost; 
    int base_food_cost2; 
    
    //counting
    int count;
    int count_monkey;
    int count_sea_otter;
    int count_sloth;
    int count_sell_animal;
    
    //time and age
    int month;
    
    //number of animal
    int num_monkey;
    int baby_monkey;
    int num_sea_otter;
    int num_sloth;
    
    //number of attendance and total animal
    int total_attendance;
    int total_animals;
    
    //money
    float revenue;
    float bank_account;
public:
    Zoo();
   ~Zoo();
    //getters
    float get_bank_account();
    int get_total_attendance();
    int get_total_animal();
    float get_monkey_revenue();
    float get_sea_otter_revenue();
    float get_sloth_revenue();
    float get_total_revenue();
    int get_count();
    
    
    //setters
    void set_count_specie(int,int,int);
    void set_count_sell_animal(int);
    void set_count(int);
    void set_base_food_cost2(int);
    
    //member function
    int ask_question();
   
    //get baby animals
    int get_monkey_baby();
    int get_sea_otter_baby();
    int get_sloth_baby();

    //feeding animals
    int feed_monkey();
    int feed_sea_otter();
    int feed_sloth();
    int feed_animals();

    //buy animals
    int ask_animals();
    void buy_monkey();
    void buy_sea_otter();
    void buy_sloth();
    void buy_animals(int&);

    //sell animals
    int ask_sell_animals();
    void sell_monkey();
    void sell_sea_otter();
    void sell_sloth();
    void sell_animals(int&);

    
    //go to next month
    void get_older();

    //special events
    void sick_animal();

    //get animal baby    
    void monkey_birth();
    void sea_otter_birth();
    void sloth_birth();

    
    void zoo_boom();
    
    //extra credit
    void game_win();
    
    //special events
    void special_events();
    void for_special_events();
    
    void delete_animals();
    
    void print_animals();
    int program_screen();
    void start_program();

};
#endif