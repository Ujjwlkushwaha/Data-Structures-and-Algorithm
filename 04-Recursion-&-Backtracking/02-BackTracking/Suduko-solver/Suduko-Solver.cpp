#include <iostream>
#include <vector>
using namespace std;

#define N 9

// Function to check if it's safe to place a number in a given cell
bool isSafe(vector<vector<int>> &grid, int row, int col, int num)
{
    for (int x = 0; x < grid[0].size(); x++)
    {
        if (grid[row][x] == num || grid[x][col] == num)
        {
            return false;
        }
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }
    return true;
}

// Function to solve Sudoku using backtracking
bool solveSudokuHelper(vector<vector<int>> &grid)
{
    int row, col;
    bool isEmpty = false;

    for (row = 0; row < grid.size(); row++)
    {
        for (col = 0; col < grid[0].size(); col++)
        {
            if (grid[row][col] == 0)
            {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
            break;
    }

    if (!isEmpty)
        return true; // No empty cells left

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solveSudokuHelper(grid))
                return true;
            grid[row][col] = 0; // Backtrack
        }
    }
    return false;
}

// Wrapper function to solve Sudoku
void solveSudoku(vector<vector<int>> &mat)
{
    solveSudokuHelper(mat);
}

// Function to print the Sudoku grid
void printGrid(vector<vector<int>> &grid)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    solveSudoku(grid);
    printGrid(grid);

    return 0;
}
