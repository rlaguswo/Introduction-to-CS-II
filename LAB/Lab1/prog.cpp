#include <iostream>
#include <cstdlib>
#include "multdiv.h"

using namespace std;

int main(int argc,char** argv){
	is_valid_dimensions(argv[1],argv[2]);

	int rows = atoi(argv[1]);
	int cols = atoi(argv[2]);

	multdiv_entry** Table = create_table(rows,cols);
	print_table(Table,rows,cols);
	delete_table(Table,rows);




return 0;
}
