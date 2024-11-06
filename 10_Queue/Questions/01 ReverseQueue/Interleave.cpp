    // 📌 Interleave first and second half of queue
#include <bits/stdc++.h>
using namespace std;

void printQueue(queue<int> st)
{
    while (!st.empty())
    {
        cout << st.front() << " ";
        st.pop();
    }
    cout << endl;
    return; // Return to avoid printing the extra newline character at the end of the output.
}

// Function to interleave first and second half of queue
void interleaveQueue(queue<int> &q1)
{
    // Check if queue is empty
    if (q1.empty())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    int n = q1.size();
    queue<int> q2;

    // Push all elements of queue into two stacks
    for (int i = 0; i < n/2; i++)
    {
        q2.push(q1.front());
        q1.pop();
    }

    // interleaving
    while( !q1.empty() and !q2.empty() )
    {
        int firstElement = q2.front();
        q2.pop();
        q1.push(firstElement);

        int secondElement = q1.front();
        q1.pop();
        q1.push(secondElement);
    }

    if( n & 1 ){
        int element = q1.front();
        q1.pop();
        q1.push(element);
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    printQueue(q);
}