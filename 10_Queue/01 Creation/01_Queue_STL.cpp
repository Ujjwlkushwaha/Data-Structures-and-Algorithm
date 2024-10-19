#include<iostream>

// queue library
#include<queue>
using namespace std;

int main()
{
    queue<int> que ;

    
    // insert Element
    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);

    cout << "Front Element is: " << que.front() << endl;
    cout << "Back Element is: " << que.back() << endl;

    // remove element
    que.pop();
    cout << "After removing Front Element, Front Element is: " << que.front() << endl;

    // size of queue
    cout << "Size of Queue is: " << que.size() << endl;

    if(!que.empty()){
        cout << "Queue is  not empty" << endl;
    }
    return 0;
}