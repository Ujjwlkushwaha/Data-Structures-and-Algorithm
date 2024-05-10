#include <iostream>
using namespace std;

//  basic Implementation of node of singly-linked list
class Node{
    public:
        int data;
        Node* next ;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

int main(){

    // Every linked list has a head pointer which always pointing to first node of the list
    Node * head = NULL;

    // now we create a node 
    Node * First = new Node(2);

    //now head is pointing to first node 
    head = First; 

    cout << "Head containing address of first node :: " << head << endl;

    cout << "Data of first node is :: " << First->data <<endl;
    cout << "Next part of first node is :: " << First->next <<endl;
    cout << "Address of first Node is :: " << First << endl;

}