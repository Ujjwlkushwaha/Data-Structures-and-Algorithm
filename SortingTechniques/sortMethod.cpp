#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sort using pre-define method
int main(){
	
//	normal static array
	int arr[] = {3,5,12,2,4,54,3,45,65,22,12,3,5,12,2,4,54,3,45,65,22,12};
	int n = sizeof(arr)/sizeof(arr[0]);
	
//	dynamic array
	vector<int> vrr(arr , arr+n) ;
	
//	sort normal array in ascending order..............
	sort(arr , arr+n);
	
//	sort vactor array in descending order.............
	sort(vrr.begin() , vrr.end() , greater<int>());
	
	
//	printing arrays...................................
	for(int i = 0 ; i< n ; i++){
		cout<<arr[i] << " ";
	}
	
	cout<<endl;
	
	for(int it = 0 ; it<vrr.size() ; it++){
		cout<< vrr[it] << " ";
	}
	
	
}
