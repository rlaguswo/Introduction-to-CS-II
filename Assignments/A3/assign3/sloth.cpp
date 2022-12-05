/************************************************************************************************
 * Program: sloth.cpp
 * Author: Hyunjae Kim
 * Date: 08/02/2020
 * Description: This is a cpp file of the sloth class which is inherited from animal class.
 * *********************************************************************************************/

#include "sloth.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*************************************************
 * Function: Sloth()
 * description: This is sloth class contructor.
 * ***********************************************/
Sloth::Sloth(){
    this->cost = 2500;
    this->name = "sloth";
    this->age = 0;
}

/************************************************
 * Function: get_cost()
 * description: This gets the cost of the sloth
 * **********************************************/
int Sloth::get_cost(){
    return this->cost;
}