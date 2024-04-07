#include<iostream>
using namespace std;


// Single inheritence .............................

class Parent{
	public:
		int id;
		string name = "Pta nhi";
		string address = "pta nhi";
		
		void print(){
			cout << "this is parent classs" << endl;
		}
};

// single inheritence.............................
class child: public Parent{
	
	public:
		void display(){
			cout << id << endl;
			cout << name << endl;
			cout << address << endl;
		}
	
};

int main(){
	
	child ch1;
	
	cout << "Called by child class..............."<< endl;
	ch1.display();
	ch1.print();
}
