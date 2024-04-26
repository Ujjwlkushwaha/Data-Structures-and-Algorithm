#include<iostream>
using namespace std;

//=> har number 2 baar aayega ak ko chhorke vhi ak element chahiye

int uniqueElement(int *arr , int size)
{
    int ans = 0 ;
    for(int i = 0 ; i<size ; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
    
}// jai shree ramifications aayega  ak ko chhorke vhi ak element chahiye 


int main()
{
    int arr[] = {1,3,1,3,6,5,4,6,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int i = uniqueElement(arr , size);

    cout <<"Your unique element is : " << i << endl;
    
}