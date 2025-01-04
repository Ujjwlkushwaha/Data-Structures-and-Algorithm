#include<bits/stdc++.h>
using namespace std;

/*

✅ Count all triplets with given sum in sorted array ( Difficulty: Medium )

    Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.

Examples:

    Input: arr[] = [-3, -1, -1, 0, 1, 2], target = -2
    Output: 4

    Explanation: Two triplets that add up to -2 are:
    arr[0] + arr[3] + arr[4] = (-3) + 0 + (1) = -2
    arr[0] + arr[1] + arr[5] = (-3) + (-1) + (2) = -2
    arr[0] + arr[2] + arr[5] = (-3) + (-1) + (2) = -2
    arr[1] + arr[2] + arr[3] = (-1) + (-1) + (0) = -2

*/

int countTripplets(vector<int> arr , int target )
{
    int n=arr.size();
    int count = 0;

    for( int i=0 ;i<=n-3 ; i++) 
    {
        int j=i+1 , k=n-1;
        while( j < k )
        {
            int sum = arr[i] + arr[j] + arr[k];
            
            if( sum > target )k--;
            else if( sum < target )j++;
            else if(sum == target )
            {
                count++;
                int temp = j+1;
                while( temp < k and arr[temp] == arr[temp-1])
                {
                    count++;
                    temp++;
                }
                k--;
            }
        }
    }

    return count;
}

int main()
{

    vector<int> arr = {-3, -1, -1, 0, 1, 2};
    int target = -2;

    cout << "Number of tripplets :: " << countTripplets( arr , target ) << endl;

}