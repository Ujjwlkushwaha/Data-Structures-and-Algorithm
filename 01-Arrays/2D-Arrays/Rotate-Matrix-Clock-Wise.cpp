/*
    Rotate by 90 degree ( Difficulty: Easy )
    
    Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 

Examples:

    Input: mat[][] = [[1, 2, 3],
                    [4, 5, 6]
                    [7, 8, 9]]

    Output: Rotated Matrix:
    [3, 6, 9]
    [2, 5, 8]
    [1, 4, 7]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void rotateMatrixClockWise(vector<vector<int>>& mat)
    {
         int n = mat.size();
         
        // Transpose the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++)
        {
            reverse(mat[i].begin(), mat[i].end());
        }
        
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> mat = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};
    obj.rotateMatrixClockWise(mat);
    cout << "Rotated Matrix:" << endl;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
