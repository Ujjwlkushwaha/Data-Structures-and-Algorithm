#include <bits/stdc++.h>
using namespace std;

/*
   ✅  Count Subarrays with given XOR
            Difficulty: MediumAccuracy: 58.86%Submissions: 17K+Points: 4

    Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

Examples: 

    Input: arr[] = [4, 2, 2, 6, 4], k = 6
    Output: 4

    Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.
*/


// } Driver Code Ends
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int prefixXOR = 0;
        int count = 0;
    
        for (int num : arr) {
            // Update the prefix prefixXOR
            prefixXOR ^= num;
            
            if(  prefixXOR == k) count++;
    
            // Check if (prefixXOR - k) exists in the map
            if (mp.find(prefixXOR^k) != mp.end()) {
                count += mp[prefixXOR^k];
            }
    
            // Update the map with the current prefix prefixXOR
            mp[prefixXOR]++;
        }
    
        return count;
    }
};

int main()
{
    Solution ob;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    cout << " Number of elements : " << ob.subarrayXor(arr , k) << endl;
}