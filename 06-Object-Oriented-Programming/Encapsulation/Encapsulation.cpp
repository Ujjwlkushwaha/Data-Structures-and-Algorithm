// Encapsulation.................................................................

#include <iostream>
using namespace std;

// dekho -> Class me kisi bhi data and methods ko wrap krna hi encapsulation hota hai

class EncapsulationExample{
	
	// this is your data members
	private:
		int age;
		string name;
		int salary;
	
	public:
		// default Constructor
		EncapsulationExample(){
			age = 18;
			name = "xyz";
			salary = 25000;
		}
		
		// geter 
		void getData(){
			cout<<this->age << endl;
			cout<<this->name << endl;
			cout<<this->salary << endl;
		}
};


int main(){
	EncapsulationExample ob;
	
	ob.getData();
}
