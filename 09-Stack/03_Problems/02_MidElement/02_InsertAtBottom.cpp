#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& stack , int key)
{
    if(stack.empty())
    {
        stack.push(key);
        return;
    }

    // store top value for backtracking
    int temp = stack.top();

    stack.pop();
    insertAtBottom(stack , key);
    stack.push(temp);
}

void printStack(stack<int> s)
{
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
int main(){
    
    stack<int> s;
    int arr[] = {1, 2, 3, 4, 5};
    // Push elements into the stack
    for(int i=0; i<5; i++)
        s.push(arr[i]);

    int target = 33;
    insertAtBottom(s , target);

    printStack(s);
}