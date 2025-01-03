//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> prefixSumCount;
        int prefixSum = 0;
        int count = 0;
    
        // Initialize with prefix sum 0
        prefixSumCount[0] = 1;
    
        for (int num : arr) {
            // Update the prefix sum
            prefixSum += num;
    
            // Check if (prefixSum - k) exists in the map
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - k];
            }
    
            // Update the map with the current prefix sum
            prefixSumCount[prefixSum]++;
        }
    
        return count;

    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends


/*
    
    ✅ Subarrays with sum K ( Difficulty: Medium )

    Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.

Examples:

    Input: arr = [10, 2, -2, -20, 10], k = -10
    Output: 3
Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.

    Input: arr = [9, 4, 20, 3, 10, 5], k = 33
    Output: 2
Explaination: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.

    Input: arr = [1, 3, 5], k = 0
    Output: 0
Explaination: No subarray with 0 sum.

Constraints:

    1 ≤ arr.size() ≤ 105
    -103 ≤ arr[i] ≤ 103
    -107 ≤ k ≤ 107

*/