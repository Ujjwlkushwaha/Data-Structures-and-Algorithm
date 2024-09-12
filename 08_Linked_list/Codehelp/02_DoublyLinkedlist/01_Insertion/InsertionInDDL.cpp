#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *pre;
    node *next;

    node(int data)
    {
        this->data = data;
        this->pre = NULL;
        this->next = NULL;
    }
};

class DoublyLinkedList
{
    private : 
        node* head;
        node* tail;

    public:
        DoublyLinkedList(){
            this->head = NULL;
            this->tail = NULL;
        }

        void insertAtEnd(int data){
            node * newNode = new node(data);

            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }

            node* temp = head;

            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }


        void insertAtBeginning(int data){
            node* newNode = new node(data);

            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }

            newNode->next = head;
            head->pre = newNode;
            head = newNode;
        }


        void insertAtPos(int data , int pos){
            node* newNode = new node(data);

            if(pos == 1){
                insertAtBeginning(data);
                return;
            }

            node* temp  = head;
            int c = 1;
            while( temp->next != NULL and c < pos-1){
                c++;
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        void printList(){
            node* temp = head;

            while(temp != NULL){
                cout << temp->data << "-> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
};

int main()
{
    DoublyLinkedList l1;

    int arr[] = {1,2,3,4};


    for(int i = 0 ; i<4 ; i++){
        l1.insertAtEnd(arr[i]);
    }

    l1.printList();
    l1.insertAtBeginning(0);
    l1.printList();

    l1.insertAtPos(10 , 3);
    l1.printList();

    l1.insertAtPos(5 , 1);
    l1.printList();

    l1.insertAtPos(12, 6);
    l1.printList();
}