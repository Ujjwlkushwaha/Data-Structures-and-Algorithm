#include <bits/stdc++.h> 
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
} ;
//............................................................................................................................
// creation of singly-linked list
void createList(Node* &head , int data)
{
    // ak nya node bnaya or usne data daal diyaa
    Node* newNode = new Node(data);

    // ab usko list me set to krna pdega naa

    // to check kiya list khali to nhi haii
    if(head == NULL){ // agar hnn

        // to head me iss nye node ka address daal do jisse ye pta lgega ki ye pahla node hai
        head = newNode;
        return;// and go back
    }

    // agar nhi to ak temp pointer bnao kyuki hm head ko direct nhi chhed sakte
    Node* temp = head;

    // ab meko tab tak aage badhna hai jab tak awsa NODE na mil jaye jiske next me NULL ho
    while(temp->next != NULL){
        temp = temp->next; // jump 
    }

    // jab vo node mil jaye to uske next me newNode ka address daal do 
    temp->next = newNode ;
    
    // or head ko avap bhej do
}

//............................................................................................................................

void insertAtBg(Node* &head , int data)
{
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;

}
//............................................................................................................................

// insert at given position

void insertAtPosition(Node* &head , int data , int position)
{
    // pahle to check kr lo jo jagah bol rha hai vo valid hai bhi ya nhii

    if(position == 1){
        insertAtBg(head , data);
        return;
    }

    if(position < 1){
        cout <<"Sorry bro :: Enter valid position :) " << endl;
        return;
    }

    Node * newNode = new Node(data);
    Node *temp = head;

    int c = 1;

    // jiss position pe jana hai uske ak pahle ruk jao
    while(c<position-1){
        temp = temp->next;
        c++;
    }
     // cross connection bhidaa do
    newNode->next = temp->next;
    temp->next = newNode ;
}
//............................................................................................................................


// displaying the data of the list
void displayList(Node* head)
{
    Node* temp = head;

    // tab tak bhago jab tak aakhri node na aa jaye jiske pass NULL hia 
    while(temp != NULL){
        cout << temp->data << " -> " ;
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

//............................................................................................................................

int main(){

    Node* head = NULL; 

    vector<int> arr = {2,3,4,5,6}; // maine iss vector ko ak list me daal diya bass

    for(int i = 0 ; i<arr.size() ; i++){
        createList(head , arr[i]);
    }

    // display kara liya data ko
    displayList(head);

    // insert element at begining of the list
    insertAtBg(head , 1);
    displayList(head);

    // insert at given Position
    insertAtPosition(head , 10 , 2);
    displayList(head);

    insertAtPosition(head , 15 , 6);
    displayList(head);
}
