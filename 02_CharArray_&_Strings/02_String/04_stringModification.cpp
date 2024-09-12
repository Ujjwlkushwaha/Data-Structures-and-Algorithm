#include <iostream>
#include <string>
using namespace std;

//.........................................modification in string.............................................................

int main()
{
	
	string str = "Ujjwal";
	
// insert Content into string ...............................................................................
	
	string str2 = "Jai" ;
	
	str += str2 ; // direct method to concatinate into string
	
	str.push_back('K') ;// add character at last of the given string 
	cout << "After pushing something -> " << str << endl;
	
	str.append("kushwaha"); // append string at last 
	cout << "After appending something -> "<< str << endl;
	
	str.insert(str.begin() , 'M'); // inserting something 
	cout << "After inserting ->  " << str << endl;
	
	string str3 = "This is america "; 
	str3.replace(8 , 5 , "india");
	
	cout << "After replaceing -> " << str3 <<endl;

//  diiffrent way of accessing string.........................................................................

	cout << "Simple way of printing complete string -> " <<str3 << endl;
	
	for(int i = 0 ; i < str3.length() ; i++)
	{
		//printing every character of string
		cout << str3[i] << endl;
	}  
	
// removing something from the string...........................................................................
	 
	
	
	
}
