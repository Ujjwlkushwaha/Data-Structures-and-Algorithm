#include<iostream>
using namespace std;

// Bubble sort  Time Complexity -> O(n*n)
void bubbleSort(int *arr , int n)
{
	// swap nabouring element if it is greater then others
	for(int i = 1 ; i<= n ; i++)
	{
		for(int j = 0 ; j < n-i ; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j] , arr[j+1]);
			}
		}
	}
}
int main()
{
	int arr[] = {5,8,9,1,11,3,4,15,6,43,23,12,12,3,32,8};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	bubbleSort(arr , size);
	
	for(int i=0 ; i<size ; i++){
		cout<< arr[i] << " ";
	}
}
