#include<iostream>
using namespace std;

// binary search -> for sorted array 
int binarySearch(int arr[] , int size , int key)
{

    int s = 0 , e = size-1 ;

    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid] == key){
            return mid;
        }

        if(arr[mid] > key){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }

    return -1;
}


int main()
{
    int arr[] = {3,4,5,7,9,10,12,14,15};

    int target = 7;

    int index = binarySearch(arr , 9 , target);

    if(index == -1){
        cout << "Element not found :(" << endl;
    }else{
        cout << "Your element at index :: " << index << endl;
    }
}