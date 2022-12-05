/***************************************************
 * Program: catalog.h
 * Author: Hyunjae Kim
 * Date: 07/05/2020
 * Description: This is a header file. So it stores 
 * 					struct and function declaration.
 * *************************************************/




#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

struct wizard{
	string name;
	int id;
	string password;
	string position_title;
	float beard_length;
};

struct spellbook{
	string title;
	string author;
	int num_pages;
	int edition;
	int num_spells;
	float avg_success_rate;
	struct spell* s;
};

struct spell{
	string name;
	float success_rate;
	string effect;
};
#endif

wizard* create_wizards(int a);
void populate_wizard_data(wizard* w,int a,ifstream& f);
spell* create_spells(int a);
void populate_spell_data(spell* s,int a,ifstream& f);
spellbook* create_spellbooks(int a);
void populate_spellbook_data(spellbook* sb,int a,ifstream& f);
void swap_spellbook(spellbook& a,spellbook& b);
void swap(int& a,int& b);
void swap_float(float& a,float& b);
void swap_spell(spell& a,spell& b);
void swap_string(string& a,string& b);
void print_message(wizard* w,int& n);
void print_error(int& n);
void ask_id_pw(string& a,string& b);
void detect_id_pw(wizard* w,int a,string& b,string& c,int& n);
void login(wizard* w,int a,int& n,string& b,string& c,int& e);
void ask_infromation_display(int& a,spellbook* s,int b);
void print_spellbooks(spellbook* s,int a);
void hide_print1(spellbook* sp,int a);
void hide_file1(spellbook* sp,int a,ofstream& f);
void sort_function(spellbook* s,int a);
void hide_spellbooks(spellbook* sp,int a,wizard* w,int& n);
void file1(spellbook* s,int a,int& b,wizard* w,int& n);
void sort_spellbooks_pages(spellbook* s,int a,int& b,wizard* w,int& n);
int change_to_int(string effect);
void print_spells(string w[],string w2[]);
void hide_print2(string w[],string w2[]);
void hide_file2(string w[],string w2[],ofstream& f);
void store_spells(spellbook* sp,int a,string w[],string w2[]);
void sort_spells(string w1[],string w2[]);
void hide_spells(wizard* w,int n,string w1[],string w2[]);
void file2(spellbook* sp,int a,int& b,wizard* w,int& n,ofstream& f2,string w1[],string w2[]);
void group_spells_effect(spellbook* sp,int a,int& b,wizard* w,int& n);
void cal_average(spellbook* s,int a);
void sort_rate(spellbook* s,int a);
void hide_print3(spellbook* sp,int a);
void hide_file3(spellbook* sp,int a,ofstream& f);
void hide_rate(spellbook* sp,int a,wizard* w,int& n);
void print_average(spellbook* s,int a);
void file3(spellbook* s,int a,int& b,wizard* w,int& n);
void sort_average_rate(spellbook* s,int a,int& b,wizard* w,int& n);
void delete_data(wizard** w,int b,spellbook** s_arr,int a);
void ask_choice(int& a,wizard* w,spellbook* s,int c,int& n);
void close_functions(ifstream& f1,ifstream& f2);
void populate_datas(wizard* w,int a,spellbook* sp,int b,ifstream& f1,ifstream& f2);
void opening_functions(ifstream& f1,ifstream& f2,char* m,char* n);
