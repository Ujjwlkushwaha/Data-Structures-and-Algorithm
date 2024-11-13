#include<bits/stdc++.h>
using namespace std;

// reverse queue
void reverse_queue( queue<int>&q )
{   
    stack<int> s;

    // pahle queue ke sare element stack me daal do
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    // then stack se saare element fir se queue me daal do
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return;
    // queue ke elements reverse ho gaye hai

}

void reverseQueueUsingRecursion( queue<int>&q)
{
    if(q.empty()) return;

    int temp = q.front();
    q.pop();

    reverseQueueUsingRecursion(q);

    q.push(temp);
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQueueUsingRecursion(q);

    cout << "\nReversed Queue: ";
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    
    }
}