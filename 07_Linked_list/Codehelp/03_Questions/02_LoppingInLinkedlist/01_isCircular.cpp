// check given linkedlist is circuler of not


#include<iostream>
using namespace std;

// structure of node {data , *next}
class Node{
    public:
        int data;
        Node* next;

    Node(int data)
    {
        this->next = NULL;
        this->data = data;
    }
};

// inserting a node in circuler linkedlist 
void insertNode(Node* &head , int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}


bool isCirculer(Node* head)
{
    if(head == NULL){
        return false;
    }

    Node* temp = head;

    while(temp != NULL)
    {
        temp = temp->next;
        if(temp == head){
            return true;
        }
    }

    return false;

}



int main()
{
     Node* head = NULL;
    int arr[] = {3,4,5,6,7,8,9,10};

    int s = sizeof(arr) / sizeof(arr[0]);

    for(int i=0 ; i<s ; i++){
        insertNode(head , arr[i]);
    }

    if(isCirculer(head)){
        cout << "List is circuler !"<<endl;
    }else{
        cout << "List is not circuler" << endl;
    }
}