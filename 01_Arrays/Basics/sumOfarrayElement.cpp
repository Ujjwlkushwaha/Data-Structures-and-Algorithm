//-> Sum of array elements

#include<iostream>
using namespace std;

int sumOfArrayElement(int arr[] , int s)
{
	int sum = 0 ;
	for(int i= 0 ; i<s ; i++){
		sum += arr[i];
	}
	
	return sum;
}
int main(){
// here is your code

	int arr[5] = {1,2,3,4,5};
	
	// sum of array element
	cout << "The sum of array element :: " << sumOfArrayElement(arr , 5) << endl;
	
 	return 0;
}


