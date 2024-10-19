#include<bits/stdc++.h>
using namespace std;

// In this question we have to find non repeated char in stream

char notRepeatedChar( string str )
{
    // using queue 

    queue<char> q;
    unordered_map<char, int> freq;
    
    // fill queue and map with char and its frequency
    for( char ch : str)
    {
        q.push(ch);
        freq[ch]++;
    }

    while(!q.empty())
    {
        char ch = q.front();
        q.pop();
        if( freq[ch] == 1)
            return ch;
        freq[ch]--;
    }
    return -1; // if no non repeated char found
    // or if all chars are repeated
}
int main()
{

    string str = "google";
    cout << notRepeatedChar(str) << endl; // output: 'l'

}