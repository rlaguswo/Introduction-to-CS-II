/************************************************************************************************
 * Program: sloth.h
 * Author: Hyunjae Kim
 * Date: 08/02/2020
 * Description: This is a header file of the sloth class which is inherited from animal class.
 * *********************************************************************************************/

#ifndef SLOTH_H
#define SLOTH_H

#include "animal.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sloth: public Animal{
private:
    int cost;
public:
    Sloth();
    int get_cost();
};
#endif