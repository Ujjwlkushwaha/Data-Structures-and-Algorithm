#include <bits/stdc++.h>
using namespace std;

// Helper function to check if `sub` is a substring of `main`.
bool isSubstringOf(string &sub, string &main)
{
    // Loop through possible starting indices in `main`.
    for (int startIndex = 0; startIndex < main.size(); startIndex++)
    {
        bool subFits = true;

        // Check if the substring matches from the current start index.
        for (int subIndex = 0; subIndex < sub.size(); subIndex++)
        {
            if (startIndex + subIndex >= main.size() ||
                main[startIndex + subIndex] != sub[subIndex])
            {
                subFits = false; // The substring doesn't match.
                break;           // No need to continue further for this start index.
            }
        }

        if (subFits)
        {
            return true; // Found a match, return true.
        }
    }

    return false; // No match found.
}

// ✅ Brute force Approach
vector<string> stringMatching(vector<string> &words)
{

    vector<string> ansStringArray;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            // mean we match same words
            if (words[i] == words[j])
                continue;

            // if the words[i] is the subStringOF words[j]
            if (isSubstringOf(words[i], words[j]))
            {
                ansStringArray.push_back(words[i]);
                break;
            }
        }
    }

    return ansStringArray;
}

int main()
{
    vector<string> words = {"mass","as","hero","superhero"};

    vector<string> ans = stringMatching(words);

    for( auto word : ans)
    {
        cout << word << " ";
    }
    
    return 0;
}