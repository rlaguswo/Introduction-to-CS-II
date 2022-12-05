/************************************************************************************************************************
 * Program: zoo.cpp
 * Author: Hyunjae Kim
 * Date: 08/02/2020
 * Description: This is a cpp file of the zoo class which has inherited classes from animal class and animal class.
 * *********************************************************************************************************************/
#include "zoo.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//Zoo contructor
Zoo::Zoo(){
    
    this->base_food_cost = 100;
    this->base_food_cost2 = 0;
    this->count = 0;
    this->count_monkey = 0;
    this->count_sea_otter = 3;
    this->count_sea_otter = 5;
    this->count_sell_animal = 0;
    this->month = 0;
    this->bank_account = 50000;
    this->num_monkey = 0;
    this->baby_monkey = 0;
    this->num_sea_otter = 0;
    this->num_sloth = 0;
    this->total_animals = 0;
    this->total_attendance = 0;
    this->revenue = 0;
}

//Zoo destructor
Zoo::~Zoo(){
      for(int i = 0;i < animals.size();i++){
            
            delete animals[i];
            animals[i] = NULL;
            
        }
 
    
    animals.clear();
}

//gets the money in the bank account
float Zoo::get_bank_account(){
    return this->bank_account;
}

//it get the number of buying animal
int Zoo::get_count(){
    return this->count;
}

//it mutates the value of the count
void Zoo::set_count(int input){
    this->count = input;
}

//It sets the counting number of species.
void Zoo::set_count_specie(int input1,int input2,int input3){
    this->count_monkey = input1;
    this->count_sea_otter = input2;
    this->count_sloth = input3;
}

//it sets the number of selling animal
void Zoo::set_count_sell_animal(int input){
    this->count_sell_animal = input;
}

//it gets total attendance of the zoo
int Zoo::get_total_attendance(){
    if(this->month > 0){
        srand(time(NULL));   
        this->total_attendance = get_total_animal()*(rand()%51+50);
        return this->total_attendance;
    }
}

int Zoo::get_total_animal(){
    return this->total_animals;
}

void Zoo::set_base_food_cost2(int input){
    this->base_food_cost2 = input;
}
//get animal baby
/***********************************************************
 * Function: get_monkey_baby()
 * description: it gets the baby of the monkey
 * ********************************************************/
int Zoo::get_monkey_baby(){
    int monkey_baby = 0;
    for(int i = 0;i < animals.size();i++){
        if(animals[i]->get_name() == "monkey" && animals[i]->get_age() < 6){
                monkey_baby++;
        }
    }
    return monkey_baby;
}

/***********************************************************
 * Function: get_sea_otter_baby()
 * description: it gets the baby of the sae otter
 * ********************************************************/
int Zoo::get_sea_otter_baby(){
    int sea_otter_baby = 0;
    for(int i = 0;i < animals.size();i++){
        if(animals[i]->get_name() == "sea otter" && animals[i]->get_age() < 6){
            sea_otter_baby++;
        }
    }
    return sea_otter_baby;
}

/***********************************************************
 * Function: get_sloth_baby()
 * description: it gets the baby of the sloth
 * ********************************************************/
int Zoo::get_sloth_baby(){
    int sloth_baby = 0;
    for(int i = 0;i < animals.size();i++){
        if(animals[i]->get_name() == "sloth" && animals[i]->get_age() < 6){
            sloth_baby++;
        }
    }
    return sloth_baby;
}

//feeding animals

/***********************************************************
 * Function: feed_monkey()
 * description: it feeds monkeys in the zoo
 * ********************************************************/
int Zoo::feed_monkey(){
    srand(time(NULL));
    int feed_monkey_cost = 4*num_monkey*base_food_cost; 
    int feed_monkey_cost2 = 4*num_monkey*(rand()%51+75);
    for(int i = 0; i < animals.size();i++){
        if(animals[i]->get_name() == "monkey"){
            if(month == 1){ // when it is first month
                bank_account -= feed_monkey_cost;
                return feed_monkey_cost;
            }
            else if(month > 1){ //when it is after the first month
                bank_account -= feed_monkey_cost2;
                return feed_monkey_cost;
            }
        }
    }
}

