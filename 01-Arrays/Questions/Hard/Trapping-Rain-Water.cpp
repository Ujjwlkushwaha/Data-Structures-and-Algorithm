#include <bits/stdc++.h>
using namespace std;

/*
    ✅ Trapping Rain Water  ( Difficulty: Hard )
``
        Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.

Examples:

    Input: arr[] = [3, 0, 1, 0, 4, 0 2]
    Output: 10
Explanation: Total water trapped = 0 + 3 + 2 + 3 + 0 + 2 + 0 = 10 units.
*/

int maxWater(vector<int> &arr)
{
    // code here
    int totalWater = 0;
    int lmax = 0 , rMax = 0 ;

    int i=0 , j=arr.size()-1;

    while( i < j )
    {
        lmax = max( lmax , arr[i]);
        rMax = max( rMax , arr[j]);

        if( arr[i] <= arr[j] )
        {
            totalWater += lmax-arr[i];
            i++;
        }else{
            totalWater += rMax-arr[j];
            j--;
        }
    }

    return totalWater;
}
int main()
{
    vector<int> arr = {3, 0, 1, 0, 4, 0 ,2};
    cout << " Total water is :: " << maxWater(arr) << endl;
}