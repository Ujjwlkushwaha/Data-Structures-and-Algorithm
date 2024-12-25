/*
    ✅ Search in a Row-Column sorted matrix  ( Difficulty: Easy )

    Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order and a number x,
    the task is to find whether element x is present in the matrix.

Examples:

    Input: mat[][] = [[3, 30, 38],[20, 52, 54],[35, 60, 69]], x = 62
    Output: false
Explanation: 62 is not present in the matrix, so output is false.

    Input: mat[][] = [[18, 21, 27],[38, 55, 67]], x = 55
    Output: true
Explanation: 55 is present in the matrix.

*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0;
    int j = m - 1;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == target)
        {
            return true;
        }
        else if (matrix[i][j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

//{ Driver Code Starts.
int main()
{
    vector<vector<int>> matrix = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int x = 14;
    bool an = searchMatrix(matrix, x);
    if (an)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
// } Driver Code Ends