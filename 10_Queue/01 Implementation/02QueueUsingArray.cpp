#include <iostream>
using namespace std;

/*
        ## Queue DataStructures ::  ```````

*/

class Queue
{
        int front, rear, capacity, *queue;

public:
        Queue(int size)
        {
                this->front = 0;
                this->rear = -1;
                this->capacity = size;
                this->queue = new int[size];
        }

        ~Queue() { delete[] queue; }

        // Inserting element into queue
        void enqueue(int value)
        {

                //⭐ 1st -> check queue is full or not
                if (rear == capacity - 1)
                {
                        cout << "Queue Overflow" << endl;
                        return;
                }

                //⭐ 2nd -> increment rear index and insert value
                rear++;
                queue[rear] = value;
        }

        void dequeue()
        {
                // 1st -> check queue is empty or not
                if (front >= rear)
                {
                        cout << "Queue Underflow" << endl;
                        return;
                }

                queue[front] = -1;
                // 2nd -> increment front index
                front++;

                if (front == rear)
                {
                        front = 0;
                        rear = -1;
                }

                cout << "Front element removed" << endl;
        }

        void print()
        {

                if (front >= rear)
                {
                        cout << "Queue is empty" << endl;
                        return;
                }

                int i = front;

                while (i <= rear)
                {
                        cout << queue[i] << " <- ";
                        i++;
                }

                cout << endl;
        }

        void getFront()
        {
                if (front > rear)
                {
                        cout << "Queue is empty" << endl;
                        return;
                }

                cout << queue[front] << endl;
        }

        void size()
        {
                cout << "Size of queue: " << rear - front + 1 << endl;
        }
};

int main()
{

        Queue q1(6);

        q1.getFront();

        // 🗡️ inserting element 
        q1.enqueue(10);
        q1.enqueue(20);
        q1.enqueue(30);
        q1.enqueue(40);
        q1.enqueue(50);
        q1.enqueue(60);
        
        // getting size

        q1.print();

        q1.getFront();

        q1.size();
        
        q1.dequeue();

        q1.print();

        q1.dequeue();

        q1.print();

        q1.enqueue(78);

        q1.size();
}