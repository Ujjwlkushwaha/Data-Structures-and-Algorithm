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

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    Node* newNode = new Node(data);
    if (position == 1) {
        // newNode->next = head;
        head = newNode;
        if (tail == NULL) { // If the list was empty, now tail is also the newNode.
            tail = newNode;
        }
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        cout << "Position exceeds the size of the list." << endl;
        delete newNode; // Prevent memory leak since newNode is not added to the list.
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if (newNode->next == NULL) { // If newNode is inserted at the end, update the tail.
        tail = newNode;
    }
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