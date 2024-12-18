#include <iostream>
using namespace std;

int partition(int *arr , int s , int e)
{

	int pivot = s;
	int cnt = 0 ; 

    // Count the number of elements less than pivot in left part
	for(int i = s+1 ; i<=e ; i++){
		if(arr[pivot] > arr[i])cnt++;
	}
	
    // and update pivotIndex accordingly  (pivotIndex = cnt + s)  in place of cnt+s in original code.
	int pivotIndex = cnt+s;
	swap(arr[s] , arr[pivotIndex]);
	
	int i = s , j = e;
	while( i < pivotIndex && j> pivotIndex){
		if(arr[i] < arr[pivotIndex])i++;
		
		if(arr[j] > arr[pivotIndex])j--;
		
		if(arr[i] > arr[j]){
			swap(arr[i] , arr[j]);
			i++;
			j--;
		}
	}
	
	return pivotIndex;
}

void quickSort(int *arr , int s , int e){
	
	// Base case
	if(s >= e){
		return;
	}
    // Partitioning idx
	int p = partition(arr , s , e);
	
	// recursive call
	quickSort(arr , s , p-1); // sort left part
	quickSort(arr , p+1 , e); // sort right part
}


int main(){
	int arr[] = {3,5,2,6,3,5,2,6,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	quickSort(arr , 0 , n-1);
	
	for(int i = 0 ; i<n ; i++){
		cout<<arr[i] <<" ";
	}
}
