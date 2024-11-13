#include<iostream>
using namespace std;

// reverse an array 
void reverseArray(int arr[] , int size)
{
    int s = 0 , e = size-1 ;

    while(s <= e)
    {
        swap(arr[s] , arr[e]);
        s++ ;
        e--;
    }
}

//printing array
void printArray(int *arr , int s)
{
    for(int i = 0 ; i<s ; i++){
        cout<< arr[i] << " ";
    }
}

int main()
{
    int arr[] = {3,4,5,7,9,10,12,14,15};

    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr , size);

   // reverse array 
   reverseArray(arr , size);
   printArray(arr , size);
}