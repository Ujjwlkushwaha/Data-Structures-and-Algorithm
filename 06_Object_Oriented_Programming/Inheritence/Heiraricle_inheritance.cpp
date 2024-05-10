#include<iostream>
using namespace std;


// heiraricle  inheritence .............................

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
class child1: public Parent{
	
	public:
		child1(){
			cout<< "This is child 1 " << endl;
		}
		
		void display(){
			cout << id << endl;
			cout << name << endl;
			cout << address << endl;
		}
	
};

class child2 : public Parent{
	
	public:
		child2(){
			cout<< "\nThis is child 2 "<<endl;
		}
		
		void display(){
				cout << id << endl;
				cout << name << endl;
				cout << address << endl;
			}
}; 

int main(){
	
	child1 ch1;
	
	cout << "\nCalled by child1 class..............."<< endl;
	ch1.display();
	ch1.print();
	
	
	child2 ch2;
	
	cout << "\nCalled by child2 class..............."<< endl;
	ch2.display();
	ch2.print();
}
