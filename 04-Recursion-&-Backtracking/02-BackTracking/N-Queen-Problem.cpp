#include <bits/stdc++.h>
using namespace std;

/*
    👸👑 N-Queen Problem  => ( Difficulty: Hard )

        The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other.

        ⭐Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

    Given an integer n, find all distinct solutions to the n-queens puzzle.

    You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n]. In this representation, the number in the ith position denotes the row in which the queen is placed in the ith column.

    Examples:

        Input: n = 1
        Output: [1]
        Explaination: Only one queen can be placed in the single cell available.

        Input: n = 4
        Output: [[2 4 1 3 ] [3 1 4 2 ]]
        Explaination: There are 2 possible solutions for n = 4.

        Input: n = 2
        Output: []
        Explaination: There are no possible solutions for n = 2.

*/
class Solution
{
public:
    void solve(int colo, int n, vector<vector<int>> &ans, vector<int> &sol, vector<bool> &col, vector<bool> &ldiag, vector<bool> &rdiag)
    {
        for (int i = 0; i < n; i++)
        {
            if (colo == n)
            {
                ans.push_back(sol);
                return;
            }

            if (!col[i] and !ldiag[colo - i + n - 1] and !rdiag[i + colo])
            {
                sol.push_back(i + 1);
                col[i] = true;
                ldiag[colo - i + n - 1] = true;
                rdiag[i + colo] = true;

                solve(colo + 1, n, ans, sol, col, ldiag, rdiag);

                // backtrack
                sol.pop_back();
                col[i] = false;
                ldiag[colo - i + n - 1] = false;
                rdiag[i + colo] = false;
            }
        }
    }

    
    vector<vector<int>> nQueen(int n)
    {
        // code here
        vector<bool> col(n, false);
        vector<bool> ldiag(2 * n - 1, false);
        vector<bool> rdiag(2 * n - 1, false);
        vector<vector<int>> ans;
        vector<int> sol;
        solve(0, n, ans, sol, col, ldiag, rdiag);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution ob;
    vector<vector<int>> ans = ob.nQueen(n);
    if (ans.size() == 0)
        cout << -1 << "\n";
    else
    {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "[";
            for (int u : ans[i])
                cout << u << " ";
            cout << "] ";
        }
        cout << endl;
    }

    cout << "~" << "\n";
}