/***************************************************************************************
 * Program: catalog.cpp
 * Author: Hyunjae Kim
 * Description: This program contains all fuction defintions except the main function.
 * *************************************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

#include "catalog.h"

/***********************************************************
 * Function: create_wizard
 * Description: This function creates the heap of wizard
 * ********************************************************/
wizard* create_wizards(int a){
	wizard* W = new wizard[a];
	return W;
}

/*****************************************************************************************
 * Function: populate_wizard_data
 * Description: This function fills the wizard struct with the information from text file
 * **************************************************************************************/
void populate_wizard_data(wizard* w,int a,ifstream& f){
	for(int i = 0;i < a;i++){
		f >> w[i].name >> w[i].id >> w[i].password >> w[i].position_title >> w[i].beard_length;
	}
}


/********************************************************
 * Function: create_spells
 * Description:This function creates the heap of spell
 * ****************************************************/
spell* create_spells(int a){
	spell* s = new spell[a];
	return s;
}

/***************************************************************************************
 * Function: populate_spell_data
 * Description:This function fills the spell struct with the information from text file
 * *************************************************************************************/
void populate_spell_data(spell* s,int a,ifstream& f){
	for(int i = 0;i < a;i++){
		f >> s[i].name >> s[i].success_rate >> s[i].effect;
	}
}

/*****************************************************************
 * Function: create_spellbooks
 * Description:This function creates the heap of spellbook
 * **************************************************************/
spellbook* create_spellbooks(int a){
	spellbook* SB = new spellbook[a];
	return SB;
}

/*******************************************************************************************
 * Function: populate_spellbook_data
 * Description: This function fills the spellbook struct with the information from text file
 * *****************************************************************************************/
void populate_spellbook_data(spellbook* sb,int a,ifstream& f){
	for(int i = 0;i < a;i++){
		f >> sb[i].title >> sb[i].author >> sb[i].num_pages >> sb[i].edition >> sb[i].num_spells;
		sb[i].s = create_spells(sb[i].num_spells);// create the array of spell pointer
		populate_spell_data(sb[i].s,sb[i].num_spells,f);//fill the spell pointer
	}

}

/****************************************************************
 * Function: swap_spellbook
 * Description: This function swap the value of spellbook array
 * *******************************************************************/
void swap_spellbook(spellbook& a,spellbook& b){
	spellbook tmp = a;
	a = b;
	b = tmp;
}

/*****************************************************************************
 * Function: swap
 * Description: This function swaps the interger value of element of array
 * ***************************************************************************/
void swap(int& a,int& b){
	int tmp = a;
	a = b;
	b = tmp;  					  
}

/*****************************************************************************
 * Function: swap_float
 * Description:This function swaps the float value of element of array.
 * **************************************************************************/
void swap_float(float& a,float& b){
	float tmp = a;
	a = b;
	b = tmp;
}

/*****************************************************************************
 * Function: swap_string
 * Description: This function swap the string.
 * ***************************************************************************/
void swap_string(string& a,string& b){
	string tmp = a;
	a = b;
	b = tmp;
}


/********************************************************************************************
 * Function: print_message
 * Description:This function prints out the struct of wizard when the id and pw are valid.
 * *****************************************************************************************/
void print_message(wizard* w,int& n){

		cout << "Welcome " << w[n].name << endl 
		<< "ID: " << w[n].id << endl << "Status: "<< w[n].position_title << endl
		<< "Beard Length: " << w[n].beard_length << endl;

}

/******************************************************************************
 * Function: print_error
 * Description: This function prints out message when the id or pw is invalid.
 * ****************************************************************************/
void print_error(int& n){
	if(n == -1){
	cout << "Incorrect id or password." << endl;
	}
}

/*************************************************************
 * Function: ask_id_pw
 * Description: This function asks the user to enter id and pw
 * ***********************************************************/
void ask_id_pw(string& a,string& b){

	cout << "Please enter your id: ";
	cin >> a;
	cout << "Please enter your password: ";
	cin >> b;
}


