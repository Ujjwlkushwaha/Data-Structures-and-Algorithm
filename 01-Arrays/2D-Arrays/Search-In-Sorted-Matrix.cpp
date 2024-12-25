/*
    ✅ Search in a sorted Matrix  ( Difficulty: Medium )

        ✔️ Given a strictly sorted 2D matrix mat[][] of size n x m and a number x.
        ✔️ Find whether the number X is present in the matrix or not.

    ✅ Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, and the first element of the ith row (i!=0) is greater than the last element of the (i-1)th row.

☑️ Examples:

        Input: mat[][] = [[1, 5, 9], [14, 20, 21], [30, 34, 43]], x = 14
        Output: true
    Explanation: 14 is present in the matrix, so output is true.

        Input: mat[][] = [[1, 5, 9, 11], [14, 20, 21, 26], [30, 34, 43, 50]], x = 42
        Output: false
    Explanation: 42 is not present in the matrix.

*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0;
    int j = n*m-1;
    while (i <= j)
    {
        int mid = i+(j-i)/2;

        int val = matrix[mid/m][mid%m];

        if( val == target ) return true;

        if ( val < target )
        {
            i = mid+1;
        }else{
            j = mid-1;
        }
        
    }
    return false;
}

//{ Driver Code Starts.
int main()
{

    vector<vector<int>> matrix = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int x = 17;
    bool an = searchMatrix(matrix, x);
    if (an)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}