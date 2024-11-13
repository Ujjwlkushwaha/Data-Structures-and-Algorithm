#include<iostream>
using namespace std;


// inheritence -> inheriting data and method of a class by the another class;
class Parent{
	private:
		int a;
	
	public:
		// constructor
		Parent(){
			cout<< "-> This is parent Constructor" << endl;
		}
		
		void print1(){
			cout<<"This is parent class :)" << endl;
		}
};

class child:public Parent{
	
	
	public: 
		// constructor
		child(){
			cout<<"-> this is child constructor" << endl;
		}
		
		void print2(){
			cout<< "this is child class" << endl;
		}
};


int main()
{
	child ch1; // ye pahle baap ke constructor ko call krega fir child wale ka hoga
	
	ch1.print2();
}
