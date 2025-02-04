#include <bits/stdc++.h>
using namespace std;

/*
    ✅ 1800. Maximum Ascending Subarray Sum

        Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

        A subarray is defined as a contiguous sequence of numbers in an array.

        A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.



        Example 1:

            Input: nums = [10,20,30,5,10,50]
            Output: 65
            Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

        Example 2:

            Input: nums = [10,20,30,40,50]
            Output: 150
            Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of
*/

int maxAscendingSum(vector<int> &nums)
{
    int maxSum = 0;
    int currentSubarraySum = nums[0];

    // Loop through the array starting from the second element
    for (int currentIdx = 1; currentIdx < nums.size(); ++currentIdx)
    {
        if (nums[currentIdx] <= nums[currentIdx - 1])
        {
            // If the current element is not greater than the previous one,
            // update maxSum
            maxSum = max(maxSum, currentSubarraySum);
            // Reset the sum for the next ascending subarray
            currentSubarraySum = 0;
        }
        currentSubarraySum += nums[currentIdx];
    }

    // Final check after the loop ends to account for the last ascending
    // subarray
    return max(maxSum, currentSubarraySum);
}

int main()
{
    // make you own
}