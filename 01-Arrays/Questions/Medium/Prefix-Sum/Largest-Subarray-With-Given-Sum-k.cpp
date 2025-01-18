#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubarrayWithSumK(vector<int>& arr, int k)
{
    unordered_map<int, int> prefixSumMap;
    
    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // Agar prefixSum k ke barabar ho, toh length update karo
        if (prefixSum == k) {
            maxLength = i + 1;
        }

        // Agar (prefixSum - k) map me milta hai, toh length update karo
        if (prefixSumMap.find(prefixSum - k) != prefixSumMap.end()) {
            maxLength = max(maxLength, i - prefixSumMap[prefixSum - k]);
        }

        // Prefix sum ko map me store karo agar pehle se nahi hai
        if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
            prefixSumMap[prefixSum] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr1 = {10, 5, 2, 7, 1, -10};
    int k1 = 15;
    cout << "Output: " << longestSubarrayWithSumK(arr1, k1) << endl;

    vector<int> arr2 = {-5, 8, -14, 2, 4, 12};
    int k2 = -5;
    cout << "Output: " << longestSubarrayWithSumK(arr2, k2) << endl;

    vector<int> arr3 = {10, -10, 20, 30};
    int k3 = 5;
    cout << "Output: " << longestSubarrayWithSumK(arr3, k3) << endl;

    return 0;
}
