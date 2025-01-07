/*
   ✅🤔 Sum Pair closest to target   ( Difficulty: Easy )

    Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a<=b whose sum is closest to target.

    Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

Examples:

    Input: arr[] = [10, 30, 20, 5], target = 25
    Output: [5, 20]
Explanation: As 5 + 20 = 25 is closest to 25.

    Input: arr[] = [5, 2, 7, 1, 4], target = 10
    Output: [2, 7]

Explanation: As (4, 7) and (2, 7) both are closest to 10, but absolute difference of (2, 7) is 5 and (4, 7) is 3. Hence, [2, 7] has maximum absolute difference and closest to target
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> sumClosest(vector<int> &arr, int target)
    {
        // code here
        sort(arr.begin(), arr.end());
        int i = 0, j = arr.size() - 1, diff = INT_MAX, first = -1, second = -1;

        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (diff > abs(sum - target))
            {
                first = arr[i];
                second = arr[j];
                diff = abs(sum - target);
            }
            else if (diff == abs(sum - target))
            {
                if (arr[j] - arr[i] > second - first)
                {
                    first = arr[i];
                    second = arr[j];
                }
            }

            if (sum <= target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        if (first == -1 and second == -1)
            return {};

        return {first, second};
    }
};

//{ Driver Code Starts.
int main()
{

    vector<int> arr = {5, 2, 7, 1, 4};
    int target = 10;

    Solution ob;
    vector<int> ans = ob.sumClosest(arr, target);
    if (ans.empty())
    {
        cout << "[]";
    }
    else
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
    }

    return 0;
}
// } Driver Code Ends