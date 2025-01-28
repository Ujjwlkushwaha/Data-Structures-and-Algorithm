#include <bits/stdc++.h>
using namespace std;

void recurPermute(int index, string &s,
                  unordered_set<string> &ans)
{

    // Base Case
    if (index == s.size())
    {
        ans.insert(s);
        return;
    }

    // Swap the current index with all
    // possible indices and recur
    for (int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        recurPermute(index + 1, s, ans);
        swap(s[index], s[i]);
    }
}

vector<string> findPermutation(string &s)
{
    // Code here there
    unordered_set<string> st;
    recurPermute(0, s, st);
    vector<string> ans ( st.begin() , st.end());
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    string str = "abc";
    vector<string> ans = findPermutation(str);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}