/**************************************************************************
 * Function: detect_id_pw
 * Description:This function detect id input if the id has any character
 * *************************************************************************/
void detect_id_pw(wizard* w,int a,string& b,string& c,int& n){
	for(int i = 0;i <= b.length();i++){
		if(isdigit(b[i]) == 0){
			n = -1;
		}

		
		} 
			}	
		
/**************************************************************************
 * Function: login
 * Description: This function checks the user's input id and pw is valid.
 * 				 Also the function counts how much the user fails the login.
 * ************************************************************************/
void login(wizard* w,int a,int& n,string& b,string& c,int& e){	
	int f = 1;
	while(e < 3 || f > 0){
		ask_id_pw(b,c);
		detect_id_pw(w,a,b,c,n);	
		for(int i = 0;i < a;i++){
			if(atoi(b.c_str()) == w[i].id){
				if(c == w[i].password){
					n = i;
					print_message(w,n);
					}
			}	
		}
	print_error(n);
	if(n== -1){
	 	++e;
		}
	else if(n != -1){
		f = 0;
		}
	if(f==0||e == 3)
		break;
		}	
}








/*******************************************************************************************
 * Function name: ask_information_display
 * Desciption: This function asks the user to choose the way of displaying information.
 * *****************************************************************************************/
void ask_information_display(int& a,spellbook* s,int b){
	cout << "How would you like the information displayed?" << endl
	<< "1. Print to screen (Press 1) " << endl << "2. Print to file (Press 2)" << endl << "Your choice: ";
	cin >> a;
}


/******************************************************************************************************
 * Function: print_spellbooks
 * Description: This prints out the title and the pages of spellbook.
 * ****************************************************************************************************/
void print_spellbooks(spellbook* s,int a){
	for(int i = 0;i< a;i++){
		cout << s[i].title << " " << s[i].num_pages << endl;
	}
}


/*******************************************************************************************
 * Function:hide_print1
 * Description: This function don't print spellbook which title is null and page is zero.
 * ****************************************************************************************/
void hide_print1(spellbook* sp,int a){
	for(int i = 0;i < a;i++){
		if(sp[i].num_pages == 0 && sp[i].title == " "){
			continue;
			}
		else{
			cout << sp[i].title << " " << sp[i].num_pages << endl;
			}
	}	
}


/*********************************************************************************************
 * Function: hide_file1
 * Description:This function don't append spellbook which page is 0 to the file.
 * ******************************************************************************************/
void hide_file1(spellbook* sp,int a,ofstream& f){
	for(int i = 0;i < a;i++){
		if(sp[i].num_pages == 0){
			f << endl;
		}
		else{
			f << sp[i].title << " " << sp[i].num_pages << endl;
		}
		
	}
}
/********************************************************
 * Function: sort_function
 * Description: This function sorts the spellbook
 * 					by pages in descending order.
 * ********************************************************/
void sort_function(spellbook* s,int a){
	for(int i = 1;i < a;i++){
		for(int j = 0;j < a-1;j++){
			if(s[j].num_pages < s[j+1].num_pages)
				swap_spellbook(s[j],s[j+1]);//swap spellbook
		}
	}

}

/********************************************************************
 * Function: hide_spellbooks
 * Description: This function makes  the spellbook which has poison or
 * 				 death spells to have null title and 0 page.when the 
 * 				 id is student id.
 * *****************************************************************/
void hide_spellbooks(spellbook* sp,int a,wizard* w,int& n){
	if(w[n].position_title == "Student"){
		for(int i = 0;i < a;i++){
			for(int j = 0;j < sp[i].num_spells;j++){
				if(sp[i].s[j].effect == "death" || sp[i].s[j].effect == "poison"){
					sp[i].title = " ";
					sp[i].num_pages = 0;
				}
			}
		}
	}
}

/********************************************************************
 * Function: file1
 * Description:This function contains functions which makes the user 
 * 				to append the information to file.
 * *****************************************************************/
