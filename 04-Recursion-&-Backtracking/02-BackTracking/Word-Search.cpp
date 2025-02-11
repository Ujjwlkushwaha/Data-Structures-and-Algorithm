#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> &mat, string &word, int i, int j, int idx)
{
    if (idx == word.length())
        return true;

    if (i < 0 or i >= mat.size() or j >= mat[0].size() or mat[i][j] != word[idx])
    {
        return false;
    }

    char temp = mat[i][j];
    mat[i][j] = '-1';

    bool found = dfs(mat, word, i + 1, j, idx + 1) or
                 dfs(mat, word, i - 1, j, idx + 1) or
                 dfs(mat, word, i, j + 1, idx + 1) or
                 dfs(mat, word, i, j - 1, idx + 1);

    mat[i][j] = temp;
    return found;
}

bool isWordExist(vector<vector<char>> &mat, string &word)
{
    // Code here
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == word[0] and dfs(mat, word, i, j, 0))
                return true;
        }
    }
}