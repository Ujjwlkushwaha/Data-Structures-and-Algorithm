/*
    ✅ K-th element of two Arrays
        
        Difficulty: MediumAccuracy: 37.4%Submissions: 291K+Points: 4
    
    Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

    Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
    Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

Constraints:

    1 <= a.size(), b.size() <= 106
    1 <= k <= a.size() + b.size()
    0 <= a[i], b[i] < 108

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        
        // Merge two sorted array
        int len1 = a.size() ;
        int len2 = b.size();
        
        int i = 0;
        int j = 0;
        vector< int > ans;
        while( i < len1 and j < len2 )
        {
            if( a[i] <= b[j] )
            {
                ans.push_back(a[i]);
                i++;
            }else{
                ans.push_back(b[j]);
                j++;
            }
        }
        
        while( i < len1 )
        {
            ans.push_back(a[i]);
            i++;
        }
        
        while( j < len2 )
        {
            ans.push_back( b[j] );
            j++;
        }
        
        return ans[k-1];
    }
};

int main()
{
    Solution obj;
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    cout << obj.kthElement(a, b, k) << endl;
    return 0;
}