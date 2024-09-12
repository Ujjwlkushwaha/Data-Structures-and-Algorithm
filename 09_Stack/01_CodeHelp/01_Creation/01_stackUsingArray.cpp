#include <iostream>
using namespace std;

// In this code we have learn how to implement stack using arrays
class Stack
{
public:
    int size;
    int *stack;
    int top;
    // Constructor
    Stack(int s)
    {
        size = s;
        stack = new int[size];
        top = -1;
    }

    // insert a new element into the stack
    void push(int value)  //O(1)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        stack[top] = value;
    }

    void pop() //O(1)
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        top--;
    }

    int getLength() //O(1)
    {
        if (top == -1)
            return 0;

        return top + 1;
    }

    bool isEmpty() //O(1)
    {
        return top == -1;
    }

    int peek() //O(1)
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stack[top];
    }

    void display()  //O(n)
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
    }
    ~Stack()
    {
        delete[] stack;
    }
};

// Driver code

int main()
{
    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50); // This will cause stack overflow
    stack.push(50); // This will cause stack overflow
    stack.push(50); // This will cause stack overflow

    cout << "Top element is: " << stack.peek() << endl;
    cout << "Stack length is: " << stack.getLength() << endl;
    stack.display();
    stack.pop();
    cout << "\nTop element after popping is: " << stack.peek() << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop(); // This will cause stack underflow
}