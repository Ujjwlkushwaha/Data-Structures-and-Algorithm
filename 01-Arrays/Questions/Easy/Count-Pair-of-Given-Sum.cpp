/*
    ✅ Count pairs with given sum ( Difficulty: Easy )

        Given an array arr[] and an integer target. You have to find numbers of pairs in array arr[] which sums up to given target.

Examples:

        Input: arr[] = [1, 5, 7, -1, 5], target = 6
        Output: 3
    Explanation: Pairs with sum 6 are (1, 5), (7, -1) and (1, 5).

        Input: arr[] = [1, 1, 1, 1], target = 2
        Output: 6
    Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1).

*/

#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &arr, int target)
{
    // Code here
    unordered_map<int, int> mp;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int secValue = target - arr[i];
        if (mp.find(secValue) != mp.end())
        {
            count += mp[secValue];
        }
        mp[arr[i]]++;
    }

    return count;
}

int main()
{
    vector<int> arr = {1, 5, 7, -1, 5};
    int target = 6;

    //  string ans = isTwoSum(arr , target ) ? "Value is Present !" : "Value is not Present!";
    //  cout << ans << endl;

    cout << "Number of pairs:: " <<  countPairs(arr, target);


}