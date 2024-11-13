#include<iostream>
using namespace std;

void printArray(int arr[] , int size , int i)
{
    if( i == size)return;

    cout << arr[i] << " " ;
    printArray(arr, size , i + 1) ;

}

void printReveseArray(int arr[] , int size , int i)
{   

        // base case
        if(i == size)return;

        printReveseArray(arr , size, i + 1);

        cout<< arr[i] << " " ;

}
int main()
{

    int arr[] = {1,2,3,4,5,6,7,8 ,9,10,11 ,12,13,14,15,16,17};
    int s = sizeof(arr)/sizeof(arr[0]);

    // we need three thing for printing array using recursion ( arr , size  , startingIndex)
    int i = 0;
    printArray(arr , s , i);

    printReveseArray(arr main  )

}