/***********************************************************
 * Function: feed_sea_otter()
 * description: it feeds sea otters in the zoo
 * ********************************************************/
int Zoo::feed_sea_otter(){
    srand(time(NULL));
    int feed_sea_otter_cost = 2* num_sea_otter * base_food_cost;
    int feed_sea_otter_cost2 = 2* num_sea_otter* (rand()%51+75);
    for(int i = 0;i < animals.size();i++){
        if(animals[i]->get_name() == "sea otter"){ 
            if(month == 1){
                bank_account -= feed_sea_otter_cost;
                return feed_sea_otter_cost;
            }
            else if(month > 1){
                bank_account -= feed_sea_otter_cost2;
                return feed_sea_otter_cost2;
            }
        }
    }
}

/***********************************************************
 * Function: feed_sloth()
 * description: it feeds sloths in the zoo
 * ********************************************************/
int Zoo::feed_sloth(){
    srand(time(NULL));
    int feed_sloth_cost = num_sloth * base_food_cost;
    int feed_sloth_cost2 = num_sloth* (rand()%51+75);
    for(int i = 0;i < animals.size();i++){
        if(animals[i]->get_name() == "sloth"){
            if(month == 1){
                bank_account -= feed_sloth_cost;
                return feed_sloth_cost;
            }
            else if(month > 1){
                bank_account -= feed_sloth_cost2;
                return feed_sloth_cost2;
            }
        }
    }
}

/*****************************************************************
 * Function: feed_animals()
 * description: This gets the cost of feeding animals in the zoo. 
 * ***************************************************************/
int Zoo::feed_animals(){
    int total_cost = feed_monkey() + feed_sea_otter() + feed_sloth();
    return total_cost;
}


/************************************************************************
 * Function: get_monkey_revenue()
 * description: This gets the revenue which monkeys earned in the zoo. 
 * ***********************************************************************/
float Zoo::get_monkey_revenue(){
    float monkey_revenue = 2*(num_monkey + get_monkey_baby())*get_total_attendance();
    return monkey_revenue;
}


/************************************************************************
 * Function: get_sea_otter_revenue()
 * description: This gets the revenue which sea otters earned in the zoo. 
 * ***********************************************************************/
float Zoo::get_sea_otter_revenue(){
    float sea_otter_revenue = (num_sea_otter + get_sea_otter_baby()) * get_total_attendance()/(2.0);
    return sea_otter_revenue;
}


/************************************************************************
 * Function: get_sloth_revenue()
 * description: This gets the revenue which sloths earned in the zoo. 
 * ***********************************************************************/
float Zoo::get_sloth_revenue(){
    float sloth_revenue = (num_sloth + get_sloth_baby())* get_total_attendance()/(2.0);
    return sloth_revenue;
}


/************************************************************************
 * Function: get_total_revenue()
 * description: This gets the total revenue which animals earned in the zoo. 
 * ***********************************************************************/
float Zoo::get_total_revenue(){
    this->revenue = get_monkey_revenue() + get_sea_otter_revenue() + get_sloth_revenue();
    bank_account += this->revenue;
    return this->revenue;
}


//member function
/***********************************************************
 * Function: ask_question()
 * description: it asks the user's choice 
 * ********************************************************/
int Zoo::ask_question(){
    int a;
    cout << "Your choice is: ";
    cin >> a;
    return a;
}

//buy animals
/***********************************************************
 * Function: ask_animal()
 * description: it asks the user to choose the specie of the animal
 * ********************************************************/
int Zoo::ask_animals(){
    int buy_choice;
    cout << "What animal you want to buy?" << endl;
    cout << "1.Monkey 2.Sea Otter 3.Sloth 4.Quit" << endl;
    cout << "Your choice is: ";
    cin >> buy_choice;
    return buy_choice;
}

/***********************************************************
 * Function: buy_monkey()
 * description: This buys adult monkey
 * ********************************************************/
