/************************************************************************************************
 * Program: monkey.cpp
 * Author: Hyunjae Kim
 * Date: 08/02/2020
 * Description: This is a cpp file of the monkey class which is inherited from animal class.
 * *********************************************************************************************/
#include "monkey.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*****************************************************
 * Function: Monkey()
 * description: This is monkey class contructor.
 * ***************************************************/
Monkey::Monkey(){
    this->cost = 15000;
    this->name = "monkey";
    this->age = 0;
}

/************************************************
 * Function: get_cost()
 * description: This gets the cost of the monkey
 * **********************************************/
int Monkey::get_cost(){
    return this->cost;
}
