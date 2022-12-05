#include <iostream>

using namespace std;

struct multdiv_entry{
	int mult;
	float div;
};

bool is_valid_dimensions(char* m, char* n);
multdiv_entry** create_table(int row, int col);
void print_table(multdiv_entry** table, int row, int col);
void delete_table(multdiv_entry** table, int row);