void Zoo::buy_monkey(){
    animals.push_back(new Monkey());
    animals[animals.size()-1]->set_age(24);
    num_monkey++;
    total_animals++;
    bank_account -= animals[animals.size()-1]->get_cost();
    count++;
    count_monkey++;

}

/***********************************************************
 * Function: buy_sea_otter()
 * description: This buys adult sea otter
 * ********************************************************/
void Zoo::buy_sea_otter(){
    animals.push_back(new Sea_Otter());
    animals[animals.size()-1]->set_age(24);
    num_sea_otter++;
    total_animals++;
    bank_account -= 5000;
    count++;
    count_sea_otter++;
  
}

/***********************************************************
 * Function: buy_sloth()
 * description: This buys adult sloth
 * ********************************************************/
void Zoo::buy_sloth(){
    animals.push_back(new Sloth());
    animals[animals.size()-1]->set_age(24);
    num_sloth++;
    total_animals++;
    bank_account -= 2500;
    count++;
    count_sloth++;
   
}

/***********************************************************
 * Function: buy_animals(int& choice)
 * description: It can buy animal by the user's choice
 * ********************************************************/
void Zoo::buy_animals(int& choice){
    if(choice == 1){buy_monkey();}
    else if(choice == 2){buy_sea_otter();}
    else if(choice == 3){buy_sloth();}
    else if(choice == 4){
        cout << "Not buying animal!" << endl;
    }
   
}

//sell animals
/******************************************************************************
 * Function: ask_sell_animals()
 * description: This asks the user to choose the specie of the animal to sell.
 * ****************************************************************************/
int Zoo::ask_sell_animals(){
    int sell_choice;
    cout << "What animal you want to sell?" << endl;
    cout << "1.Monkey 2.Sea Otter 3.Sloth 4.Quit" << endl;
    cout << "Your choice is: ";
    cin >> sell_choice;
    return sell_choice;
}

/***********************************************************
 * Function: sell_monkey()
 * description: This sells monkey in the zoo.
 * ********************************************************/
void Zoo::sell_monkey(){
    int sell_monkey;
    if(num_monkey > 0){
        for(int i = 0;i < animals.size();i++){
            if(animals[i]->get_name() == "monkey"){
                sell_monkey = i;
            }
        }
        if(animals[sell_monkey]->get_age() < 6){baby_monkey--;}
        num_monkey--;
        total_animals--;
        bank_account += (animals[sell_monkey]->get_cost())/2;
        count_sell_animal++;
        //animals.erase(animals.begin()+sell_monkey);
        //delete animals[sell_monkey];
    }
    else{
        cout << "You can't sell monkey!" << endl;
    }
}


/***********************************************************
 * Function: sell_sea_otter()
 * description: This sells sea otter in the zoo.
 * ********************************************************/
void Zoo::sell_sea_otter(){
    int sell_sea_otter;
    if(num_sea_otter > 0){
        for(int i = 0;i < animals.size();i++){
            if(animals[i]->get_name() == "sea otter"){
                sell_sea_otter = i;
            }
        }
        num_sea_otter--;
        total_animals--;
        bank_account += (animals[sell_sea_otter]->get_cost())/2;
        count_sell_animal++;
       //animals.erase(animals.begin()+sell_sea_otter);
        //delete animals[sell_sea_otter];
    }
    else{
        cout << "You can't sell sea otter!" << endl;
    }
}


/***********************************************************
 * Function: sell_sloth()
 * description: This sells sloth in the zoo.
 * ********************************************************/
void Zoo::sell_sloth(){
    int sell_sloth;
    if(num_sloth > 0){
        for(int i = 0;i < animals.size();i++){
            if(animals[i]->get_name() == "sloth"){
                sell_sloth = i;
            }
        }
        int baby_sloth = get_sloth_baby();
        num_sloth--;
        total_animals--;
        bank_account += (animals[sell_sloth]->get_cost())/2;
        count_sell_animal++;
        //animals.erase(animals.begin()+sell_sloth);
        //delete animals[sell_sloth];
    }
    else{
        cout << "You can't sell sloth!" << endl;
    }
}


