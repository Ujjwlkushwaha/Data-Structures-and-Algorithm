#include <iostream>
using namespace std;


// Empty class  -> size is 1 
class EmptyClass{
	// nothing inside this class
};


// creating my first class
class Demo{
	char ch;
	int num; // 4 byte
	float height; // 4 bytr
	string str; // 8 byte
	
	//there is largest dataType is string so string ke size le according hi memory
    //allocate hoogi yani there is allocate 24 bytes 
	
};
int main()
{
	// Empty class object
	EmptyClass s1;
	cout << s1 << endl;
	cout << "Size of empty class is :: "<< sizeof(s1)<<endl;
	// creating first object..............................
	Demo obj ;
	
	
	// this will print size of the class 
	cout << "Size of object  : "       << sizeof(obj) <<endl; // class can calculate the size according to largest dataType in class
	cout <<"Size of class :" << sizeof(Demo) << endl; // class can calculate the size according to largest dataType in class
	
//	note : bina object create kre bhi memory alloacate ho jati haii

	
	
}
