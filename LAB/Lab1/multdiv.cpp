#include <iostream>
#include <cstdlib>

#include "multdiv.h"

using namespace std;

/*struct multdiv_entry{
	int mult;
	float div;
};

*/
bool is_valid_dimensions(char* m,char* n){
	while(atoi(m) <= 0 || atoi(n) <= 0){
		cout << "Invalid Size(s)!!!" << endl;
		cout << "Enter an integer greater than 0 and for row: ";
		cin >> m;
		cout << "Enter an integer greater than 0 and for col: ";
		cin >> n;
	}
	
return true;   
}

multdiv_entry** create_table(int row,int col){
	multdiv_entry** table = NULL;
	table = new multdiv_entry*[row];
	for(int x = 0;x < row;x++)
		table[x] = new multdiv_entry[col];
	for(int i = 0;i < row;i++){
		for(int j = 0;j < col;j++){
			table[i][j].mult = (i+1)*(j+1);
			table[i][j].div = (i+1.0)/(j+1.0);
		}
	}
return table;
}

void print_table(multdiv_entry** tables,int row, int col){
	
	cout << "Multiplication Table: " << endl;
	for(int i =0;i < row;i++){
		for(int j = 0;j < col;j++){
			cout << tables[i][j].mult << "\t";
		}
	cout << endl;
	}
	cout << endl;
	cout << "Division Table: " << endl;
	for(int x = 0;x < row;x++){
		for(int y = 0;y < col;y++){
			cout << tables[x][y].div << "\t";
		}
		cout << endl;
	}

}

void delete_table(multdiv_entry** tables,int row){
	for(int i = 0;i < row;i++){
		delete [] tables[i];
		tables[i] = NULL;	
	}
	delete [] tables;
	tables = NULL;
}

/*int main(int argc, char** argv){

	is_valid_dimensions(argv[1],argv[2]);

	int rows = atoi(argv[1]);
	int cols = atoi(argv[2]);


	multdiv_entry** Table = create_table(rows,cols);
	print_table(Table,rows,cols);
	delete_table(Table,rows);

return 0; 
}*/
