#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;

        // initialization List
        Node(int data) : data(data) , next(nullptr) {}
};

class LinkedList{
    Node* head;

    public:
        LinkedList() : head(nullptr){}

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

    //insert at given position in the linked list
        void insert(int data , int pos)
        {
            Node* newNode = new Node(data);

            Node *temp = head;
            for(int i = 1 ; i<pos-1 ; i++){
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        int size(){
            Node* temp = head;
            int count = 0;
            while(temp!=nullptr){
                count++;
                temp =temp->next;
            }

            return count;
        }

    // printing the list
        void print_list(){
            Node* temp = head;
            while(temp!=nullptr){
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

    list->insert(5 , 1);
    list->insert(15 , 2);
    list->insert(25 , 4);
    list->insert(35 , 6);
    list->insert(45 , 8);
    list->insert(50 , 9);

    cout << "sizeof linked list :: " << list->size()<< endl;

    // printing the list
    list->print_list();
}