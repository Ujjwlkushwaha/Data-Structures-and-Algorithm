#include<iostream>
using namespace std;


// multiple inheritence .............................

class Parent1{
	public:
		
		void print(){
			cout << "this is parent1 classs" << endl;
		}
};

// single inheritence.............................
class Parent2{
	
	public:
		void print(){
			cout << "This is parent2 class :) " << endl;
		}
	
};

// multiple inheritence -> class can inherite the property of more than one class
class child : public Parent1 , public Parent2{
	
};

int main(){
	
	child ch1;
	
	cout << "Called by child class..............."<< endl;
	
	// this inheritence has a problem if the same property both class have so child confuse ho jayga ki call kisko karu

//	ch1.print(); -> iss tarike se nhi chalega

// solution ->.....................................................
	
	ch1.Parent2::print();
	
	ch1.Parent1::print();
	
//...................................................................
	
}
