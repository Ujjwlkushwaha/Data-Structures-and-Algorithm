// linear searching in array -> to search any element in unsorted array

#include<iostream>
using namespace std;

int linearSearch(int arr[] , int s , int ele)
{
	for(int i = 0 ; i<s ; i++){
		if(ele == arr[i])
		{
			return i;
		}
	}
	
	return -1;
}


int main(){
	
	int arr[10] = {2,4,5,3,6,4,5,6,7,10};
	
 	int ele = 0;
 	
 	cout << "Enter the element that you want to search :: " ;
 	cin >> ele ;
 	
 	cout <<"Your elemenet in the index of " << linearSearch(arr , 10 ,ele) << endl;
 	return 0;
}

