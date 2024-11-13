#include<iostream>
using namespace std;


// mlti-level inheritence .............................


class Vehicle{
	
	// grand parent class...............................
	public:
		void Break(){
			cout << "break lagao :)" << endl;
		}	
		
		void start(){
			cout << "gaadi start karo :) " << endl;
		}
};

// inheriting the property of vehicle class
class Car : public Vehicle{
	
	// parent class.......................................
	public:
		void print(){
			cout<<"Caar chal rhhi haii parent se :) " <<endl;
		}
};

// inheriting the property of car class and indirectly vehicle class ki bhi
class child: public Car{
	
	// child clss........................................
	// multi level inheritence 
};
	
int main(){
	
	child ch1;
	
	cout << "Called by child class..............."<< endl;
	ch1.start();
	ch1.Break();
	ch1.print();
}
