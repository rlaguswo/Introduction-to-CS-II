/************************************************************************************************
 * Program: monkey.h
 * Author: Hyunjae Kim
 * Date: 08/02/2020
 * Description: This is a header file of the monkey class which is inherited from animal class.
 * *********************************************************************************************/

#ifndef MONKEY_H
#define MONKEY_H

#include "animal.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Monkey: public Animal{
private:
    int cost;
public:
    Monkey();
    bool define_baby();
    int get_cost();
};
#endif