void file1(spellbook* s,int a,int& b,wizard* w,int& n){
	string filename1;

	cout << "Please provide desired filename: ";
	cin >> filename1;
	
	ofstream f1;
	
	f1.open(filename1.c_str(),ios::app);
	
	if(!f1.is_open()){
		cout << "Error opening the file to write." << endl;
			cout << a << " " << b << endl;
		}
	
	if(w[n].position_title == "Student"){
		hide_file1(s,a,f1);
			}
	
	else{
		for(int i = 0;i < a;i++){
			f1 << s[i].title << " " << s[i].num_pages << endl;
				}
			}
	
	if(f1.is_open()){
		cout << "Appended requested information to file." << endl;
		}
	
	if(!f1.is_open()){
		cout << "Error" << endl;
		}
	
	f1.close();
}
/****************************************************************************
 * Function: sort_spellbooks_pages
 * Description: This Function prints out the result the user chosen, and 
 * 				offer the user how to handle the information.
 * ***************************************************************************/
void sort_spellbooks_pages(spellbook* s,int a, int& b,wizard* w,int& n){
	ask_information_display(b,s,a);
	
	sort_function(s,a);
	
	hide_spellbooks(s,a,w,n);
	
	if(b==1){
			if(w[n].position_title == "Student"){
				hide_print1(s,a);
			}
			else{
			print_spellbooks(s,a);
			}
		}
	
	else if(b == 2){
  		file1( s, a,b,w, n);
	}

}

/**********************************************************
 * Function: change_to_int
 * Description:This function returns integer value in order
 * 				to sort the spells by effect.
 * *********************************************************/
int change_to_int(string effect){
		if(effect == "memory_loss")return 1;
		else if(effect == "fire") return 2;
		else if(effect == "bubble")return 3;
		else if(effect == "poison")return 4;
		else if(effect == "death")return 5;
		else
			return 0;

}

/********************************************************
 * Function:print_spells
 * Description:This function prints the spell from array
 * *******************************************************/
void print_spells(string w[],string w2[]){	
	for(int i = 0;i < 28;i++){
		cout << w[i] <<" " <<w2[i] << endl;
	}
}

/***************************************************
 * Function: hide_print2
 * Dscription:This function doesn't print if both 
 * 			 elelment of array is null.
 * *************************************************/
void hide_print2(string w[],string w2[]){
	for(int i = 0;i < 28;i++){
		if(w[i] == " " && w2[i] == " "){
			continue;
		}
		else{
			cout << w[i] << " " << w2[i] << endl;
		}
	}

}

/*****************************************************************
 * Function: hide_file2
 * Description:This function doesn't append the information of the
 * 				element which is null.
 * ****************************************************************/
void hide_file2(string w[],string w2[],ofstream& f){
	for(int i = 0;i < 28;i++){
	if(w[i] == " " && w2[i] == " "){
		f << endl;
	}
	else{
		f << w[i] << " " << w2[i] << endl;
		}
	}	
}

/***********************************************************************************
 * Function:store_spells
 * Description: This function makes the spell array to be stored in string array.
 * ********************************************************************************/
void store_spells(spellbook* sp,int a,string w[],string w2[]){
		int h = 0;
		while(h < 28){
			for(int i = 0;i < a;i++){
				for(int j = 0;j < sp[i].num_spells;j++){
					w[h] = sp[i].s[j].effect;
					w2[h] = sp[i].s[j].name;
					h++;
				}
			}
		}
}

/*************************************************************************************
 * Function: sort_spells
 * Description:This swap the string array as a determined order.
 * ***********************************************************************************/
void sort_spells(string w1[],string w2[]){
	 for(int i = 1;i < 28;i++){
	 	for(int j = 0;j < 27;j ++ ){
			if(change_to_int(w1[j]) > change_to_int(w1[j+1])){
				swap_string(w1[j],w1[j+1]);
				swap_string(w2[j],w2[j+1]);
			
			
			}
		}
	}
}


/******************************************************************************
 * Function: hide_spells
 * Description: This function makes the element of the string array if it is 
 * 				a spell which effect is poison or death when the id is student id.
 * ****************************************************************************/
