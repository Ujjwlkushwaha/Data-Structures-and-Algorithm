#include <iostream>
using namespace std;

// In this code we have learn how to implement stack using arrays
class Stack
{
public:
    int size;
    int *array;
    int top1;
    int top2;
    // Constructor
    Stack(int s)
    {
        size = s;
        array = new int[size,0];
        top1  =  -1;
        top2 = size;
    }

    // insert a new element into the stack
    void pushLeftStack(int value)
    {
        if (top2 - top1 <= 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top1++;
        array[top1] = value;
    }
    void pushRightStack(int value)
    {
        if (top2 - top1 <= 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        top2--;
        array[top2] = value;
    }


    void popfromleft()
    {
        if (top1 == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        top1--;
    }

    int getLengthOfLeftStack()
    {
        if (top1 == -1)
            return 0;

        return top1 + 1;
    }
    int getLengthOfRightStack()
    {
        if (top2 == size)
            return 0;

        return size-top2+1;
    }


    void display()
    {
        cout << "Stack elements are: ";
        for (int i = 0; i <size; i++)
        {
            cout << array[i] << " ";
        }
    }
};

// Driver code

int main()
{
    Stack stack(10);

    stack.pushLeftStack(10);
    stack.pushLeftStack(20);
    stack.pushLeftStack(30);
    stack.pushLeftStack(40);
    stack.pushLeftStack(50);
    stack.pushLeftStack(60);
    stack.pushRightStack(100);
    stack.pushRightStack(90);
    stack.display();
}