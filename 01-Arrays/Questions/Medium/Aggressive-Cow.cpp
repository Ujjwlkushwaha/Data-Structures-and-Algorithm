#include<bits/stdc++.h>
using namespace std;

/*
    ✅Aggressive Cows ( Difficulty: Medium )

        You are given an array with unique elements of stalls[], which denote the position of a stall.
        You are also given an integer k which denotes the number of aggressive cows.
        Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

    Examples :

        Input: stalls[] = [1, 2, 4, 8, 9], k = 3
        Output: 3

    Explanation: The first cow can be placed at stalls[0], 
        the second cow can be placed at stalls[2] and 
        the third cow can be placed at stalls[3]. 
        The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
*/


class Solution {
  public:
  
    bool isPossible( vector<int>&stalls , int k, int mid)
    {
        int count = 0;
        int prev = -1;
        
        for( int i=0 ; i<stalls.size() ; i++)
        {
            if( prev == -1 || stalls[i] - prev >= mid )
            {
                count++;
                prev=stalls[i];
            }
        }
        return count >=k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin() , stalls.end());
        int n=stalls.size();
        int lo=0,hi=stalls[n-1]-stalls[0];
        int ans = -1;
        
        while(lo <= hi)
        {
            int mid = ( lo + hi)/2;
            if( isPossible(stalls,k,mid))
            {
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return ans;
    }
};



int main()
{
    Solution obj;
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << obj.aggressiveCows(stalls, k) << endl;
    return 0;
}