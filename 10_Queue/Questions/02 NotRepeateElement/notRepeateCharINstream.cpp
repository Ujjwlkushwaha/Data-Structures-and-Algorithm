#include<bits/stdc++.h>
using namespace std;

//📌 we have to find first non repeated char in stream

void printQueue(queue<char> st)
{
    while (!st.empty())
    {
        cout << st.front() << " ";
        st.pop();
    }
    cout << endl;
    return; // Return to avoid printing the extra newline character at the end of the output.
}



char notRepeatedChar( string str )
{
    // using queue 
    queue<char> q;
    
    // fill queue and map with char and its frequency
    for( char ch : str)
    {
        q.push(ch);
    }
}


int main()
{

    string str = "googlee";
    cout << notRepeatedChar(str) << endl; // output: 'l'

}