//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> &arr)
{
    // Code here
    vector<vector<int>> result;
    int n = arr.size();

    for (int i = 0; i < n - 2; i++)
    {
        unordered_map<int, vector<int>> mp;

        for (int j = i + 1; j < n; j++)
        {
            int needed = 0 - arr[i] - arr[j];
            if (mp.count(needed))
            {
                for (auto k : mp[needed])
                {
                    result.push_back({i, k, j});
                }
            }

            mp[arr[j]].push_back(j);
        }
    }

    return result;
}

//{ Driver Code Starts.

int main()
{
    vector<int> arr = {0, -1, 2, -3, 1};
    vector<vector<int>> res = findTriplets(arr);
    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << "~" << endl;
}
// } Driver Code Ends