void hide_spells(wizard* w,int n, string w1[],string w2[]){
	if(w[n].position_title == "Student"){
		for(int i = 0;i < 28;i ++){
			if(w1[i] == "death" || w1[i] == "poison"){
				w1[i] = " ";
				w2[i] = " ";
		}
		}
	}
}

/**************************************************************************************************
 * Function: file2
 * Description: This function contains functions which makes the user to append the information
 * 				 to the file.
 * ************************************************************************************************/
void file2(spellbook* sp,int a,int& b,wizard* w,int& n,ofstream& f2,string w1[],string w2[]){
	if(!f2.is_open()){
			cout << "Error opening the file to write." << endl;
		}
	
		sort_spells(w1,w2);
		if(w[n].position_title == "Student")
			hide_file2(w1,w2,f2);
		else{
		for(int i = 0;i < 28;i++){
			f2 << w1[i] << " " << w2[i] << endl;
			}
		}
		
		if(f2.is_open()){
			cout << "Appended requested information to file." << endl;		
		}
		
		f2.close();
}

/*************************************************************************************
 * Function: group_spells_effect
 * Description: This function shows the result that the user chosen. 
 * 				 In this case, this function sorts spells by effect.
 * ***********************************************************************************/
void group_spells_effect(spellbook* sp,int a,int& b,wizard* w,int& n){
	string w1[29], w2[29];
	store_spells(sp,a,w1,w2);
	sort_spells(w1,w2);
	hide_spells(w,n,w1,w2);
	ask_information_display(b,sp,a);
	string filename2;
	if(b == 1){
		if(w[n].position_title == "Student")
			hide_print2(w1,w2);
		else
			print_spells(w1,w2);
	}
	if(b == 2){
		cout << "Please provide desired filename: ";
		cin >> filename2;
		ofstream f2;
		f2.open(filename2.c_str(),ios::app);
	 file2(sp, a, b, w,n, f2,w1, w2);
	}
}

/*********************************************************
 * Function: cal_average
 * Description: This function calculates the average
 * 				success rate of spellbook.
 * *******************************************************/
void cal_average(spellbook* s,int a){
	for(int i = 0;i < a;i++){
		for(int j = 0;j < s[i].num_spells;j++){
			s[i].avg_success_rate +=(s[i].s[j].success_rate)/s[i].num_spells;
		}
	}
}

/*************************************************************
 * Function:sort_rate
 * Description:This function sorting the spellbook by average
 * 				success rate in ascending order.
 * ***********************************************************/
void sort_rate(spellbook* s,int a){
	for(int i = 1;i < a;i++){
		for(int j = 0;j < a-1;j++){
			if(s[j].avg_success_rate > s[j+1].avg_success_rate)
				swap_spellbook(s[j],s[j+1]);
		}
	}

}

/*********************************************************
 * Function: hide_print3
 * Description:This function doesn't print the element of
 * 				average success rate array which is 0.
 * *****************************************************/
void hide_print3(spellbook* sp,int a){
	for(int i = 0;i < a;i++){
		if( sp[i].avg_success_rate == 0){
			continue;
		}
		else{
			cout << sp[i].title << " " << sp[i].avg_success_rate << endl;
		}
	}
}

/******************************************************
 * Function: hide_file3
 * Description:This function doesn't append the element 
 * 				of average success rate array which is 0
 * 				to the file.
 * ****************************************************/
void hide_file3(spellbook* sp,int a,ofstream& f){
	for(int i = 0;i < a;i++){
		if(sp[i].avg_success_rate == 0){
			f << endl;
		}
		else{
			f << sp[i].title << " " << sp[i].avg_success_rate << endl;
		}
	}
}

/****************************************************************
 *Function: hide_rate
 *Description: This function makes the makes the title null and 
 					page 0. when the id is student id.
 *****************************************************************/
void hide_rate(spellbook* sp,int a,wizard* w,int& n){
	if(w[n].position_title == "Student"){
		for(int i = 0;i < a;i ++ ){
			for(int j = 0;j < sp[i].num_spells;j++){
				if(sp[i].s[j].effect == "death" || sp[i].s[j].effect == "poison"){
					sp[i].title = "   ";
					sp[i].avg_success_rate = 0;
				}
			}
		}
	}
}

