#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;

        // initialization List
        Node(int data) : data(data) , next(NULL) {}
};

class LinkedList{
    Node* head;

    public:
        LinkedList() : head(NULL){}

    // insert at the end of the linked list
        void append(int data)
        {
            Node* newNode = new Node(data);

            if(head == nullptr){
                head = newNode;
                return;
            }

            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }

            temp->next = newNode;
        }

    // insert at the beginning of the linked list
         void insertAtbegining(int data)
         {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
       }

    // printing the list
        void print_list(){
            Node* temp = head;
            while(temp != NULL)
            {
                cout<<temp->data << "-> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
};

int main(){
    LinkedList *list = new LinkedList();

    list->append(10);
    list->append(20);
    list->append(30);
    list->append(40);

    // printing the list
    list->print_list();
}