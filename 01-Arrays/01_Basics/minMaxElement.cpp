// -> find min and max element in an array without using predefine function

#include<iostream>
using namespace std;

// find minimum element 
int minElement(int arr[] , int s)
{
	int min = arr[0]; // let's assume my first element is smallest element
	
	for(int i=1 ; i<s ; i++)
	{
		if(arr[i] < min)
		{
			min = arr [i];
		}
	}
	
	return min;
}

// find maximum element 
int maxElement(int arr[] , int s)
{
	int mx = arr[0]; // let's assume my first element is laregest element
	
	for(int i=1 ; i<s ; i++)
	{
		if(arr[i] > mx)
		{
			mx = arr [i];
		}
	}
	
	return mx;
}

// sortCut to find min and max element in an array

void minMaxElement(int arr[] , int s)
{
	int mn = arr[0];
	int mx = arr[0];
	
	for(int i = 1 ; i<s ; i++){
		mn = min(mn , arr[i]);
		mx = max(mx , arr[i]);
	}
	
	cout << "minimum element is " << mn << endl;
	cout << "maximum element is " << mx<< endl;
	
}
int main(){
	
	//create array
	int arr[10] = {4,6,3,17,9,16,6,5,3,10};
	
	cout << "-> minMax without using sortCut functions " << endl;
	cout << "minimum element is " << minElement(arr , 10) << endl;
	cout << "maximum element is " << maxElement(arr , 10) << endl;
	
	// sortCut technique
	
	cout << "\n-> minMax using sortCut function" << endl;
	minMaxElement(arr , 10);
	
}
