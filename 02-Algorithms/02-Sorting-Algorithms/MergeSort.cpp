#include <iostream>
using namespace std;

void merge(int *arr , int s , int e){
	
	int mid = s + (e - s)/2;
	
	int len1 = mid - s + 1 ;
	int len2 = e - mid;
	
	int *left = new int[len1];
	int *right = new int[len2];
	
	int k = s;
	for(int i=0 ; i<len1 ; i++){
		left[i] = arr[k++];
	}
	
	k = mid+1;
	for(int i=0 ; i<len2 ; i++){
		right[i] = arr[k++];
	} 
	
	// merge two sorted array
	
	int i= 0 ; int j = 0;
	int mainArray = s;
	while(i<len1 && j<len2){
		if(left[i] < right[j]){
			arr[mainArray++] = left[i++];
		}else{
			arr[mainArray++] = right[j++];
		}
	}
	
	while(i < len1){
		arr[mainArray++] = left[i++];
	}
	
	while(j < len2){
		arr[mainArray++] = right[j++];
	}
}
void mergeSort(int *arr , int s , int e){
	
	//base case
	if(s>=e)return;
	
	int mid = s + (e - s)/2;
	
	mergeSort(arr , s , mid);
	
	mergeSort(arr , mid+1 , e);
	
	merge(arr , s , e);
}

int main(){
	int arr[] = {3,2,6,8,5,4,3,8,0,9,7,23,54,3,2,6,8,5,4,3,8,0,9,7,23,54};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<< "-> Before sorting ...." << endl;
	for(int i = 0 ; i<n ; i++){
		cout << arr[i] <<" ";
	}
	
	mergeSort(arr , 0 , n-1);
	
	cout << "-> After sorting ...." << endl;
	for(int i = 0 ; i<n ; i++){
		cout << arr[i] <<" ";
	}
}
