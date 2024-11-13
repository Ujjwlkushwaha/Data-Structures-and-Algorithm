#include<iostream>
using namespace std;

// selection sort
void selectionSort(int *arr , int n){
	
	for(int i = 0 ; i<n-1 ; i++){
		int minVal = i ;
		for(int j = i+1 ; j < n ; j++){
			if(arr[j] < arr[minVal]){
				minVal = j;
			}
		}
		
		swap(arr[i] , arr[minVal]);
	}
}
int main(){
	int arr[] = {5,8,9,1,3,4,5,6,43,23,12,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr , size);
	
	for(int i=0 ; i<size ; i++){
		cout<< arr[i] << " ";
	}
}
