/************************************************************************************************
 * Program: sea_otter.h
 * Author: Hyunjae Kim
 * Date: 08/02/2020
 * Description: This is a header file of the sea otter class which is inherited from animal class.
 * *********************************************************************************************/

#ifndef SEA_OTTER_H
#define SEA_OTTER_H

#include "animal.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sea_Otter: public Animal{
private:
    int cost;
public:
    Sea_Otter();
    int get_cost();
};
#endif