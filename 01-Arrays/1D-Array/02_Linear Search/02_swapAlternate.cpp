#include<iostream>
using namespace std;

void swapAlternate(int *arr , int size)
{
    for(int i=0 ; i<size ; i=i+2){
        if(i+1 < size){
            swap(arr[i] , arr[i+1]);
        }
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
    
    // swap alternate values of an array
    swapAlternate(arr , size);
    printArray(arr , size);
}