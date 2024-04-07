#include <iostream>
using namespace std;

// function overloading.....................................
class Maths{
	public:
		
//		function overloading me function ka name same hota hai bss signature change hota hai

//	signature -> number of parameters and datatype of parameters
		
		int sum(int a , int b){
			return a+b;
		}
		
		int sum( int a , int b , int c){
			return a+b+c;
		}
		
		int sum(int a , double b){
			return a+b;
		}

		// changing the sequence of parameters
		int sum(double a , int b){
			return a+b;
		}
		
		int sum( double a , double b){
			return a+b;
		}
};

int main(){
	
	Maths m1;
	// function overloading
	
	cout << m1.sum(2,5) << endl;
	
	cout << m1.sum(5,4.4) << endl;

	cout << m1.sum(5.4,4) << endl;
	
	cout << m1.sum(5,6,7) << endl;
	
	cout <<m1.sum(4.5,5.5) << endl;	
}
