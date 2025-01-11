//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*
    Spirally traversing a matrix  ( Difficulty: Medium )

    You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.

Examples:

        Input: mat[][] = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]
        Output: [1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]

        Explanation: Applying same technique as shown above

*/

// } Driver Code Ends
class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        // code here
        vector<int> result;
        int top = 0, bottom = mat.size() - 1, left = 0, right = mat[0].size() - 1;
        int dir = 0;
        while (top <= bottom && left <= right)
        {
            if (dir == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    result.push_back(mat[top][i]);
                }
                top++;
            }
            else if (dir == 1)
            {
                for (int i = top; i <= bottom; i++)
                {
                    result.push_back(mat[i][right]);
                }
                right--;
            }
            else if (dir == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    result.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            else if (dir == 3)
            {
                for (int i = bottom; i >= top; i--)
                {
                    result.push_back(mat[i][left]);
                }
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends