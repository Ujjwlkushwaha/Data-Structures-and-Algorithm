/*
    Longest substring with distinct character ( Difficulty: Easy )

        Given a string s, find the length of the longest substring with all distinct characters.

Examples:

    Input: s = "geeksforgeeks"
    Output: 7
Explanation: "eksforg" is the longest substring with all distinct characters.

    Input: s = "aaa"
    Output: 1
Explanation: "a" is the longest substring with all distinct characters.

    Input: s = "abcdefabcbb"
    Output: 6
Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.

*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestSubstringWithDistinctChars(const string &s)
{
    unordered_map<char, int> charIndexMap; // To store the index of characters
    int maxLength = 0;                     // To store the length of the longest substring
    int start = 0;                         // Start of the sliding window

    for (int end = 0; end < s.length(); ++end)
    {
        char currentChar = s[end];

        // If the character is already in the map and within the current window
        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start)
        {
            start = charIndexMap[currentChar] + 1; // Move the start to the right of the duplicate
        }

        charIndexMap[currentChar] = end;             // Update the index of the current character
        maxLength = max(maxLength, end - start + 1); // Update the maximum length
    }

    return maxLength;
}

int main()
{
    string s;

    cout << "Enter a string: ";
    cin >> s;

    int result = longestSubstringWithDistinctChars(s);
    cout << "The length of the longest substring with distinct characters is: " << result << endl;

    return 0;
}
