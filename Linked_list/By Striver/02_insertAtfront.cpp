#include<iostream>
using namespace std;

class Node{
    public:
       int data;
       Node* next;

       Node(int data) : data(data) ,next(nullptr){}
};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }

    void insertAtbegining(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void printList(){
        
        Node* temp = head;
        while(temp != nullptr){
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