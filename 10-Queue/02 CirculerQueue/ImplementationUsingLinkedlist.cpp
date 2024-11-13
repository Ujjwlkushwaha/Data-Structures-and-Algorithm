#include<iostream>
using namespace std;

// Implementation of Queue using linked list
class QNode{
    public:
        int data;
        QNode* next;

        QNode(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Queue{
    QNode* front;
    QNode* rear;

    public:
        Queue()
        {
            this->front =  NULL;
            this->rear = NULL;
        }

        // check if queue is empty  or not  (front == NULL and rear == NULL)
        bool isEmpty()
        {
            return front == NULL and rear == NULL;
        }

        // insert into queue
        void enQueue(int d ){
            
            QNode* newNode = new QNode(d);
            // check 
            if( front == NULL and rear == NULL )
            {
                front = rear = newNode;
                return;
            }

            rear->next = newNode;
            rear = newNode;
        }

        int dequeue()
        {

            // check queue is empty or not
            if( isEmpty()){
                cout << "Queue is underflow!" << endl;
                return -1;
            }

            // queue has single element
            if( front->next == NULL )
            {
                QNode * temp = front;
                front = rear = NULL;

                int data = temp->data;
                temp->next = NULL;
                delete temp;

                return data;
            }

            // normal case

            QNode* temp = front;
            front = front->next ;

            temp->next = NULL;
            int data = temp->data;
            delete temp;

            return data;
        }

        int frontElement(){
            if( isEmpty() ){
                cout << "Queue is underflow!" << endl;
                return -1;
            }

            return front->data;
        }
        void printQueue()
        {
            QNode * temp = front;
            while( temp ){
                cout << temp->data << "<-";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }

};

int main()
{

    Queue q;

    q.enQueue(5);
    q.enQueue(6);
    q.enQueue(7);
    q.enQueue(8);
    q.enQueue(9);
    q.enQueue(10);

    q.printQueue(); // 5<-6<-7<-8<-9<-10<-NULL

    cout << "Deleted elemenet is:: " << q.dequeue() << endl; // Deleted elemenet is:: 5

    q.printQueue(); // 6<-7<-8<-9<-10<-NULL


    cout << "Deleted elemenet is:: " << q.dequeue() << endl; 
    cout << "Deleted elemenet is:: " << q.dequeue() << endl;
    cout << "Deleted elemenet is:: " << q.dequeue() << endl; 
    cout << "Deleted elemenet is:: " << q.dequeue() << endl; 
    cout << "Deleted elemenet is:: " << q.dequeue() << endl; 
    cout << "Deleted elemenet is:: " << q.dequeue() << endl; 

// Deleted elemenet is:: 6
// Deleted elemenet is:: 7
// Deleted elemenet is:: 8
// Deleted elemenet is:: 9
// Deleted elemenet is:: 10
// Queue is underflow!
// Deleted elemenet is:: -1

}