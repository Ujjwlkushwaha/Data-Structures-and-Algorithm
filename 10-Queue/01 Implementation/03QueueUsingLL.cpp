#include<iostream>
using namespace std;

// 1️⃣ ---------------------creating node--------------------------
class Node{
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};

//-----------------------creating queue---------------------------
class Queue
{
    Node* front;
    Node* rear;

    public:
        Queue()
        {
            this->front =  NULL;
            this->rear = NULL;
        }

        bool isEmpty()
        {
            return front == NULL and rear == NULL;
        }

        void enQueue( int d )
        {
            if( front == NULL )
            {
                Node* newNode = new Node(d);
                front = newNode;
                rear = newNode;
            }
            
        }

};


int main(){

}