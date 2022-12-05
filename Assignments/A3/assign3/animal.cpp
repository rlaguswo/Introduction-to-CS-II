#include "animal.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Animal::Animal(){
	this->age = 0;
	this->name = "";
}

string Animal::get_name()const{
	return this->name;
}

int Animal::get_age()const{
	return this->age;
}

void Animal::set_age(int input){
	this->age = input;
}

Animal& Animal::operator++(){
	++this->age;
	return *this;
}
