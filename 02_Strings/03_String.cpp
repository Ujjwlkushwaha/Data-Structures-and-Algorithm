//.............................Take about strings ...................................................

#include <iostream>
#include <string>
using namespace std ;

//string -> dynamic char array bol skte hai
int main(){
	
	string name ; // declaration 
	
	getline(cin , name); // input lene ka tarikaa 
	
	cout << "Your name is -> "<<  name << endl; // output print karne ka tarika
	
//	length of a string 
	cout << "Length of string -> "<< name.length() << endl;
	
//-----------------------------------------------------------------------------------------------------------------------------------------
	
// basic method of string ................................................................

//	1 . capacity() -> to get max capacity of string 
	cout << "max capacity of this string -> " << name.capacity() << endl;
	
//	2 . .clear() -> to clear the string 
	
	name.clear() ;
	cout << "String is clear :) " << name << endl;
	
//	3 . .empty() -> to check string is empty or not
	if(name.empty()){
		cout << "String is Emplty :( " << endl;
	}else{
		cout << "String is not Empty :) " << endl;
	}
	
}
