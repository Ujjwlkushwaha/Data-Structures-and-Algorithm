/*
     ✅ Two Sum - Pair with Given Sum ( Difficulty: Easy )

        - Given an array arr[] of positive integers and another integer target.
        - Determine if there exists two distinct indices such that the sum of there elements is equals to target.

Examples:

        Input: arr[] = [1, 4, 45, 6, 10, 8], target = 16
        Output: true
    Explanation: arr[3] + arr[4] = 6 + 10 = 16.

        Input: arr[] = [1, 2, 4, 3, 6], target = 11
        Output: false
    Explanation: None of the pair makes a sum of 11.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;

// ================ ✅ Two pointer approach=========

bool isTwoSum(vector<int> &arr, int target)
{
    // code here
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = n - 1;

    while (i < j){
        if (arr[i] + arr[j] == target){
            return true;
        }

        (arr[i] + arr[j] < target) ? i++ : j--;
    }

    return false;
}

// =================✅ using map ====================
vector<int> twoSum( vector<int>&arr , int target )
{
    map<int , int> mp;
    vector<int> ans;

    for( int i = 0 ; i < arr.size() ; i++ )
    {
        mp[arr[i]] = i;
    }

    for( int i=0 ; i<arr.size() ; i++ )
    {
        int val = target-arr[i];

        if( mp.find(val) != mp.end() )
        {
            ans.push_back(i);
            ans.push_back(mp[val]);
            return ans;
        }
    }

    // if no index found
    ans.push_back( -1 );
    return ans;
}

int main()
{
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 16;

    //  string ans = isTwoSum(arr , target ) ? "Value is Present !" : "Value is not Present!";
    //  cout << ans << endl;

     vector<int> ans = twoSum(arr , target) ;

     for( auto val : ans ) cout << val << " "; 
}