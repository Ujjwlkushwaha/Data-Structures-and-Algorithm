#include<iostream>
using namespace std;

// InsertionSort  Time Complexity -> O(n*n)
void insertionSort(int *arr , int n)
{
	// swap nabouring element if it is greater then others
	for(int i = 1 ; i< n ; i++)
	{
		for(int j = i-1 ; j > 0 ; j--)
		{
			if(arr[j] > arr[i])
			{
				arr[j+1] = arr[j];
			}else{
//				arr[j+1] = arr[i];
//				break;
			}
		}	
	}
}
int main()
{
	int arr[] = {5,8,9,1,11,3,4,15,6,43,23,12,12,3,32,8};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	insertionSort(arr , size);
	
	for(int i=0 ; i<size ; i++){
		cout<< arr[i] << " ";
	}
}
