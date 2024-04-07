#include <iostream>
using namespace std;

// basic input function
void inputInArray(int arr[] , int s){
	
	for(int i=0 ; i<s ; i++){
		cin >> arr[i];
	}
}

// printing array function
void printArray(int arr[] , int s){
	
	for(int i = 0 ; i<s ; i++){
		cout << arr[i] << " ";
	}
}

int main()
{
//	creating array

	int arr[5]; // integer array diclaration
	
	// input
	inputInArray(arr , 5);

	// print array
	printArray(arr , 5);
	
	return 0;
}
