#include <bits/stdc++.h>
using namespace std;

void isPresent(string str)
{
    string s = "abcdefghijklmnopqrstuvwxyz";
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        if (s.find(str[i], 0) != string::npos)
        {
            cout << str[i] << " Found " << endl;
        }else{
            cout << str[i] << " not Found " << endl;
        }
    }
}

int main()
{
    isPresent("lj");
}