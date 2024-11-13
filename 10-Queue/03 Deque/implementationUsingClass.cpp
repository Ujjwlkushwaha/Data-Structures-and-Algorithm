#include<iostream>
using namespace std;

class Queue{
    public:
        int front,rear;
        int size;
        int *deque;

        Queue( int s) {
            this->front =-1;
            this->rear =-1;
            this->size = s;
            deque = new int[size];
        }

        bool isFull(){
            if(( front==0 and rear == size-1) or ( front == rear+1 )){
                return true;
            }else{
                return false;
            }
        }

        bool isEmpty(){
            if(( front==-1 and rear == -1)){
                return true;
            }else{
                return false;
            }
        }

        void push_front( int data )
        {   
            // before pushing anywhere lets check queue is full or not
            if( isFull()){
                cout << "Deque is full buddy!" << endl;
            }
            // if queue is empty, then both front and rear will be 0
            else if(isEmpty()){
                front = rear = 0;
                deque[front] = data;
                cout << "Data inserted at front " << endl;
            }
            // if queue is not empty, then front will decrement
            else if(front == 0){
                front = size-1;
                deque[front] = data;
                cout << "Data inserted at front " << endl;
            }
            else{
                front--;
                deque[front] = data;
                cout << "Data inserted at front " << endl;
            }
        }

        void push_back( int data )
        {
            // before pushing anywhere lets check queue is full or not
            if( isFull()){
                cout << "Deque is full buddy!" << endl;
            }
            // if queue is empty, then both front and rear will be 0
            else if(isEmpty()){
                front = rear = 0;
                deque[rear] = data;
                cout << "Data inserted at back " << endl;
            }
            // if queue is not empty, then rear will increment
            else if(rear == size-1){
                rear = 0;
                deque[rear] = data;
                cout << "Data inserted at back " << endl;
            }
            else{
                rear++;
                deque[rear] = data;
                cout << "Data inserted at back " << endl;
            }
        }

        void pop_front()
        {
            // before popping anywhere lets check queue is empty or not
            if( isEmpty()){
                cout << "Deque is empty buddy!" << endl;
            }
            // if queue has only one element then both front and rear will be -1
            else if(front == rear){
                cout <<  deque[front] << "is deleted from front 👍 " << endl;
                deque[front] = -1;
                front = rear = -1;
            }
            // if queue has more than one element and front is on last index
            else if(front == size-1){
                cout <<  deque[front] << "is deleted from front 👍 " << endl;
                deque[front] = -1;
                front = 0;
            }
            else{ 
                // normal case
                cout <<  deque[front] << "is deleted from front 👍 " << endl;
                deque[front] = -1;
                front++;
            }
        }

        void pop_back()
        {
            // before popping anywhere lets check queue is empty or not
            if( isEmpty()){
                cout << "Deque is empty buddy!" << endl;
            }
            // if queue has only one element then both front and rear will be -1
            else if(front == rear)
            {
                cout <<  deque[rear] << "is deleted from back �� " << endl;
                deque[rear] = -1;
                front = rear = -1;
            }
            // if queue has more than one element and rear is on first index
            else if(rear == 0){
                cout <<  deque[rear] << "is deleted from back �� " << endl;
                deque[rear] = -1;
                rear = size-1;
            }
            else{
                // normal case
                cout <<  deque[rear] << "is deleted from back �� " << endl;
                deque[rear] = -1;
                rear--;
            }
        }

        void display()
        {
            if(isEmpty()){
                cout << "Deque is empty buddy!" << endl;
            }
            else{
                cout << "Deque elements are: ";
                if(front <= rear)
                {
                    for(int i = front; i <= rear; i++)
                        cout << deque[i] << " ";
                }
                else
                {
                    for(int i = front; i < size; i++)
                        cout << deque[i] << " ";
                    for(int i = 0; i <= rear; i++)
                        cout << deque[i] << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
    Queue q(5);
    q.push_back(10);
    q.push_back(20);
    q.push_back(30);
    q.push_back(40);
    q.display();

    q.push_front(15);
    q.display();

    q.pop_back();
    q.display();

    q.pop_front();
    q.display();
}