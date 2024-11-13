#include<iostream>
using namespace std;

int findDuplicate(int *arr , int size)
{   
    int ans = 0;
    for(int i = 0; i < size; i++){
        ans ^= arr[i];
    }

    for(int i = 1 ; i<size ; i++){
        ans ^= i;
    }

    return ans;

}
int main(){

    int arr[] = {1,2,3,4,5,6,7,8,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Duplicate value is :: "<< findDuplicate(arr,size);
}