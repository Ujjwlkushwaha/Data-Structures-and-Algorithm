#include <bits/stdc++.h>
using namespace std;

int sum(vector<int>&arr , int s , int e)
    {
        int sum = 0;
        for( int i=s ; i<e ; i++)
        {
            sum += arr[s]+arr[e];
        }
        
        return sum;
        
    }
    int findEquilibrium(vector<int> &arr) {
        // code here
        
        int index = -1;

        for (int i = 1; i < arr.size() - 1; i++)
        {
            int leftSum = sum(arr , 0 , i);
            int rightSum = sum( arr, i , arr.size());
    
            cout << leftSum << " " << rightSum << endl;
    
            if(leftSum == rightSum)
            {
                return i;
            }
        }
    
        return index;
    }
int main()
{
    vector<int> arr = {1,2,0,3};
    cout<< findEquilibrium(arr) << endl;
}