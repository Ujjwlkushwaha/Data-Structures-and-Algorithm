
// 😣 A word or a sentence is called a pangram if it contains all the English alphabet letters. 

#include <bits/stdc++.h>
using namespace std;

bool checkPanagram(string str)
{
    vector<int> frq(26, 0);
    // change string to lower case
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    for (int i = 0; i < str.size(); i++)
    {
        // cout << str[i]-'a' << " ";
        frq[str[i] - 'a']++;
    }

    cout << "\n printing frq of letters :: " << endl;
    for (auto val : frq)
    {
        if (val == 0)
            return false;
    }

    return true;
}
int main()
{
    string str = "TheQuickBrownFoxJumpsOverTheLazyDog";

    bool ans = checkPanagram(str) ? "true" : "False";
    cout << ans << endl;

    return 0;
}