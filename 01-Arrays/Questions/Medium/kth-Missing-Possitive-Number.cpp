/*
   ✅  Kth Missing Positive Number in a Sorted Array  ( Difficulty: Medium )

    Given a sorted array of distinct positive integers arr[], we need to find the kth positive number that is missing from arr[].

Examples :
        Input: arr[] = [2, 3, 4, 7, 11], k = 5
        Output: 9
Explanation: Missing are 1, 5, 6, 8, 9, 10… and 5th missing number is 9.

        Input: arr[] = [1, 2, 3], k = 2
        Output: 5
Explanation: Missing are 4, 5, 6… and 2nd missing number is 5.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthMissing(vector<int> &arr, int k)
    {

        int n = arr.size();
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // If the number of missing elements before the mid element is less than k
            // then the kth missing element must be after the mid element
            if (arr[mid] - mid - 1 < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        // At the end of the loop, low must be greater than high
        // and low is the smallest index such that the number of missing elements before arr[low] is less than k
        // The kth missing number is arr[low] - 1 - (low - 1) + k = arr[low] + k - low - 1
        return low + k;
    }
};
int main()
{
    Solution obj;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << "Kth Missing Positive Number: " << obj.kthMissing(arr, k) << endl;
}