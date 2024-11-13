#include<bits/stdc++.h>
using namespace std;

// reverse k element of a queue
void reverseKelement( queue<int>&q , int k)
{   
    // agr k zero ho ya fir size se jyada bda ho to
    if( k == 0 or k > q.size())
    {
        cout << "Not possible bhaiya ! "<< endl;
        return;
    }
    
    stack<int> s;
    int n = k;

    while( !q.empty() and n)
    {
        s.push(q.front());
        q.pop();
        n--;
    }

    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    int remaining = q.size() - k;

    while(remaining--)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

int main()
{
    queue<int> q;
    int k = 3; // k elements to be reversed

    q.push(1);


    q.push(2);
    q.push(3);
    // q.push(4);
    q.push(5);


    reverseKelement(q, k);

    cout << "\nReversed Queue: ";
    while(!q.empty() )
    {
        cout << q.front() << " ";
        q.pop();
    }
}