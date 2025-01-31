#include <bits/stdc++.h>
using namespace std;

/*
    ✅ Reverse vowels in a string

        You are given a string 'S'. Your task is to reverse the vowels in the string while keeping the consonants unchanged.

        Note:

        The alphabets 'a', 'e', 'i', 'o', and 'u' are vowels, while all the remaining alphabets are consonants.

        Detailed explanation ( Input/output format, Notes, Images )

        Constraints:
        1 <= T <= 10
        1 <= |S| <= 10^5

        All characters of string S are lowercase alphabets only.

        Where '|S|' denotes the length of string 'S'.

        Time limit: 1 sec

        Sample Input 1:
        2
        abced
        pperu

        Sample Output 1:
        ebcad
        ppure
*/

bool isVowel(char s)
{
    string vowels = "aeiou";

    for (int i = 0; i < vowels.size(); i++)
    {
        if (vowels[i] == s)
        {
            return true;
        }
    }

    return false;
}

string reverseVowels(string &s)
{

    int n = s.size();

    int i = 0, j = n - 1;

    while (i < j)
    {
        if (isVowel(s[i]) and isVowel(s[j]))
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        else if (isVowel(s[i]) and !isVowel(s[j]))
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return s;
}

int main()
{
    string str = "pperu";
    cout << reverseVowels(str);
}