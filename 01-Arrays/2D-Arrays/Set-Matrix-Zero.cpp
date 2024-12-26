/*
    ✅ Set Matrix Zeroes ( Difficulty: Medium )

    You are given a 2D matrix mat{}{} of size n×m.

    The task is to modify the matrix such that if mat{i}{j} is 0, all the elements in the i-th row and j-th column are set to 0 and do it in constant space complexity.

Examples:

    Input: mat{}{} = {{1, -1, 1},
                    {-1, 0, 1},
                    {1, -1, 1}}
    Output: {{1, 0, 1},
            {0, 0, 0},
            {1, 0, 1}}
Explanation: mat{1}{1} = 0, so all elements in row 1 and column 1 are updated to zeroes.

    Input: mat{}{} = {{0, 1, 2, 0},
                    {3, 4, 5, 2},
                    {1, 3, 1, 5}}
    Output: {{0, 0, 0, 0},
            {0, 4, 5, 0},
            {0, 3, 1, 0}}
Explanation: mat{0}{0} and mat{0}{3} are 0s, so all elements in row 0, column 0 and column 3 are updated to zeroes.


*/

#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Variables to check if the first row and column should be zero
    bool isFirstRowZero = false;
    bool isFirstColZero = false;

    // Check if the first row has a zero
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            isFirstRowZero = true;
            break;
        }
    }

    // Check if the first column has a zero
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            isFirstColZero = true;
            break;
        }
    }

    // Use the first row and column as markers
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark the row
                matrix[0][j] = 0; // Mark the column
            }
        }
    }

    // Update the matrix based on markers
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Handle the first row
    if (isFirstRowZero) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Handle the first column
    if (isFirstColZero) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    setZeroes(mat);

    // Output the result
    for (const auto& row : mat) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
