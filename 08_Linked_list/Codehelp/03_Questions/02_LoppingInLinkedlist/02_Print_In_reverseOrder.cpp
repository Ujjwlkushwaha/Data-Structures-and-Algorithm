#include<iostream>
using namespace std;

// basic structure of nodes
class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void appendNode(Node* &head , Node* &tail , int data){
    // create a new Node
    Node* newNode = new Node( data );

    // if list is empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void print(Node* head){

    if(head == NULL)return;

    cout << head->data << " ";

    print(head->next);
}

void printFromEnd(Node* head){

    if(head == NULL)return;

    printFromEnd(head->next);

    cout << head->data << " ";
}


int main(){

    Node* head = NULL;
    Node* tail = NULL;
    int arr[] = {1,2,3,4,5,6,5};
    
    int s = sizeof(arr)/sizeof(arr[0]);

    for(int i=0 ; i<s ; i++){
        appendNode(head , tail , arr[i]);
    }

    cout<< "Initial linkedlist" << endl;
    print(head);

    cout <<"Print in reverse Order :: " ;
    printFromEnd(head);

}