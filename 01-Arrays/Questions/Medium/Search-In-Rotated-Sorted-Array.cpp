//  ✅ Search element in roteded sorted array
#include<iostream>
#include<vector>
using namespace std;


// find pivot element in rotated array
int pivotIndex(vector<int>arr)
{
    int s=0 , e=arr.size()-1;

    while(s<e)
    {
        int mid = s + (e-s)/2;
        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }else{
            e = mid;
        }
    }

    return s;
}

int binarySearch(vector<int>arr , int s, int e , int  key)
{
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(arr[mid] == key)
        {
            return mid;
        }
        
        if(arr[mid] > key)
        {
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return -1; // element not found in array
}

//✅Search element in roted sorted array
int searchElement(vector<int>arr , int key)
{
    int n = arr.size();
    int pivot = pivotIndex(arr);

    cout << "Pivot element is :: " << arr[pivot] << endl;

    if(arr[pivot] == key)
        return pivot;
    
    if( arr[pivot] <= key and key <= arr[n-1])
    {
        return binarySearch(arr, pivot, n-1, key);
    }else{
        return binarySearch(arr, 0, pivot-1, key);
    }
}
int main()
{
    vector<int> arr = {33, 42, 72, 99};
    int key = 42;
    int index = searchElement(arr, key);
    cout<<"Element "<<key<<" found at index "<<index<<endl;
    return 0;

}