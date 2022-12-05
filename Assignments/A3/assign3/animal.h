/***********************************************************************
 * Program: animal.h
 * Author: Hyunjae Kim
 * Date: 08/02/2020
 * Description: This is a header file of the class animal
 * **********************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal{
protected:
    string name;
    int age;
public:
    //Animal constructor
    Animal();

    //getters
    string get_name()const;
    int get_age()const;
    
    //setters
    void set_age(int);

    //pure virtual function
    virtual int get_cost()=0;

    //member function
    Animal& operator++();
};
#endif