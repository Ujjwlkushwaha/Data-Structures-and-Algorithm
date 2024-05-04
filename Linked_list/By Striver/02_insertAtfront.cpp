#include<iostream>
using namespace std;

class Node{
    public:
       int data;
       Node* next;

    // initializer_list
       Node(int data) : data(data) ,next(NULL){}
};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = NULL;
    }

    void insertAtbegining(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void printList(){
        
        Node* temp = head;
        while(temp != NULL)
        {
            cout<< temp->data <<" -> ";
            temp = temp->next;
        }
        cout << "NULL"<<endl;
    }
};
int main(){

    LinkedList list;

    list.insertAtbegining(30);
    list.insertAtbegining(20);
    list.insertAtbegining(10);

    list.printList();

}