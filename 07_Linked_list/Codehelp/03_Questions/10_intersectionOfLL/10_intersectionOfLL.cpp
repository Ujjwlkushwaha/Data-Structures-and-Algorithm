#include<iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->next = NULL;
            this->data = data;
        }
};

void printList(Node* head){
    if(head == NULL)return;

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


// find  intersection  of  2 linkedlist

Node* intersectionNode(Node* headA , Node* headB){

    if(headA == NULL or headB == NULL){
        return NULL;
    }

    Node* l1 = headA;
    Node* l2 = headB;

    if(l1->next == NULL and l2->next == NULL) {
        if(l1 == l2){
            return l1;
        }
    }

// agar dono length equal ho
    while(l1->next != NULL && l2->next != NULL)
    {
        if(l1 == l2){
            return l1;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    // agar list 1 is bigger then 2
    if(l1->next != NULL){
        // l1 is greater

        // count how much bigger
        int l1Len = 0;
        while(l1->next != NULL){
            l1Len++;
            l1 = l1->next;
        } 

        // list 1 ke head ke utne aage set kr do
        while(l1Len--){
            headA = headA->next;
        }
    }

    // agar list 2 badi huyi
    else if(l2->next != NULL){
        // l1 is greater
        int l2Len = 0;
        while(l2->next != NULL){
            l2Len++;
            l2 = l2->next;
        } 

        while(l2Len--){
            headB = headB->next;
        }
    }


    while(headA != NULL && headB != NULL){
            if(headA == headB){
                return headA;
            }

            headA = headA->next;
            headB = headB->next;
    }

    return NULL;
}


int main(){

// crete 1st linkedlist
    Node* headA = NULL;

    Node* List1node1 = new Node(1);
    headA = List1node1;
    Node* List1node2 = new Node(2);
    List1node1->next = List1node2;
    Node* List1node3 = new Node(3);
    List1node2->next = List1node3;
    Node* List1node4 = new Node(4);
    List1node3->next = List1node4;
    Node* List1node5 = new Node(5);
    List1node4->next = List1node5;
    Node* List1node6 = new Node(6);
    List1node5->next = List1node6;

    cout << "Linkedlist 1st :: " << endl;
    printList(headA);


// create 2nd linkedlist
    Node* headB = NULL;

    Node* List2node1 = new Node(1);
    headB = List2node1;

    Node* List2node3 = new Node(2);
    List2node1->next = List2node3;

    // this line create intersection between the linkedlist
    List2node3->next = List1node6;

    cout << "Linkedlist 2nd :: " << endl;
    printList(headB);

    if(intersectionNode(headA , headB) != NULL)
    {
       cout << " the intersection Node is : " << intersectionNode(headA , headB)->data << endl;
    }else{
        cout << "No intersection between these Linkedlist !!" << endl;
    }
}