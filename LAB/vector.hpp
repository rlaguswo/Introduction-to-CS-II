#include <stdlib.h>
#include <stdexcept>
#include <iostream>

using std::cout;
using std::endl;
template <class T>
class vector {
   private:
      T *v;
      int s;
      int c;
   public:

      //vector constructor
      vector(){
	     s=0;
        c = 1;
	     v=NULL;
      }
	  //vector destructor
      ~vector(){
	     delete [] v;
      }
	  
     //vector copy construtor
     vector(vector& other){
       // std::cout << "Copy constructo called" << std::endl;
        this->s = other.s;
        this->c = other.c;
        this->v = new T[this->s];
        for(int i = 0;i < this->s;i++){
           this->v[i] = other.v[i];
        }
     }

     //vector AOO
     vector operator=(vector<T> &other){
        //std::cout << "Assignment operator called" <<std::endl;
        if(this != &other){
           this->s = other.s;
           this->c = other.c;
           if(this->v != NULL){
              delete [] v;
           }

           this->v = new T[s];
           for(int i = 0;i < s;i++){
              this->v[i] = other.v[i];
           }
        }
        return *this;
     }

      T operator[] (int element){
         return v[element];
      }

      T at(int address){
         try{
             if(address >= s){
               throw std::out_of_range("out of my vector bound");
            }
          else{
               return v[address];
            }
         }
         catch(std::out_of_range& e){
               cout << "Caought exception: " << e.what() << endl;
         }
        
      }


      int size() {
	     return s;
      }

      int capacity(){
         return c;
      }

      void resize(){
         if(s >c){
            T* tmp;
            c *=2;
            tmp = new T[c];
            for(int i = 0;i < c-1;i++){
               tmp[i] = v[i];
            }
            delete [] v;
            v = tmp;
         }
         else if(s == c){
            T*tmp1;
            c = s;
            tmp1 = new T[c];
            for(int i = 0;i < c-1;i++){
               tmp1[i] = v[i];
            }
            delete [] v;
            v = tmp1;
         }

      }

      int reserve(){
         return c-s;
      }


      void push_back(T ele) {
	     T *temp;
	     temp = new T[++s];
	     for(int i=0; i<s-1; i++)
	        temp[i]=v[i];

	     delete [] v;
	     v=temp;
	     v[s-1]=ele;
        resize();
      }
};