/****************************************************************************
 * Function: sell_animals(int& choice)
 * description: This sells animals in the zoo dependin on the user's choice.
 * **************************************************************************/
void Zoo::sell_animals(int& choice){
    if(choice == 1){sell_monkey();}
    else if(choice == 2){sell_sea_otter();}
    else if(choice == 3){sell_sloth();}
    else if(choice == 4){
        cout << "Not selling animal!" << endl;
    }
}


/****************************************************************
 * Function: get_older()
 * description: This increments ages of all animals by 1 month.
 * *************************************************************/
void Zoo::get_older(){
    for(int i = 0;i < animals.size();i++){
        animals[i]->operator++();
    }
}


/*****************************************************************
 * Function: sick_animal()
 * description: This makes animal sick and cure the animal.
 *              The cost will be deducted from the bank account.
 * ***************************************************************/
void Zoo::sick_animal(){
    if(total_animals > 0){
        srand(time(NULL));
        int random_animal = rand()%animals.size();
        bank_account -= animals[random_animal]->get_cost()/2;
        cout << "\e[5mYour animal got sick. But your animal is cured.\e[0m" << endl;
        if(bank_account < animals[random_animal]->get_cost()/2){
            cout << "\e[5mYour animal is dead\e[0m" << endl;
            total_animals--;
            if(animals[random_animal]->get_name() == "monkey"){
                num_monkey--;
            }
            else if(animals[random_animal]->get_name() == "sea otter"){
                num_sea_otter--;
            }
            else if(animals[random_animal]->get_name() == "sloth"){
                num_sloth--;
            }
        }
    }
}


/***********************************************************
 * Function: monkey_birth()
 * description: This makes one baby monkey in the zoo.
 * ********************************************************/
void Zoo::monkey_birth(){
    for(int i = 0;i < animals.size();i++){
        if(animals[i]->get_name() == "monkey" && animals[i]->get_age() > 6){
            animals.push_back(new Monkey());
            baby_monkey++;
            num_monkey++;
            total_animals++;
            cout << "\e[5mYou got a monkey baby\e[0m" << endl;
            break;
        }
        else{
            break;
        }
    }
}

/***********************************************************
 * Function: sea_otter_birth()
 * description: This makes 2 sea otter babies in the zoo. 
 * ********************************************************/
void Zoo::sea_otter_birth(){
    for(int i = 0;i < animals.size();i++){
        if(animals[i]->get_name() == "sea otter" && animals[i]->get_age() > 6){
            for(int j = 0;j < 2;j++){
                animals.push_back(new Sea_Otter());
                num_sea_otter++;
                total_animals++;
            }
            cout << "\e[5mYou got 2 sea otter babies\e[0m" << endl;
            break;
        
        }
        else{
            break;
        }
    }
}


/***********************************************************
 * Function: sloth_birth()
 * description: This makes 4 sloth babies in the zoo. 
 * ********************************************************/
void Zoo::sloth_birth(){
    for(int i = 0;i < animals.size();i++){
        if(animals[i]->get_name() == "sloth" && animals[i]->get_age() > 6){
            for(int j = 0;j < 4;j++){
               animals.push_back(new Sloth());
                num_sloth++;
                total_animals++;
            
            }
            cout << "\e[5mYou got 4 sloth babies\e[0m" << endl;
            break;
        }
        else{
            break;
        }
    }
    
}

/*****************************************************************************************************************
 * Function: zoo_boom()
 * description: This makes the boom which the total attendance and the cost of the food are doubled in the zoo
 * **************************************************************************************************************/
void Zoo::zoo_boom(){
    if(total_animals > 0){
        total_attendance *= 2;
        int double_cost = 2*(rand()%51+75);
        set_base_food_cost2(double_cost);
        cout << "\e[5mBoom Occured!\e[0m" << endl;
    }
}

