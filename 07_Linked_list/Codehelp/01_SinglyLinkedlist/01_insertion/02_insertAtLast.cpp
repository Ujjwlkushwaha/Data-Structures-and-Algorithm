#include<iostream>
using namespace std;

//creating a node
class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

//function to insert at the end of the list
void insertAtEnd(Node* &head , Node* &tail , int data)
{
    Node *newNode = new Node(data);
    if( head == NULL && tail == NULL ){
        head = newNode;
        tail = newNode;
        return;
    }
    
    tail->next = newNode;
    tail = newNode;
}

void display(Node* &head)
{
    Node* temp = head;
    while(temp->next != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout <<"NULL";
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
   
    int arr[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    
    for(int i=0; i<14 ; i++){
        insertAtEnd(head ,tail , arr[i]);
    }

    display(head);
    return 0;

}