#include <iostream>
#include <string>
using namespace std;

// char Array -> char ch[size] 
int main()
{
	char name[20];
	// taking input in this char array.................................................
	cout<<"Enter your name buddy :) -> " ;
	cin >> name ; // -> ye kewal space tak ka hi read krega mtlb agar string "ujjwal kushwha" hai to vo 
				  //	ujjwal hi read krega
	
//	printing char array 

	cout << "Your name is :: " << name <<endl;
	
// reading complete Name char array.....................................................
	
	char name2[20];
	
	// taking complete char array as input
	cin.getline(name2 , 20);
	
	// printing name2
	cout << name2 <<endl;
	
// length of char array ;.................................................................

	int i=0;
	int length = 0;
	
	while(name2[i++] != '\0'){
		length++;
	}
	
	cout << "The length of char array is :: " << length << endl;
	
// predefine method for length .........................................................

}