/*****************************************************************
 * Function:print_average
 * Description:This function prints the average success rate of 
 * 				spellbook.
 * ***************************************************************/
void print_average(spellbook* s,int a){
	for(int i = 0;i < a;i++){
		cout << s[i].title << " " << s[i].avg_success_rate << endl;
	}
}

/******************************************************************
 * Function: file3
 * Description: This function contains functions which make the user
 * 			to append information to the file.
 * ****************************************************************/
void file3(spellbook* s,int a,int& b,wizard* w,int& n){
		string filename3;
		cout << "Please provide desired filename: ";
		cin >> filename3;
		
		ofstream f3;
		f3.open(filename3.c_str(),ios::app);
		if(!f3.is_open()){
			cout << "Error opening the file to write!" << endl;
		}
		if(w[n].position_title == "Student")
			hide_file3(s,a,f3);
		else{
		for(int i = 0;i < a;i++){
			f3 << s[i].title << " " << s[i].avg_success_rate << endl;
		}
		}
		if(f3.is_open()){
		cout << "Appended requested information to file." << endl;
		}
		f3.close();



}

/***********************************************************************
 *Function: sort_average
 *Description: This function shows the result that the user chosen,
 				  In this case, it shows the average success rate of
				  spellbook.
 *********************************************************************/
void sort_average_rate(spellbook* s,int a,int& b,wizard* w,int& n){
	cal_average(s,a);
	sort_rate(s,a);
	hide_rate(s,a,w,n);
	ask_information_display(b,s,a);
	if(b == 1){
		if(w[n].position_title == "Student")
			hide_print3(s,a);
		else
			print_average(s,a);
			}
	
	else if(b == 2){
	 file3( s, a,b, w, n);
	}
}


/***************************************************************
 * Function: delete_data
 * Description: This function frees the heap of wizard and
 * 				the heap of spellbook.
 * *************************************************************/
void delete_data(wizard** w,int b,spellbook** s_arr,int a){
	delete [] *w;
	
	
	for(int i = 0;i < a;i++){
		delete [] (*s_arr)[i].s;
		(*s_arr)[i].s = NULL;
	}
	delete [] *s_arr;
	*s_arr = NULL;

}

/********************************************************************
 * Function: ask_choice
 * Description: This function asks user choices.
 * ******************************************************************/
void ask_choice(int& a,wizard* w,spellbook* s,int c,int& n){
	while(true){
	cout << "Which option would you like to choose?" << endl;
	cout << "1.Sort spellbooks by number of pages" << endl
	<< "2.Group spells by their effect" << endl
	<< "3.Sort spellbooks by average success rate" << endl
	<< "4.Quit" << endl << "Your Choice: ";
	cin >> a;
	if(a == 1)
		sort_spellbooks_pages(s,c,a,w,n);
	else if(a == 2)
		group_spells_effect(s,c,a,w,n);
	else if(a == 3)
		sort_average_rate(s,c,a,w,n);
	else if(a==4)
		break;
	}
}

/*************************************************************
 * Function: close_functions
 * Description:This functions close the files.
 * ***********************************************************/
void close_functions(ifstream& f1,ifstream& f2){
	f1.close();
	f2.close();
}

/************************************************************************
 * Function: populate_dats
 * Description: This function fill the wizard struct and the spellbook
 * 				 struct in the main function.
 * **********************************************************************/
void populate_datas(wizard* w,int a,spellbook* sp,int b,ifstream& f1,ifstream& f2){
	populate_wizard_data(w,a,f1);
	
	populate_spellbook_data(sp,b,f2);
}

/*****************************************************************************
 * Function: opening_functions
 * Description:This function opens two files in the main function.
 * ***************************************************************************/
void opening_functions(ifstream& f1,ifstream& f2,char* m,char* n){
	f1.open(m);
	f2.open(n);
}

