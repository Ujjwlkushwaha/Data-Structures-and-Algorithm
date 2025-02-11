#include<bits/stdc++.h>
using namespace std;

void removeOccurrences(string s, string part) {
    
    // find kro 
    while( s.find( part , 0 ) != string::npos )
    {
        int i = s.find( part , 0 );
        s.erase(i , part.length()) ; // erase krte jao 
    }
    
    cout << s << endl;
}

int main()
{
    removeOccurrences("abbbbcccc" , "bc");
}

// Leetcode : https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/?envType=daily-question&envId=2025-02-11