//extra credit
/***************************************************************************************************************************************
 * Function: game_win()
 * description: This informs the user that the user is the winner of the program when there is more than $500000 in the bank account.
 *              The user can choose to continue the program or not.
 * *************************************************************************************************************************************/
void Zoo::game_win(){
    
    if(bank_account > 500000){
        cout << "\e[5m\e[92mYou won the game!\e[0m\e[0m" << endl;
    }

}

/***********************************************************
 * Function: special_event()
 * description: This randomly activates the special events.
 * ********************************************************/
void Zoo::special_events(){
    srand(time(NULL));
    int random = rand()%6;
    switch(random){
        case 0: monkey_birth();
            break;
        case 1: sea_otter_birth();
            break;
        case 2: sloth_birth();
            break;
        case 3: sick_animal();
            break;
        case 4: zoo_boom();
            break;
        case 5: // nothing happens in the zoo. 
            break;
        default:
            break;
    }
}

/***********************************************************
 * Function: for_special_event()
 * description: This activate special event function 
 *              after the first month.
 * ********************************************************/
void Zoo::for_special_events(){
    if(this->month > 0)
        special_events();
}

/***********************************************************
 * Function: print_animals()
 * description: This prints animals in the zoo. 
 * ********************************************************/
void Zoo::print_animals(){
    int baby_monkey = get_monkey_baby();
    cout << "Monkey: Adult: " << num_monkey-baby_monkey << " Baby: " << baby_monkey << endl;
    cout << "Sea Otter: Adult: " << num_sea_otter-get_sea_otter_baby() << " Baby: " << get_sea_otter_baby() << endl;
    cout << "Sloth: Adult: " << num_sloth-get_sloth_baby() << " Baby: " << get_sloth_baby() << endl;
}


/***********************************************************
 * Function: program_screen()
 * description: This is the screen of the zoo tycoon. 
 *              It reflects the changes in the zoo.
 * ********************************************************/
int Zoo::program_screen(){
    Monkey m1;
    Sea_Otter s1;
    Sloth sloth;
    cout << "________________________________________________________________________________________" << endl;
    game_win();
    cout << "Bank account: $" << bank_account << endl;
    cout << "Total Animals: " << get_total_animal() << "   " << "Total Attendance: " << get_total_attendance() << endl;
    print_animals();
    cout << "Month: " << month << endl;
    cout << "Revenue: $" << get_total_revenue() << endl;
    cout << "Monkey: $" << m1.get_cost() << " Sea Otter: $" << s1.get_cost() << " Sloth: $" << sloth.get_cost() << endl;
    cout << "Cost for feeding: $" << feed_animals() << endl;
    cout << "What do you want to choose?" << endl;
    cout <<"1. Buy animals 2.Sell animals 3.GOTO next month 4.Quit" << endl;
    int choice = ask_question();
    //when there is no money in the bank account
    if(bank_account < 0){
        cout << "\e[5m\e[95mBankrupt! Game Over!\e[0m\e[0m"<< endl;
        return 4;
    }

    if(choice == 1){
        if(count < 2){
            if(count_monkey <=1 || count_sea_otter <= 1 || count_sloth <= 1){
            
                int choice1_1 = ask_animals();
                buy_animals(choice1_1);
            }
                
        }
        else{
            cout << "You can't buy animals!" << endl;
        }
       
    }

    else if(choice == 2){
       if(count_sell_animal <1){
        int choice1_2 = ask_sell_animals();
        sell_animals(choice1_2);
       }
       else{cout << "You can't sell animal!" << endl;}
    }
    
    else if(choice == 3){
        this->month++;
        get_older();
        feed_animals();
        set_count(0);
        set_count_specie(0,3,5);
        set_count_sell_animal(0);
        special_events();
    }

    else if(choice == 4){
        return choice;
    }
} 

/*******************************************************************************************************
 * Function: start_program()
 * description: This makes the program able to iterate the zoo tycoon until the user quits the program.
 * *****************************************************************************************************/
void Zoo::start_program(){
  int quit_choice = 0;
  
  while(quit_choice != 4){
      quit_choice = program_screen();
  }
}