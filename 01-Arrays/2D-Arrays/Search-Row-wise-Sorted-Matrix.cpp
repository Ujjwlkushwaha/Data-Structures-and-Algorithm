//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*
    ✅ Search in a row-wise sorted matrix  ( Difficulty: Easy )

    Given a row-wise sorted 2D matrix mat[][] of size n x m and an integer x, find whether element x is present in the matrix.

    Note: In a row-wise sorted matrix, each row is sorted in itself, i.e. for any i, j within bounds, mat[i][j] <= mat[i][j+1].

Example:

    Input: mat[][] = [[3, 4, 9],[2, 5, 6],[9, 25, 27]], x = 9
    Output: true
*/

// } Driver Code Ends

class Solution
{
public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = n * m - 1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;

            int val = matrix[mid / m][mid % m];

            if (val == target)
                return true;

            if (val < target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{

    int n, m;
    cout << "Enter n and m which is n*m :: " << endl;
    cin >> n >> m;
    vector<vector<int>> matrix(n);

    cout << "Enter the elements of matrix " << endl;
    for (int i = 0; i < n; i++)
    {
        matrix[i].assign(m, 0);
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int x;
    cout << " Enter the number that you want to search :: ";
    cin >> x;
    Solution obj;
    if (obj.searchRowMatrix(matrix, x))
        cout << "true\n";
    else
        cout << "false\n";

    cout << "~"
         << "\n";
}

// } Driver Code Ends