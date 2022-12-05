#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector
   int input = 0;
   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);

 

   cout << "Enter a number: ";
   cin >> input;
   cout << endl;

   for(int i = 0;i < input;i++){
      stdv.push_back(i);
      v.push_back(i);
   }
   
  //Copy constructor
   vector<int> v1 = v;
   
   //AOO 
   vector<int> v2;
   v2 = v1;

   cout << "Our vector size: " << v.size() << endl;
   cout << "Our vecotr capacity: " << v.capacity() << endl;
   cout << "Our vecotr reserve: " << v.reserve() << endl;
   cout << endl;
   
   cout << "Our vector1 size: " << v1.size() << endl;
   cout << "Our vecotr1 capacity: " << v1.capacity() << endl;
    cout << "Our vecotr1 reserve: " << v1.reserve() << endl;
   cout << endl;
   
   cout << "Our vector2 size: " << v2.size() << endl;
   cout << "Our vecotr2 capacity: " << v2.capacity() << endl;
     cout << "Our vecotr2 reserve: " << v2.reserve() << endl;
   cout << endl;
   
   cout << "STL vector size: " << stdv.size() << endl;
   cout << "STL vector capacity: " << stdv.capacity() << endl;
   return 0;
}

