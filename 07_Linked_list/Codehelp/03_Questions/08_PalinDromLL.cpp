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

void print(Node* head) {
        Node* temp = head;

        while(temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
        }
        cout << endl;
}

// 1, getMidNode()

Node* getMidNode(Node* head){

    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL  and fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* reverseList(Node* &head){

    if(head == NULL){
        return NULL;
    }

    if(head->next == NULL){
        return head;
    }

    Node* pre = NULL;
    Node* curr = head;
    Node* forword = curr->next;

    while(forword != NULL ){
        forword = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forword; 
    }

    return pre;
}

bool isPalindrom(Node* head){
    if(head == NULL) {
        return false;
    }

    if(head->next == NULL){
        return true;
    }

    Node* midNode = getMidNode(head);
    Node* reversePointer = reverseList(midNode->next);

    midNode->next = reversePointer;

    Node* temp1 = head;
    Node* temp2 = reversePointer;

    while(temp2 != NULL ){

        if(temp1->data != temp2->data){
            return false;
        }
        else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    return true;
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;
    int arr[] = {1,2,3,4,5,6,5,4,3,2,1};
    
    int s = sizeof(arr)/sizeof(arr[0]);

    for(int i=0 ; i<s ; i++){
        appendNode(head , tail , arr[i]);
    }

    cout<< "Initial linkedlist" << endl;
    print(head);

    cout <<"get the middle node of the linkedlist: "<<endl;
    cout << getMidNode(head)->data << endl;

    cout << "After reversing the linkedlist " << endl;
    head = reverseList(head);
    print(head);

    if(isPalindrom(head)){
        cout<< " Yes, It is palindrom !" << endl;
    }else{
        cout << "No! ,  it is not palindrom ! "<< endl;
    }

}