#include <iostream>
using namespace std;

/*
     ⭐ Circular Queue implementation :: Circular Queue is advance version of normal queue in which last element is connected to
    first element of the queue. thats make circuler queue .

        Operation of Circular Queue

                enQueue -> insert Element
                deQueue -> remove Element
                front -> first element
                rear -> last element
 */

class Queue
{
    int front, rear, capacity;
    int *queue;

public:
    Queue(int size)
    {
        this->front = -1;
        this->rear = -1;
        this->capacity = size;
        this->queue = new int[size];
    }

    void enQueue(int val)
    {

        // Check queue is full or not
        // check if queue has single element
        // maintain circuler nature
        // normal flow

        if ((front == 0 && rear == capacity - 1) || ((rear + 1) % capacity == front))
        {
            cout << "Queue is Full buddy! " << val << " is not inserted " << endl;
            return;
        }

        // quque is empty
        if (front == -1)
        {
            front = rear = 0;
            queue[rear] = val;
        }
        else if (rear == capacity - 1 && front != 0)
        {
            rear = 0;
            queue[rear] = val;
        }
        else
        {
            rear++;
            queue[rear] = val;
        }
    }

    void deQueue()
    {

        if (front == -1)
        {
            cout << "Queue is empty Bro ! " << endl;
            return;
        }

        int x = queue[front];
        queue[front] = -1;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == capacity - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        cout << x << " is removed from queue" << endl;
    }

    void getFront()
    {
        cout << " front = " << queue[front] << endl;
    }

    void getBack()
    {
        cout << " Back = " << queue[rear] << endl;
    }
}
;

int main()
{
    Queue q1(6);

    q1.enQueue(14);
    q1.enQueue(15);
    q1.enQueue(16);
    q1.enQueue(19);
    q1.enQueue(34);
    q1.enQueue(15);
    // q1.enQueue(65);

    q1.getFront();
    q1.getBack();

    q1.deQueue();
    q1.getFront();

    q1.deQueue();
    q1.getFront();

}