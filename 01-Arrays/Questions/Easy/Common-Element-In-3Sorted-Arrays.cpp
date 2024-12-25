#include <bits/stdc++.h>
using namespace std;

//======== ✅ Brute force approach ( TC: O(s1 + s2 + s3) )===============
vector<int> commonElmenets(vector<int> A, vector<int> B, vector<int> C)
{

    int s1 = A.size();
    int s2 = B.size();
    int s3 = C.size();

    map<int, int> mp;

    for (int i = 0; i < s1; i++)
    {
        mp[A[i]]++;
    }

    for (int i = 0; i < s2; i++)
    {
        mp[B[i]]++;
    }

    for (int i = 0; i < s3; i++)
    {
        mp[C[i]]++;
    }

    vector<int> ans;

    for (auto i : mp)
    {
        if (i.second == 3)
        {
            ans.push_back(i.first);
        }
    }

    return ans;
}


// ===========✅ Optimized Approach===============
vector<int> commonElmenetsInSortedArray(vector<int> A, vector<int> B, vector<int> C)
{
    int i = 0 ;
    int j = 0;
    int k = 0;

    vector<int> ans;

    while( i < A.size() and j < B.size() and k < C.size() )
    {
        if( A[i] == B[j] and B[j] == C[k])
        {
            ans.push_back( A[i]) ;
            i++;j++;k++;
        }
        else if( A[i] < B[j])
        {
            i++;
        }else if( B[j] < C[k])
        {
            j++;
        }else{
            k++;
        }

    }

    return ans;
}


// =========== ✅ Driver Code =====================

int main()
{
    vector<int> A = {1, 5, 10, 20, 40, 80};
    vector<int> B = {6, 7, 20, 80, 100};
    vector<int> C = {3, 4, 15, 20, 30, 70, 80, 120};
    vector<int> ans = commonElmenetsInSortedArray(A, B, C);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}