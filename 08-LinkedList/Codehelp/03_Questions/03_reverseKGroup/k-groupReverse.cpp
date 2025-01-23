// In this problem->

// Iss problem me hme ak LL dee hai jisme hme k(integer) group me reverse krna hai 

// input list    3-> 4-> 5-> 6-> 7-> 8-> 9-> 10-> NULL    k=3
// output list  5-> 4-> 3-> 8-> 7-> 6-> 9-> 10->NULL

// hm logo ko uss perticular group ki nodes ko reverse krna hai bsss jitne group bn sake uss ll me

#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node* &head , int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}


int getLen(Node* head){
    if(head == NULL){
        return 0;
    }

    int c = 0;
    Node* temp = head;
    while(temp != NULL){
        c++;
        temp = temp->next;
    }

    return c;
}


void printData(Node* head){
    if(head == NULL){
        cout << "list is empty!" << endl;
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data << "-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// approach -> this problem can be solved using recursion 
// iska ak group hm log revese krege baaki recursion se ho jayga

Node* reverseKgroup(Node* &head , int k){

// base case 1

    if(k == 0 or k > getLen(head)){
        return head;
    }

    if(head == NULL){
        cout << "list is empty, task denay!" << endl;
        return NULL;
    }

    Node* pre = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    int count = 0;

    while(count < k){
        forward = curr->next;
        curr->next = pre;
        pre  = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL){
        head->next = reverseKgroup(forward , k);
    }

    return pre;
}


int main()
{

    Node* head = NULL;
    int arr[] = {3,5, 4, 7, 7, 9, 8, 3, 1, 8, 6};

    int s = sizeof(arr) / sizeof(arr[0]);

    for(int i=0 ; i<s ; i++){
        insertNode(head , arr[i]);
    }

    printData(head);

    head = reverseKgroup(head , 3);
    printData(head);
}