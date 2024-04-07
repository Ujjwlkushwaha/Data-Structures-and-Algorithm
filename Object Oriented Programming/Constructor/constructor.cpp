#include <iostream>
using namespace std;

// here we learn about constructors...........
class constructor{
   int a,b;

   public:
      // normal constructor
      constructor(){
        a = 0;
        b = 0;
      }
     // Parameterized Constructor
      constructor(int x,int y){
        a = x;
        b = y;        
      }
    // Cpoy Construtor
      constructor(constructor &obj){
        a = obj.a;
        b = obj.b;
      }
};
int main() {
	
	// ye automatically default constructor ko call krega
  constructor ob1;
  
  // ye parameterzed constructor ko call krega
  constructor ob2(5,6);
  
  // ye copy constructor ko call krega
  constructor ob3(ob2);
}
