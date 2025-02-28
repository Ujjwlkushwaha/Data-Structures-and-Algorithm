#include <iostream>
#include <vector>
#include<limits>
using namespace std;

// Brute force approach
void printAllSubArrays(vector<int> &arr)
{ // TC = O(n^3)

    int n = arr.size();

    // starting index
    for (int st = 0; st < n; st++)
    {
        // ending index
        for (int en = st; en < n; en++)
        {

            // print from start index to ending idex
            for (int i = st; i <= en; i++)
            {
                cout << arr[i];
            }

            cout << " ";
        }

        cout << endl;
    }
}

int totalNoOFSubarray(int n)
{

    // formula for total num of subarrays
    int totalNoOfSubArrays = (n * (n + 1)) / 2;

    cout << "There are " << totalNoOfSubArrays << " SubArrays";
}

int maxSumSubArray(vector<int> &nums)
{
    // use kadane's algorithm

    int currSum = 0; // manage corrent sum
    int maxSum = INT64_MIN;

    for (int val : nums)
    {
        currSum += val;                // updating current sum
        maxSum = max(maxSum, currSum); //  updating maxSum

        // main step to this algorithm
        if (currSum < 0)
            currSum = 0; // reset the currSum if it is nigative
    }
    return maxSum;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    // print all the subarrays
    printAllSubArrays(arr);
    /*
        1 12 123 1234 12345
        2 23 234 2345
        3 34 345
        4 45
        5
    */

    totalNoOFSubarray(arr.size());
}
