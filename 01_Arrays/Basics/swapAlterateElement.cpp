// -> swap alternate element in the array

#include<iostream>
using namespace std;

void swapAlternateElement(int arr[] , int s)
{
	for(int i=0 ; i<s ; i = i+2)
	{
		if(i+1 < s){
			swap(arr[i] , arr[i+1]);
		}
	}
}

void print(int arr[] , int s)
{
	for(int i=0 ; i<s ; i++)
	{
		cout << arr[i] << " ";
	}
	
	cout << endl;
}
int main(){

	int arr[10] = {2,4,5,3,6,4,5,6,7,10};
	
	// printing original array
	print(arr , 10);
	
	swapAlternateElement(arr , 10);
	
	// print afer swap array
	print(arr , 10);
	
	return 0;
}

