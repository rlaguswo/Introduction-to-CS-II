/**********************************************************
 * Program: run_wizard.cpp
 * Author: Hyunjae Kim
 * Date: 07/05/2020
 * Description: This program is a driver file of Makefile. 
 * 				 It contains the main function.
 * *******************************************************/




#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

#include "catalog.h"

int main(int argc,char** argv){
	ifstream f1,f2;
	int a = 0,num = -1,attempt = 0;
	
	opening_functions(f1,f2,argv[1],argv[2]);
	if(!f1.is_open() || !f2.is_open()){ // send message and terminate
		cout << "Error opening the file to read!" << endl;
		return 1;
	}

	string str1,str2,ID,PW;
	
	/*when I used this function in one file,it worked well,
	 * but when I seperated the file it made error.
	 * so I have to use several lines of commands, and it made 
	 * the main function over 15 lines.
		getlines(str1,str2,f1,f2,num_of_wizards,num_of_spellbooks);*/
	
	
	getline(f1,str1);
	getline(f2,str2);

	int num_of_wizards = atoi(str1.c_str());
	int num_of_spellbooks = atoi(str2.c_str());

	wizard* wiz_arr = create_wizards(num_of_wizards);//create the heap
	spellbook* sp = create_spellbooks(num_of_spellbooks);//create the heap

	populate_datas(wiz_arr,num_of_wizards,sp,num_of_spellbooks,f1,f2);// filling both wizard struct and spellbook struct.

	login(wiz_arr,num_of_wizards,num,ID,PW,attempt);
	if(attempt == 3){ // fail to login over three times
		delete_data(&wiz_arr,num_of_wizards,&sp,num_of_spellbooks);//free the heap
		return 1;
	}
	ask_choice(a,wiz_arr,sp,num_of_spellbooks,num); // give choices when the user login the program.

	delete_data(&wiz_arr,num_of_wizards,&sp,num_of_spellbooks);
	close_functions(f1,f2);

return 0;
}
