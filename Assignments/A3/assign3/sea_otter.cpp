/************************************************************************************************
 * Program: sea_otter.cpp
 * Author: Hyunjae Kim
 * Date: 08/02/2020
 * Description: This is a cpp file of the sea otter class which is inherited from animal class.
 * *********************************************************************************************/

#include "sea_otter.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*****************************************************
 * Function: Sea_Otter()
 * description: This is sea otter class contructor.
 * ***************************************************/
Sea_Otter::Sea_Otter(){
    this->cost = 5000;
    this->name = "sea otter";
    this->age = 0;
}

/****************************************************
 * Function: get_cost()
 * description: This gets the cost of the sea otter.
 * **************************************************/
int Sea_Otter::get_cost(){
    return this->cost;
}