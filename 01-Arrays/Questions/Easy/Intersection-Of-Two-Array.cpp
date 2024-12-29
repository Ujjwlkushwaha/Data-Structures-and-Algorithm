#include<bits/stdc++.h>
using namespace std;

/*
   ✅  Intersection of Two arrays with Duplicate Elements ( Difficulty: Easy )
    
        Given two integer arrays a[] and b[], you have to find the intersection of the two arrays. Intersection of two arrays is said to be elements that are common in both arrays. The intersection should not have duplicate elements and the result should contain items in any order.

Note: The driver code will sort the resulting array in increasing order before printing.

Examples:

    Input: a[] = [1, 2, 1, 3, 1], b[] = [3, 1, 3, 4, 1]
    Output: [1, 3]
Explanation: 1 and 3 are the only common elements and we need to print only one occurrence of common elements.

    Input: a[] = [1, 1, 1], b[] = [1, 1, 1, 1, 1]
    Output: [1]
Explanation: 1 is the only common element present in both the arrays.

    Input: a[] = [1, 2, 3], b[] = [4, 5, 6]
    Output: []
Explanation: No common element in both the arrays.

*/



vector<int> intersectionWithDuplicates(vector<int> &a, vector<int> &b)
{
    // code here
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> ans;
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;

    while (i < n and j < m)
    {
        if (a[i] == b[j])
        {
            auto it = find(ans.begin(), ans.end(), a[i]);
            if (it == ans.end())
            {
                ans.push_back(a[i]);
            }
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return ans;
}

int main()
{
        vector<int> a = {1, 2, 1, 3, 1};
        vector<int> b = {3, 1, 3, 4, 1};

        vector<int> ans = intersectionWithDuplicates(a , b);

        // printing answer
        for( auto val : ans)
        {
            cout << val << " " ;
        }
}