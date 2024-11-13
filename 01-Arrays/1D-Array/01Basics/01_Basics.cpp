#include<iostream>

// required.....
#include<vector>

using namespace std;

int main()
{
	// initialization of vector
	
	// way - 01
	vector<int> vr1 = {1,2,3,4,5,6};
	
	// way - 02
	vector<int> vr2({2,3,4,5,6,7});
	
	// way - 03
	vector<int> vr3(5,10);
	
	// way - 04
	vector <int> v4(vr3); 

	// printing vector
	for (const int& i : vr2)
	{
		cout << i << " ";
	}

	
	
	
}
