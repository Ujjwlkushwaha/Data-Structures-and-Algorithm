#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

int main(){

    // create head of the linkedlist
    Node* head = NULL;

    // creating and connecting the node

    Node* node1 = new Node(10);
    head = node1;

    Node* node2 = new Node(11);
    node1->next = node2;
    Node* node3 = new Node(12);
    node2->next = node3;

    Node* node4 = new Node(13);
    node3->next = node4;

    Node* node5 = new Node(14);
    node4->next = node5 ;

    // traverse the linkedlist
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << "-> ";

        // this line helps pointer to jump one node to another
        temp = temp->next;
    }

    cout << "NULL" << endl;


}